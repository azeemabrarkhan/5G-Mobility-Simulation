#ifndef MODULES_COMMUNICATION_NR_APPLICATION_TESTRECEIVERAPP_H_
#define MODULES_COMMUNICATION_NR_APPLICATION_TESTRECEIVERAPP_H_

#include <string.h>
#include <omnetpp.h>

#include <inet/networklayer/common/L3AddressResolver.h>
#include <inet/transportlayer/contract/udp/UdpSocket.h>
#include "TestSenderAppPacket_m.h"

class TestReceiverApp : public omnetpp::cSimpleModule
{
    inet::UdpSocket socket;

    omnetpp::simsignal_t deliveryDelay_;

  protected:

    virtual int numInitStages() const override { return inet::NUM_INIT_STAGES; }
    void initialize(int stage) override;
    void handleMessage(omnetpp::cMessage *msg) override;


};



#endif /* MODULES_COMMUNICATION_NR_APPLICATION_TESTRECEIVERAPP_H_ */
