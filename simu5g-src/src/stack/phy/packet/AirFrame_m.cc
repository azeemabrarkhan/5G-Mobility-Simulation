//
// Generated file, do not edit! Created by nedtool 5.6 from stack/phy/packet/AirFrame.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include "AirFrame_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

namespace {
template <class T> inline
typename std::enable_if<std::is_polymorphic<T>::value && std::is_base_of<omnetpp::cObject,T>::value, void *>::type
toVoidPtr(T* t)
{
    return (void *)(static_cast<const omnetpp::cObject *>(t));
}

template <class T> inline
typename std::enable_if<std::is_polymorphic<T>::value && !std::is_base_of<omnetpp::cObject,T>::value, void *>::type
toVoidPtr(T* t)
{
    return (void *)dynamic_cast<const void *>(t);
}

template <class T> inline
typename std::enable_if<!std::is_polymorphic<T>::value, void *>::type
toVoidPtr(T* t)
{
    return (void *)static_cast<const void *>(t);
}

}


// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule to generate operator<< for shared_ptr<T>
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const std::shared_ptr<T>& t) { return out << t.get(); }

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// operator<< for std::vector<T>
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');

    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

class inet__CoordDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    inet__CoordDescriptor();
    virtual ~inet__CoordDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(inet__CoordDescriptor)

inet__CoordDescriptor::inet__CoordDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Coord)), "")
{
    propertynames = nullptr;
}

inet__CoordDescriptor::~inet__CoordDescriptor()
{
    delete[] propertynames;
}

bool inet__CoordDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<inet::Coord *>(obj)!=nullptr;
}

const char **inet__CoordDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "existingClass",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *inet__CoordDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname, "existingClass")) return "";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int inet__CoordDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int inet__CoordDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *inet__CoordDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int inet__CoordDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *inet__CoordDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **inet__CoordDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *inet__CoordDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int inet__CoordDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    inet::Coord *pp = (inet::Coord *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *inet__CoordDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    inet::Coord *pp = (inet::Coord *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string inet__CoordDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    inet::Coord *pp = (inet::Coord *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool inet__CoordDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    inet::Coord *pp = (inet::Coord *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *inet__CoordDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *inet__CoordDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    inet::Coord *pp = (inet::Coord *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class ModulationTypeDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    ModulationTypeDescriptor();
    virtual ~ModulationTypeDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(ModulationTypeDescriptor)

ModulationTypeDescriptor::ModulationTypeDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(ModulationType)), "")
{
    propertynames = nullptr;
}

ModulationTypeDescriptor::~ModulationTypeDescriptor()
{
    delete[] propertynames;
}

bool ModulationTypeDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<ModulationType *>(obj)!=nullptr;
}

const char **ModulationTypeDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "existingClass",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *ModulationTypeDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname, "existingClass")) return "";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int ModulationTypeDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int ModulationTypeDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *ModulationTypeDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int ModulationTypeDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *ModulationTypeDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **ModulationTypeDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *ModulationTypeDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int ModulationTypeDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    ModulationType *pp = (ModulationType *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *ModulationTypeDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ModulationType *pp = (ModulationType *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string ModulationTypeDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ModulationType *pp = (ModulationType *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool ModulationTypeDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    ModulationType *pp = (ModulationType *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *ModulationTypeDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *ModulationTypeDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    ModulationType *pp = (ModulationType *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(AirFrame)

AirFrame::AirFrame(const char *name, short kind) : ::omnetpp::cPacket(name, kind)
{
}

AirFrame::AirFrame(const AirFrame& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

AirFrame::~AirFrame()
{
}

AirFrame& AirFrame::operator=(const AirFrame& other)
{
    if (this == &other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void AirFrame::copy(const AirFrame& other)
{
    this->pSend = other.pSend;
    this->channelNumber = other.channelNumber;
    this->duration = other.duration;
    this->bitrate = other.bitrate;
    this->snr = other.snr;
    this->lossRate = other.lossRate;
    this->powRec = other.powRec;
    this->senderPos = other.senderPos;
    this->carrierFrequency = other.carrierFrequency;
    this->bandwidth = other.bandwidth;
    this->modulationType = other.modulationType;
}

void AirFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->pSend);
    doParsimPacking(b,this->channelNumber);
    doParsimPacking(b,this->duration);
    doParsimPacking(b,this->bitrate);
    doParsimPacking(b,this->snr);
    doParsimPacking(b,this->lossRate);
    doParsimPacking(b,this->powRec);
    doParsimPacking(b,this->senderPos);
    doParsimPacking(b,this->carrierFrequency);
    doParsimPacking(b,this->bandwidth);
    doParsimPacking(b,this->modulationType);
}

void AirFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->pSend);
    doParsimUnpacking(b,this->channelNumber);
    doParsimUnpacking(b,this->duration);
    doParsimUnpacking(b,this->bitrate);
    doParsimUnpacking(b,this->snr);
    doParsimUnpacking(b,this->lossRate);
    doParsimUnpacking(b,this->powRec);
    doParsimUnpacking(b,this->senderPos);
    doParsimUnpacking(b,this->carrierFrequency);
    doParsimUnpacking(b,this->bandwidth);
    doParsimUnpacking(b,this->modulationType);
}

double AirFrame::getPSend() const
{
    return this->pSend;
}

void AirFrame::setPSend(double pSend)
{
    this->pSend = pSend;
}

int AirFrame::getChannelNumber() const
{
    return this->channelNumber;
}

void AirFrame::setChannelNumber(int channelNumber)
{
    this->channelNumber = channelNumber;
}

omnetpp::simtime_t AirFrame::getDuration() const
{
    return this->duration;
}

void AirFrame::setDuration(omnetpp::simtime_t duration)
{
    this->duration = duration;
}

double AirFrame::getBitrate() const
{
    return this->bitrate;
}

void AirFrame::setBitrate(double bitrate)
{
    this->bitrate = bitrate;
}

double AirFrame::getSnr() const
{
    return this->snr;
}

void AirFrame::setSnr(double snr)
{
    this->snr = snr;
}

double AirFrame::getLossRate() const
{
    return this->lossRate;
}

void AirFrame::setLossRate(double lossRate)
{
    this->lossRate = lossRate;
}

double AirFrame::getPowRec() const
{
    return this->powRec;
}

void AirFrame::setPowRec(double powRec)
{
    this->powRec = powRec;
}

const inet::Coord& AirFrame::getSenderPos() const
{
    return this->senderPos;
}

void AirFrame::setSenderPos(const inet::Coord& senderPos)
{
    this->senderPos = senderPos;
}

double AirFrame::getCarrierFrequency() const
{
    return this->carrierFrequency;
}

void AirFrame::setCarrierFrequency(double carrierFrequency)
{
    this->carrierFrequency = carrierFrequency;
}

double AirFrame::getBandwidth() const
{
    return this->bandwidth;
}

void AirFrame::setBandwidth(double bandwidth)
{
    this->bandwidth = bandwidth;
}

const ModulationType& AirFrame::getModulationType() const
{
    return this->modulationType;
}

void AirFrame::setModulationType(const ModulationType& modulationType)
{
    this->modulationType = modulationType;
}

class AirFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_pSend,
        FIELD_channelNumber,
        FIELD_duration,
        FIELD_bitrate,
        FIELD_snr,
        FIELD_lossRate,
        FIELD_powRec,
        FIELD_senderPos,
        FIELD_carrierFrequency,
        FIELD_bandwidth,
        FIELD_modulationType,
    };
  public:
    AirFrameDescriptor();
    virtual ~AirFrameDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(AirFrameDescriptor)

AirFrameDescriptor::AirFrameDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(AirFrame)), "omnetpp::cPacket")
{
    propertynames = nullptr;
}

AirFrameDescriptor::~AirFrameDescriptor()
{
    delete[] propertynames;
}

bool AirFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<AirFrame *>(obj)!=nullptr;
}

const char **AirFrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *AirFrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int AirFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 11+basedesc->getFieldCount() : 11;
}

unsigned int AirFrameDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_pSend
        FD_ISEDITABLE,    // FIELD_channelNumber
        0,    // FIELD_duration
        FD_ISEDITABLE,    // FIELD_bitrate
        FD_ISEDITABLE,    // FIELD_snr
        FD_ISEDITABLE,    // FIELD_lossRate
        FD_ISEDITABLE,    // FIELD_powRec
        FD_ISCOMPOUND,    // FIELD_senderPos
        FD_ISEDITABLE,    // FIELD_carrierFrequency
        FD_ISEDITABLE,    // FIELD_bandwidth
        FD_ISCOMPOUND,    // FIELD_modulationType
    };
    return (field >= 0 && field < 11) ? fieldTypeFlags[field] : 0;
}

const char *AirFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "pSend",
        "channelNumber",
        "duration",
        "bitrate",
        "snr",
        "lossRate",
        "powRec",
        "senderPos",
        "carrierFrequency",
        "bandwidth",
        "modulationType",
    };
    return (field >= 0 && field < 11) ? fieldNames[field] : nullptr;
}

int AirFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "pSend") == 0) return base+0;
    if (fieldName[0] == 'c' && strcmp(fieldName, "channelNumber") == 0) return base+1;
    if (fieldName[0] == 'd' && strcmp(fieldName, "duration") == 0) return base+2;
    if (fieldName[0] == 'b' && strcmp(fieldName, "bitrate") == 0) return base+3;
    if (fieldName[0] == 's' && strcmp(fieldName, "snr") == 0) return base+4;
    if (fieldName[0] == 'l' && strcmp(fieldName, "lossRate") == 0) return base+5;
    if (fieldName[0] == 'p' && strcmp(fieldName, "powRec") == 0) return base+6;
    if (fieldName[0] == 's' && strcmp(fieldName, "senderPos") == 0) return base+7;
    if (fieldName[0] == 'c' && strcmp(fieldName, "carrierFrequency") == 0) return base+8;
    if (fieldName[0] == 'b' && strcmp(fieldName, "bandwidth") == 0) return base+9;
    if (fieldName[0] == 'm' && strcmp(fieldName, "modulationType") == 0) return base+10;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *AirFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "double",    // FIELD_pSend
        "int",    // FIELD_channelNumber
        "omnetpp::simtime_t",    // FIELD_duration
        "double",    // FIELD_bitrate
        "double",    // FIELD_snr
        "double",    // FIELD_lossRate
        "double",    // FIELD_powRec
        "inet::Coord",    // FIELD_senderPos
        "double",    // FIELD_carrierFrequency
        "double",    // FIELD_bandwidth
        "ModulationType",    // FIELD_modulationType
    };
    return (field >= 0 && field < 11) ? fieldTypeStrings[field] : nullptr;
}

const char **AirFrameDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *AirFrameDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int AirFrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    AirFrame *pp = (AirFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *AirFrameDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    AirFrame *pp = (AirFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string AirFrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    AirFrame *pp = (AirFrame *)object; (void)pp;
    switch (field) {
        case FIELD_pSend: return double2string(pp->getPSend());
        case FIELD_channelNumber: return long2string(pp->getChannelNumber());
        case FIELD_duration: return simtime2string(pp->getDuration());
        case FIELD_bitrate: return double2string(pp->getBitrate());
        case FIELD_snr: return double2string(pp->getSnr());
        case FIELD_lossRate: return double2string(pp->getLossRate());
        case FIELD_powRec: return double2string(pp->getPowRec());
        case FIELD_senderPos: {std::stringstream out; out << pp->getSenderPos(); return out.str();}
        case FIELD_carrierFrequency: return double2string(pp->getCarrierFrequency());
        case FIELD_bandwidth: return double2string(pp->getBandwidth());
        case FIELD_modulationType: {std::stringstream out; out << pp->getModulationType(); return out.str();}
        default: return "";
    }
}

bool AirFrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    AirFrame *pp = (AirFrame *)object; (void)pp;
    switch (field) {
        case FIELD_pSend: pp->setPSend(string2double(value)); return true;
        case FIELD_channelNumber: pp->setChannelNumber(string2long(value)); return true;
        case FIELD_bitrate: pp->setBitrate(string2double(value)); return true;
        case FIELD_snr: pp->setSnr(string2double(value)); return true;
        case FIELD_lossRate: pp->setLossRate(string2double(value)); return true;
        case FIELD_powRec: pp->setPowRec(string2double(value)); return true;
        case FIELD_carrierFrequency: pp->setCarrierFrequency(string2double(value)); return true;
        case FIELD_bandwidth: pp->setBandwidth(string2double(value)); return true;
        default: return false;
    }
}

const char *AirFrameDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_senderPos: return omnetpp::opp_typename(typeid(inet::Coord));
        case FIELD_modulationType: return omnetpp::opp_typename(typeid(ModulationType));
        default: return nullptr;
    };
}

void *AirFrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    AirFrame *pp = (AirFrame *)object; (void)pp;
    switch (field) {
        case FIELD_senderPos: return toVoidPtr(&pp->getSenderPos()); break;
        case FIELD_modulationType: return toVoidPtr(&pp->getModulationType()); break;
        default: return nullptr;
    }
}

