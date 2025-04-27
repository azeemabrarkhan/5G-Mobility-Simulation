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

package ultras.src.modules.communication.ideal;

simple WirelessInterface{
    
    	parameters:
    	    double wirelessRange @unit(m) = default (2000m);   //parameter wireless range
    
    	gates:
    	
    	//interface to agent module    
	    input LowerLayerIn;   
	    
	    //interfaces to communication coordinator module
	    input UpperLayerIn;	  
	    output UpperLayerOut;
	    
	    
}

    