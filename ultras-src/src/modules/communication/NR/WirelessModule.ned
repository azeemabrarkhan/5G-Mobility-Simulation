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

package ultras.src.modules.communication.NR;

import inet.applications.contract.IApp;
import inet.common.packet.recorder.PcapRecorder;
import inet.linklayer.contract.IExternalInterface;
import inet.networklayer.common.InterfaceTable;
import inet.networklayer.ipv4.Ipv4RoutingTable;
import inet.networklayer.contract.IRoutingTable;
import inet.networklayer.contract.INetworkLayer;
import inet.common.packet.recorder.PcapRecorder;
import inet.transportlayer.contract.ITcp;
import inet.transportlayer.contract.IUdp;
import inet.transportlayer.contract.ISctp;
import inet.common.MessageDispatcher;
import simu5g.stack.ICellularNic;
import simu5g.stack.NRNicUe;



module WirelessModule
{
parameters:
        @networkNode();
        @display("i=device/pocketpc;bgb=860,600");
        @figure[applicationLayer](type=rectangle; pos=250,6; size=600,130; lineColor=#808080; cornerRadius=5; fillColor=#ffff00; fillOpacity=0.1);
        @figure[applicationLayer.title](type=text; pos=845,11; anchor=ne; text="application layer");
        @figure[transportLayer](type=rectangle; pos=250,156; size=600,130; fillColor=#ff0000; lineColor=#808080; cornerRadius=5; fillOpacity=0.1);
        @figure[transportLayer.title](type=text; pos=845,161; anchor=ne; text="transport layer");
        @figure[networkLayer](type=rectangle; pos=250,306; size=600,130; fillColor=#00ff00; lineColor=#808080; cornerRadius=5; fillOpacity=0.1);
        @figure[networkLayer.title](type=text; pos=845,311; anchor=ne; text="network layer");
        @figure[linkLayer](type=rectangle; pos=250,456; size=600,130; fillColor=#0000ff; lineColor=#808080; cornerRadius=5; fillOpacity=0.1);
        @figure[linkLayer.title](type=text; pos=845,461; anchor=ne; text="link layer");
        @figure[submodules];


        //# Apps
        int numApps = default(0);   // no of apps.
                                    // Specify the app types in INI file with app[0..1].typename="UdpVideoStreamClient" syntax 

        //# Transport layer
        bool hasUdp = default(firstAvailableOrEmpty("Udp") != "");
        bool hasTcp = default(firstAvailableOrEmpty("Tcp", "TcpLwip", "TcpNsc") != "");
        bool hasSctp = default(false);

        //# Node specs
        string nodeType = "UE";  // DO NOT CHANGE
        int nrMasterId = default(0);
        int nrMacNodeId = default(0); // TODO: this is not a real parameter
        int nrMacCellId = default(0); // TODO: this is not a real parameter
        //# D2D capability
        string nicType = default("NRNicUe");
        

        //# Network Layer specs
        bool hasIpv4 = default(true);
        bool hasIpv6 = default(false);
        *.interfaceTableModule = default(absPath(".interfaceTable"));
        *.routingTableModule = default("^.ipv4.routingTable");

        //# Ext Interface
        bool enableExtInterface = default(false);
        string extHostAddress = default("");

        int numPcapRecorders = default(0); // no of PcapRecorders

    gates:
        input nrRadioIn @directIn;     // connection to master
        input upperRadioIn @directIn;  //connection to application layer

    submodules:
        interfaceTable: InterfaceTable {
            @display("p=127.368004,257.868;is=s");
        }
        app[numApps]: <> like IApp {
            @display("p=374.47998,72.479996,row,140");
        }
        udp: <default(firstAvailableOrEmpty("Udp"))> like IUdp if hasUdp {
            parameters:
                @display("p=375,226");
        }
        tcp: <default(firstAvailableOrEmpty("Tcp", "TcpLwip", "TcpNsc"))> like ITcp if hasTcp {
            parameters:
                @display("p=525,226");
        }
        sctp: <default(firstAvailableOrEmpty("Sctp"))> like ISctp if hasSctp {
            parameters:
                @display("p=675,226");
        }
        // network layer
        ipv4: <default("Ipv4NetworkLayer")> like INetworkLayer if hasIpv4 {
            parameters:
                @display("p=375,376;q=queue");
        }
        ipv6: <default("Ipv6NetworkLayer")> like INetworkLayer if hasIpv6 {
            parameters:
                @display("p=525,376;q=queue");
        }
        cellularNic: <nicType> like ICellularNic {
            nodeType = nodeType;
            //d2dCapable = d2dCapable;
            @display("p=374.47998,523.06396");
        }
        // message dispatcher for SAP between application and transport layer
        at: MessageDispatcher {
            parameters:
                @display("p=550,146;b=600,5,,,,1");
        }
        // message dispatcher for SAP between transport and network layer
        tn: MessageDispatcher {
            parameters:
                @display("p=550,296;b=600,5,,,,1");
        }
        // message dispatcher for SAP to link layer
        nl: MessageDispatcher {
            parameters:
                @display("p=550,446;b=600,5,,,,1");
        }

        ext: <default("ExtInterface")> like IExternalInterface if enableExtInterface {
            parameters:
                @display("p=524.272,521.856,row,10;q=txQueue;i=block/ifcard");
        }

        pcapRecorder[numPcapRecorders]: PcapRecorder {
            @display("p=126.84,346.69598,r,10");
        }
    connections allowunconnected:
        //# 
        //# Wireless Module and Application layer
        //#
        app[i].socketIn <-- upperRadioIn;
        
        //# LTE Nic 
        cellularNic.nrRadioIn <-- nrRadioIn;

        cellularNic.upperLayerOut --> nl.in++;
        cellularNic.upperLayerIn <-- nl.out++;

        //# 
        //# Internal Tcp/Udp applications connections with transport layer
        //#

        for i=0..numApps-1 {
            app[i].socketOut --> at.in++;
            app[i].socketIn <-- at.out++;
        }

        at.out++ --> udp.appIn if hasUdp;
        at.in++ <-- udp.appOut if hasUdp;

        at.out++ --> tcp.appIn if hasTcp;
        at.in++ <-- tcp.appOut if hasTcp;

        at.out++ --> sctp.appIn if hasSctp;
        at.in++ <-- sctp.appOut if hasSctp;

        //# 
		//# Internal transport layer connections to network layer
		//# 

        udp.ipOut --> tn.in++ if hasUdp;
        udp.ipIn <-- tn.out++ if hasUdp;

        tcp.ipOut --> tn.in++ if hasTcp;
        tcp.ipIn <-- tn.out++ if hasTcp;

        sctp.ipOut --> tn.in++ if hasSctp;
        tn.out++ --> sctp.ipIn if hasSctp;

        ipv4.ifIn <-- nl.out++ if hasIpv4;
        ipv4.ifOut --> nl.in++ if hasIpv4;

        ipv4.transportIn <-- tn.out++ if hasIpv4;
        ipv4.transportOut --> tn.in++ if hasIpv4;

        ipv6.ifIn <-- nl.out++ if hasIpv6;
        ipv6.ifOut --> nl.in++ if hasIpv6;

        ipv6.transportIn <-- tn.out++ if hasIpv6;
        ipv6.transportOut --> tn.in++ if hasIpv6;

        tn.out++ --> nl.in++;
        tn.in++ <-- nl.out++;

        //#
        //# Connections between Ext interface and IP layer 
        //#
        nl.out++ --> ext.upperLayerIn if enableExtInterface;
        nl.in++ <-- ext.upperLayerOut if enableExtInterface;
    
}