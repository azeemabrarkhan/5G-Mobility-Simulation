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


/**
 * @file LocalSituationPicture.cc
 *
 * @brief Class for simple module Local Situation picture
 *
 *
 *
 * @author Shashini Wanniarachchi
 * Contact: shashini.wanniarachchi@tuhh.de
 *
 */

#ifndef MODULES_LOCALSITUATIONPICTURE_H_
#define MODULES_LOCALSITUATIONPICTURE_H_

#include <omnetpp.h>
#include<stdio.h>
#include<string.h>

#include "util/DataTypes/StateDataTypes.h"
#include "LocalSensorFusion.h"
#include "messages/WirelessMsg_m.h"
#include "util/NeighborData.h"

using namespace omnetpp;

/**
 * Implementing the generation of a situation picture
 * locally in an air taxi
 *
 */
class LocalSituationPicture : public cSimpleModule
{

protected :
    StateWithCovariance state_lsp;    ///<current vehicle state;
    NeighborData *neighborState;      ///<neighbor state pointer to class NeighborData

    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;

public:

    /** (*Direct access method*)
     *
     * Return current state with covariance.
     * @return current state with covariance
     */
    StateWithCovariance getStateWithCovarianceLsp();

    /** (*Direct access method*)
     *
     * Return current state with covariance information
     *  of the neighbors to a considered air taxi
     * @return current state with covariance information
     * of the neighbors to a considered air taxi
     */
    NeighborData getNeighborData();

};



#endif /* MODULES_LOCALSITUATIONPICTURE_H_ */
