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

package ultras.src.modules.groundStation;

import inet.visualizer.scene.NetworkNodeOsgVisualizer;
import inet.node.inet.StandardHost;

import ultras.src.modules.communication.ideal.GroundWirelessInterface;
import ultras.src.modules.groundStation.SituationControlCenter;
import ultras.src.modules.groundStation.GlobalSensorFusion;
import ultras.src.modules.sensors.GlobalSensors;

module GroundStation extends StandardHost
{
	parameters:
	    @networkNode;
        @labels(node,ethernet-node,wireless-node);
		@display("i=device/antennatower");
	
	    
    submodules:
         networkNodeOsgVisualizer: NetworkNodeOsgVisualizer {
               @display("p=207,50");
               displayModuleName = false;   
               visualizationTargetModule = "^.^"; 
                
        }
        situationControlCenter: SituationControlCenter {
            @display("p=75,194");
        }
        globalSensorFusion: GlobalSensorFusion {
            @display("p=75,123");
        }
        globalSensors: GlobalSensors {

            @display("p=75,55");
        }




}
