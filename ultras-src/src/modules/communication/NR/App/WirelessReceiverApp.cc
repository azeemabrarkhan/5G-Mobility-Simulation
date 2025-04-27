/*
 * WirelessRecieverApp.cc
 *
 *  Created on: Mar 24, 2022
 *      Author: cif7992
 */


#include "WirelessReceiverApp.h"


Define_Module(WirelessReceiverApp);
using namespace inet;

void WirelessReceiverApp::initialize(int stage)
{
    cSimpleModule::initialize(stage);

    if (stage != inet::INITSTAGE_APPLICATION_LAYER)
        return;

    int port = par("localPort");
    EV << "WirelessReceiverApp::initialize - binding to port: local:" << port << endl;
    if (port != -1)
    {
        socket.setOutputGate(gate("socketOut"));
        socket.bind(port);
    }

    deliveryDelay_ = registerSignal("deliveryDelay");

}

void WirelessReceiverApp::handleMessage(cMessage *msg)
{
    if (msg->isSelfMessage())
        return;

    Packet* pPacket = check_and_cast<Packet*>(msg);

    // read msg
    auto wirelessapppacket = pPacket->popAtFront<WirelessAppPacket>();

    // emit statistics
    simtime_t delay = simTime() - wirelessapppacket->getPayloadTimestamp();
    emit(deliveryDelay_, delay);


    EV << "WirelessReceiverApp::handleMessage - Packet received Delay[" << delay << "]" << endl;
    cModule *targetModule = getParentModule()->getSubmodule("LocalSituationPicture");
    sendDirect(msg, targetModule, "LSPradioIn");
}

