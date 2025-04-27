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

#ifndef MODULES_DYNAMICS_IDYNAMICS_H_
#define MODULES_DYNAMICS_IDYNAMICS_H_

#include <omnetpp.h>
#include "util/DataTypes/StateDataTypes.h"
#include "util/DataTypes/ControlInput.h"

using namespace omnetpp;

/**
 * Interface implemented by dynamics classes.
 */
class IDynamics {
public:
    State state;            //!< current vehicle state
    double samplingTime;    //!< sampling time

    /** (*virtual method*)
     *
     * Initialize state and sampling time.
     * @param state state
     * @param samplingTime sampling time
     */
    virtual void initialize(State state, double samplingTime){this->state = state; this->samplingTime = samplingTime;};

    /** (*virtual method*)
     *
     * Update the state based on given input signal.
     * @param in control input
     */
    virtual void updateState(ControlInput &in) = 0;
};

#endif /* MODULES_DYNAMICS_IDYNAMICS_H_ */
