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

#include "CommunicationCoordinator.h"


Define_Module(CommunicationCoordinator);

void CommunicationCoordinator::initialize()
{

    //self message
    event = new cMessage("event");
    scheduleAt(simTime() + 10 , event);

    std::string fileName = "../../../ReturnDirectory/Results/CoordinateOut/Coordinates_" + std :: string(simTime().str()) + "_" + std :: string(getParentModule()->str()) + ".csv";
    logcoord = new logCoord(getParentModule(), fileName);
}


void CommunicationCoordinator :: handleMessage(cMessage *msg)
{
    if (msg -> isSelfMessage()) {

        cModule *targetModule = getParentModule() ->getSubmodule("localSituationPicture");
        LocalSituationPicture *position = check_and_cast <LocalSituationPicture *>(targetModule);
        state_cc = position -> getStateWithCovarianceLsp();

        double *cov_po;
        double *cov_ve;
        for ( int i = 0; i < 36; i++ ) {
            state_cc.pose.covariance[i] = cov_po[i];
         }
        for ( int i = 0; i < 36; i++ ) {
            state_cc.velocity.covariance[i] = cov_ve[i];
         }

        //Logging coordinate data to csv
        logcoord->coord = state_cc.pose.pose;
        logcoord->log();

        SensorMsg *sensmsg = new SensorMsg();
        sensmsg -> setVehicleState(state_cc);
        send(sensmsg, "LowerLayerOut");

        scheduleAt(simTime() + 10 , event);


    }


    else {
        send(msg, "UpperLayerOut");
    }
}




void CommunicationCoordinator::finish()
{

    if (event->isScheduled()) {
        cancelEvent(event);
    }

    delete event;



}
