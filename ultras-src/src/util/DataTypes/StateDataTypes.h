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

#ifndef UTIL_STATEDATATYPES_H_
#define UTIL_STATEDATATYPES_H_

#include <omnetpp.h>
#include "inet/common/geometry/common/Coord.h"
#include <util/DataTypes/UQuaternion.h>

using namespace omnetpp;
using namespace inet;

/**
 * Pose
 */
struct Pose{
    simtime_t stamp = -1;   //!< time stamp
    Coord pose;             //!< pose
    UQuaternion attitude;   //!< attitude
};
/**
 * Pose with covariance
 */
struct PoseWithCovariance{
    simtime_t stamp = -1;   //!< time stamp
    Coord pose;             //!< pose
    UQuaternion attitude;   //!< attitude
    double covariance[36];  //!< covariance
};
/**
 * Velocity
 */
struct Velocity{
    simtime_t stamp = -1;   //!< time stamp
    Coord linear;           //!< linear velocity
    Coord angular;          //!< angular velocity
};
/**
 * Velocity with covariance
 */
struct VelocityWithCovariance{
    simtime_t stamp = -1;   //!< time stamp
    Coord linear;           //!< linear velocity
    Coord angular;          //!< angular velocity
    double covariance[36];  //!< covariance
};
/**
 * State
 */
struct State{
    Pose pose;              //!< pose
    Velocity velocity;      //!< velocity
};
/**
 * State with covariance
 */
struct StateWithCovariance{
    PoseWithCovariance pose;            //!< pose with covariance
    VelocityWithCovariance velocity;    //!< velocity with covariance
};

#endif /* UTIL_STATEDATATYPES_H_ */
