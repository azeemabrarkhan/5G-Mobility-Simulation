/*
 * WirelessApp.h
 *
 *  Created on: Feb 16, 2022
 *      Author: cif7992
 */

#ifndef MODULES_COMMUNICATION_NR_APP_WIRELESSSENDERAPP_H_
#define MODULES_COMMUNICATION_NR_APP_WIRELESSSENDERAPP_H_

#include <omnetpp.h>
#include<stdio.h>
#include<string.h>

#include <inet/transportlayer/contract/udp/UdpSocket.h>
#include <inet/networklayer/common/L3Address.h>
#include <inet/networklayer/common/L3AddressResolver.h>

#include "util/DataTypes/StateDataTypes.h"
#include "modules/vehicle/LocalSituationPicture.h"
#include "WirelessAppPacket_m.h"

using namespace omnetpp;
using namespace std;
using namespace inet;

class AgentInfo;

class WirelessSenderApp: public omnetpp::cSimpleModule
{
    inet::UdpSocket socket;

    //sender
    int size_;

    omnetpp::simtime_t stopTime_;
    omnetpp::cMessage *selfSender_;

    int localPort_;
    int destPort_;
    inet::L3Address destAddress_;

    void sendWirelessAppPacket();
    void readAndLogData();

  public:
    ~WirelessSenderApp();
    WirelessSenderApp();

    inet :: Coord ownCoord;                             ///<position coordinates of own air taxi
    inet :: Coord neighCoord;                           ///<position coordinates of neighboring air taxis

  protected:
    logCoord * logcoord;
    double wirelessRange;
    StateWithCovariance state_current;     ///<current vehicle state
    NeighborData *neighborData;

    virtual int numInitStages() const override { return inet::NUM_INIT_STAGES; }
    void initialize(int stage) override;
    void handleMessage(omnetpp::cMessage *msg) override;
    virtual void sendNeighborData();

  private:

    AgentInfo *ownVehicleInfo;                           ///<pointer to class nodeInfo
    list<AgentInfo *> allVehicleInfoList;                ///<list for all the air taxi information
    list<AgentInfo *> NeighbourVehicleInfoList;          ///<list for neighboring air taxi information

};



#endif /* MODULES_COMMUNICATION_NR_APP_WIRELESSSENDERAPP_H_ */
