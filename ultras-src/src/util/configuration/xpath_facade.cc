//============================================================================
// Name        : xpath_facade.cpp
// Author      : Marcus Venzke
// Version     :
// Description : Facade tpo tinyXPath / tinyXML to query data from XML files.
//============================================================================

#include <iostream>
#include <vector>
#include "xpath_facade.h"

using namespace std;
using namespace TinyXPath;

#define Node TiXmlNode

Node* loadXML(const char* filename) {
	TiXmlDocument* doc = new TiXmlDocument(filename);
	bool loadOK = doc->LoadFile();
	if (!loadOK) {
		throw std::runtime_error("Could open/read XML file.");
	}
	return doc->RootElement();
}

vector<Node*> getNodes(const Node *node, const char *xPathExpression, int &numResults) {
	xpath_processor *xp = new xpath_processor(node, xPathExpression);
	numResults = xp->u_compute_xpath_node_set(); // Number of results of the xPath expression

	vector<Node*> result = vector<Node*>(numResults); // Resulting vector of this function

	for (int i = 0; i < numResults; i++) {
		result[i] = xp->XNp_get_xpath_node(i);
	}
	delete xp;
	return result;
}

string getAttribute(const Node* node, const char *xPathExpression) {
	TIXML_STRING res = S_xpath_string(node, xPathExpression);
	return res.c_str();
}

string getElement(const Node* node, const char *xPathExpression) {
	int numResults;
	vector<Node*> nodes = getNodes(node, xPathExpression, numResults);
	if (numResults <= 0) {
		return "";
	} else {
		if (nodes[0]->Type() == Node::NodeType::ELEMENT) { // element
			return nodes[0]->ToElement()->GetText();
		} else { // Not an element
			return nodes[0]->Value();
		}
	}
}

/*  // Test code.
int main() {
    int numMissions;
	const Node *cpacs = loadXML("toolInput/toolInput.xml");

	cout << "From: " << getElement(cpacs, "//vertiports/vertiport[@uID='Altona-Altstadt_vertiport1']/name") << endl;
	cout << endl;

	vector<Node*> missions = getNodes(cpacs, "//missions/mission", numMissions);
	cout << "Number of missions: " <<  numMissions << endl;
	cout << endl;

	for (int i = 0; i < numMissions; i++) {
		Node *m = missions[i];
		cout << "Mission Name: " << getElement(m, "name") << endl;
		cout << "from:" << getElement(m, "fromVertipadUID") << endl;
		cout << "to:" << getElement(m, "toVertipadUID") << endl;
		cout << "lats:" << getElement(m, "//flightPath/latitude") << endl;
		cout << "lons:" << getElement(m, "//longitude") << endl;

		cout << "-------------------" << endl;
 	}

	cout << "End" << endl;
	delete cpacs;
}
*/
