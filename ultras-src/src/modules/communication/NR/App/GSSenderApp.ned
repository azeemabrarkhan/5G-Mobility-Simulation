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

simple GSSenderApp like IApp
{
    parameters:
        @signal[dataSentSignal](type="long");
        @statistic[dataSentSignal](title="No. of bytes sent"; source="dataSentSignal"; record=vector,stats; interpolationmode=none);
        @signal[dataSentSignalKbs](type="double");
        @statistic[dataSentSignalKbs](title="No. of KBs sent"; source="dataSentSignalKbs"; record=vector,stats; interpolationmode=none);
        int localPort = default(3088+ancestorIndex(0));
        int destPort = default(3000);
        string destAddress = default("GroundStation");
        int packetSize = default(40);
        volatile double period @unit("s") = default(uniform(0s,0.04s));
        double startTime @unit("s") = default(uniform(0s,0.02s));
        double stopTime @unit("s") = default(0s); // 0 means "never stops" 
        string interfaceTableModule;
        bool sendImages = default(false); 
        bool sendVideos = default(false);
        int videoLength = default(0);
        int fps = default(0);

        @display("i=block/source");
    gates:
        output socketOut;
        input socketIn;
}