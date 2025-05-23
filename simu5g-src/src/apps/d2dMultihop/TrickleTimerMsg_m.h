//
// Generated file, do not edit! Created by nedtool 5.6 from apps/d2dMultihop/TrickleTimerMsg.msg.
//

#ifndef __TRICKLETIMERMSG_M_H
#define __TRICKLETIMERMSG_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0506
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



class TrickleTimerMsg;
/**
 * Class generated from <tt>apps/d2dMultihop/TrickleTimerMsg.msg:13</tt> by nedtool.
 * <pre>
 * message TrickleTimerMsg
 * {
 *     uint32_t msgid;          // unique id of the message  < sender id  | local msg id >
 * }
 * </pre>
 */
class TrickleTimerMsg : public ::omnetpp::cMessage
{
  protected:
    uint32_t msgid = 0;

  private:
    void copy(const TrickleTimerMsg& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const TrickleTimerMsg&);

  public:
    TrickleTimerMsg(const char *name=nullptr, short kind=0);
    TrickleTimerMsg(const TrickleTimerMsg& other);
    virtual ~TrickleTimerMsg();
    TrickleTimerMsg& operator=(const TrickleTimerMsg& other);
    virtual TrickleTimerMsg *dup() const override {return new TrickleTimerMsg(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual uint32_t getMsgid() const;
    virtual void setMsgid(uint32_t msgid);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const TrickleTimerMsg& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, TrickleTimerMsg& obj) {obj.parsimUnpack(b);}

#endif // ifndef __TRICKLETIMERMSG_M_H

