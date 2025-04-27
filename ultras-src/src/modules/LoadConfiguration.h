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

#ifndef __ULTRAS_LOADCONFIGURATION_H_
#define __ULTRAS_LOADCONFIGURATION_H_

#include <omnetpp.h>
#include <string.h>
#include "util/configuration/ultras_dynamic_configuration.h"
#include "util/DataTypes/Trajectory.h"
#include "util/DataTypes/StateDataTypes.h"
#include "util/DataTypes/UGeoCoord.h"
#include "util/DataTypes/CoordGeoConversion.h"

using namespace omnetpp;
using namespace inet;


class LoadConfiguration : public cSimpleModule
{
protected:
    Configuration* config;
protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    CPACSTrajectory trajectoryFromMissionIDAndTrajectoryID(string missionID, string trajectoryID);
public:
    Configuration* getConfig();
    Trajectory getTrajectory(string missionID, string trajectoryID);
};

#endif
