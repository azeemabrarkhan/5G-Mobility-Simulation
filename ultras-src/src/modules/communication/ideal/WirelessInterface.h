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


/**
 * @file WirelessInterface.cc
 *
 * @brief Class for simple module Wireless Interface
 *
 *
 *
 * @author Shashini Wanniarachchi
 * Contact: shashini.wanniarachchi@tuhh.de
 *
 */

#ifndef MODULES_WIRELESSINTERFACE_H_
#define MODULES_WIRELESSINTERFACE_H_


#include <omnetpp.h>
#include<stdio.h>
#include<string.h>


#include "util/DataTypes/StateDataTypes.h"
#include "modules/vehicle/CommunicationCoordinator.h"
#include "messages/WirelessMsg_m.h"
#include "messages/SensorMsg_m.h"
#include "modules/vehicle/LocalSensorFusion.h"
#include "util/NeighborData.h"


using namespace omnetpp;
using namespace std;
using namespace inet;

class AgentInfo;

/**
 * Implementing ideal wireless communication module
 * inside an air taxi
 *
 */
class WirelessInterface : public cSimpleModule
{

protected :
    StateWithCovariance state_current;     ///<current vehicle state
    StateWithCovariance state_received;    ///<recieved vehicle state from neighbors
    NeighborData *neighborData;         ///<pointer to the NeighborData class

    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;


    /**Sending neighbor data information to
     * own local situation picture
     *
     */
    virtual void sendNeighborData();

private:
    double wirelessRange;                               ///< wireless range

    AgentInfo *ownVehicleInfo;                           ///<pointer to class nodeInfo
    list<AgentInfo *> allVehicleInfoList;                ///<list for all the air taxi information
    list<AgentInfo *> NeighbourVehicleInfoList;          ///<list for neighboring air taxi information


public:
    inet :: Coord ownCoord;                             ///<position coordinates of own air taxi
    inet :: Coord neighCoord;                           ///<position coordinates of neighboring air taxis


};



#endif /* MODULES_WIRELESSINTERFACE_H_ */
