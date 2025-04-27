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

#ifndef __ULTRAS_GNC_H_
#define __ULTRAS_GNC_H_

#include <omnetpp.h>
#include "util/DataTypes/ControlInput.h"
#include "util/NeighborData.h"

#include "util/DataTypes/Trajectory.h"
#include "modules/vehicle/LocalSituationPicture.h"

#include "modules/dynamics/Dynamics_NoDynamics.h"

#include "modules/control/Control_PositionAttitude_NoDynamics.h"

using namespace omnetpp;
//using namespace std;

class GNC : public cSimpleModule
{
protected:
    // NED parameters
    int selectDynamics;             //!< dynamics selector
    int selectPositionController;   //!< position controller selector

    // controller sampling times
    double attitudeSamplingTime;        //!< attitude controller sampling time
    double pathFollowingSamplingTime;   //!< path following controller sampling time
    double pathManagementSamplingTime;  //!< path manager controller sampling time

    // dynamics
    Dynamics_NoDynamics * NoDynamics;   //!< kinematic integrator dynamcis

    //controllers
    Control_PositionAttitude_NoDynamics *NoDynamicsController; //!< controller for kinematic integrator dynamics
    cMessage *timer_PosAtt;

    // reference trajectory
    Trajectory referenceTrajectory;     //!< reference trajectory
    bool hasChangedReference = false;   //!< for detection if reference has changed

    ControlInput *controlInput;                 //!< control input
    LocalSituationPicture* situationPicture;    //!< Local Situation Picture module
    NeighborData neighborData;                  //!< neighbor data

    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    void sendControlSignal();
public:
    void setReferenceTrajectory(Trajectory &referenceTrajectory);
};

#endif
