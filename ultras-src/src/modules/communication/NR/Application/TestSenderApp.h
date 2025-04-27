
#ifndef MODULES_COMMUNICATION_NR_APPLICATION_TESTSENDERAPP_H_
#define MODULES_COMMUNICATION_NR_APPLICATION_TESTSENDERAPP_H_

#include <string.h>
#include <omnetpp.h>
#include <inet/transportlayer/contract/udp/UdpSocket.h>
#include <inet/networklayer/common/L3Address.h>
#include <inet/networklayer/common/L3AddressResolver.h>
#include "TestSenderAppPacket_m.h"

class TestSenderApp : public omnetpp::cSimpleModule
{
    inet::UdpSocket socket;

    //sender
    int size_;

    omnetpp::simtime_t stopTime_;
    omnetpp::cMessage *selfSender_;

    int localPort_;
    int destPort_;
    inet::L3Address destAddress_;

    void sendTestSenderAppPacket();

  public:
    ~TestSenderApp();
    TestSenderApp();

  protected:

    virtual int numInitStages() const override { return inet::NUM_INIT_STAGES; }
    void initialize(int stage) override;
    void handleMessage(omnetpp::cMessage *msg) override;

};



#endif /* MODULES_COMMUNICATION_NR_APPLICATION_TESTSENDERAPP_H_ */
