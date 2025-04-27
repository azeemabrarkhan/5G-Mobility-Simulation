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

#ifndef UTIL_LOGGING_DATATYPES_LOGID_H_
#define UTIL_LOGGING_DATATYPES_LOGID_H_

#include "util/logging/ILogging.h"

/**
 * Class for looging mission and trajectory IDs.
 */
class logID: public ILogging{
public:
    std::string missionID;      //!< mission id
    std::string trajectoryID;   //!< trajectory id
    logID(cModule *moduleName, std::string fileName): ILogging(moduleName, fileName){};

    virtual std::string logString() override{
        std::ostringstream strng;
        strng << missionID << delimiter << trajectoryID;
        std::string logString = strng.str();
        return logString;
    }

};

#endif /* UTIL_LOGGING_DATATYPES_LOGID_H_ */
