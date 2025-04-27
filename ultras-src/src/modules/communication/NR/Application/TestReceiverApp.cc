#include "TestReceiverApp.h"


Define_Module(TestReceiverApp);
using namespace inet;

void TestReceiverApp::initialize(int stage)
{
    cSimpleModule::initialize(stage);

    if (stage != inet::INITSTAGE_APPLICATION_LAYER)
        return;

    int port = par("localPort");
    EV << "TestReceiverApp::initialize - binding to port: local:" << port << endl;
    if (port != -1)
    {
        socket.setOutputGate(gate("socketOut"));
        socket.bind(port);
    }

    deliveryDelay_ = registerSignal("deliveryDelay");

}

void TestReceiverApp::handleMessage(cMessage *msg)
{
    if (msg->isSelfMessage())
        return;

    Packet* pPacket = check_and_cast<Packet*>(msg);

    // read msg
    auto testsenderapppacket = pPacket->popAtFront<TestSenderAppPacket>();

    // emit statistics
    simtime_t delay = simTime() - testsenderapppacket->getPayloadTimestamp();
    emit(deliveryDelay_, delay);


    EV << "TestReceiverApp::handleMessage - Packet received Delay[" << delay << "]" << endl;

    delete msg;
}




