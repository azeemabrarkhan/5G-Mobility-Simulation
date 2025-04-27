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

#ifndef MODULES_CONTROL_ICONTROL_H_
#define MODULES_CONTROL_ICONTROL_H_

#include <omnetpp.h>
#include "util/DataTypes/StateDataTypes.h"
#include "util/DataTypes/ControlInput.h"

using namespace omnetpp;

/**
 * Interface implemented by control classes.
 */
class IControl {
public:
    double samplingTime;    //!< sampling time
    State state;            //!< state
    ControlInput *input;    //!< controller input
    ControlInput *output;   //!< controller output

    /** (*virtual method*)
     *
     * Calculate control signal.
     */
    virtual void update() = 0;
};

#endif /* MODULES_CONTROL_ICONTROL_H_ */
