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

#include <util/DataTypes/UQuaternion.h>

using namespace inet;

UQuaternion UQuaternion::IDENTITY = UQuaternion();
UQuaternion UQuaternion::NIL = UQuaternion(NaN, NaN, NaN, NaN);

UQuaternion::UQuaternion(const Coord &axis, double angle) : UQuaternion(std::cos(angle/2), axis*std::sin(angle/2))
{
    // nothing
}

UQuaternion::UQuaternion(const UEulerAngles& angles)
{
    double cos_z_2 = std::cos(0.5 * angles.yaw);
    double cos_y_2 = std::cos(0.5 * angles.pitch);
    double cos_x_2 = std::cos(0.5 * angles.roll);

    double sin_z_2 = std::sin(0.5 * angles.yaw);
    double sin_y_2 = std::sin(0.5 * angles.pitch);
    double sin_x_2 = std::sin(0.5 * angles.roll);

    // and now compute UQuaternion
    s   = cos_z_2*cos_y_2*cos_x_2 + sin_z_2*sin_y_2*sin_x_2;
    v.x = cos_z_2*cos_y_2*sin_x_2 - sin_z_2*sin_y_2*cos_x_2;
    v.y = cos_z_2*sin_y_2*cos_x_2 + sin_z_2*cos_y_2*sin_x_2;
    v.z = sin_z_2*cos_y_2*cos_x_2 - cos_z_2*sin_y_2*sin_x_2;
}

const UQuaternion UQuaternion::operator *(const UQuaternion &q) const
{
    return UQuaternion(s*q.s - v*q.v,
              v.y*q.v.z - v.z*q.v.y + s*q.v.x + v.x*q.s,
              v.z*q.v.x - v.x*q.v.z + s*q.v.y + v.y*q.s,
              v.x*q.v.y - v.y*q.v.x + s*q.v.z + v.z*q.s);
}

const UQuaternion& UQuaternion::operator *=(const UQuaternion &q)
{
    double x = v.x, y = v.y, z = v.z, sn = s*q.s - v*q.v;

    v.x = y*q.v.z - z*q.v.y + s*q.v.x + x*q.s;
    v.y = z*q.v.x - x*q.v.z + s*q.v.y + y*q.s;
    v.z = x*q.v.y - y*q.v.x + s*q.v.z + z*q.s;

    s = sn;

    return *this;
}

UQuaternion UQuaternion::slerp(const UQuaternion &q1, const UQuaternion &q2, double t)
{
    UQuaternion q3;
    double dot = UQuaternion::dot(q1, q2);

    /*  dot = cos(theta)
        if (dot < 0), q1 and q2 are more than 90 degrees apart,
        so we can invert one to reduce spinning */
    if (dot < 0) {
        dot = -dot;
        q3 = -q2;
    }
    else q3 = q2;

    if (dot < 0.95) {
        double angle = std::acos(dot);
        return (q1*std::sin(angle*(1-t)) + q3*std::sin(angle*t))/std::sin(angle);
    }
    else // if the angle is small, use linear interpolation
        return lerp(q1, q3, t);
}

void UQuaternion::getRotationAxisAndAngle(Coord &axis, double &angle) const
{
    angle = std::acos(s);

    // pre-compute to save time
    double sin_theta_inv = 1.0 / std::sin(angle);

    // now the vector
    axis.x = v.x * sin_theta_inv;
    axis.y = v.y * sin_theta_inv;
    axis.z = v.z * sin_theta_inv;

    angle *= 2;
}

Coord UQuaternion::rotate(const Coord &v) const
{
    UQuaternion V(0, v);
    UQuaternion conjugate(*this);
    conjugate.conjugate();
    return (*this * V * conjugate).v;
}

UEulerAngles UQuaternion::toEulerAngles(bool homogenous) const
{
    // NOTE: this algorithm is prone to gimbal lock when pitch is close to +-90
    double sqw = s*s;
    double sqx = v.x*v.x;
    double sqy = v.y*v.y;
    double sqz = v.z*v.z;

    UEulerAngles euler;
    if (homogenous) {
        euler.roll = std::atan2(2.0 * (v.x*v.y + v.z*s), sqx - sqy - sqz + sqw);
        euler.pitch = std::asin(std::min(1.0, std::max(-1.0, -2.0 * (v.x*v.z - v.y*s))));
        euler.yaw = std::atan2(2.0 * (v.y*v.z + v.x*s), -sqx - sqy + sqz + sqw);
    }
    else {
        euler.roll = std::atan2(2.0 * (v.z*v.y + v.x*s), 1 - 2*(sqx + sqy));
        euler.pitch = std::asin(std::min(1.0, std::max(-1.0, -2.0 * (v.x*v.z - v.y*s))));
        euler.yaw = std::atan2(2.0 * (v.x*v.y + v.z*s), 1 - 2*(sqy + sqz));
    }
    euler.normalize();
    return euler;
}

UQuaternion UQuaternion::rotationFromTo(const Coord& from, const Coord& to)
{
    // Based on Stan Melax's article in Game Programming Gems
    // Copy, since cannot modify local
    Coord v0 = from;
    Coord v1 = to;
    v0.normalize();
    v1.normalize();

    double d = v0 * v1;

    if (d >= 1.0f) { // If dot == 1, vectors are the same
        return UQuaternion(1, 0, 0, 0); // identity
    }
    else if (d <= -1.0f) { // exactly opposite
        Coord axis = Coord(1, 0, 0) % v0;

        if (axis.length() == 0)
            axis = Coord(0, 1, 0) % v0;

        // same as fromAxisAngle(axis, PI).normalize();
        return UQuaternion(0, axis.x, axis.y, axis.z).normalized();
    }

    double s = std::sqrt((1 + d) * 2);

    Coord c = (v0 % v1) / s;

    return UQuaternion(s * 0.5, c.x, c.y, c.z).normalized();
}

void UQuaternion::getSwingAndTwist(const Coord& direction, UQuaternion& swing, UQuaternion& twist) const
{
    Coord p = direction * (v * direction); // return projection v1 on to v2  (parallel component)
    twist = UQuaternion(s, p);
    twist.normalize();
    swing = *this * twist.conjugated();
}
