/*
 * GroundStationApp.cc
 *
 *  Created on: Mar 24, 2022
 *      Author: cif7992
 */

#include <iostream>

#include <inet/common/ModuleAccess.h>
#include <inet/common/TimeTag_m.h>

#include "GSSenderApp.h"
#include "util/DataTypes/Images.h"

Define_Module(GSSenderApp);

using namespace inet;

GSSenderApp::GSSenderApp()
{
    selfSender_ = nullptr;
    stringImages = new Images();
}

GSSenderApp::~GSSenderApp()
{
    cancelAndDelete(selfSender_);
}


void GSSenderApp::initialize(int stage)
{
    EV << "GSSenderApp::initialize - stage " << stage << endl;

    cSimpleModule::initialize(stage);

    // avoid multiple initializations
    if (stage!=inet::INITSTAGE_APPLICATION_LAYER)
        return;
    
    selfSender_ = new cMessage("selfSender");
    bytesSent = 0;
    numSent = 0;
    sentFrames = 0;
    int videoLength = par("videoLength");
    int fps = par("fps");
    numFrames =  videoLength * fps;

    dataSentSignal = registerSignal("dataSentSignal");
    dataSentSignalKbs = registerSignal("dataSentSignalKbs");

    sendImages_ = par("sendImages");
    size_ = par("packetSize");
    localPort_ = par("localPort");
    destPort_ = par("destPort");
    destAddress_ = inet::L3AddressResolver().resolve(par("destAddress").stringValue());

    socket.setOutputGate(gate("socketOut"));
    socket.bind(localPort_);

    EV << "GSSenderApp::initialize - binding to port: local:" << localPort_ << " , dest:" << destPort_ << endl;

    //traffic starting time
    simtime_t startTime = par("startTime");
    //stopTime_ = par("stopTime");

    simtime_t offset = startTime + simTime();

    scheduleAt(offset ,selfSender_);
    EV << "\t starting traffic in " << offset << " seconds " << endl;

    //Define csv file to log data
    std::string fileName = "../../../ReturnDirectory/Results/CoordinateOut/Coordinates_" + std :: string(simTime().str()) + "_" + std :: string(getParentModule()->str()) + ".csv";
    logcoord = new logCoord(getParentModule(), fileName);

    // set time to stop communication once the trajectory ends
    cModule *targetModule = getParentModule()->getParentModule() ->getSubmodule("FlightScheduleManager");
    FlightScheduleManager *time = check_and_cast <FlightScheduleManager *>(targetModule);
    stopTime_ = time -> getTime();

}

void GSSenderApp::handleMessage(cMessage *msg)
{

    if (msg->isSelfMessage())
    {
        readData();
        if (!strcmp(msg->getName(), "selfSender"))
            sendWirelessAppPacket();
        else
            throw cRuntimeError("GSSenderApp::handleMessage - Unrecognized self message");

    }

}

void GSSenderApp::readData()
{
    //Read coordinate data from local situation picture module
    cModule *targetModule = getParentModule() ->getSubmodule("localSituationPicture");
    LocalSituationPicture *position = check_and_cast <LocalSituationPicture *>(targetModule);
    state_current = position -> getStateWithCovarianceLsp();

    // log data to csv file
    logcoord->coord = state_current.pose.pose;
    logcoord->log();

}

void GSSenderApp::sendWirelessAppPacket()
{
     if(par("sendVideos")) {
         if(sentFrames < numFrames){
             Packet* packet = new inet::Packet("WirelessAppPacket");
             auto wirelessapppacket = makeShared<WirelessAppPacket>();
             wirelessapppacket ->setPayloadTimestamp(simTime());

              std::string imageToSend = stringImages->getRandomImage();
              wirelessapppacket ->setImage(imageToSend);
              wirelessapppacket->setChunkLength(B(imageToSend.size()));

              wirelessapppacket->addTag<CreationTimeTag>()->setCreationTime(simTime());
              packet->insertAtBack(wirelessapppacket);

              int packetSizeInBytes = packet->getBitLength()/8;
              double packetSizeInKBs = packetSizeInBytes/1024;

              emit(dataSentSignal, packetSizeInBytes);
              emit(dataSentSignalKbs, packetSizeInKBs);
              bytesSent = bytesSent + packetSizeInBytes;
              socket.sendTo(packet, destAddress_, destPort_);
              sentFrames++;
              int fps = par("fps");
              scheduleAt(simTime()+(1/fps), selfSender_);
         } else {
             numSent = numSent + sentFrames;
             sentFrames = 0;

             //scheduling the time for periodic message
             simtime_t d = simTime() + par("period") + par("videoLength");

             //send the msg
             if (stopTime_ <= SIMTIME_ZERO || d < stopTime_) {
             scheduleAt(d, selfSender_);
             } else {   //stop transmission (At the end of trajectory)
                 cout << getParentModule() << " " << stopTime_ << " GSSenderApp- WirelessAppPacket::sendPacket - Stop time reached, stopping transmissions" << endl;
             }
         }

     } else {
         // Create the packet
         Packet* packet = new inet::Packet("WirelessAppPacket");
         auto wirelessapppacket = makeShared<WirelessAppPacket>();
         wirelessapppacket ->setPayloadTimestamp(simTime());

         if(!(par("sendImages"))) {
             wirelessapppacket ->setAgentLocation(state_current);
             wirelessapppacket->setChunkLength(B(size_));
         } else if (par("sendImages")) {
             std::string imageToSend = stringImages->getRandomImage();
             wirelessapppacket ->setImage(imageToSend);
             wirelessapppacket->setChunkLength(B(imageToSend.size()));
         }
         wirelessapppacket->addTag<CreationTimeTag>()->setCreationTime(simTime());
         packet->insertAtBack(wirelessapppacket);
         int packetSizeInBytes = packet->getBitLength()/8;
         double packetSizeInKBs = packetSizeInBytes/1024;
         EV << "GSSenderApp- WirelessAppPacket::sendPacket - Sending message \n";

         emit(dataSentSignal, packetSizeInBytes);
         emit(dataSentSignalKbs, packetSizeInKBs);
         bytesSent = bytesSent + packetSizeInBytes;
         socket.sendTo(packet, destAddress_, destPort_);
         numSent++;

         //scheduling the time for periodic message
         simtime_t d = simTime() + par("period");

         //send the msg
        if (stopTime_ <= SIMTIME_ZERO || d < stopTime_) {
            scheduleAt(d, selfSender_);

        }
        //stop transmission (At the end of trajectory)
        else
            cout << getParentModule() << " " << stopTime_ << " GSSenderApp- WirelessAppPacket::sendPacket - Stop time reached, stopping transmissions" << endl;
     }
}

void GSSenderApp::finish()  {
        recordScalar("numSent", numSent);
        recordScalar("bytesSent", bytesSent);
        recordScalar("KbsSent", bytesSent/1024);
}
