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

#ifndef UTIL_DATATYPES_CONTROLINPUT_H_
#define UTIL_DATATYPES_CONTROLINPUT_H_

#include <omnetpp.h>

/**
 * Control input with variable size.
 */
class ControlInput: public omnetpp::cNamedObject {
public:
    std::vector<double> data;
    ControlInput(){};
    ControlInput(std::vector<double> &data): data(data){};
    virtual ControlInput *dup() const override  {return new ControlInput(*this);}
};

#endif /* UTIL_DATATYPES_CONTROLINPUT_H_ */
