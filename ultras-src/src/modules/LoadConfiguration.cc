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

#include "LoadConfiguration.h"

Define_Module(LoadConfiguration);

void LoadConfiguration::initialize()
{
    string inputFile= par("inputFile");
    config = new Configuration(inputFile);
    EV << "Configuration loaded." << endl;
}

void LoadConfiguration::handleMessage(cMessage *msg) {}

Configuration* LoadConfiguration::getConfig()
{
    Enter_Method("getConfig()");
    return config;
}

Trajectory LoadConfiguration::getTrajectory(string missionID, string trajectoryID)
{
    Enter_Method("getTrajectory(string missionID, string trajectoryID)");
    //get CPACS trajectory
    CPACSTrajectory trajectory = trajectoryFromMissionIDAndTrajectoryID(missionID, trajectoryID);
    vector<Position> trajectoryPositions = trajectory.getTrajectory();
    vector<Coord> coords(trajectoryPositions.size());
    vector<double> times(trajectoryPositions.size());

    //fill coordinate and time vector and convert to Cartesian coordinates
    UGeoCoord geoPosition = UGeoCoord();
    for(int i = 0; i < trajectoryPositions.size(); i++)
    {
        // LAT LONG SWITCH HOTFIX
        // TODO
        if (trajectoryPositions[i].getLongitude() > 15) {
            geoPosition.latitude = trajectoryPositions[i].getLongitude();
            geoPosition.longitude = trajectoryPositions[i].getLatitude();
        } else {
            geoPosition.latitude = trajectoryPositions[i].getLatitude();
            geoPosition.longitude = trajectoryPositions[i].getLongitude();
        }
        geoPosition.altitude = trajectoryPositions[i].getElevation();
        coords[i] = GeoToCoord(geoPosition);
        times[i] = trajectoryPositions[i].getTime();
    }
    return Trajectory(coords, times);
}

CPACSTrajectory LoadConfiguration::trajectoryFromMissionIDAndTrajectoryID(string missionID, string trajectoryID)
{
    Fleet* fleet = config->getFleets()[0];
    vector<Route*> routes = fleet->getRoutes();
    for (Route* route: routes)
    {
        if (route->getMissionUID() == missionID)
        {
            vector<CPACSTrajectory*> trajectories = route->getTrajectories();
            for(CPACSTrajectory* trajectory: trajectories)
            {
                if(trajectory->getUID() == trajectoryID)
                {
                    return *trajectory;
                }
            }
        }
    }
}
