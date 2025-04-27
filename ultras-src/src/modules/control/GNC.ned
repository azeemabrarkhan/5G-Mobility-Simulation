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

package ultras.src.modules.control;

//
// Guidance, Navigation, and Control module
//
simple GNC
{
    parameters:
        int selectDynamics = default(0); 									// dynamics selector
        int selectPositionController = default(0);							// position controller selector
        string situationPictureName = default("localSituationPicture");		// local situation picture module
}
