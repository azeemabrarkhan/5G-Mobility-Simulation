/*
 * GroundStationApp.h
 *
 *  Created on: Mar 24, 2022
 *      Author: cif7992
 */

#ifndef MODULES_COMMUNICATION_NR_APP_GSSENDERAPP_H_
#define MODULES_COMMUNICATION_NR_APP_GSSENDERAPP_H_

#include <omnetpp.h>
#include<stdio.h>
#include<string.h>

#include <inet/transportlayer/contract/udp/UdpSocket.h>
#include <inet/networklayer/common/L3Address.h>
#include <inet/networklayer/common/L3AddressResolver.h>

#include "util/DataTypes/StateDataTypes.h"
#include "util/DataTypes/Images.h"
#include "util/AgentMobility.h"
#include "modules/vehicle/LocalSituationPicture.h"
#include "modules/planning/FlightScheduleManager.h"
#include "WirelessAppPacket_m.h"  //edit
//#include "messages/SensorMsg_m.h
#include "messages/CreationMsg_m.h"

using namespace omnetpp;
using namespace std;
using namespace inet;

class GSSenderApp: public omnetpp::cSimpleModule
{
    inet::UdpSocket socket;

    //sender
    int size_;

    simtime_t stopTime_;
    omnetpp::cMessage *selfSender_;

    int localPort_;
    int destPort_;
    bool sendImages_;
    Images* stringImages;
    inet::L3Address destAddress_;

    void sendWirelessAppPacket();
    void readData();

  private:
    simsignal_t dataSentSignal;
    simsignal_t dataSentSignalKbs;

  public:
    ~GSSenderApp();
    GSSenderApp();

  protected:
    StateWithCovariance state_current;     ///<current vehicle state
    long bytesSent;
    int numSent;
    int sentFrames;
    double numFrames;

    virtual int numInitStages() const override { return inet::NUM_INIT_STAGES; }
    void initialize(int stage) override;
    void handleMessage(omnetpp::cMessage *msg) override;
    void finish() override;

    logCoord * logcoord;

};



#endif /* MODULES_COMMUNICATION_NR_APP_GSSENDERAPP_H_ */
