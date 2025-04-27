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

module Agent
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

    gates:
        input radioIn @directin @loose;
    submodules:
        mobility: AgentMobility {
            @display("p=75,50");
        }
        gnc: GNC {
            @display("p=75,275");
        }
        dynamics: VehicleDynamics {
            @display("p=150,150");
        }
        localSituationPicture: LocalSituationPicture {
            @display("p=433,182");
        }
        sensors: LocalSensors {
            @display("p=433,50");
        }
        localSensorFusion: LocalSensorFusion {
            @display("p=433,117");
        }
        communicationCoordinator: CommunicationCoordinator {
            @display("p=433,117");
        }
        wirelessInterface: WirelessInterface {
            @display("p=433,239");
        }
        networkNodeOsgVisualizer: NetworkNodeOsgVisualizer {
            @display("p=207,50");
            displayModuleName = true;
            visualizationTargetModule = "^.^";
        }
    connections allowunconnected:
        localSituationPicture.LowerLayerIn <-- communicationCoordinator.UpperLayerOut;
        communicationCoordinator.LowerLayerIn <-- wirelessInterface.UpperLayerOut;
        wirelessInterface.UpperLayerIn <-- communicationCoordinator.LowerLayerOut;
        wirelessInterface.LowerLayerIn <-- radioIn;
}

