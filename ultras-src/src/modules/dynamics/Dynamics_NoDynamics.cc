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

#include <modules/dynamics/Dynamics_NoDynamics.h>

/**
 * Set position from control input and calculate velocity based on sampling time
 * @param in desired position and orientation (x, y, z, roll, pitch, yaw)
 */
void Dynamics_NoDynamics::updateState(ControlInput &in)
{
    //create temporary state variable
    State _state;
    Coord linearInput = Coord(in.data[0], in.data[1], in.data[2]);
    Coord angularInput = Coord(in.data[3], in.data[4], in.data[5]);

    //convert state attidude to rad
    UEulerAngles attitude = state.pose.attitude.toEulerAngles(false);

    //set state stamp
    _state.pose.stamp = simTime();
    _state.velocity.stamp = _state.pose.stamp;

    //calculate state update
    _state.pose.pose = linearInput;
    _state.velocity.linear =(linearInput.operator -=(state.pose.pose)).operator /=(samplingTime);
    _state.pose.attitude = UQuaternion(angularInput);
    _state.velocity.angular = (angularInput.operator -=(Coord(attitude.roll, attitude.pitch, attitude.yaw))).operator /=(samplingTime);

    //update state
    state = _state;
}
