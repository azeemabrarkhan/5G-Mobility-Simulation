//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

#include <modules/communication/ideal/WirelessInterface.h>
#include "modules/communication/AgentInfo.h"

Define_Module(WirelessInterface);

void WirelessInterface::initialize()
{

    //parameters
    wirelessRange = par("wirelessRange");

    neighborData = new NeighborData();

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


void WirelessInterface :: handleMessage(cMessage *msg)
{

    //Defining the arrival gates
    cGate *gate;
    char gateName[64];
    gate = msg->getArrivalGate();
    strcpy(gateName, gate ->getName());

    if (strstr(gateName, "UpperLayerIn") != NULL) {

        //Retrieving sensor message received from communication coordinator
        SensorMsg *sensmsg = check_and_cast <SensorMsg *>(msg);
        state_current = sensmsg->getVehicleState();

        delete msg;

        //Generate wireless message
        WirelessMsg *wmsg = new WirelessMsg;
        wmsg->setVehicleLocation(state_current);

       //Send message to ground module
        cModule *groundmodule = getParentModule() -> getParentModule() ->getSubmodule("groundStation");
        sendDirect(wmsg, groundmodule, "radioIn");


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

      //creating messages
      if (NeighbourVehicleInfoList.size() > 0) {

          list<AgentInfo *>::iterator iteratorNeighbourInfo = NeighbourVehicleInfoList.begin();
          while (iteratorNeighbourInfo != NeighbourVehicleInfoList.end()) {
              AgentInfo *nodeInform = *iteratorNeighbourInfo;
              StateWithCovariance neigh_State = nodeInform ->vehicleMobilityModule->getStateAndCov();
              neighborData->neighborlist.push_back ({neigh_State});


              //sending own position data to other neighbor vehicles
              WirelessMsg *wmsg2 = new WirelessMsg;
              wmsg2->setVehicleLocation(state_current);

              cGate* g = nodeInform->vehicleModule->gate("radioIn");
              if(g->isConnectedInside()){
                  sendDirect(wmsg2, nodeInform->vehicleModule, "radioIn");
              }
              else {
                 delete wmsg2;
              }
              iteratorNeighbourInfo++;
          }

          // send neighbor position list message to own local situation picture
           sendNeighborData();
           neighborData->neighborlist.clear();



          }

    }

    else {

           // Retrieving wireless message received from the neighbor agents
            WirelessMsg *wmsg2 = check_and_cast <WirelessMsg *>(msg);
            state_received = wmsg2->getVehicleLocation();

            delete wmsg2;

            //Generate a sensor message to be sent to the communication coordinator using received wireless message
            SensorMsg *recievedmsg = new SensorMsg;
            recievedmsg->setVehicleState(state_received);

            send(recievedmsg, "UpperLayerOut");
  }

}


void WirelessInterface::sendNeighborData()
{
        cMessage *neighborinfo = new cMessage("neighbourList");
        NeighborData *nD = new NeighborData(neighborData->neighborlist);
        nD->setName("neighbourList");
        neighborinfo->addObject(nD);
        sendDirect(neighborinfo, getParentModule() ->getSubmodule("localSituationPicture"), "radioIn");
}






