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

#include "LocalSensorFusion.h"

Define_Module(LocalSensorFusion);

void LocalSensorFusion::initialize(){}


void LocalSensorFusion :: handleMessage(cMessage *msg){}


StateWithCovariance LocalSensorFusion::getStateWithCovarianceLsf(){
cModule *targetModule = getParentModule() ->getSubmodule("sensors")->getSubmodule("gps");
Gps *position = check_and_cast <Gps *>(targetModule);
state_lsf = position -> getStateWithCovariance();
Enter_Method("getStateWithCovarianceLsf()");
return state_lsf;
}


StateWithCovariance LocalSensorFusion::getStateAndCov(){
Enter_Method("getStateAndCov()");
return state_lsf;
}
