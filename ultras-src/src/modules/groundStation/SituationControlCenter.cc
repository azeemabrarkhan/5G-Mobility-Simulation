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

#include <modules/groundStation/SituationControlCenter.h>

Define_Module(SituationControlCenter);

void SituationControlCenter::initialize()
{

}


void SituationControlCenter :: handleMessage(cMessage *msg){

    //Define gates
    cGate *gate;
    char gateName[64];
    gate = msg->getArrivalGate();
    strcpy(gateName, gate ->getName());

    //Receive the message containing neighbour position data sent from wireless interface received from other vehicles and send it to further modules
    if (strstr(gateName, "LowerLayerIn") != NULL) {
        delete msg;
    }

}








