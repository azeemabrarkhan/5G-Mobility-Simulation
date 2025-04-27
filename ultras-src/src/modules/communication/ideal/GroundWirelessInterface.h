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


/**
 * @file GroundWirelessInterface.cc
 *
 * @brief Class for simple module Wireless Interface
 * at the ground station
 *
 *
 *
 * @author Shashini Wanniarachchi
 * Contact: shashini.wanniarachchi@tuhh.de
 *
 */

#ifndef MODULES_GROUNDWIRELESSINTERFACE_H_
#define MODULES_GROUNDWIRELESSINTERFACE_H_

#include <omnetpp.h>
#include<stdio.h>
#include<string.h>

#include "messages/WirelessMsg_m.h"

using namespace omnetpp;
using namespace std;

/**
 * Implementing a wireless communication
 * module inside the ground station
 *
 */
class GroundWirelessInterface : public cSimpleModule
{

protected :


    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;





};



#endif /* MODULES_GROUNDWIRELESSINTERFACE_H_ */
