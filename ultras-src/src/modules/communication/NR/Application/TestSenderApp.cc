#include <inet/common/ModuleAccess.h>
#include <inet/common/TimeTag_m.h>

#include "TestSenderApp.h"


Define_Module(TestSenderApp);

using namespace inet;

TestSenderApp::TestSenderApp()
{
    selfSender_ = nullptr;
}

TestSenderApp::~TestSenderApp()
{
    cancelAndDelete(selfSender_);
}

void TestSenderApp::initialize(int stage)
{
    EV << "TestSenderApp::initialize - stage " << stage << endl;

    cSimpleModule::initialize(stage);

    // avoid multiple initializations
    if (stage!=inet::INITSTAGE_APPLICATION_LAYER)
        return;

    selfSender_ = new cMessage("selfSender");

    size_ = par("packetSize");
    localPort_ = par("localPort");
    destPort_ = par("destPort");
    destAddress_ = inet::L3AddressResolver().resolve(par("destAddress").stringValue());

    socket.setOutputGate(gate("socketOut"));
    socket.bind(localPort_);

    EV << "TestSenderApp::initialize - binding to port: local:" << localPort_ << " , dest:" << destPort_ << endl;

    //traffic starting time
    simtime_t startTime = par("startTime");
    stopTime_ = par("stopTime");

    simtime_t offset = startTime + simTime();

    scheduleAt(offset ,selfSender_);
    EV << "\t starting traffic in " << offset << " seconds " << endl;
}

void TestSenderApp::handleMessage(cMessage *msg)
{
    if (msg->isSelfMessage())
    {
        if (!strcmp(msg->getName(), "selfSender"))
            sendTestSenderAppPacket();
        else
            throw cRuntimeError("TestSenderApp::handleMessage - Unrecognized self message");
    }
}

void TestSenderApp::sendTestSenderAppPacket()
{
    Packet* packet = new inet::Packet("TestSenderAppPacket");

    auto testsenderapppacket = makeShared<TestSenderAppPacket>();
    testsenderapppacket ->setPayloadTimestamp(simTime());
    testsenderapppacket->setChunkLength(B(size_));
    testsenderapppacket->addTag<CreationTimeTag>()->setCreationTime(simTime());

    packet->insertAtBack(testsenderapppacket);

    EV << "TestSenderAppPacket::sendPacket - Sending message \n";

    socket.sendTo(packet, destAddress_, destPort_);

    simtime_t d = simTime() + par("period");
    if (stopTime_ <= SIMTIME_ZERO || d < stopTime_) {
        scheduleAt(d, selfSender_);
    }
    else
        EV << "TestSenderAppPacket::sendTestPacket - Stop time reached, stopping transmissions" << endl;
}




