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

#ifndef UTIL_DATATYPES_UROTATIONMATRIX_H_
#define UTIL_DATATYPES_UROTATIONMATRIX_H_

#include "inet/common/geometry/common/Coord.h"
#include <util/DataTypes/UEulerAngles.h>
#include <util/DataTypes/UQuaternion.h>

using namespace inet;

/**
 * Rotation matrix class based on inet's RotationMatrix class.
 */
class URotationMatrix {
public:
    double matrix[3][3]; //!< 3x3 rotation matrix

protected:
    void computeRotationMatrix(const double& q0, const double& q1, const double& q2, const double& q3);
    double computeDeterminant() const;

public:
    URotationMatrix();
    URotationMatrix(const double matrix[3][3]);
    URotationMatrix(const UEulerAngles& eulerAngles);

    Coord rotateVector(const Coord& vector) const;
    Coord rotateVectorInverse(const Coord& vector) const;

    UEulerAngles toEulerAngles() const;
    UQuaternion toQuaternion() const;
};

#endif /* UTIL_DATATYPES_UROTATIONMATRIX_H_ */
