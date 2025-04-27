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

#ifndef MODULES_CONTROL_CONTROL_POSITIONATTITUDE_NODYNAMICS_H_
#define MODULES_CONTROL_CONTROL_POSITIONATTITUDE_NODYNAMICS_H_

#include <omnetpp.h>
#include "modules/control/IControl.h"
#include "util/DataTypes/StateDataTypes.h"
#include "util/DataTypes/Trajectory.h"
#include "inet/common/geometry/common/Coord.h"
#include <cmath>

using namespace omnetpp;

/**
 * Controller for direct feedthrough dynamics model.
 */
class Control_PositionAttitude_NoDynamics: public IControl {

protected:
    int trajectoryIndex; //!< current trajectory index

public:
    Control_PositionAttitude_NoDynamics();
    Trajectory *trajectory; //!< reference trajectory
    void update() override;
};

#endif /* MODULES_CONTROL_CONTROL_POSITIONATTITUDE_NODYNAMICS_H_ */
