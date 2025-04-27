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

#ifndef UTIL_LOGGING_DATATYPES_LOGCOORD_H_
#define UTIL_LOGGING_DATATYPES_LOGCOORD_H_

#include "util/logging/ILogging.h"
#include "inet/common/geometry/common/Coord.h"

/**
 * Class for looging coordinates.
 */
class logCoord: public ILogging{
public:
    Coord coord; //!< coordinate to log
    logCoord(cModule *moduleName, std::string fileName):ILogging(moduleName, fileName){};

    virtual std::string logString() override{
        std::ostringstream strng;
        strng << coord.x << delimiter << coord.y << delimiter <<coord.z;
        std::string logString = strng.str();
        return logString;
    }

};

#endif /* UTIL_LOGGING_DATATYPES_LOGCOORD_H_ */
