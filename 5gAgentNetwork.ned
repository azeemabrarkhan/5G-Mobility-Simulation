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

package ultras.simulations;


import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;
import inet.networklayer.ipv4.RoutingTableRecorder;
import inet.node.ethernet.Eth10G;
import inet.node.inet.Router;
import inet.visualizer.contract.IMobilityVisualizer;
import inet.visualizer.mobility.MobilityVisualizer;
import simu5g.common.binder.Binder;
import simu5g.common.carrierAggregation.CarrierAggregation;
import simu5g.nodes.Upf;
import simu5g.nodes.NR.gNodeB;
import simu5g.nodes.eNodeB;
import simu5g.nodes.PgwStandard;
import simu5g.nodes.ExtCell;
import simu5g.world.radio.LteChannelControl;

import ultras.src.modules.LoadConfiguration;
import ultras.src.modules.agents.NRAgent;
import simu5g.nodes.NR.NRUe;
import ultras.src.modules.groundStation.GroundStation;
import inet.visualizer.integrated.IntegratedVisualizer;
import inet.common.geometry.common.OsgGeographicCoordinateSystem;
import inet.visualizer.scene.NetworkNodeOsgVisualizer;

import ultras.src.modules.planning.FlightScheduleManager;


network AgentNetwork
{
    parameters:
        bool osgPresent = default(true);

        @display("bgb=800,800");
    submodules:
        visualizer: IntegratedVisualizer {
            @display("p=751,107");
        }

        coordinateSystem: OsgGeographicCoordinateSystem if osgPresent {
            parameters:
                sceneLatitude = 53.551086deg;
                sceneLongitude = 9.993682deg;
                sceneAltitude = 0m;
                @display("p=751,38");
        }

        channelControl: LteChannelControl {
            @display("p=750,343;is=s");
        }
        routingRecorder: RoutingTableRecorder {
            @display("p=751,291;is=s");
        }
        configurator: Ipv4NetworkConfigurator {
            @display("p=861.325,119.665");
            config = xmldoc("demo.xml");
        }
        binder: Binder {
            @display("p=751,393;is=s");
        }
        carrierAggregation: CarrierAggregation {
            @display("p=751,238;is=s");
        }
        GroundStation: GroundStation {
            @display("p=100,80;is=n;i=device/server");
        }
        router: Router {
            @display("p=200,80;i=device/smallrouter");
        }
        upf: Upf {
            @display("p=400,80;is=l");
        }
        gnb1: gNodeB {
            @display("p=200,200;is=vl");
        }
        gnb2: gNodeB {
            @display("p=600,200;is=vl");
        }
        gnb3: gNodeB {
            @display("p=200,600;is=vl");
        }
        gnb4: gNodeB {
            @display("p=600,600;is=vl");
        }
        loader: LoadConfiguration {
            @display("p=946.8,119.665");
        }
        FlightScheduleManager: FlightScheduleManager {
            @display("p=895.515,38.135002");
        }
        mobilityVisualizer: MobilityVisualizer {
            @display("p=751,180");
        }

    connections:
        GroundStation.pppg++ <--> Eth10G <--> router.pppg++;
        router.pppg++ <--> Eth10G <--> upf.filterGate;
        upf.pppg++ <--> Eth10G <--> gnb1.ppp;
        upf.pppg++ <--> Eth10G <--> gnb2.ppp;
        upf.pppg++ <--> Eth10G <--> gnb3.ppp;
        upf.pppg++ <--> Eth10G <--> gnb4.ppp;

        // connect with every station
        gnb1.x2++ <--> Eth10G <--> gnb2.x2++;
        gnb1.x2++ <--> Eth10G <--> gnb3.x2++;
        gnb1.x2++ <--> Eth10G <--> gnb4.x2++;
        gnb2.x2++ <--> Eth10G <--> gnb3.x2++;
        gnb2.x2++ <--> Eth10G <--> gnb4.x2++;
        gnb3.x2++ <--> Eth10G <--> gnb4.x2++;

//      square
//        gnb1.x2++ <--> Eth10G <--> gnb2.x2++;
//        gnb1.x2++ <--> Eth10G <--> gnb3.x2++;
//        gnb2.x2++ <--> Eth10G <--> gnb4.x2++;
//        gnb3.x2++ <--> Eth10G <--> gnb4.x2++;
}
