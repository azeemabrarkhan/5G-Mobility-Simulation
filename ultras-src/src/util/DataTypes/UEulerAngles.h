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

#ifndef UTIL_DATATYPES_UEULERANGLES_H_
#define UTIL_DATATYPES_UEULERANGLES_H_

#include "inet/common/INETMath.h"
#include "inet/common/Units.h"
#include "inet/common/geometry/common/Coord.h"
//#include <util/DataTypes/UQuaternion.h>

using namespace inet;

/**
 * Euler angles class based on inet's EulerAngles class.
 */
class UEulerAngles {
public:
    double roll;    //!< roll in rad
    double pitch;   //!< pitch in rad
    double yaw;     //!< yaw in rad

private:
    void copy(const UEulerAngles& other) { roll = other.roll; pitch = other.pitch; yaw = other.yaw; }

public:
    UEulerAngles(): roll(0.0), pitch(0.0), yaw(0.0) {}

    UEulerAngles(double roll, double pitch, double yaw): roll(roll), pitch(pitch), yaw(yaw) {}

    UEulerAngles(Coord &coord): roll(coord.x), pitch(coord.y), yaw(coord.z) {}

    double getRoll() const { return roll; }
    void setRoll(double roll) { this->roll = roll; }

    double getPitch() const { return pitch; }
    void setPitch(double pitch) { this->pitch = pitch; }

    double getYaw() const { return yaw; }
    void setYaw(double yaw) { this->yaw = yaw; }

    UEulerAngles normalize()
    {
        roll = math::modulo(roll + M_PI, 2 * M_PI) - M_PI;
        pitch = math::modulo(pitch + M_PI, 2 * M_PI) - M_PI;
        yaw = math::modulo(yaw + M_PI, 2 * M_PI)- M_PI;
        return *this;
    }

    UEulerAngles operator+(const UEulerAngles a) const { return UEulerAngles(roll + a.roll, pitch + a.pitch, yaw + a.yaw); }

    UEulerAngles operator-(const UEulerAngles a) const { return UEulerAngles(roll - a.roll, pitch - a.pitch, yaw - a.yaw); }

    UEulerAngles operator*(float f) const { return UEulerAngles(roll * f, pitch * f, yaw * f); }
};


#endif /* UTIL_DATATYPES_UEULERANGLES_H_ */
