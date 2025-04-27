/*
 * GSReceiverApp.cc
 *
 *  Created on: Mar 25, 2022
 *      Author: cif7992
 */


#include "GSReceiverApp.h"


Define_Module(GSReceiverApp);
using namespace inet;

void GSReceiverApp::initialize(int stage)
{
    latencySingal = registerSignal("latencySingal");
    dataReceivedSignal = registerSignal("dataReceivedSignal");
    dataReceivedSignalKbs = registerSignal("dataReceivedSignalKbs");
    latency = 0;
    bytesReceived = 0;
    numReceived = 0;
    cSimpleModule::initialize(stage);

    if (stage != inet::INITSTAGE_APPLICATION_LAYER)
        return;

    int port = par("localPort");
    EV << "GSReceiverApp::initialize - binding to port: local:" << port << endl;
    if (port != -1)
    {
        socket.setOutputGate(gate("socketOut"));
        socket.bind(port);
    }

    deliveryDelay_ = registerSignal("deliveryDelay");

}

void GSReceiverApp::handleMessage(cMessage *msg)
{
    if (msg->isSelfMessage())
        return;

    Packet* pPacket = check_and_cast<Packet*>(msg);

    int packetSizeInBytes = pPacket->getBitLength()/8;
    double packetSizeInKBs = packetSizeInBytes/1024;

    EV << "Sender Module Name: " << pPacket->getSenderModule()->getFullName() << packetSizeInBytes << endl;
    EV << "Receiving Module Name: " << pPacket->getArrivalModule()->getFullName() << dataReceivedSignalKbs<< endl;

    emit(dataReceivedSignal, packetSizeInBytes);
    emit(dataReceivedSignalKbs, packetSizeInKBs);

    bytesReceived = bytesReceived + packetSizeInBytes;

    // read msg
    auto wirelessapppacket = pPacket->popAtFront<WirelessAppPacket>();

    // emit statistics
    numReceived = numReceived + 1;
    double currentLatency = simTime().dbl() - pPacket->getCreationTime().dbl();
    latency = (latency*(numReceived-1) + currentLatency)/numReceived;
    emit(latencySingal, currentLatency);

    simtime_t delay = simTime() - wirelessapppacket->getPayloadTimestamp();
    emit(deliveryDelay_, delay);

    delete msg;
}

void GSReceiverApp::finish()  {
        recordScalar("numReceived", numReceived);
        recordScalar("latencyInSeconds", latency);
        recordScalar("latencyInMicroseconds", latency*1000);
        recordScalar("bytesReceived", bytesReceived);
        recordScalar("KbsReceived", bytesReceived/1024);
}


