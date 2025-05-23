//
// Generated file, do not edit! Created by nedtool 5.6 from stack/mac/packet/LteMacPdu.msg.
//

#ifndef __LTEMACPDU_M_H
#define __LTEMACPDU_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0506
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



class LteMacPdu;
class MacControlElement;
class MacBsr;
#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/common/packet/Packet_m.h" // import inet.common.packet.Packet

#include "inet/common/packet/chunk/Chunk_m.h" // import inet.common.packet.chunk.Chunk

// cplusplus {{
   using namespace inet;
// }}

/**
 * Class generated from <tt>stack/mac/packet/LteMacPdu.msg:25</tt> by nedtool.
 * <pre>
 * class LteMacPdu extends inet::FieldsChunk
 * {
 *     \@customize(true);
 *     abstract inet::Packet sdu[];
 *     unsigned int headerLength = 0;
 *     // need separate macPduId (e.g. for feedback packets) since OMNET PDU id is automatically updated
 *     // whenever a new packet is created, e.g. when this PDU is duplicated
 *     long macPduId = 0;
 * 
 *     //#
 *     //# Follows a list of elements only present in
 *     //# the customized class (see LteMacPdu.h):
 *     //#
 *     //# MacSduList sduList;
 *     //# MacControlElementsList ceList;
 *     //#
 * }
 * </pre>
 *
 * LteMacPdu_Base is only useful if it gets subclassed, and LteMacPdu is derived from it.
 * The minimum code to be written for LteMacPdu is the following:
 *
 * <pre>
 * class LteMacPdu : public LteMacPdu_Base
 * {
 *   private:
 *     void copy(const LteMacPdu& other) { ... }

 *   public:
 *     LteMacPdu() : LteMacPdu_Base() {}
 *     LteMacPdu(const LteMacPdu& other) : LteMacPdu_Base(other) {copy(other);}
 *     LteMacPdu& operator=(const LteMacPdu& other) {if (this==&other) return *this; LteMacPdu_Base::operator=(other); copy(other); return *this;}
 *     virtual LteMacPdu *dup() const override {return new LteMacPdu(*this);}
 *     // ADD CODE HERE to redefine and implement pure virtual functions from LteMacPdu_Base
 * };
 * </pre>
 *
 * The following should go into a .cc (.cpp) file:
 *
 * <pre>
 * Register_Class(LteMacPdu)
 * </pre>
 */
class LteMacPdu_Base : public ::inet::FieldsChunk
{
  protected:
    unsigned int headerLength = 0;
    long macPduId = 0;

  private:
    void copy(const LteMacPdu_Base& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const LteMacPdu_Base&);
    // make constructors protected to avoid instantiation
    LteMacPdu_Base();
    LteMacPdu_Base(const LteMacPdu_Base& other);
    // make assignment operator protected to force the user override it
    LteMacPdu_Base& operator=(const LteMacPdu_Base& other);

  public:
    virtual ~LteMacPdu_Base();
    virtual LteMacPdu_Base *dup() const override {throw omnetpp::cRuntimeError("You forgot to manually add a dup() function to class LteMacPdu");}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual void setSduArraySize(size_t size) = 0;
    virtual size_t getSduArraySize() const = 0;
    virtual const inet::Packet& getSdu(size_t k) const = 0;
    virtual inet::Packet& getSduForUpdate(size_t k) { handleChange();return const_cast<inet::Packet&>(const_cast<LteMacPdu_Base*>(this)->getSdu(k));}
    virtual void setSdu(size_t k, const inet::Packet& sdu) = 0;
    virtual void insertSdu(const inet::Packet& sdu) = 0;
    virtual void insertSdu(size_t k, const inet::Packet& sdu) = 0;
    virtual void eraseSdu(size_t k) = 0;
    virtual unsigned int getHeaderLength() const;
    virtual void setHeaderLength(unsigned int headerLength);
    virtual long getMacPduId() const;
    virtual void setMacPduId(long macPduId);
};

/**
 * Class generated from <tt>stack/mac/packet/LteMacPdu.msg:46</tt> by nedtool.
 * <pre>
 * //
 * // Mac Control Element
 * //
 * class MacControlElement
 * {
 *     double timestamp;
 * }
 * </pre>
 */
class MacControlElement
{
  protected:
    double timestamp = 0;

  private:
    void copy(const MacControlElement& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const MacControlElement&);

  public:
    MacControlElement();
    MacControlElement(const MacControlElement& other);
    virtual ~MacControlElement();
    MacControlElement& operator=(const MacControlElement& other);
    virtual void parsimPack(omnetpp::cCommBuffer *b) const;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b);

    // field getter/setter methods
    virtual double getTimestamp() const;
    virtual void setTimestamp(double timestamp);
};

/**
 * Class generated from <tt>stack/mac/packet/LteMacPdu.msg:54</tt> by nedtool.
 * <pre>
 * //
 * // Mac Buffer Status Report
 * //
 * class MacBsr extends MacControlElement
 * {
 *     int size;
 * }
 * </pre>
 */
class MacBsr : public ::MacControlElement
{
  protected:
    int size = 0;

  private:
    void copy(const MacBsr& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const MacBsr&);

  public:
    MacBsr();
    MacBsr(const MacBsr& other);
    virtual ~MacBsr();
    MacBsr& operator=(const MacBsr& other);
    virtual void parsimPack(omnetpp::cCommBuffer *b) const;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b);

    // field getter/setter methods
    virtual int getSize() const;
    virtual void setSize(int size);
};

#endif // ifndef __LTEMACPDU_M_H

