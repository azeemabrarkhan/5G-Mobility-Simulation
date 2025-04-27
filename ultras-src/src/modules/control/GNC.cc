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

#include "GNC.h"

Define_Module(GNC);

/**
 * Select and initialize dynamcis, controllers and reference trajectory.
 */
void GNC::initialize()
{
    // Get pointer to localSituationPicture module
    string pictureModuleName = par("situationPictureName");
    situationPicture = check_and_cast<LocalSituationPicture *>(getParentModule()->getSubmodule(pictureModuleName.c_str()));

    // Select controllers
    selectDynamics = par("selectDynamics");
    controlInput = new ControlInput();
    switch(selectDynamics){
    case 0: // NoDynamics

        // initialize controller
        NoDynamicsController = new Control_PositionAttitude_NoDynamics();
        NoDynamicsController->trajectory = &referenceTrajectory;
        NoDynamicsController->update();

        // schedule timers
        timer_PosAtt = new cMessage("timerPosAtt");
        getParentModule()->getSubmodule("mobility")->par("changeInterval") = NoDynamicsController->samplingTime;
        scheduleAt(simTime() + NoDynamicsController->samplingTime, timer_PosAtt);
    }
}
/**
 * Execute control algorithms.
 * @param msg controller timer self messages
 */
void GNC::handleMessage(cMessage *msg)
{
    if(hasChangedReference){
        NoDynamicsController->trajectory = &referenceTrajectory;
        hasChangedReference = false;
    }
    neighborData = situationPicture->getNeighborData();
    NoDynamicsController->update();
    controlInput->data = NoDynamicsController->output->data;
    sendControlSignal();
    scheduleAt(simTime() + NoDynamicsController->samplingTime, timer_PosAtt);
}

/**
 * Send control signal to dynamics module.
 */
void GNC::sendControlSignal()
{
    cMessage *controlSignal = new cMessage("inputSignal");
    ControlInput *cI = new ControlInput(controlInput->data);
    cI->setName("inputSignal");
    controlSignal->addObject(cI);
    sendDirect(controlSignal, getParentModule()->getSubmodule("dynamics"), "ControlInput");
}

/**
 * Set reference trajectory.
 * @param referenceTrajectory reference trajectory
 */
void GNC::setReferenceTrajectory(Trajectory &referenceTrajectory)
{
    Enter_Method("setReferenceTrajectory(Trajectory referenceTrajectory)");
    this->referenceTrajectory = referenceTrajectory;
    hasChangedReference = true;
}
