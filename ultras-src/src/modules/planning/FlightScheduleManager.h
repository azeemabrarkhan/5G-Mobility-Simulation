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

#ifndef __ULTRAS_FLIGHTSCHEDULEMANAGER_H_
#define __ULTRAS_FLIGHTSCHEDULEMANAGER_H_

#include <omnetpp.h>
#include <iostream>
#include <fstream>
#include <string>
#include <Algorithm>
#include "modules/LoadConfiguration.h"
#include "messages/CreationMsg_m.h"
#include "modules/control/GNC.h"
#include "modules/dynamics/VehicleDynamics.h"
#include "util/logging/dataTypes/logID.h"


using namespace omnetpp;
using namespace std;

class FlightScheduleManager : public cSimpleModule
{
protected:
    LoadConfiguration* loader;      //!< configuration loading module
    Configuration *config;          //!< configuration
    int counter = 0;                //!< counter for agent name
    double timeStart;               //!< simulation start time
    double timeStop;                //!< simulation stop time
    string defaultName;             //!< default agent name
    string agentModuleType;         //!< agent module type
    bool startAtZero;               //!< if true, all missions start at time zero
    logID * id;                     //!< object for logging mission id and trajectory id
    int numAgents;
    simsignal_t numAgentsSignal;



protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *message);
    void scheduleFlight(double creationTime, string mID, string tID);
    void scheduleAgentDelete(string agentName, double deletionTime);

public:
    double deletionTime;
    simtime_t getTime();


};

#endif
