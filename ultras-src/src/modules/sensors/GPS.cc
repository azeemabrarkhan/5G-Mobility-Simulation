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


#include <modules/sensors/Gps.h>


Define_Module(Gps);


void Gps :: initialize(){}

void Gps :: handleMessage(cMessage *msg) {}

// position data
double *Gps:: getCovariancePose(){
    cModule *targetModule = getParentModule() ->getParentModule()-> getSubmodule("dynamics");
    VehicleDynamics *position = check_and_cast <VehicleDynamics *>(targetModule);
    pos = position -> getState();
    x = pos.pose.pose.x;
    y = pos.pose.pose.y;
    z = pos.pose.pose.z;
    a_x = pos.pose.attitude.v.x;
    a_y = pos.pose.attitude.v.y;
    a_z = pos.pose.attitude.v.z;
    a_s = pos.pose.attitude.s;

    static double covariancep[36]; //Define position covariance matrix

    covariancep[0]  = getVar(x);
    covariancep[7]  = getVar(y);
    covariancep[14] = getVar(z);
    covariancep[21] = getVar(a_x);
    covariancep[28] = getVar(a_y);
    covariancep[35] = getVar(a_z);

    return covariancep;

}

// velocity data
double *Gps:: getCovarianceVelocity(){

    cModule *targetModule = getParentModule() ->getParentModule()-> getSubmodule("dynamics");
    VehicleDynamics *Velocity = check_and_cast <VehicleDynamics *>(targetModule);
    velocity = Velocity ->getState();
    u = velocity.velocity.linear.x;
    v = velocity.velocity.linear.y;
    w = velocity.velocity.linear.z;
    p = velocity.velocity.angular.x;
    q = velocity.velocity.angular.y;
    r = velocity.velocity.angular.z;

    static double covariancev[36]; //Define velocity covariance matrix

    covariancev[0]  = getVar(u);
    covariancev[7]  = getVar(v);
    covariancev[14] = getVar(w);
    covariancev[21] = getVar(p);
    covariancev[28] = getVar(q);
    covariancev[35] = getVar(r);

    return covariancev;

}

//Formulating position and velocity information including the covariance
StateWithCovariance Gps::getStateWithCovariance(){
    double *cov_p;
    double *cov_v;

    StateWithCovariance StateWithCovariance;
    StateWithCovariance.pose.pose = Coord(x,y,z);
    StateWithCovariance.pose.attitude = UQuaternion (a_s,a_x,a_y,a_z);
    StateWithCovariance.velocity.linear = Coord (u,v,w);
    StateWithCovariance.velocity.angular = Coord (p,q,r);


    cov_p =  Gps::getCovariancePose();
    for ( int i = 0; i < 36; i++ ) {
        StateWithCovariance.pose.covariance[i] = cov_p[i];
    }

    cov_v = Gps ::getCovarianceVelocity();
    for ( int j = 0; j < 36; j++ ) {
        StateWithCovariance.velocity.covariance[j] = cov_v[j];
    }

    Enter_Method("getStateWithCovariance()");
    return StateWithCovariance;

}

//Variance Calculation
double Gps ::getVar(double g){
    omnetpp :: cNormal *normal_g = new cNormal (getRNG(0), g, std :: sqrt(10));
    omnetpp:: cStdDev stat_g("statg");

    for (int i=0; i<10; i++){
      stat_g.collect(normal_g->draw());
    }
    variance_g = stat_g.getVariance();

    delete normal_g;
    normal_g = NULL;
    return variance_g;
}


