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
 * @file CommunicationCoordinator.cc
 *
 * @brief Class for simple module Communication Coordinator
 *
 *
 *
 * @author Shashini Wanniarachchi
 * Contact: shashini.wanniarachchi@tuhh.de
 *
 */
#ifndef MODULES_VEHICLE_COMMUNICATIONCOORDINATOR_H_
#define MODULES_VEHICLE_COMMUNICATIONCOORDINATOR_H_

#include <omnetpp.h>
#include<stdio.h>
#include<string.h>

#include "util/DataTypes/StateDataTypes.h"
#include "LocalSituationPicture.h"
#include "modules/dynamics/VehicleDynamics.h"
#include "messages/SensorMsg_m.h"

#include "util/logging/dataTypes/logCoord.h"

using namespace omnetpp;
using namespace std;
using namespace inet;

/**
 * A simple module for coordinating wireless
 * communication and sensor modules
 *
 */
class CommunicationCoordinator : public cSimpleModule
{

protected :
    StateWithCovariance state_cc;    ///<current vehicle state
    logCoord * logcoord;             ///<pointer to logging class

    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    virtual void finish() override;

private :
    cMessage *event;                ///< self message



};



#endif /* MODULES_VEHICLE_COMMUNICATIONCOORDINATOR_H_ */

