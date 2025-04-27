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

#include <modules/control/Control_PositionAttitude_NoDynamics.h>

/**
 * Initialize and set output size.
 */
Control_PositionAttitude_NoDynamics::Control_PositionAttitude_NoDynamics() {

    output = new ControlInput();
    trajectory = new Trajectory();
    trajectoryIndex = 0;
    samplingTime = 1;
    // set input and output vector size
    // no input
    output->data = std::vector<double>(6,0.0);
}

/**
 * Calculate control signal by interpolating reference trajectory points.
 */
void Control_PositionAttitude_NoDynamics::update() {

    double time = simTime().dbl();

    // set target position and attitude
    Coord targetPosition;
    UEulerAngles targetAttitude;
    if (trajectory->times[0]>time){
        // do nothing if mission didn't start yet
        targetPosition = trajectory->coords[0];
        targetAttitude = UEulerAngles(0,0,0);
    } else if (trajectory->times.back() <= time){
        // set agent idle after mission is finished
        targetPosition = trajectory->coords.back();
        targetAttitude = UEulerAngles(0,0,0);
    } else {
        if ((time >= trajectory->times[trajectoryIndex]) && (trajectoryIndex +1 < trajectory->times.size())){
            trajectoryIndex++;
        }
        Coord coord = trajectory->coords[trajectoryIndex];
        Coord coord_prev = trajectory->coords[trajectoryIndex-1];
        Coord deltaCoord = coord.operator -=(coord_prev);
        double deltaTime = trajectory->times[trajectoryIndex] -(trajectory->times[trajectoryIndex-1]);
        // Attitude
        // in flight: point towards next point; ascend and descend: point north
        if (abs(deltaCoord.x)<0.1 && abs(deltaCoord.y)<0.1){
            targetAttitude = UEulerAngles(0,0,0);
        } else {
            Coord coord_final = trajectory->coords.back();
            Coord deltaFinal = coord_final.operator -=(trajectory->coords[trajectoryIndex]);
            targetAttitude = UEulerAngles(0,0,atan2(deltaFinal.y,deltaFinal.x));
        }
        // Position
        // linear interpolation for position
        targetPosition = coord_prev.operator+=(deltaCoord.operator/=(deltaTime).operator*=(time-trajectory->times[trajectoryIndex-1]));
    }

    // update output signal
    double data[] = {targetPosition.x, targetPosition.y, targetPosition.z, targetAttitude.roll, targetAttitude.pitch, targetAttitude.yaw};
    output->data.assign(data,data+6);
}
