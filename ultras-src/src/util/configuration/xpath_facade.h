/*
 * xpath_facade.h
 *
 * Simple facade to read data from XML files using XPath
 *
 * Created on: 22.02.2021
 * Author: Marcus Venzke
 */

#ifndef XPATH_FACADE_H_
#define XPATH_FACADE_H_

#include "tinyxpath/tinyxml.h"
#include "tinyxpath/xpath_processor.h"
#include "tinyxpath/xpath_static.h"

using namespace std;
using namespace TinyXPath;

#define Node TiXmlNode

Node* loadXML(const char* filename);
vector<Node*> getNodes(const Node *node, const char *xPathExpression, int &numResults);
string getAttribute(const Node* node, const char *xPathExpression);
string getElement(const Node* node, const char *xPathExpression);



#endif /* XPATH_FACADE_H_ */
