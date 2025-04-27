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

#ifndef __INET_AGENTMOBILITY_H
#define __INET_AGENTMOBILITY_H

#include "inet/common/INETDefs.h"
#include "inet/mobility/base/MovingMobilityBase.h"
#include <omnetpp.h>
#include <string.h>
#include "util/DataTypes/StateDataTypes.h"
#include "modules/dynamics/VehicleDynamics.h"

using namespace omnetpp;

namespace inet {

/**
 * Agent mobility module.
 */
class AgentMobility : public MovingMobilityBase
{
  protected:
    double changeInterval;                      //!< update interval
    simtime_t nextChange;                       //!< time of next update
    VehicleDynamics * dynamicsModule = nullptr; //!< dynamics module

  protected:
    virtual int numInitStages() const override { return NUM_INIT_STAGES; }

    /** Initializes mobility model parameters.*/
    virtual void initialize(int stage) override;

    /** Move the host*/
    virtual void move() override;

    void updateState();

  public:
    AgentMobility();
    void setStationary(bool stationaryState);
    bool getStationary();
};

} // namespace inet

#endif // ifndef __INET_AGENTMOBILITY_H
