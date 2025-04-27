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

#include "AgentMobility.h"
#include "inet/common/geometry/common/Quaternion.h"
#include "inet/common/geometry/common/EulerAngles.h"
#include "inet/common/geometry/common/Coord.h"
#include "inet/common/geometry/common/GeographicCoordinateSystem.h"



namespace inet {

Define_Module(AgentMobility);

AgentMobility::AgentMobility()
{
}

void AgentMobility::initialize(int stage)
{
    EV_TRACE << "initializing AgentMobility stage " << stage << endl;
    changeInterval = par("changeInterval");
    updateInterval = changeInterval;
    nextChange = changeInterval;
    MovingMobilityBase::initialize(stage);
    if (stage == INITSTAGE_LAST)
    {
        changeInterval = par("changeInterval");
        updateInterval = changeInterval;
        nextChange = changeInterval;
        std::string dynamicsModuleName = par("dynamicsModuleName");
        dynamicsModule = check_and_cast<VehicleDynamics *>(getParentModule()->getSubmodule(dynamicsModuleName.c_str()));
        updateState();
    }
}

void AgentMobility::move()
{
    simtime_t now = simTime();
    if (now >= nextChange && !stationary) {
        updateState();
        Coord dummyCoord;
        handleIfOutside(REFLECT, dummyCoord, lastVelocity);
        nextChange = now + changeInterval;
    }
}

void AgentMobility::updateState()
{
    if(dynamicsModule != nullptr){
        State state = dynamicsModule->getState();
        lastPosition = state.pose.pose;
        UEulerAngles attitude = state.pose.attitude.toEulerAngles(false);
        lastOrientation = Quaternion(EulerAngles(rad(attitude.yaw), rad(attitude.pitch), rad(attitude.roll)));
        //        lastVelocity = state.velocity.linear;
        //        lastAngularVelocity = Quaternion(EulerAngles((rad)state.velocity.angular.z, (rad)state.velocity.angular.y,(rad)state.velocity.angular.x));
    }
}

void AgentMobility::setStationary(bool stationaryState){
    Enter_Method("setStationary(bool stationaryState)");
    stationary = stationaryState;
}

bool AgentMobility::getStationary(){
    Enter_Method("getStationary()");
    return stationary;
}

} // namespace inet


