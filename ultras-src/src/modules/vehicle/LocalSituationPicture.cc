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


#include "LocalSituationPicture.h"

Define_Module(LocalSituationPicture);

void LocalSituationPicture::initialize(){

    //Initialize
    neighborState = new NeighborData();
    neighborState->neighborlist = std::vector <StateWithCovariance>();
}


void LocalSituationPicture :: handleMessage(cMessage *msg){

    //Define gates
    cGate *gate;
    char gateName[64];
    gate = msg->getArrivalGate();
    strcpy(gateName, gate ->getName());

    //Receive the message containing neighbor position data sent from wireless interface of neighbor vehicles
    if (strstr(gateName, "LowerLayerIn") != NULL) {
        delete msg;
    }

    else if(strstr(gateName, "LSPradioIn") != NULL) {
        delete msg;
    }


    //Receive the neighbor list message generated at own module's wireless interface containing neighbor positions
    else {
        NeighborData *nData = check_and_cast <NeighborData *>(msg->getObject("neighbourList"));
        neighborState->neighborlist = nData->neighborlist ;
        delete msg;
    }

}

StateWithCovariance LocalSituationPicture::getStateWithCovarianceLsp(){
 cModule *targetModule = getParentModule() ->getSubmodule("localSensorFusion");
 LocalSensorFusion *position = check_and_cast <LocalSensorFusion *>(targetModule);
 state_lsp = position -> getStateWithCovarianceLsf();
 Enter_Method("getStateWithCovarianceLsp()");
 return state_lsp;
 }

NeighborData LocalSituationPicture::getNeighborData(){
    Enter_Method("getNeighborData()");
    return *neighborState;
}




