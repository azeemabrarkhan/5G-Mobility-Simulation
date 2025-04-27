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

#ifndef __ULTRAS_VEHICLEDYNAMICS_H_
#define __ULTRAS_VEHICLEDYNAMICS_H_

#include <omnetpp.h>
#include "util/DataTypes/ControlInput.h"
#include "Dynamics_NoDynamics.h"
#include "util/DataTypes/StateDataTypes.h"

using namespace omnetpp;
using namespace inet;
class VehicleDynamics : public cSimpleModule
{
protected:
    State state;            //!< current vehicle state
    ControlInput *input;    //!< input signal
    int selectDynamics;     //!< variable for selecting vehicle dynamics
    double samplingTime;    //!< sampling time in seconds

    // Available Dynamics
    //case 0: no dynamics
    //case 1: double integrator
    Dynamics_NoDynamics *noDynamics;                //!< no dynamics vehicle dynamics

    virtual void initialize();
    virtual void handleMessage(cMessage *msg);

public:
    /** (*Direct access method*)
     *
     * Return current state.
     * @return current state
     */
    State getState();

    /** (*Direct access method*)
     *
     * Initialize state from outside.
     * @param state Initial state
     */
    void initializeState(State state);
};

#endif
