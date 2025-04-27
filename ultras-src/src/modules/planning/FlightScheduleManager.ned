// This file is part of the ULTRAS OMNeT++ Simulation Framework
//
// Author: Philipp Hastedt <philipp.hastedt@tuhh.de>
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

package ultras.src.modules.planning;

//
// Scheduling of Flights, dynamic creation and deletion of agent modules.
//
simple FlightScheduleManager
{
    parameters:
        @signal[numAgentsSignal](type="int");
        @statistic[numAgentsSignal](title="numAgents"; source="numAgentsSignal"; record=vector,stats; interpolationmode=none);
        string loaderModuleName = default("loader"); // name of configuration loader module
        double timeStart = default(0.0); // simulation start time
        double timeStop = default(-1); // simulation stop time, -1 for open end
        string defaultName = default("Agent"); // default agent name
        bool startAtZero = default(false); // start all missions at time 0
        //string agentModuleType = default("ultras.src.modules.agents.Agent"); // agent module type
        string agentModuleType = default("ultras.src.modules.agents.NRAgent"); // agent module type
        string gncModuleName = default("gnc"); // name of GNC module
        string dynamicsModuleName = default("dynamics"); // name of dynamics module
        bool sendImages = default(false);
        bool sendVideos = default(false);
        volatile double period @unit("s") = default(uniform(0s,0.04s));
        int videoLength = default(0);
        int fps = default(0);
        
        // Submodule Parameters
        double wirelessRange @unit(m) = default (2000m); // wireless communication range
}
