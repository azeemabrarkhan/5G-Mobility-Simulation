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

#ifndef UTIL_DATATYPES_UQuaternion_H_
#define UTIL_DATATYPES_UQuaternion_H_

#include "util/DataTypes/UEulerAngles.h"
#include "inet/common/geometry/common/Coord.h"

using namespace inet;

/**
 * Quaternion class based on inet's Quaternion class.
 */
class UQuaternion {
public:
    static UQuaternion IDENTITY; //!< identitiy quaternion
    static UQuaternion NIL;     //!< zero quaternion

  public:
    double s = 1;   //!< real component
    Coord v;        //!< imaginary components

    // basic constructors
    UQuaternion() {}
    UQuaternion(double real, double i, double j, double k): s(real), v(i, j, k) { }
    UQuaternion(double real, const Coord &imag): s(real), v(imag) { }

    // constructs a UQuaternion from a normalized axis - angle pair rotation
    UQuaternion(const Coord &axis, double angle);

    // from 3 euler angles
    explicit UQuaternion(const UEulerAngles& angles);

    double getS() const { return s; }
    void setS(double s) { this->s = s; }

    const Coord& getV() const { return v; }
    void setV(const Coord& v) { this->v = v; }

    // basic operations
    bool operator==(const UQuaternion& q) { return s == q.s && v == q.v; }
    bool operator!=(const UQuaternion& q) { return !(*this == q); }

    UQuaternion &operator =(const UQuaternion &q) { s = q.s; v = q.v; return *this; }

    const UQuaternion operator +(const UQuaternion &q) const { return UQuaternion(s+q.s, v+q.v); }
    const UQuaternion operator -(const UQuaternion &q) const { return UQuaternion(s-q.s, v-q.v); }
    const UQuaternion operator *(const UQuaternion &q) const;
    const UQuaternion operator /(const UQuaternion &q) const { return (*this) * q.inverse(); }

    const UQuaternion operator *(double scale) const { return UQuaternion(s * scale,v * scale); }
    const UQuaternion operator /(double scale) const { return UQuaternion(s / scale, v / scale); }

    const UQuaternion operator -() const { return UQuaternion(-s, -v); }

    const UQuaternion &operator +=(const UQuaternion &q) { v += q.v; s += q.s; return *this; }
    const UQuaternion &operator -=(const UQuaternion &q) { v -= q.v; s -= q.s; return *this; }
    const UQuaternion &operator *=(const UQuaternion &q);

    const UQuaternion &operator *= (double scale) { s *= scale; v *= scale; return *this; }
    const UQuaternion &operator /= (double scale) { s /= scale; v /= scale; return *this; }


    //! gets the length of this UQuaternion
    double length() const { return std::sqrt(s*s + v*v); }

    //! gets the squared length of this UQuaternion
    double lengthSquared() const { return (s*s + v*v); }

    //! normalizes this UQuaternion
    void normalize() { *this /= length(); }

    //! returns the normalized version of this UQuaternion
    UQuaternion normalized() const { return (*this) / length(); }

    //! computes the conjugate of this UQuaternion
    void conjugate() { v = -v; }

    UQuaternion conjugated() const { return UQuaternion(s, -v.x, -v.y, -v.z); }

    //! inverts this UQuaternion
    void invert() { conjugate(); *this /= lengthSquared(); }

    //! returns the inverse of this UQuaternion
    UQuaternion inverse() const { UQuaternion q(*this); q.invert(); return q; }

    //! computes the dot product of 2 UQuaternions
    static inline double dot(const UQuaternion &q1, const UQuaternion &q2) { return q1.v*q2.v + q1.s*q2.s; }

    //! linear UQuaternion interpolation
    static UQuaternion lerp(const UQuaternion &q1, const UQuaternion &q2, double t) { return (q1*(1-t) + q2*t).normalized(); }

    //! spherical linear interpolation
    static UQuaternion slerp(const UQuaternion &q1, const UQuaternion &q2, double t);

    //! returns the axis and angle of this unit UQuaternion
    Coord getRotationAxis() const { Coord axis; double angle; getRotationAxisAndAngle(axis, angle); return axis; }
    double getRotationAngle() const { return std::acos(s) * 2; }
    void getRotationAxisAndAngle(Coord &axis, double &angle) const;

    //! rotates v by this UQuaternion (UQuaternion must be unit)
    Coord rotate(const Coord &v) const;

    //! returns the euler angles from a rotation UQuaternion
    UEulerAngles toEulerAngles(bool homogenous=false) const;

    // adapted from https://svn.code.sf.net/p/irrlicht/code/trunk/include/UQuaternion.h
    static UQuaternion rotationFromTo(const Coord& from, const Coord& to);

    /**
       Decompose the rotation on to 2 parts.
       1. Twist - rotation around the "direction" vector
       2. Swing - rotation around axis that is perpendicular to "direction" vector
       The rotation can be composed back by rotation = swing * twist

       has singularity in case of swing_rotation close to 180 degrees rotation.
       if the input UQuaternion is of non-unit length, the outputs are non-unit as well
       otherwise, outputs are both unit
    */
    void getSwingAndTwist(const Coord& direction, UQuaternion& swing, UQuaternion& twist) const;
};


#endif /* UTIL_DATATYPES_UQuaternion_H_ */
