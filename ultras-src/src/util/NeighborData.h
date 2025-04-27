/**
 *
 * @brief Class for neighbor list
 * message generation at the wireless
 * interface of the air taxi
 *
 *
 *
 * @author Shashini Wanniarachchi
 * Contact: shashini.wanniarachchi@tuhh.de
 *
 */

#ifndef UTIL_NEIGHBORDATA_H_
#define UTIL_NEIGHBORDATA_H_

#include <omnetpp.h>
#include "DataTypes/StateDataTypes.h"

using namespace inet;

/**
 * Generating neighbor list messages
 *
 */
class NeighborData: public omnetpp::cNamedObject {

public:
    std::vector< StateWithCovariance > neighborlist;                        ///< vector neighbor state
    NeighborData(){};                                                       ///<Constructor
    NeighborData(std::vector<StateWithCovariance> &neighborlist): neighborlist(neighborlist){};
    virtual NeighborData *dup() const override  {return new NeighborData(*this);}
};



#endif /* UTIL_NEIGHBORDATA_H_ */
