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

#include "VehicleDynamics.h"

Define_Module(VehicleDynamics);

/**
 * Select dynamics and set sampling time based on provided parameters.
 */
void VehicleDynamics::initialize()
{
    // get parameters
    selectDynamics = par("selectDynamics");
    samplingTime = par("samplingTime");

    //set initial state
    switch(selectDynamics){
    case 0: // no dynamics
        noDynamics = new Dynamics_NoDynamics();
        noDynamics->initialize(state, samplingTime);
        //    case 1: // double integrator
        //        doubleIntegrator.initialize(state, samplingTime);
    }
}

void VehicleDynamics::handleMessage(cMessage *msg)
{
    input = check_and_cast<ControlInput *>(msg->getObject("inputSignal"));
    //update state
    switch(selectDynamics){
    case 0: // no dynamics
        noDynamics->updateState(*input);
        state = noDynamics->state;
    }
    cancelAndDelete(msg);
    EV << getParentModule() << " " << simTime() << " logState  "
            << state.pose.pose.x <<" " << state.pose.pose.y <<" " << state.pose.pose.z <<" "
            << state.pose.attitude.s <<" " << state.pose.attitude.v.x <<" " << state.pose.attitude.v.y <<" " << state.pose.attitude.v.z<<" "
            << state.velocity.linear.x <<" " << state.velocity.linear.y <<" " << state.velocity.linear.z <<" "
            << state.velocity.angular.x <<" " << state.velocity.angular.y <<" " << state.velocity.angular.z <<"\n";
}


State VehicleDynamics::getState()
{
    Enter_Method("getState()");
    return state;
}

void VehicleDynamics::initializeState(State state)
{
    Enter_Method("initializeState(State state)");
    this->state = state;
}
