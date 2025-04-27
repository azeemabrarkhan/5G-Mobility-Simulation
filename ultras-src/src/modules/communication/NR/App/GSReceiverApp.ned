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

package ultras.src.modules.communication.NR.App;


import inet.applications.contract.IApp;

simple GSReceiverApp like IApp
{
    parameters:
        @signal[latencySingal](type="double");
        @statistic[latencySingal](title="Ground station latency"; source="latencySingal"; record=vector,stats; interpolationmode=none);
        @signal[dataReceivedSignal](type="long");
        @statistic[dataReceivedSignal](title="No. of bytes received"; source="dataReceivedSignal"; record=vector,stats; interpolationmode=none);
        @signal[dataReceivedSignalKbs](type="double");
        @statistic[dataReceivedSignalKbs](title="No. of KBs received"; source="dataReceivedSignalKbs"; record=vector,stats; interpolationmode=none);
        int localPort = default(3000);
        string interfaceTableModule;
        
        @signal[deliveryDelay];
        @statistic[deliveryDelay](title="Message Delivery Delay"; unit="s"; source="deliveryDelay"; record=mean,vector);    
            
        @display("i=block/source");
        
    gates:
        output socketOut;
        input socketIn;
}