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

#ifndef UTIL_DATATYPES_UGEOCOORD_H_
#define UTIL_DATATYPES_UGEOCOORD_H_

#include "inet/common/INETMath.h"
#include "inet/common/geometry/common/Coord.h"

using namespace inet;

/**
 * Geographic coordinate class based on inet's GeoCoord class.
 */
class UGeoCoord {
public:
    double latitude;    //!< latitude
    double longitude;   //!< longitude
    double altitude;    //!< altitude

public:
    UGeoCoord() : latitude(0.0), longitude(0.0), altitude(0.0) {}
    UGeoCoord(double latitude, double longitude, double altitude) : latitude(latitude), longitude(longitude), altitude(altitude) {}
    UGeoCoord operator+(const UGeoCoord a) const { return UGeoCoord(latitude + a.latitude, longitude + a.longitude, altitude + a.altitude); }
    UGeoCoord operator-(const UGeoCoord a) const { return UGeoCoord(latitude - a.latitude, longitude - a.longitude, altitude - a.altitude); }
};

#endif /* UTIL_DATATYPES_UGEOCOORD_H_ */
