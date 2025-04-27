/*
 * ultras_dynamic_configuration.h
 *
 * Definitions of the configuration of the dymamic simulator of ULTRAS projekt.
 * The definition is loaded from a CPACS file.
 *
 * Created on: 22.02.2021
 * Author: Marcus Venzke
 */

#ifndef ULTRAS_DYNAMIC_CONFIGURATION_H_
#define ULTRAS_DYNAMIC_CONFIGURATION_H_

#include <limits>
#include <string>
#include <vector>
#include "xpath_facade.h"

using namespace std;

class Vertiport;
class Route;
class Fleet;
class Configuration;

/********************************* Support functions **********************************/

/**
 * Reads a CSV-String of floats and returns it as a vector.
 *
 * It uses Space, Comma or Semicolon as seperator character.
 */
vector<double> doubleVectorFromCSVString(string s);

/********************************* Class Position3D **********************************/
class Position
{
	public:
		Position(double nLongitude = numeric_limits<double>::quiet_NaN(),
		         double nLatitude  = numeric_limits<double>::quiet_NaN(),
		         double nElevation = numeric_limits<double>::quiet_NaN(),
		         double nTime      = numeric_limits<double>::quiet_NaN(),
		         double nDistance  = numeric_limits<double>::quiet_NaN(),
		         double nEnergyConsumption = numeric_limits<double>::quiet_NaN());
		inline double getLongitude() {return longitude;}
		inline void setLongitude(double nLongitude) {longitude = nLongitude;}
		inline double getLatitude() {return latitude;}
		inline void setLatitude(double nLatitude) {latitude = nLatitude;}
		inline double getElevation() {return elevation;}
		inline void setElevation(double nElevation) {elevation = nElevation;}
		inline double getTime() {return time;}
		inline void setTime(double nTime) {time = nTime;}
		inline double getDistance() {return distance;}
		inline void setDistance(double nDistance) {distance = nDistance;}
		inline double getEnergyConsumption() {return energyConsumption;}
		inline void setEnergyConsumption(double nEnergyConsumption) {energyConsumption = nEnergyConsumption;}
		string toString();
		static vector<Position> loadFromCsv(string longitudes, string latitudes, string elevations="", string times="", string distances="", string energyConsumptions="");
		static string vectorToString(vector<Position> positions);
	private:
		double longitude; // In degreases north
		double latitude; // In degreases east
		double elevation; // in meter
		double time;      // in second of the day
		double distance;  // in meter
		double energyConsumption; // in kWh
};

/********************************* Class Vertipad **********************************/
class Vertipad
{
public:
	Vertipad(const Node *vertpadNode, Vertiport *nVertiport, Configuration* nConfiguration); // Loads a vertipad fron a vertipad element node.
	inline string getUID(){return uID;}
	inline string getName(){return name;}
	inline Position getPosition(){return position;}
	inline Vertiport* getVertiport(){return vertiport;}
	static vector<Vertipad*> loadVertipadsFromCpacs(const Node* vertiportNode, Vertiport* vertiport, Configuration* nConfiguration);
	string toString();
private:
	string uID;
	string name;
	Position position;
	Vertiport *vertiport;
	Configuration *configuration;
};

/********************************* Class Vertiport **********************************/
class Vertiport
{
public:
	Vertiport(const Node *vertiportNode, Configuration* nConfiguration); // Loads a vertiport fron a vertiport element node.
	~Vertiport();
	inline string getUID(){return uID;}
	inline string getName(){return name;}
	inline Position getPosition(){return position;}
	inline int getCapacity(){return capacity;}
	inline vector<Vertipad*> getVertipads() {return vertipads;}
	static vector<Vertiport*> loadVertiportsFromCpacs(const Node *cpacsNode, Configuration* nConfiguration);
	string toString();
private:
	string uID;
	string name;
	Position position;
	int capacity;    // movements / h
	vector<Vertipad*> vertipads;
	Configuration* configuration;
};

/*********************************** Class Mission **********************************/

class Mission
{
public:
	Mission(const Node *missionNode, Configuration* nConfiguration);
	inline string getUID(){return uID;}
	inline string getName(){return name;}
	inline string getFromVertipadUID(){return fromVertipadUID;}
	inline string getToVertipadUID(){return toVertipadUID;}
	Vertipad* getFromVertipad();
	Vertipad* getToVertipad();
	inline vector<Position> getFlightPath() {return flightPath;}
	static vector<Mission*> loadMissionsFromCpacs(const Node *cpacsNode, Configuration* nConfiguration);
	string toString();
private:
	string uID;
	string name;
	string fromVertipadUID;
	string toVertipadUID;
	vector<Position> flightPath;
	Configuration* configuration;
};


/*********************************** Class Trajectory **********************************/
class CPACSTrajectory
{
public:
	CPACSTrajectory(const Node *trajectoryNode, Route* nRoute, Configuration* nConfiguration);
	inline string getUID() {return uID;}
	inline vector<Position> getTrajectory() {return trajectory;}
	inline Route* getRoute() {return route;}
	static vector<CPACSTrajectory*> loadTrajectoryFromCpacs(const Node* trajectoryNode, Route* route, Configuration* configuration);
	string toString();
private:
	string uID;
	vector<Position> trajectory;
	Route* route;
	Configuration *configuration;
};

/*********************************** Class Route **********************************/
class Route
{
public:
	Route(const Node *routeNode, Fleet* nFleet, Configuration* nConfiguration);
	~Route();
	inline string getUID() {return uID;}
	inline string getModelUID() {return modelUID;}
	inline string getMissionUID() {return missionUID;}
	Mission* getMission();
	inline int    getFrequency() {return frequency;}
	inline string getUtcStartingTime() {return utcStartingTime;}
	inline vector<CPACSTrajectory*> getTrajectories() {return trajectories;}
	inline vector<Position> getReferenceTrajectory() {return referenceTrajectory;}
	inline double getMissionTime() {return missionTime;} // seconds
	inline double getMissionDistance() {return missionDistance;} // meter
	inline double getMissionFL() {return missionFL;} // meter
	inline double getEnergyConsumption() {return energyConsumption;} // kWh
	inline double getCOC() {return COC;} // $/cyc
	inline double getDOC() {return DOC;} // $/cyc
	inline Fleet* getFleet() {return fleet;}
	static vector<Route*> loadRoutesFromCpacs(const Node* routeNode, Fleet* fleet, Configuration* configuration);
	string toString();
private:
	string uID;
	string modelUID;
	string missionUID;
	int frequency;    // In flight per day.
	string utcStartingTime;
	vector<CPACSTrajectory*> trajectories;
	/* from subelement referenceTrajectory> */
	vector<Position> referenceTrajectory;
	// To be added: Data from referenceTrajectory/OperatingCost
	/* from subelement global */
	double missionTime; // seconds
	double missionDistance; // meter
	double missionFL; // meter
	double energyConsumption; // kWh
	double COC; // $/cyc
	double DOC; // $/cyc
	Fleet* fleet;
	Configuration *configuration;
};


/*********************************** Class Fleet **********************************/
class Fleet
{
public:
	Fleet(const Node *fleetNode, Configuration* nConfiguration);
	~Fleet();
	inline string getUID() {return uID;}
	inline vector<Route*> getRoutes() {return routes;}
	static vector<Fleet*> loadFleetsFromCpacs(const Node *cpacsNode, Configuration* nConfiguration);
	string toString();
private:
	string uID;
	vector<Route*> routes;
	Configuration* configuration;
};


/******************************** Class Configuration *******************************/

class Configuration
{
public:
	Configuration(string cpacsFile);
	~Configuration();
	inline vector<Vertiport*> getVertiports() {return vertiports;}
	inline vector<Mission*>   getMissions() {return missions;}
	inline vector<Fleet*>     getFleets() {return fleets;}
	Vertipad*   getVertipad(string uID);
	Vertiport*  getVertiport(string uID);
	// Trajectory* getTrajectory(string uID); Cannot be used as uIDs of trajectories are not unique.
	Mission*    getMission(string uID);
	Route*      getRoute(string uID);
	Fleet*      getFleet(string uID);
private:
	vector<Vertiport*> vertiports;
	vector<Mission*>   missions;
	vector<Fleet*>     fleets;
};


#endif /* ULTRAS_DYNAMIC_CONFIGURATION_H_ */
