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

#ifndef UTIL_DATATYPES_TRAJECTORY_H_
#define UTIL_DATATYPES_TRAJECTORY_H_

#include <omnetpp.h>
#include "inet/common/geometry/common/Coord.h"

using namespace inet;

/**
 * Trajectory with times.
 */
class Trajectory: public cNamedObject {
public:
    std::vector<Coord> coords;  //!< coordinate points
    std::vector<double> times;  //!< times
    /**
     * Constructor.
     */
    Trajectory(){};
    /**
     * Constructor.
     * @param coords coordinate points
     * @param times times
     */
    Trajectory(std::vector<Coord> &coords, std::vector<double> &times): coords(coords), times(times){};
};

#endif /* UTIL_DATATYPES_TRAJECTORY_H_ */
