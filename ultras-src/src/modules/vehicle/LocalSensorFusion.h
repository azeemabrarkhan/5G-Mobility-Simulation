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
 * @file LocalSensorFusion.cc
 *
 * @brief Class for simple module Local Sensor Fusion
 *
 *
 *
 * @author Shashini Wanniarachchi
 * Contact: shashini.wanniarachchi@tuhh.de
 *
 */

#ifndef MODULES_LOCALSENSORFUSION_H_
#define MODULES_LOCALSENSORFUSION_H_

#include <modules/sensors/Gps.h>
#include <omnetpp.h>
#include<stdio.h>
#include<string.h>

#include "util/DataTypes/StateDataTypes.h"

using namespace omnetpp;

/**
 * Implementing sensor fusion of different sensors
 * locally in an air taxi
 *
 */
class LocalSensorFusion : public cSimpleModule
{

protected :
    StateWithCovariance state_lsf;    ///<current vehicle state

    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;

public:
    /** (*Direct access method*)

     *
     * Return current state with covariance.
     * @return current state with covariance
     */
    StateWithCovariance getStateAndCov();

    /** (*Direct access method*)

     *
     * Return current state with covariance.
     * @return current state with covariance
     */
    StateWithCovariance getStateWithCovarianceLsf();



};


#endif /* MODULES_LOCALSENSORFUSION_H_ */
