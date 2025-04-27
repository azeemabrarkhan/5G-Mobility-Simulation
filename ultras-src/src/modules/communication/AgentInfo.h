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
 * @file NodeInfo.cc
 *
 * @brief Class for node information of air taxis
 *
 *
 *
 * @author Shashini Wanniarachchi
 * Contact: shashini.wanniarachchi@tuhh.de
 *
 */

#ifndef MODULES_NODEINFO_H_
#define MODULES_NODEINFO_H_

#include "modules/vehicle/LocalSensorFusion.h"

#include <omnetpp.h>
#include <cstdlib>
#include <string>

using namespace omnetpp;
using namespace inet;

/**
 * Class for agent information
 *
 *
 */
class AgentInfo {

public:

        /** mobility related info
         *
         */

        cModule *vehicleModule;                         ///<Agent (Air taxi)
        LocalSensorFusion *vehicleMobilityModule;       ///<Mobility module of air taxi



};



#endif /* MODULES_NODEINFO_H_ */
