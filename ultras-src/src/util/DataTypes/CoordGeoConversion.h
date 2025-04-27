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

#ifndef UTIL_DATATYPES_COORDGEOCONVERSION_H_
#define UTIL_DATATYPES_COORDGEOCONVERSION_H_

#include <util/DataTypes/UGeoCoord.h>
#include "inet/common/geometry/common/Coord.h"
#include "inet/common/INETMath.h"

using namespace inet;


static const double EARTH_RADIUS = 6364341; //!< earth radius at ORIGIN (https://rechneronline.de/earth-radius/)
// origin of scene; has to match coordinates in hamburg.earth
static const double LATITUDE_ORIGIN = 53.551086; //!< latitude of origin (Hamburg)
static const double LONGITUDE_ORIGIN = 9.993682; //!< longitude of origin (Hamburg)
static const double ALTITUDE_ORIGIN = 0.0; //!< altitude of origin (Hamburg) is assumed to be 0

/**
 * Covert geographic to Cartesian coordinates.
 * @param &geo geographic coordinate
 * @return Cartesian coordinate
 */
inline Coord GeoToCoord(UGeoCoord &geo){
    double x = (geo.longitude-LONGITUDE_ORIGIN) * cos(LATITUDE_ORIGIN*M_PI/180.0)*EARTH_RADIUS*M_PI/180.0;
    double y = (geo.latitude-LATITUDE_ORIGIN) * EARTH_RADIUS *M_PI/180.0;
    double z = geo.altitude + ALTITUDE_ORIGIN;
    return Coord(x, y, z);
}

/**
 * Covert Cartesian to geographic coordinates.
 * @param &coord Cartesian coordinate
 * @return geographic coordinate
 */
inline UGeoCoord CoordToGeo(Coord &coord){
    UGeoCoord geo = UGeoCoord();
    geo.latitude = coord.y / EARTH_RADIUS *180.0/M_PI + LATITUDE_ORIGIN;
    geo.longitude = coord.x / cos(LATITUDE_ORIGIN*M_PI/180.0) / EARTH_RADIUS * 180.0/M_PI + LONGITUDE_ORIGIN;
    geo.altitude = coord.z - ALTITUDE_ORIGIN;
    return geo;
}

#endif /* UTIL_DATATYPES_COORDGEOCONVERSION_H_ */
