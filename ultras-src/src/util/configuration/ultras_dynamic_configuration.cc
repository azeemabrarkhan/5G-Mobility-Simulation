/*
 * ultras_dynamic_configuration.cpp
 *
 *  Created on: 22.02.2021
 *      Author: ti5mv
 */

#include <cassert>
#include <cmath>
#include <iostream>
#include <sstream>
#include "ultras_dynamic_configuration.h"

/********************************* Support functions **********************************/

/**
 * Reads a CSV-String of floats and returns it as a vector.
 *
 * It uses Space, Comma or Semicolon as seperator character.
 */
vector<double> doubleVectorFromCSVString(string s)
{
	vector<double> result;
	stringstream ss(s);
	double number;

	while (ss >> number) // Read next number from the string
	{
		result.push_back(number);
 		while (ss.peek() != EOF && (ss.peek() == ',' || ss.peek() == ';' || ss.peek() == ' '))
		{
			ss.ignore();
		}
	}

	return result;
}


/********************************* Class Position **********************************/
Position::Position(double nLongitude,
		           double nLatitude,
		           double nElevation,
		           double nTime,
		           double nDistance,
		           double nEnergyConsumption)
: longitude(nLongitude), latitude(nLatitude), elevation(nElevation), time(nTime), distance(nDistance), energyConsumption(nEnergyConsumption)
{}

string Position::toString() {
	ostringstream os;

	os << "[Position " ;
	os << "longitude="   << getLongitude();
	os << ", latitude=" << getLatitude();
	if (!isnan(getElevation()))
	{
		os << ", elevation=" << getElevation();
	}
	if (!isnan(getTime()))
	{
		os << ", time=" << getTime();
	}
	if (!isnan(getDistance()))
	{
		os << ", distance=" << getDistance();
	}
	if (!isnan(getEnergyConsumption()))
	{
		os << ", energyConsumption=" << getEnergyConsumption();
	}
	os << "]";

	return os.str();;
}

vector<Position> Position::loadFromCsv(string longitudes, string latitudes, string elevations, string times, string distances, string energyConsumptions)
{
	bool withElevations         = !elevations.empty();
	bool withTimes              = !times.empty();
	bool withDistances          = !distances.empty();
	bool withEnergyConsumptions = !energyConsumptions.empty();

	vector<double> longitudesVector = doubleVectorFromCSVString(longitudes);
	vector<double> latitudesVector = doubleVectorFromCSVString(latitudes);
	vector<double> elevationsVector;
	vector<double> timesVector;
	vector<double> distancesVector;
	vector<double> energyConsumptionsVector;

	assert(longitudesVector.size() == latitudesVector.size());

	if (withElevations) {
		elevationsVector = doubleVectorFromCSVString(elevations);
		assert(longitudesVector.size() == elevationsVector.size());
	}

	if (withTimes) {
		timesVector = doubleVectorFromCSVString(times);
		assert(longitudesVector.size() == timesVector.size());
	}

	if (withDistances) {
		distancesVector = doubleVectorFromCSVString(distances);
		assert(longitudesVector.size() == distancesVector.size());
	}

	if (withEnergyConsumptions) {
		energyConsumptionsVector = doubleVectorFromCSVString(energyConsumptions);
		assert(longitudesVector.size() == energyConsumptionsVector.size());
	}

	vector<Position> result = vector<Position>();
	for (unsigned i = 0; i < longitudesVector.size(); i++)
	{
		double elevation;
		double time;
		double distance;
		double energyConsumption;

		if (withElevations)
			elevation = elevationsVector[i];
		else
			elevation = numeric_limits<double>::quiet_NaN();

		if (withTimes)
			time = timesVector[i];
		else
			time = numeric_limits<double>::quiet_NaN();

		if (withDistances)
			distance = distancesVector[i];
		else
			distance = numeric_limits<double>::quiet_NaN();

		if (withEnergyConsumptions)
			energyConsumption = energyConsumptionsVector[i];
		else
			energyConsumption = numeric_limits<double>::quiet_NaN();

		result.push_back(Position(longitudesVector[i], latitudesVector[i], elevation, time, distance, energyConsumption));
	}
	return result;
}

string Position::vectorToString(vector<Position> positions)
{
	ostringstream os;

	for (Position position: positions)
	os << position.toString() << endl;
	return os.str();
}

/********************************* Class Vertipad **********************************/
Vertipad::Vertipad(const Node *vertipadNode, Vertiport *nVertiport, Configuration *nConfiguration)
{
	uID = getAttribute(vertipadNode, "@uID");
	name = getElement(vertipadNode, "name");
	position.setLongitude(stod(getElement(vertipadNode, "positionNorth"))); // Compensate swapping errro in CPACS file.
	position.setLatitude(stod(getElement(vertipadNode, "positionEast")));  // Compensate swapping error in CPACS file.
	position.setElevation(stod(getElement(vertipadNode, "elevation")));
	vertiport = nVertiport;
	configuration = nConfiguration;
}

vector<Vertipad*> Vertipad::loadVertipadsFromCpacs(const Node *vertiportNode, Vertiport *vertiport, Configuration* nConfiguration) {
	int numVertipads;
	vector<Vertipad*> result;
	vector<Node*> vpads = getNodes(vertiportNode, "//vertipad", numVertipads);
	result = vector<Vertipad*>(numVertipads);
	for (int i = 0; i < numVertipads; i++) {
		result[i] = new Vertipad(vpads[i], vertiport, nConfiguration);
	}
	return result;
}

string Vertipad::toString() {
	ostringstream os;

	os << "[Vertipad " ;

	os << "uID=" << getUID();
	os << ", name=" << getName();
	os << ", position=" << getPosition().toString();
	os << "]";

	return os.str();
}


/********************************* Class Vertiport **********************************/

Vertiport::Vertiport(const Node* vertiportNode, Configuration* nConfiguration)
{
	uID = getAttribute(vertiportNode, "@uID");
	name = getElement(vertiportNode, "name");
	position.setLongitude(stod(getElement(vertiportNode, "positionNorth"))); // Compensate swapping errro in CPACS file.
	position.setLatitude(stod(getElement(vertiportNode, "positionEast")));  // Compensate swapping error in CPACS file.
	position.setElevation(stod(getElement(vertiportNode, "elevation")));
	capacity = stoi(getElement(vertiportNode, "Capacity"));
	vertipads = Vertipad::loadVertipadsFromCpacs(vertiportNode, this, nConfiguration);
	configuration = nConfiguration;
}

Vertiport::~Vertiport()
{
	for (Vertipad* vertipad: vertipads)
		delete vertipad;
}

vector<Vertiport*> Vertiport::loadVertiportsFromCpacs(const Node *cpacsNode, Configuration *nConfiguration)
{
	int numVertiports;
	vector<Vertiport*> result;
	vector<Node*> vports = getNodes(cpacsNode, "//vertiports/vertiport", numVertiports);
	result = vector<Vertiport*>(numVertiports);
	for (int i = 0; i < numVertiports; i++) {
		result[i] = new Vertiport(vports[i], nConfiguration);
	}
	return result;
}

string Vertiport::toString() {
	ostringstream os;
	vector<Vertipad*> vertipads;

	os << "[Vertiport " ;
	os << "uID=" << getUID();
	os << ", name=" << getName();
	os << ", capacity=" << getCapacity();
	os << ", position=" << getPosition().toString() << endl;

	vertipads = getVertipads();
	for (Vertipad* vertipad: vertipads)
	{
		os << "  " << vertipad->toString() << endl;
	}

	os << "]" << endl;

	return os.str();;
}


/*********************************** Class Mission **********************************/
Mission::Mission(const Node *missionNode, Configuration *nConfiguration)
{
	string flightPathLatitudes;
	string flightPathLongitudes;
	uID = getAttribute(missionNode, "@uID");
	name = getElement(missionNode, "name");
	fromVertipadUID = getElement(missionNode, "fromVertipadUID");
	toVertipadUID = getElement(missionNode, "toVertipadUID");
	flightPathLongitudes = getElement(missionNode, "//longitude");
	flightPathLatitudes = getElement(missionNode, "//latitude");
	flightPath = Position::loadFromCsv(flightPathLongitudes, flightPathLatitudes);
	configuration = nConfiguration;
}

Vertipad* Mission::getFromVertipad()
{
	string uID = getFromVertipadUID();
	return configuration->getVertipad(uID);
}

Vertipad* Mission::getToVertipad()
{
	string uID = getToVertipadUID();
	return configuration->getVertipad(uID);
}

vector<Mission*> Mission::loadMissionsFromCpacs(const Node *cpacsNode, Configuration *nConfiguration)
{
	int numMissions;
	vector<Mission*> result;
	vector<Node*> missions = getNodes(cpacsNode, "//missions/mission", numMissions);
	result = vector<Mission*>(numMissions);
	for (int i = 0; i < numMissions; i++) {
		result[i] = new Mission(missions[i], nConfiguration);
	}
	return result;
}

string Mission::toString()
{
	ostringstream os;

	os << "[Mission " ;
	os << "uID=" << getUID();
	os << ", name=" << getName();
	os << ", fromVertipadUID=" << getFromVertipadUID();
	os << ", toVertipadUID=" << getToVertipadUID();
	os << ", flightPath=" << endl;
	os << Position::vectorToString(flightPath);
	os << "]" << endl;

	return os.str();
}


/*********************************** Class Trajectory **********************************/

CPACSTrajectory::CPACSTrajectory(const Node *trajectoryNode, Route* nRoute, Configuration* nConfiguration)
{
	string flightTimes;
	string latitues;
	string longitues;
	string altitudes;
	string distances;
	string energyConsumptions;

	uID = getAttribute(trajectoryNode, "@uID");

	flightTimes = getElement(trajectoryNode, "//flighttime");
	longitues   = getElement(trajectoryNode, "//longitude");
	latitues    = getElement(trajectoryNode, "//latitude");
	altitudes   = getElement(trajectoryNode, "//altitude");
	distances   = getElement(trajectoryNode, "//distance");
	energyConsumptions = getElement(trajectoryNode, "//energyConsumption");
	trajectory = Position::loadFromCsv(longitues, latitues, altitudes, flightTimes, distances, energyConsumptions);

	route = nRoute;
	configuration = nConfiguration;
}

vector<CPACSTrajectory*> CPACSTrajectory::loadTrajectoryFromCpacs(const Node* trajectoryNode, Route* route, Configuration* configuration)
{
	int numTrajectories;
	vector<CPACSTrajectory*> result;
	vector<Node*> trajectories = getNodes(trajectoryNode, "//trajectory", numTrajectories);
	result = vector<CPACSTrajectory*>(numTrajectories);
	for (int i = 0; i < numTrajectories; i++) {
		result[i] = new CPACSTrajectory(trajectories[i], route, configuration);
	}
	return result;
}

string CPACSTrajectory::toString()
{
	ostringstream os;

	os << "[Trajectory " ;
	os << "uID=" << getUID();
	os << endl << Position::vectorToString(getTrajectory());
	os << "]" << endl;

	return os.str();
}


/*********************************** Class Route **********************************/
Route::Route(const Node *routeNode, Fleet* nFleet, Configuration* nConfiguration)
{
	string referenceTrajectoryFlightTimes;
	string referenceTrajectoryLatitues;
	string referenceTrajectoryLongitues;
	string referenceTrajectoryAltitudes;
	string referenceTrajectoryDistances;
	string referenceTrajectoryEnergyConsumptions;

	uID             = getAttribute(routeNode, "@uID");
	modelUID        = getElement(routeNode, "modelUID");
	missionUID      = getElement(routeNode, "missionUID");
	frequency       = stoi(getElement(routeNode, "frequency"));
	utcStartingTime = getElement(routeNode, "utcStartingTime");

	trajectories = CPACSTrajectory::loadTrajectoryFromCpacs(routeNode, this, nConfiguration);

	/* Read from subelement referenceTrajectory> */
	referenceTrajectoryFlightTimes = getElement(routeNode, "//referenceTrajectory/flighttime");
	referenceTrajectoryLongitues   = getElement(routeNode, "//referenceTrajectory/longitude");
	referenceTrajectoryLatitues    = getElement(routeNode, "//referenceTrajectory/latitude");
	referenceTrajectoryAltitudes   = getElement(routeNode, "//referenceTrajectory/altitude");
	referenceTrajectoryDistances   = getElement(routeNode, "//referenceTrajectory/distance");
	referenceTrajectoryEnergyConsumptions = getElement(routeNode, "//referenceTrajectory/energyConsumption");
	referenceTrajectory = Position::loadFromCsv(referenceTrajectoryLongitues,
			                                                     referenceTrajectoryLatitues,
																 referenceTrajectoryAltitudes,
																 referenceTrajectoryFlightTimes,
																 referenceTrajectoryDistances,
																 referenceTrajectoryEnergyConsumptions
																);

	// To be added: Reading Data from referenceTrajectory/OperatingCost

	/* Read from subelement global */
	missionTime = stod(getElement(routeNode, "//global/MissionTime"));
	missionDistance = stod(getElement(routeNode, "//global/MissionDistance"));
	missionFL = stod(getElement(routeNode, "//global/MissionFL"));
	energyConsumption = stod(getElement(routeNode, "//global/energyConsumption"));
	//COC = stod(getElement(routeNode, "//global/COC"));
	//DOC = stod(getElement(routeNode, "//global/DOC"));

	fleet = nFleet;
	configuration = nConfiguration;
}

Route::~Route()
{
	for (CPACSTrajectory* trajectory: trajectories)
		delete trajectory;
}

Mission* Route::getMission()
{
	string uID = getMissionUID();
	return configuration->getMission(uID);
}

vector<Route*> Route::loadRoutesFromCpacs(const Node* routeNode, Fleet* fleet, Configuration* configuration)
{
	int numRoutes;
	vector<Route*> result;
	vector<Node*> routes = getNodes(routeNode, "//route", numRoutes);
	result = vector<Route*>(numRoutes);
	for (int i = 0; i < numRoutes; i++) {
		result[i] = new Route(routes[i], fleet, configuration);
	}
	return result;
}

string Route::toString(){
	ostringstream os;

	os << "[Route " ;
	os << "uID=" << getUID();
	os << ", modelUID=" << getModelUID();
	os << ", missionUID=" << getMissionUID();
	os << ", frequency=" << getFrequency();
	os << ", utcStartingTime=" << getUtcStartingTime();
	os << ", missionTime=" << getMissionTime();
	os << ", missionDistance=" << getMissionDistance();
	os << ", missionFL=" << getMissionFL();
	os << ", energyConsumption=" << getEnergyConsumption();
	os << ", COC=" << getCOC();
	os << ", DOC=" << getDOC();
	// os << endl << "referenceTrajectory=" << Position::vectorToString(getReferenceTrajectory());
	os << "]" << endl;

	return os.str();
}

/*********************************** Class Fleet **********************************/
Fleet::Fleet(const Node *fleetNode, Configuration* nConfiguration)
{
	uID = getAttribute(fleetNode, "@uID");
	routes = Route::loadRoutesFromCpacs(fleetNode, this, nConfiguration);
	configuration = nConfiguration;
}

Fleet::~Fleet()
{
	for (Route* route: routes)
		delete route;
}

vector<Fleet*> Fleet::loadFleetsFromCpacs(const Node *cpacsNode, Configuration* nConfiguration)
{
	int numFleets;
	vector<Fleet*> result;
	vector<Node*> fleets = getNodes(cpacsNode, "//fleets/fleet", numFleets);
	result = vector<Fleet*>(numFleets);
	for (int i = 0; i < numFleets; i++) {
		result[i] = new Fleet(fleets[i], nConfiguration);
	}
	return result;
}

string Fleet::toString()
{
	ostringstream os;
	vector<Route*> routes;

	os << "[Fleet " ;
	os << "uID=" << getUID();
	os << ", routes=" << endl;
	routes = getRoutes();
	for (Route* route: routes)
	{
		os << "  " << route->toString() << endl;
	}

	os << "]" << endl;

	return os.str();
}


/******************************** Class Configuration *******************************/
Configuration::Configuration(string cpacsFile)
{
	const Node *cpacsNode = loadXML(cpacsFile.c_str());
	vertiports = Vertiport::loadVertiportsFromCpacs(cpacsNode, this);
	missions = Mission::loadMissionsFromCpacs(cpacsNode, this);
	fleets = Fleet::loadFleetsFromCpacs(cpacsNode, this);

	delete cpacsNode;
}

Configuration::~Configuration()
{
	for (Vertiport* vertiport: vertiports)
		delete vertiport;

	for (Mission* mission: missions)
		delete mission;

	for (Fleet* fleet: fleets)
		delete fleet;
}

Vertiport* Configuration::getVertiport(string uID)
{
	for (Vertiport* vertiport: vertiports)
	{
		if (vertiport->getUID() == uID)
		{
			return vertiport;
		}
	}
	throw std::invalid_argument( "Received an invalid uID of a vertiport");
}

Vertipad* Configuration::getVertipad(string uID)
{
	for (Vertiport* vertiport: vertiports)
	{
		for (Vertipad* vertipad: vertiport->getVertipads())
		{
			if (vertipad->getUID() == uID)
			{
				return vertipad;
			}
		}
	}
	throw std::invalid_argument( "Received an invalid uID of a vertipad.");
}

Mission* Configuration::getMission(string uID)
{
	for (Mission* mission: missions)
	{
		if (mission->getUID() == uID)
		{
			return mission;
		}
	}
	throw std::invalid_argument( "Received an invalid uID of a mission.");
}

/* Cannot be used as uIDs of trajectories are not unique.
Trajectory* Configuration::getTrajectory(string uID)
{
	for (Fleet* fleet: fleets)
	{
		for (Route* route: fleet->getRoutes())
		{
			for (Trajectory* trajectory: route->getTrajectories())
			{
				if (trajectory->getUID() == uID)
				{
					return trajectory;
				}
			}
		}
	}
	throw std::invalid_argument( "Received an invalid uID of a trajectory.");
}
*/

Route* Configuration::getRoute(string uID)
{
	for (Fleet* fleet: fleets)
	{
		for (Route* route: fleet->getRoutes())
		{
			if (route->getUID() == uID)
			{
				return route;
			}
		}
	}
	throw std::invalid_argument( "Received an invalid uID of a route.");
}

Fleet* Configuration::getFleet(string uID)
{
	for (Fleet* fleet: fleets)
	{
		if (fleet->getUID() == uID)
		{
			return fleet;
		}
	}
	throw std::invalid_argument( "Received an invalid uID of a fleet.");
}
