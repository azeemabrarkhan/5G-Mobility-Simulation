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

#include "FlightScheduleManager.h"

Define_Module(FlightScheduleManager);

/**
 * Schedule flights as specified in the configuration.
 */
void FlightScheduleManager::initialize()
{
    // Load configuration from network module
    string loadModuleName = par("loaderModuleName");
    //check and cast submodule having a name equal to loaderModuleName(mentioned in the ned) and assign it to "loader"
    //which should be a pointer to the LoadConfiguration.
    loader = check_and_cast<LoadConfiguration *>(getParentModule()->getSubmodule(loadModuleName.c_str()));
    //get config which was created in LoadConfiguration with the filename mentioned in its NED file.
    config = loader->getConfig();

    // load scheduling time window
    timeStart = par("timeStart");
    timeStop = par("timeStop");
    numAgents = 0;
    numAgentsSignal = registerSignal("numAgentsSignal");

    // load default agent name
    //why we change it to string with stdstringValue and not with c_str?
    defaultName = par("defaultName").stdstringValue();

    startAtZero = par("startAtZero");
    agentModuleType = par("agentModuleType").stdstringValue();

    // iterate over all routes and trajectories
    Fleet* fleet = config->getFleets()[0];
    vector<Route*> routes = fleet->getRoutes();
    for (Route* route: routes)
    {
        vector<CPACSTrajectory*> trajectories = route->getTrajectories();
        for(CPACSTrajectory* trajectory: trajectories)
        {
            double creationTime = trajectory->getTrajectory()[0].getTime();

            // schedule flight if between start and stop time
            if (creationTime > timeStart && (creationTime < timeStop || timeStop < 0))
            {
                // offset creation time if possible
                double offset = 10.0;
                if (creationTime > offset){
                    creationTime -= offset;
                }
                // move start time to zero if startAtZero is true
                if (startAtZero){
                    creationTime = 0;
                }

                // get missionID and trajectory ID
                string missionID = route->getMissionUID();
                string trajectoryID = trajectory->getUID();

                // schedule flight
                scheduleFlight(creationTime, missionID, trajectoryID);
            }
        }
    }

    std::string fileName = "../../../ReturnDirectory/Results/Mission_ID.csv";
    id = new logID(getParentModule(), fileName);
}
/**
 * Schedule flights as specified in the configuration.
 *
 * @param creationTime creation time
 * @param mID mission ID of flight
 * @param tID trajectory ID of flight
 */
void FlightScheduleManager::scheduleFlight(double creationTime, string mID, string tID)
{
    // create message
    string msgName = "create" + std::to_string(counter);
    CreationMsg *create = new CreationMsg(msgName.c_str());
    //fill message fields and add Trajectory object
    string moduleName = defaultName + std::to_string(counter);
    create->setModuleName(moduleName.c_str());
    create->setMissionID(mID.c_str());
    create->setTrajectoryID(tID.c_str());

    // Kind 0: creation message
    create->setKind(0);
    Trajectory t = loader->getTrajectory(mID, tID);
    Trajectory *trajectory = new Trajectory(t.coords, t.times);
    trajectory->setName("trajectory");
    // if startAtZero: shift times forward
    if (startAtZero){
        double deltaT = trajectory->times[0];
        for(auto &time: trajectory->times){
            time -= deltaT;
        }
    }
    create->addObject(trajectory);

    //schedule message
    scheduleAt(creationTime, create);

    // advance counter
    counter++;
}

/**
 * Schedule deletion of agent.
 *
 * @param agentName agent name
 * @param deletionTime deletion time
 */
void FlightScheduleManager::scheduleAgentDelete(string agentName, double deletionTime)
{
    EV << "DELETING AN AGENT" << endl;
    string msgName = "delete" + agentName;
    CreationMsg *del = new CreationMsg(msgName.c_str());
    // add name of agent to delete to message
    string moduleName = agentName;
    del->setModuleName(moduleName.c_str());
    // Kind 1: deletion message
    del->setKind(1);
    scheduleAt(deletionTime, del);
}

/**
 * Handle messages: kind 0: creation message, kind 1: deletion message, kind 2: update active agents
 *
 * @param message message
 */
void FlightScheduleManager::handleMessage(cMessage *message)
{
    //check if creation message
    if (message->getKind() == 0){
        CreationMsg *msg = check_and_cast<CreationMsg *>(message);
        const char *type = agentModuleType.c_str();
        cModuleType *moduleType = cModuleType::get(type);
        cModule *module = moduleType->create(msg->getModuleName(), getParentModule());
        module->par("missionID") = msg->getMissionID();
        module->par("trajectoryID") = msg->getTrajectoryID();
        module->finalizeParameters();
        module->buildInside();
        // set submodule parameters here
        module->getSubmodule("mobility")->par("changeInterval") = 10.0;
        module->getDisplayString().parse("p=0,0;i=misc/aircraft");

        if(agentModuleType == "ultras.src.modules.agents.Agent"){

            module->getSubmodule("wirelessInterface")->par("wirelessRange") = par("wirelessRange");
        }
//        module->getSubmodule("celullarNic")->par("d2dInitialMode") = true;
//
        else{
            if(par("sendVideos")) {
                module->getSubmodule("app", 0)->par("sendVideos") = true;
                module->getSubmodule("app", 0)->par("stopTime") = 1.0;
                module->getSubmodule("app", 0)->par("destAddress") = "";
                module->getSubmodule("app", 0)->par("destPort") = 4000;
                module->getSubmodule("app", 0)->par("packetSize") = 1;

                module->getSubmodule("app", 1)->par("destAddress") = "GroundStation";
                module->getSubmodule("app", 1)->par("destPort") = 5000;
                module->getSubmodule("app", 1)->par("startTime") = 0.0;

                short fps = par("fps");
                short videoLength = par("videoLength");

                module->getSubmodule("app", 1)->par("videoLength") = videoLength;
                module->getSubmodule("app", 1)->par("burstSize") = fps * videoLength;
                module->getSubmodule("app", 1)->par("interBurstTime") = par("period");
                module->getSubmodule("app", 1)->par("packetSize") = 51200;
                module->getSubmodule("app", 1)->par("intraBurstTime") = 1.0/fps;
            } else {
                module->getSubmodule("app", 0)->par("destAddress")= "GroundStation";
                module->getSubmodule("app", 0)->par("localPort")= 3088;
                module->getSubmodule("app", 0)->par("destPort")= 4000;            
                module->getSubmodule("app", 0)->par("packetSize")= 40;
                module->getSubmodule("app", 0)->par("startTime")= uniform(0,0.02);
                module->getSubmodule("app", 0)->par("period") = par("period");
                if(par("sendImages")) {
                    module->getSubmodule("app", 0)->par("sendImages") = true;
                } else {
                module->getSubmodule("app", 0)->par("sendImages") = false;
                module->getSubmodule("app", 0)->par("sendVideos") = false;
                }
            }
        }

        //Logging mission and trajectory ID data directly to csv
        id->missionID = msg->getMissionID();
        id->trajectoryID = msg->getTrajectoryID();
        id->log();

        //set reference trajectory in GNC module
        Trajectory *trajectory = check_and_cast<Trajectory *>(msg->getObject("trajectory"));
        string gncModuleName = par("gncModuleName");
        GNC *gncModule = check_and_cast<GNC *>(module->getSubmodule(gncModuleName.c_str()));
        gncModule->setReferenceTrajectory(*trajectory);

        // initialize state in VehicleDynamics module
        string dynamicsModuleName = par("dynamicsModuleName");
        VehicleDynamics *dynamicsModule = check_and_cast<VehicleDynamics *>(module->getSubmodule(dynamicsModuleName.c_str()));
        State state;
        state.pose.pose = trajectory->coords[0];
        dynamicsModule->initializeState(state);

        //Set Deletion Time (10s after end of trajectory)
        int lastTime = trajectory->times.size();
        deletionTime = trajectory->times[lastTime-1];

        if(par("sendVideos")) {
            module->getSubmodule("app", 1)->par("stopTime") = deletionTime;
        }

        // Initialize
        module->callInitialize();
        numAgents = numAgents + 1;
        emit(numAgentsSignal, numAgents);

        schedule delete 10s after end of trajectory
        scheduleAgentDelete(module->getName(), deletionTime+10);

        // delete message
        cancelAndDelete(message);
    }

   // check if deletion message
    if(message->getKind() == 1){
        CreationMsg *msg = check_and_cast<CreationMsg *>(message);

        // check if cmd or qtenv
        bool isCmd = !getParentModule()->par("osgPresent");

        // get list of submodules except OSG
        std::vector<string> deletionList;
        for (cModule::SubmoduleIterator it(getParentModule()->getSubmodule(msg->getModuleName())); !it.end(); ++it) {
            cModule *submodule = *it;

            //Delete only the mobility module and GNC Module (solution for the meantime)
            if (strcmp(submodule->getName(), "mobility") ==0 || strcmp(submodule->getName(), "gnc") ==0){
                deletionList.push_back(submodule->getName());
            }

        }
        // call finish() of agent and delete modules in deletionList
        getParentModule()->getSubmodule(msg->getModuleName())->callFinish();
        for(auto const& module: deletionList) {
            getParentModule()->getSubmodule(msg->getModuleName())->getSubmodule(module.c_str())->deleteModule();
        }

        numAgents = numAgents - 1;
        emit(numAgentsSignal, numAgents);

        cancelAndDelete(message);
    }
}

//Get Deletion time
simtime_t  FlightScheduleManager::getTime(){
     Enter_Method("getTime()");
     return deletionTime;
}
