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

package simu5g.apps.burst;

import inet.applications.contract.IApp;


simple BurstReceiver like IApp
{
    parameters:
        int localPort = default(3000);
        string latencyFileName;

        @signal[burstRcvdPkt];
        @statistic[burstRcvdPkt](title="Received packet ID"; unit=""; source="burstRcvdPkt"; record=vector);
        @signal[burstPktDelay];
        @statistic[burstPktDelay](title="Delay of received packets"; unit="s"; source="burstPktDelay"; record=mean,vector);
        
        @display("i=block/source");
    gates:
        output socketOut;
        input socketIn;

}

