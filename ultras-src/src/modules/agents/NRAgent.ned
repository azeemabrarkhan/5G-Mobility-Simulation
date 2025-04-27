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

package ultras.src.modules.agents;


import inet.visualizer.scene.NetworkNodeOsgVisualizer;
import ultras.src.util.AgentMobility;
import ultras.src.modules.vehicle.LocalSituationPicture;
import ultras.src.modules.sensors.LocalSensors;
import ultras.src.modules.vehicle.LocalSensorFusion;
import ultras.src.modules.vehicle.CommunicationCoordinator;
import ultras.src.modules.communication.ideal.WirelessInterface;

import ultras.src.modules.dynamics.VehicleDynamics;

import ultras.src.modules.control.GNC;
import simu5g.nodes.NR.NRUe;

import inet.networklayer.common.InterfaceTable;
import inet.networklayer.contract.IRoutingTable;
import inet.networklayer.contract.INetworkLayer;
import inet.networklayer.configurator.ipv4.HostAutoConfigurator;

module NRAgent extends NRUe
{
    parameters:
        @networkNode;
        @labels(node,ethernet-node,wireless-node);
        // display and visualization parameters
        bool hasStatus = default(false);
        string osgModel = default("3d/drone.ive.700.scale.0,0,90.rot");
        string osgModelColor = default("");
        string canvasImage = default("");
        string canvasImageColor = default("");
        string missionID = default("mission1");
        string trajectoryID = default("trajectory1");

        mobilityType = default("AgentMobility");
        nrMacNodeId = 1;    //intuniform(1,4);
        nrMasterId = 1;     //intuniform(1,4);
        
        nicType = "NRNicUe";
                
        numApps = 2;
        app[0].typename = "GSSenderApp";
        app[1].typename = "BurstSender";
        
        //# Network Layer specs
        *.routingTableModule = default(absPath(".ipv4.routingTable"));
        
        ipv4.configurator.typename = "HostAutoConfigurator";
        ipv4.configurator.interfaces = "wlan";
        configurator.mcastGroups = "224.0.0.10";

    submodules:
        gnc: GNC {
            @display("p=714,39");
        }
        dynamics: VehicleDynamics {
            @display("p=650,39");
        }
        sensors: LocalSensors {
            @display("p=779,39");
        }
        localSensorFusion: LocalSensorFusion {
            @display("p=779,111");
        }
        localSituationPicture: LocalSituationPicture {
            @display("p=779,187");
        }
        networkNodeOsgVisualizer: NetworkNodeOsgVisualizer {
            @display("p=119,39");
            displayModuleName = true;
            visualizationTargetModule = "^.^";
        }
        configurator: HostAutoConfigurator {
        }
     // mobility: AgentMobility {
     //       @display("p=75,50");
     //   }
        
}
