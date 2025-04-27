/*
 * ultras_dynamic_configuration_test.cpp
 *
 * Code for testing ultras_dynamic_configuration.h / ultras_dynamic_configuration.cpp.
 *
 * Created on: 22.02.2021
 * Author: ti5mv
 */

#include <iostream>
#include "ultras_dynamic_configuration.h"

int main_testcode_for_configuration()
{
	Configuration config = Configuration("toolInput/toolInput.xml");
	cout << "File has been loaded. " << endl;

	vector<Vertiport*> vertiports = config.getVertiports();
	cout << "Vertiports: " << vertiports.size() << endl;

	for (Vertiport* vertiport: vertiports)
	{
		// cout << vertiport.getName() << endl;
		cout << vertiport->toString();
		cout << "  -----------------------------" << endl;
	}

	cout << "====================================================" << endl;
	vector<Mission*> missions = config.getMissions();
	for (Mission* mission: missions)
	{
		cout << mission->toString();
		cout << "  -----------------------------" << endl;
	}
	cout << "====================================================" << endl;

	vector<Fleet*> fleets = config.getFleets();
	for (Fleet* fleet: fleets)
	{
		cout << fleet->toString();
		cout << "  -----------------------------" << endl;
	}

	cout << "====================================================" << endl;
	cout << "One Vertiport: " << config.getVertiport("Blankenese_vertiport1")->toString() << endl;
	cout << "----------------" << endl;
	Vertipad* v = config.getVertipad("HafenCity_vertiport1_vertipad1");
	cout << "One Vertipad: " << v->toString() << endl;
	cout << "Its Vertiport: " << v->getVertiport()->toString() << endl;

	cout << "====================================================" << endl;

	Mission* mission = config.getMission("mission7");
	cout << "One Mission : " << mission->toString() << endl;

	cout << "It's fromVertiport" << endl;
	cout << mission->getFromVertipad()->getVertiport()->toString() << endl;

	cout << "It's toVertiport" << endl;
	cout << mission->getToVertipad()->getVertiport()->toString() << endl;

	cout << "====================================================" << endl;

	// Fleet* fleet = config.getFleet("swarm_ID");
	// cout << "One Fleet: " << fleet->toString() << endl;

	Route* route = config.getRoute("HafenCity_vertiport1_vertipad1__to__Bergedorf_vertiport1_vertipad1");
	cout << "One Route: " << route->toString() << endl;

	CPACSTrajectory* trajectory = route->getTrajectories()[2];
	cout << "One Trajectory: " << trajectory->toString() << endl;

	cout << "====================================================" << endl;

}
