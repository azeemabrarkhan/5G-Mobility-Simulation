/*
 * WirelessReceiverApp.h
 *
 *  Created on: Mar 24, 2022
 *      Author: cif7992
 */

#ifndef MODULES_COMMUNICATION_NR_APP_WIRELESSRECEIVERAPP_H_
#define MODULES_COMMUNICATION_NR_APP_WIRELESSRECEIVERAPP_H_

#include <string.h>
#include <omnetpp.h>

#include <inet/networklayer/common/L3AddressResolver.h>
#include <inet/transportlayer/contract/udp/UdpSocket.h>
#include "util/DataTypes/StateDataTypes.h"
#include "modules/vehicle/LocalSituationPicture.h"
#include "WirelessAppPacket_m.h"

class WirelessReceiverApp : public omnetpp::cSimpleModule
{
    inet::UdpSocket socket;

    omnetpp::simsignal_t deliveryDelay_;

  protected:

    StateWithCovariance state_received;

    virtual int numInitStages() const override { return inet::NUM_INIT_STAGES; }
    void initialize(int stage) override;
    void handleMessage(omnetpp::cMessage *msg) override;


};



#endif /* MODULES_COMMUNICATION_NR_APP_WIRELESSRECEIVERAPP_H_ */
