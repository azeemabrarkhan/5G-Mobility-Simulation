// 
//                  Simu5G
//
// Authors: Giovanni Nardini, Giovanni Stea, Antonio Virdis (University of Pisa)
// 
// This file is part of a software released under the license included in file
// "license.pdf". Please read LICENSE and README files before using it.
// The above files and the present reference are part of the software itself, 
// and cannot be removed from it.
// 


package simu5g.stack.phy;
import simu5g.stack.phy.LtePhy;


// 
// NR Phy module of PHY Layer
//
simple NRPhyUe extends LtePhyUeD2D {
     parameters:
         @class("NRPhyUe");
         @signal[successfulHandoversSingal](type="int");
         @statistic[successfulHandoversSingal](title="Number of successful handovers"; source="successfulHandoversSingal"; record=vector,stats; interpolationmode=none);
         @signal[triggeredHandoversSingal](type="int");
         @statistic[triggeredHandoversSingal](title="Number of triggered handovers"; source="triggeredHandoversSingal"; record=vector,stats; interpolationmode=none);

}

