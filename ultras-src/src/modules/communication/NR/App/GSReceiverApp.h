/*
 * GSReceiverApp.h
 *
 *  Created on: Mar 25, 2022
 *      Author: cif7992
 */

#ifndef MODULES_COMMUNICATION_NR_APP_GSRECEIVERAPP_H_
#define MODULES_COMMUNICATION_NR_APP_GSRECEIVERAPP_H_

#include <string.h>
#include <omnetpp.h>

#include <inet/networklayer/common/L3AddressResolver.h>
#include <inet/transportlayer/contract/udp/UdpSocket.h>
#include "WirelessAppPacket_m.h"

class GSReceiverApp : public omnetpp::cSimpleModule
{
    inet::UdpSocket socket;
    omnetpp::simsignal_t deliveryDelay_;

  private:
    simsignal_t latencySingal;
    simsignal_t dataReceivedSignal;
    simsignal_t dataReceivedSignalKbs;

  protected:
  	long numReceived;
  	double latency;
  	double bytesReceived;
    virtual int numInitStages() const override { return inet::NUM_INIT_STAGES; }
    void initialize(int stage) override;
    void handleMessage(omnetpp::cMessage *msg) override;
    void finish() override;

};



#endif /* MODULES_COMMUNICATION_NR_APP_GSRECEIVERAPP_H_ */
