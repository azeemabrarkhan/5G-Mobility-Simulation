/*
 * WirelessApp.cc
 *
 *  Created on: Feb 16, 2022
 *      Author: cif7992
 */

#include <inet/common/ModuleAccess.h>
#include <inet/common/TimeTag_m.h>

#include <modules/communication/NR/App/WirelessSenderApp.h>
#include "modules/communication/AgentInfo.h"


Define_Module(WirelessSenderApp);

using namespace inet;

WirelessSenderApp::WirelessSenderApp()
{
    selfSender_ = nullptr;
}

WirelessSenderApp::~WirelessSenderApp()
{
    cancelAndDelete(selfSender_);
}


void WirelessSenderApp::initialize(int stage)
{
    EV << "WirelessSenderApp::initialize - stage " << stage << endl;

    cSimpleModule::initialize(stage);

    // avoid multiple initializations
    if (stage!=inet::INITSTAGE_APPLICATION_LAYER)
        return;

    wirelessRange = par("wirelessRange");

    selfSender_ = new cMessage("selfSender");

    size_ = par("packetSize");
    localPort_ = par("localPort");
    destPort_ = par("destPort");
    destAddress_ = inet::L3AddressResolver().resolve(par("destAddress").stringValue());

    socket.setOutputGate(gate("socketOut"));
    socket.bind(localPort_);

    // for multicast support
    inet::IInterfaceTable *ift = inet::getModuleFromPar< inet::IInterfaceTable >(par("interfaceTableModule"), this);
    inet::MulticastGroupList mgl = ift->collectMulticastGroups();
    socket.joinLocalMulticastGroups(mgl);

    // if the multicastInterface parameter is not empty, set the interface explicitly
    const char *multicastInterface = par("multicastInterface");
    if (multicastInterface[0]) {
        InterfaceEntry *ie = ift->findInterfaceByName(multicastInterface);
        if (!ie)
            throw cRuntimeError("Wrong multicastInterface setting: no interface named \"%s\"", multicastInterface);
        socket.setMulticastOutputInterface(ie->getInterfaceId());
    }


    EV << "WirelessSenderApp::initialize - binding to port: local:" << localPort_ << " , dest:" << destPort_ << endl;

    //traffic starting time
    simtime_t startTime = par("startTime");
    stopTime_ = par("stopTime");

    //simtime_t offset = startTime + simTime();
    simtime_t offset = simTime() + 10 ;

    scheduleAt(offset ,selfSender_);
    EV << "\t starting traffic in " << offset << " seconds " << endl;

    std::string fileName = "../../../ReturnDirectory/Results/CoordinateOut/Coordinates_" + std :: string(simTime().str()) + "_" + std :: string(getParentModule()->str()) + ".csv";
    logcoord = new logCoord(getParentModule(), fileName);

    //module information of the own vehicle
    ownVehicleInfo = new AgentInfo();
    ownVehicleInfo -> vehicleModule = getParentModule();
    cModule *targetModule = getParentModule() ->getSubmodule("localSensorFusion");
    ownVehicleInfo -> vehicleMobilityModule = check_and_cast <LocalSensorFusion *>(targetModule);

    //module information of all vehicles
    for (int id =0; id <= getSimulation() -> getLastComponentId(); id++){
        cModule *targetModule = getSimulation() -> getModule(id);

        if (targetModule == NULL){
              continue;
        }

        if (targetModule == ownVehicleInfo->vehicleModule){
              continue;
        }

        //Mobility module
        cModule *targetMobilitymodule = NULL;


         for (cModule::SubmoduleIterator it(targetModule); !it.end(); ++it) {
              if (dynamic_cast<LocalSensorFusion*>(*it) != NULL) {
                  targetMobilitymodule = *it;
              }
         }

         //possible neighbors
          if (targetMobilitymodule != NULL){
                AgentInfo *nodeInform = new AgentInfo();
                nodeInform->vehicleModule = targetModule;
                nodeInform->vehicleMobilityModule = dynamic_cast<LocalSensorFusion*>(targetMobilitymodule);
                allVehicleInfoList.push_back(nodeInform);

          }
    }

}

void WirelessSenderApp::handleMessage(cMessage *msg)
{
    if (msg->isSelfMessage())
    {
        readAndLogData();
        //Neighbor list
         while (NeighbourVehicleInfoList.size()>0){
               list <AgentInfo*> :: iterator iteratorNeighbourVehicleInfo = NeighbourVehicleInfoList.begin();
               AgentInfo *nodeInform = *iteratorNeighbourVehicleInfo;
               NeighbourVehicleInfoList.remove(nodeInform);
         }

         //current position of the vehicle
         ownCoord = ownVehicleInfo -> vehicleMobilityModule->getStateAndCov().pose.pose;

         // Neighbor positions
         list <AgentInfo*> ::iterator iteratorAllVehicleInfo = allVehicleInfoList.begin();
         while (iteratorAllVehicleInfo != allVehicleInfoList.end()){
             AgentInfo *nodeInform =*iteratorAllVehicleInfo;
             neighCoord = nodeInform ->vehicleMobilityModule ->getStateAndCov().pose.pose;


              //eucledian distance calculation
              double l = ((neighCoord.x- ownCoord.x)*(neighCoord.x-ownCoord.x)) +
                         ((neighCoord.y- ownCoord.y)*(neighCoord.y-ownCoord.y)) +
                         ((neighCoord.z- ownCoord.z)*(neighCoord.z-ownCoord.z));


              double r = wirelessRange* wirelessRange;

              //Finding neighbors in the range
              if (l<=r) {
                  NeighbourVehicleInfoList.push_back(nodeInform);

              }
              iteratorAllVehicleInfo++;

         }

         //creating neighbourlistmsg
         if (NeighbourVehicleInfoList.size() > 0) {

          list<AgentInfo *>::iterator iteratorNeighbourInfo = NeighbourVehicleInfoList.begin();
          while (iteratorNeighbourInfo != NeighbourVehicleInfoList.end()) {
                AgentInfo *nodeInform = *iteratorNeighbourInfo;
                StateWithCovariance neigh_State = nodeInform ->vehicleMobilityModule->getStateAndCov();
                neighborData->neighborlist.push_back ({neigh_State});

                iteratorNeighbourInfo++;
          }

          sendNeighborData();
          neighborData->neighborlist.clear();
         }

        if (!strcmp(msg->getName(), "selfSender")){
            sendWirelessAppPacket();
        }
        else{
            throw cRuntimeError("TestSenderApp::handleMessage - Unrecognized self message");
        }
    }
}

void WirelessSenderApp::readAndLogData()
{
    cModule *targetModule = getParentModule() ->getSubmodule("localSituationPicture");
    LocalSituationPicture *position = check_and_cast <LocalSituationPicture *>(targetModule);
    state_current = position -> getStateWithCovarianceLsp();

    double *cov_po;
    double *cov_ve;
    for ( int i = 0; i < 36; i++ ) {
        state_current.pose.covariance[i] = cov_po[i];
    }
    for ( int i = 0; i < 36; i++ ) {
        state_current.velocity.covariance[i] = cov_ve[i];
    }

     //Logging coordinate data to csv
     logcoord->coord = state_current.pose.pose;
     logcoord->log();

}

void WirelessSenderApp::sendWirelessAppPacket()
{

     Packet* packet = new inet::Packet("WirelessAppPacket");

     auto wirelessapppacket = makeShared<WirelessAppPacket>();
     wirelessapppacket ->setPayloadTimestamp(simTime());
     wirelessapppacket ->setAgentLocation(state_current);
     EV<< "new" << state_current .pose.pose.x << "\n";
     wirelessapppacket->setChunkLength(B(size_));
     wirelessapppacket->addTag<CreationTimeTag>()->setCreationTime(simTime());

     packet->insertAtBack(wirelessapppacket);

     EV << "WirelessAppPacket::sendPacket - Sending message \n";

     socket.sendTo(packet, destAddress_, destPort_);

     simtime_t d = simTime() + par("period");


    if (stopTime_ <= SIMTIME_ZERO || d < stopTime_) {
        scheduleAt(d, selfSender_);
    }
    else{
        EV << "WirelessAppPacket::sendWirelessAppPacket - Stop time reached, stopping transmissions" << endl;
    }

}

void WirelessSenderApp::sendNeighborData()
{
        cMessage *neighborinfo = new cMessage("neighbourList");
        NeighborData *nD = new NeighborData(neighborData->neighborlist);
        nD->setName("neighbourList");
        neighborinfo->addObject(nD);
        sendDirect(neighborinfo, getParentModule() ->getSubmodule("localSituationPicture"), "radioIn");
}
