#include <stdio.h>
#include <omnetpp.h>
#include <inet/common/packet/Packet.h>
#include "inet/applications/udpapp/UdpBasicApp.h"

using namespace inet;

class virusApp : public inet::UdpBasicApp {

    protected:
        enum SelfMsgKinds { START = 1, SEND, STOP, INFECTION, SICKNESS};
        char condition[20];
        simtime_t timeWhenInfected;
        simtime_t timeWhenSick;

        static int totalVirusTransmissions;

        virtual void initialize(int stage) override;
        virtual void processSend() override;
        virtual void processPacket(Packet *pk) override;     
        virtual void processInfection();
        virtual void processSickness();
        virtual void handleMessageWhenUp(cMessage *msg) override;
        virtual void finish() override;
};

int virusApp::totalVirusTransmissions = 0;

Define_Module(virusApp);

void virusApp::initialize(int stage) {
    UdpBasicApp::initialize(stage);

    if(par("hasVirus"))
        sprintf(condition, "sick");

    timeWhenInfected = par("timeWhenInfected");
    timeWhenSick = par("timeWhenSick");             
}

void virusApp::processSend() {
    if (!(strcmp(condition, "sick") == 0))
        return;

    this->getParentModule()->bubble("Sick!");

    double transmit = par("transmit"); //default exponential distributed
    if(transmit<=2) { //default probability is 0.86
        totalVirusTransmissions++;
        EV_INFO << "Total number of virus transmissios: " << totalVirusTransmissions << endl;
        UdpBasicApp::sendPacket();
    }

    if(par("hasVirus")) {
        selfMsg->setKind(SICKNESS);
        scheduleAt(timeWhenSick+simTime(), selfMsg);
    }
}

void virusApp::processPacket(Packet *pk) {
    if (strcmp(condition, "dead") == 0) {
        this->getParentModule()->bubble("Already Dead!");
        return;
    }

    if (strcmp(condition, "sick") == 0) {
        this->getParentModule()->bubble("Already Sick!");
        return;
    }

    emit(packetReceivedSignal, pk);    
    delete pk;
    numReceived++;

    if (strcmp(condition, "recovered") == 0) {
        this->getParentModule()->bubble("Already Recovered!");
        return;    
    }

    double infectedOrHealthy = par("infectedOrHealthy"); //default beta distribution
    if(infectedOrHealthy<=0.61) {   //default probability is 0.85

        EV_INFO << "Infected!" << endl;
        sprintf(condition, "infected");
        this->getParentModule()->bubble("Infected!");
        
        selfMsg->setKind(INFECTION);
        scheduleAt(timeWhenInfected+simTime(), selfMsg);

    } else {
        EV_INFO << "Healthy!" << endl;
        sprintf(condition, "healthy");
        this->getParentModule()->bubble("Remain Healthy!");
    }    
}

void virusApp::processInfection() {
    double sickOrRecover = par("sickOrRecover"); // default Cauchy distribution
    if(sickOrRecover<=4.13) { //default probability is 0.9
        EV_INFO << "Sick!" << endl;
        sprintf(condition, "sick");
        processSend();

        selfMsg->setKind(SICKNESS);
        scheduleAt(timeWhenSick+simTime(), selfMsg);

        } else {
            EV_INFO << "Recovered!" << endl;
            sprintf(condition, "recovered");
            this->getParentModule()->bubble("Recovered!");
        }
}

void virusApp::processSickness(){
    double dieOrRecover = par("dieOrRecover"); // default Uniform distribution
    if(dieOrRecover<=0.5) { //default probability is 0.5
        EV_INFO << "Dead!" << endl;
        sprintf(condition, "dead");
        this->getParentModule()->bubble("Dead!");

    } else {
        EV_INFO << "Recovered!" << endl;
        sprintf(condition, "recovered");
        this->getParentModule()->bubble("Recovered!");
    }
}

void virusApp::handleMessageWhenUp(cMessage *msg)
{
    if (msg->isSelfMessage()) {
        ASSERT(msg == selfMsg);
        switch (selfMsg->getKind()) {
            case START:
                processStart();
                break;

            case SEND:
                processSend();
                break;

            case STOP:
                processStop();
                break;

            case INFECTION:
                processInfection();
                break;

            case SICKNESS:
                processSickness();
                break;

            default:
                throw cRuntimeError("Invalid kind %d in self message", (int)selfMsg->getKind());
        }
    }
    else
        socket.processMessage(msg);
}

void virusApp::finish()  {
        recordScalar("totalVirusTransmissions", totalVirusTransmissions);
        UdpBasicApp::finish();
}



