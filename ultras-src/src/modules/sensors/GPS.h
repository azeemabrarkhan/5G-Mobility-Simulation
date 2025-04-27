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
 * @file Gps.cc
 *
 * @brief Class for simple module GPS Sensor
 *
 *
 *
 * @author Shashini Wanniarachchi
 * Contact: shashini.wanniarachchi@tuhh.de
 *
 */

#ifndef MODULES_Gps_H_
#define MODULES_Gps_H_

#include <omnetpp.h>
#include <string.h>
#include<iostream>

#include "inet/common/geometry/common/Coord.h"
#include "util/DataTypes/StateDataTypes.h"
#include <util/DataTypes/UQuaternion.h>
#include "modules/dynamics/VehicleDynamics.h"

using namespace omnetpp;
using namespace inet;
using namespace std;

/**
 * Implementing the behaviour of a GPS sensor in an air taxi
 *
 */
class Gps : public cSimpleModule
{

protected:
    State pos;       ///<current vehicle position
    State velocity;  ///<current vehicle velocity

    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;

    /** Calculate covariance matrix of position
     *
     * Return covariance of position.
     * @return covariance of position
     */
    double *getCovariancePose();

    /**Calculate covariance matrix of velocity
     *
     * Return covariance of velocity.
     * @return covariance of velocity
     */
    double *getCovarianceVelocity();

    /**Calculate variance of a given double variable
     *
     * @param variable for which the variance is calculated
     *
     * Return Variance
     * @return variance
     */
    double getVar(double g);

    double variance_g;       ///<variance
    double x;                ///<x coordinate
    double y;                ///<y coordinate
    double z;                ///<z coordinate
    double a_s;              ///<Real component of attitude
    double a_x;              ///<Imaginary x component of attitude
    double a_y;              ///<Imaginary y component of attitude
    double a_z;              ///<Imaginary z component of attitude
    double u;                ///<Linear x component of velocity
    double v;                ///<Linear y component of velocity
    double w;                ///<Linear z component of velocity
    double p;                ///<Angular x component of velocity
    double q;                ///<Angular y component of velocity
    double r;                ///<Angular z component of velocity

public:
    /** (*Direct access method*)
     * Create the struct state(position,attitude,velocity) with
     * respective covariance matrices
     *
     * Return current state with covariance.
     * @return current state with covariance
     */
    StateWithCovariance getStateWithCovariance();



};

#endif /* MODULES_Gps_H_ */
