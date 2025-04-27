//
// Generated file, do not edit! Created by nedtool 5.6 from common/LteControlInfo.msg.
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
#include "LteControlInfo_m.h"

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

Register_Class(LteControlInfo)

LteControlInfo::LteControlInfo() : ::inet::TagBase()
{
}

LteControlInfo::LteControlInfo(const LteControlInfo& other) : ::inet::TagBase(other)
{
    copy(other);
}

LteControlInfo::~LteControlInfo()
{
}

LteControlInfo& LteControlInfo::operator=(const LteControlInfo& other)
{
    if (this == &other) return *this;
    ::inet::TagBase::operator=(other);
    copy(other);
    return *this;
}

void LteControlInfo::copy(const LteControlInfo& other)
{
    this->sourceId = other.sourceId;
    this->destId = other.destId;
    this->direction = other.direction;
    this->d2dTxPeerId = other.d2dTxPeerId;
    this->d2dRxPeerId = other.d2dRxPeerId;
    this->application = other.application;
    this->traffic = other.traffic;
    this->rlcType = other.rlcType;
    this->lcid = other.lcid;
    this->multicastGroupId = other.multicastGroupId;
}

void LteControlInfo::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::TagBase::parsimPack(b);
    doParsimPacking(b,this->sourceId);
    doParsimPacking(b,this->destId);
    doParsimPacking(b,this->direction);
    doParsimPacking(b,this->d2dTxPeerId);
    doParsimPacking(b,this->d2dRxPeerId);
    doParsimPacking(b,this->application);
    doParsimPacking(b,this->traffic);
    doParsimPacking(b,this->rlcType);
    doParsimPacking(b,this->lcid);
    doParsimPacking(b,this->multicastGroupId);
}

void LteControlInfo::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::TagBase::parsimUnpack(b);
    doParsimUnpacking(b,this->sourceId);
    doParsimUnpacking(b,this->destId);
    doParsimUnpacking(b,this->direction);
    doParsimUnpacking(b,this->d2dTxPeerId);
    doParsimUnpacking(b,this->d2dRxPeerId);
    doParsimUnpacking(b,this->application);
    doParsimUnpacking(b,this->traffic);
    doParsimUnpacking(b,this->rlcType);
    doParsimUnpacking(b,this->lcid);
    doParsimUnpacking(b,this->multicastGroupId);
}

uint16_t LteControlInfo::getSourceId() const
{
    return this->sourceId;
}

void LteControlInfo::setSourceId(uint16_t sourceId)
{
    this->sourceId = sourceId;
}

uint16_t LteControlInfo::getDestId() const
{
    return this->destId;
}

void LteControlInfo::setDestId(uint16_t destId)
{
    this->destId = destId;
}

unsigned short LteControlInfo::getDirection() const
{
    return this->direction;
}

void LteControlInfo::setDirection(unsigned short direction)
{
    this->direction = direction;
}

uint16_t LteControlInfo::getD2dTxPeerId() const
{
    return this->d2dTxPeerId;
}

void LteControlInfo::setD2dTxPeerId(uint16_t d2dTxPeerId)
{
    this->d2dTxPeerId = d2dTxPeerId;
}

uint16_t LteControlInfo::getD2dRxPeerId() const
{
    return this->d2dRxPeerId;
}

void LteControlInfo::setD2dRxPeerId(uint16_t d2dRxPeerId)
{
    this->d2dRxPeerId = d2dRxPeerId;
}

unsigned short LteControlInfo::getApplication() const
{
    return this->application;
}

void LteControlInfo::setApplication(unsigned short application)
{
    this->application = application;
}

unsigned short LteControlInfo::getTraffic() const
{
    return this->traffic;
}

void LteControlInfo::setTraffic(unsigned short traffic)
{
    this->traffic = traffic;
}

unsigned short LteControlInfo::getRlcType() const
{
    return this->rlcType;
}

void LteControlInfo::setRlcType(unsigned short rlcType)
{
    this->rlcType = rlcType;
}

uint16_t LteControlInfo::getLcid() const
{
    return this->lcid;
}

void LteControlInfo::setLcid(uint16_t lcid)
{
    this->lcid = lcid;
}

int32_t LteControlInfo::getMulticastGroupId() const
{
    return this->multicastGroupId;
}

void LteControlInfo::setMulticastGroupId(int32_t multicastGroupId)
{
    this->multicastGroupId = multicastGroupId;
}

class LteControlInfoDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_sourceId,
        FIELD_destId,
        FIELD_direction,
        FIELD_d2dTxPeerId,
        FIELD_d2dRxPeerId,
        FIELD_application,
        FIELD_traffic,
        FIELD_rlcType,
        FIELD_lcid,
        FIELD_multicastGroupId,
    };
  public:
    LteControlInfoDescriptor();
    virtual ~LteControlInfoDescriptor();

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

Register_ClassDescriptor(LteControlInfoDescriptor)

LteControlInfoDescriptor::LteControlInfoDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(LteControlInfo)), "inet::TagBase")
{
    propertynames = nullptr;
}

LteControlInfoDescriptor::~LteControlInfoDescriptor()
{
    delete[] propertynames;
}

bool LteControlInfoDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<LteControlInfo *>(obj)!=nullptr;
}

const char **LteControlInfoDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *LteControlInfoDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int LteControlInfoDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 10+basedesc->getFieldCount() : 10;
}

unsigned int LteControlInfoDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_sourceId
        FD_ISEDITABLE,    // FIELD_destId
        FD_ISEDITABLE,    // FIELD_direction
        FD_ISEDITABLE,    // FIELD_d2dTxPeerId
        FD_ISEDITABLE,    // FIELD_d2dRxPeerId
        FD_ISEDITABLE,    // FIELD_application
        FD_ISEDITABLE,    // FIELD_traffic
        FD_ISEDITABLE,    // FIELD_rlcType
        FD_ISEDITABLE,    // FIELD_lcid
        FD_ISEDITABLE,    // FIELD_multicastGroupId
    };
    return (field >= 0 && field < 10) ? fieldTypeFlags[field] : 0;
}

const char *LteControlInfoDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "sourceId",
        "destId",
        "direction",
        "d2dTxPeerId",
        "d2dRxPeerId",
        "application",
        "traffic",
        "rlcType",
        "lcid",
        "multicastGroupId",
    };
    return (field >= 0 && field < 10) ? fieldNames[field] : nullptr;
}

int LteControlInfoDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "sourceId") == 0) return base+0;
    if (fieldName[0] == 'd' && strcmp(fieldName, "destId") == 0) return base+1;
    if (fieldName[0] == 'd' && strcmp(fieldName, "direction") == 0) return base+2;
    if (fieldName[0] == 'd' && strcmp(fieldName, "d2dTxPeerId") == 0) return base+3;
    if (fieldName[0] == 'd' && strcmp(fieldName, "d2dRxPeerId") == 0) return base+4;
    if (fieldName[0] == 'a' && strcmp(fieldName, "application") == 0) return base+5;
    if (fieldName[0] == 't' && strcmp(fieldName, "traffic") == 0) return base+6;
    if (fieldName[0] == 'r' && strcmp(fieldName, "rlcType") == 0) return base+7;
    if (fieldName[0] == 'l' && strcmp(fieldName, "lcid") == 0) return base+8;
    if (fieldName[0] == 'm' && strcmp(fieldName, "multicastGroupId") == 0) return base+9;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *LteControlInfoDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16",    // FIELD_sourceId
        "uint16",    // FIELD_destId
        "unsigned short",    // FIELD_direction
        "uint16",    // FIELD_d2dTxPeerId
        "uint16",    // FIELD_d2dRxPeerId
        "unsigned short",    // FIELD_application
        "unsigned short",    // FIELD_traffic
        "unsigned short",    // FIELD_rlcType
        "uint16",    // FIELD_lcid
        "int32",    // FIELD_multicastGroupId
    };
    return (field >= 0 && field < 10) ? fieldTypeStrings[field] : nullptr;
}

const char **LteControlInfoDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_direction: {
            static const char *names[] = { "enum", "enum",  nullptr };
            return names;
        }
        case FIELD_application: {
            static const char *names[] = { "enum", "enum",  nullptr };
            return names;
        }
        case FIELD_traffic: {
            static const char *names[] = { "enum", "enum",  nullptr };
            return names;
        }
        case FIELD_rlcType: {
            static const char *names[] = { "enum", "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *LteControlInfoDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_direction:
            if (!strcmp(propertyname, "enum")) return "Direction";
            if (!strcmp(propertyname, "enum")) return "Direction";
            return nullptr;
        case FIELD_application:
            if (!strcmp(propertyname, "enum")) return "ApplicationType";
            if (!strcmp(propertyname, "enum")) return "ApplicationType";
            return nullptr;
        case FIELD_traffic:
            if (!strcmp(propertyname, "enum")) return "LteTrafficClass";
            if (!strcmp(propertyname, "enum")) return "LteTrafficClass";
            return nullptr;
        case FIELD_rlcType:
            if (!strcmp(propertyname, "enum")) return "LteRlcType";
            if (!strcmp(propertyname, "enum")) return "LteRlcType";
            return nullptr;
        default: return nullptr;
    }
}

int LteControlInfoDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    LteControlInfo *pp = (LteControlInfo *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *LteControlInfoDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LteControlInfo *pp = (LteControlInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string LteControlInfoDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LteControlInfo *pp = (LteControlInfo *)object; (void)pp;
    switch (field) {
        case FIELD_sourceId: return ulong2string(pp->getSourceId());
        case FIELD_destId: return ulong2string(pp->getDestId());
        case FIELD_direction: return enum2string(pp->getDirection(), "Direction");
        case FIELD_d2dTxPeerId: return ulong2string(pp->getD2dTxPeerId());
        case FIELD_d2dRxPeerId: return ulong2string(pp->getD2dRxPeerId());
        case FIELD_application: return enum2string(pp->getApplication(), "ApplicationType");
        case FIELD_traffic: return enum2string(pp->getTraffic(), "LteTrafficClass");
        case FIELD_rlcType: return enum2string(pp->getRlcType(), "LteRlcType");
        case FIELD_lcid: return ulong2string(pp->getLcid());
        case FIELD_multicastGroupId: return long2string(pp->getMulticastGroupId());
        default: return "";
    }
}

bool LteControlInfoDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    LteControlInfo *pp = (LteControlInfo *)object; (void)pp;
    switch (field) {
        case FIELD_sourceId: pp->setSourceId(string2ulong(value)); return true;
        case FIELD_destId: pp->setDestId(string2ulong(value)); return true;
        case FIELD_direction: pp->setDirection((Direction)string2enum(value, "Direction")); return true;
        case FIELD_d2dTxPeerId: pp->setD2dTxPeerId(string2ulong(value)); return true;
        case FIELD_d2dRxPeerId: pp->setD2dRxPeerId(string2ulong(value)); return true;
        case FIELD_application: pp->setApplication((ApplicationType)string2enum(value, "ApplicationType")); return true;
        case FIELD_traffic: pp->setTraffic((LteTrafficClass)string2enum(value, "LteTrafficClass")); return true;
        case FIELD_rlcType: pp->setRlcType((LteRlcType)string2enum(value, "LteRlcType")); return true;
        case FIELD_lcid: pp->setLcid(string2ulong(value)); return true;
        case FIELD_multicastGroupId: pp->setMulticastGroupId(string2long(value)); return true;
        default: return false;
    }
}

const char *LteControlInfoDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *LteControlInfoDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    LteControlInfo *pp = (LteControlInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(FlowControlInfo)

FlowControlInfo::FlowControlInfo() : ::LteControlInfo()
{
}

FlowControlInfo::FlowControlInfo(const FlowControlInfo& other) : ::LteControlInfo(other)
{
    copy(other);
}

FlowControlInfo::~FlowControlInfo()
{
}

FlowControlInfo& FlowControlInfo::operator=(const FlowControlInfo& other)
{
    if (this == &other) return *this;
    ::LteControlInfo::operator=(other);
    copy(other);
    return *this;
}

void FlowControlInfo::copy(const FlowControlInfo& other)
{
    this->srcAddr = other.srcAddr;
    this->dstAddr = other.dstAddr;
    this->typeOfService = other.typeOfService;
    this->sequenceNumber = other.sequenceNumber;
    this->headerSize = other.headerSize;
    this->useNR = other.useNR;
}

void FlowControlInfo::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::LteControlInfo::parsimPack(b);
    doParsimPacking(b,this->srcAddr);
    doParsimPacking(b,this->dstAddr);
    doParsimPacking(b,this->typeOfService);
    doParsimPacking(b,this->sequenceNumber);
    doParsimPacking(b,this->headerSize);
    doParsimPacking(b,this->useNR);
}

void FlowControlInfo::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::LteControlInfo::parsimUnpack(b);
    doParsimUnpacking(b,this->srcAddr);
    doParsimUnpacking(b,this->dstAddr);
    doParsimUnpacking(b,this->typeOfService);
    doParsimUnpacking(b,this->sequenceNumber);
    doParsimUnpacking(b,this->headerSize);
    doParsimUnpacking(b,this->useNR);
}

uint32_t FlowControlInfo::getSrcAddr() const
{
    return this->srcAddr;
}

void FlowControlInfo::setSrcAddr(uint32_t srcAddr)
{
    this->srcAddr = srcAddr;
}

uint32_t FlowControlInfo::getDstAddr() const
{
    return this->dstAddr;
}

void FlowControlInfo::setDstAddr(uint32_t dstAddr)
{
    this->dstAddr = dstAddr;
}

uint16_t FlowControlInfo::getTypeOfService() const
{
    return this->typeOfService;
}

void FlowControlInfo::setTypeOfService(uint16_t typeOfService)
{
    this->typeOfService = typeOfService;
}

unsigned int FlowControlInfo::getSequenceNumber() const
{
    return this->sequenceNumber;
}

void FlowControlInfo::setSequenceNumber(unsigned int sequenceNumber)
{
    this->sequenceNumber = sequenceNumber;
}

int FlowControlInfo::getHeaderSize() const
{
    return this->headerSize;
}

void FlowControlInfo::setHeaderSize(int headerSize)
{
    this->headerSize = headerSize;
}

bool FlowControlInfo::getUseNR() const
{
    return this->useNR;
}

void FlowControlInfo::setUseNR(bool useNR)
{
    this->useNR = useNR;
}

class FlowControlInfoDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_srcAddr,
        FIELD_dstAddr,
        FIELD_typeOfService,
        FIELD_sequenceNumber,
        FIELD_headerSize,
        FIELD_useNR,
    };
  public:
    FlowControlInfoDescriptor();
    virtual ~FlowControlInfoDescriptor();

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

Register_ClassDescriptor(FlowControlInfoDescriptor)

FlowControlInfoDescriptor::FlowControlInfoDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(FlowControlInfo)), "LteControlInfo")
{
    propertynames = nullptr;
}

FlowControlInfoDescriptor::~FlowControlInfoDescriptor()
{
    delete[] propertynames;
}

bool FlowControlInfoDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<FlowControlInfo *>(obj)!=nullptr;
}

const char **FlowControlInfoDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *FlowControlInfoDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int FlowControlInfoDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int FlowControlInfoDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_srcAddr
        FD_ISEDITABLE,    // FIELD_dstAddr
        FD_ISEDITABLE,    // FIELD_typeOfService
        FD_ISEDITABLE,    // FIELD_sequenceNumber
        FD_ISEDITABLE,    // FIELD_headerSize
        FD_ISEDITABLE,    // FIELD_useNR
    };
    return (field >= 0 && field < 6) ? fieldTypeFlags[field] : 0;
}

const char *FlowControlInfoDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "srcAddr",
        "dstAddr",
        "typeOfService",
        "sequenceNumber",
        "headerSize",
        "useNR",
    };
    return (field >= 0 && field < 6) ? fieldNames[field] : nullptr;
}

int FlowControlInfoDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "srcAddr") == 0) return base+0;
    if (fieldName[0] == 'd' && strcmp(fieldName, "dstAddr") == 0) return base+1;
    if (fieldName[0] == 't' && strcmp(fieldName, "typeOfService") == 0) return base+2;
    if (fieldName[0] == 's' && strcmp(fieldName, "sequenceNumber") == 0) return base+3;
    if (fieldName[0] == 'h' && strcmp(fieldName, "headerSize") == 0) return base+4;
    if (fieldName[0] == 'u' && strcmp(fieldName, "useNR") == 0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *FlowControlInfoDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32",    // FIELD_srcAddr
        "uint32",    // FIELD_dstAddr
        "uint16",    // FIELD_typeOfService
        "unsigned int",    // FIELD_sequenceNumber
        "int",    // FIELD_headerSize
        "bool",    // FIELD_useNR
    };
    return (field >= 0 && field < 6) ? fieldTypeStrings[field] : nullptr;
}

const char **FlowControlInfoDescriptor::getFieldPropertyNames(int field) const
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

const char *FlowControlInfoDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int FlowControlInfoDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    FlowControlInfo *pp = (FlowControlInfo *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *FlowControlInfoDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    FlowControlInfo *pp = (FlowControlInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string FlowControlInfoDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    FlowControlInfo *pp = (FlowControlInfo *)object; (void)pp;
    switch (field) {
        case FIELD_srcAddr: return ulong2string(pp->getSrcAddr());
        case FIELD_dstAddr: return ulong2string(pp->getDstAddr());
        case FIELD_typeOfService: return ulong2string(pp->getTypeOfService());
        case FIELD_sequenceNumber: return ulong2string(pp->getSequenceNumber());
        case FIELD_headerSize: return long2string(pp->getHeaderSize());
        case FIELD_useNR: return bool2string(pp->getUseNR());
        default: return "";
    }
}

bool FlowControlInfoDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    FlowControlInfo *pp = (FlowControlInfo *)object; (void)pp;
    switch (field) {
        case FIELD_srcAddr: pp->setSrcAddr(string2ulong(value)); return true;
        case FIELD_dstAddr: pp->setDstAddr(string2ulong(value)); return true;
        case FIELD_typeOfService: pp->setTypeOfService(string2ulong(value)); return true;
        case FIELD_sequenceNumber: pp->setSequenceNumber(string2ulong(value)); return true;
        case FIELD_headerSize: pp->setHeaderSize(string2long(value)); return true;
        case FIELD_useNR: pp->setUseNR(string2bool(value)); return true;
        default: return false;
    }
}

const char *FlowControlInfoDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *FlowControlInfoDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    FlowControlInfo *pp = (FlowControlInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

UserControlInfo_Base::UserControlInfo_Base() : ::LteControlInfo()
{
}

UserControlInfo_Base::UserControlInfo_Base(const UserControlInfo_Base& other) : ::LteControlInfo(other)
{
    copy(other);
}

UserControlInfo_Base::~UserControlInfo_Base()
{
}

UserControlInfo_Base& UserControlInfo_Base::operator=(const UserControlInfo_Base& other)
{
    if (this == &other) return *this;
    ::LteControlInfo::operator=(other);
    copy(other);
    return *this;
}

void UserControlInfo_Base::copy(const UserControlInfo_Base& other)
{
    this->isNr_ = other.isNr_;
    this->carrierFrequency = other.carrierFrequency;
    this->acid = other.acid;
    this->cw = other.cw;
    this->txNumber = other.txNumber;
    this->ndi = other.ndi;
    this->isCorruptible_ = other.isCorruptible_;
    this->isBroadcast_ = other.isBroadcast_;
    this->deciderResult = other.deciderResult;
    this->blerTh = other.blerTh;
    this->blerValue = other.blerValue;
    this->txMode = other.txMode;
    this->frameType = other.frameType;
    this->txPower = other.txPower;
    this->d2dTxPower = other.d2dTxPower;
    this->totalGrantedBlocks = other.totalGrantedBlocks;
}

void UserControlInfo_Base::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::LteControlInfo::parsimPack(b);
    doParsimPacking(b,this->isNr_);
    doParsimPacking(b,this->carrierFrequency);
    doParsimPacking(b,this->acid);
    doParsimPacking(b,this->cw);
    doParsimPacking(b,this->txNumber);
    doParsimPacking(b,this->ndi);
    doParsimPacking(b,this->isCorruptible_);
    doParsimPacking(b,this->isBroadcast_);
    doParsimPacking(b,this->deciderResult);
    doParsimPacking(b,this->blerTh);
    doParsimPacking(b,this->blerValue);
    doParsimPacking(b,this->txMode);
    doParsimPacking(b,this->frameType);
    doParsimPacking(b,this->txPower);
    doParsimPacking(b,this->d2dTxPower);
    doParsimPacking(b,this->totalGrantedBlocks);
}

void UserControlInfo_Base::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::LteControlInfo::parsimUnpack(b);
    doParsimUnpacking(b,this->isNr_);
    doParsimUnpacking(b,this->carrierFrequency);
    doParsimUnpacking(b,this->acid);
    doParsimUnpacking(b,this->cw);
    doParsimUnpacking(b,this->txNumber);
    doParsimUnpacking(b,this->ndi);
    doParsimUnpacking(b,this->isCorruptible_);
    doParsimUnpacking(b,this->isBroadcast_);
    doParsimUnpacking(b,this->deciderResult);
    doParsimUnpacking(b,this->blerTh);
    doParsimUnpacking(b,this->blerValue);
    doParsimUnpacking(b,this->txMode);
    doParsimUnpacking(b,this->frameType);
    doParsimUnpacking(b,this->txPower);
    doParsimUnpacking(b,this->d2dTxPower);
    doParsimUnpacking(b,this->totalGrantedBlocks);
}

bool UserControlInfo_Base::isNr() const
{
    return this->isNr_;
}

void UserControlInfo_Base::setIsNr(bool isNr)
{
    this->isNr_ = isNr;
}

double UserControlInfo_Base::getCarrierFrequency() const
{
    return this->carrierFrequency;
}

void UserControlInfo_Base::setCarrierFrequency(double carrierFrequency)
{
    this->carrierFrequency = carrierFrequency;
}

unsigned char UserControlInfo_Base::getAcid() const
{
    return this->acid;
}

void UserControlInfo_Base::setAcid(unsigned char acid)
{
    this->acid = acid;
}

unsigned char UserControlInfo_Base::getCw() const
{
    return this->cw;
}

void UserControlInfo_Base::setCw(unsigned char cw)
{
    this->cw = cw;
}

unsigned char UserControlInfo_Base::getTxNumber() const
{
    return this->txNumber;
}

void UserControlInfo_Base::setTxNumber(unsigned char txNumber)
{
    this->txNumber = txNumber;
}

bool UserControlInfo_Base::getNdi() const
{
    return this->ndi;
}

void UserControlInfo_Base::setNdi(bool ndi)
{
    this->ndi = ndi;
}

bool UserControlInfo_Base::isCorruptible() const
{
    return this->isCorruptible_;
}

void UserControlInfo_Base::setIsCorruptible(bool isCorruptible)
{
    this->isCorruptible_ = isCorruptible;
}

bool UserControlInfo_Base::isBroadcast() const
{
    return this->isBroadcast_;
}

void UserControlInfo_Base::setIsBroadcast(bool isBroadcast)
{
    this->isBroadcast_ = isBroadcast;
}

bool UserControlInfo_Base::getDeciderResult() const
{
    return this->deciderResult;
}

void UserControlInfo_Base::setDeciderResult(bool deciderResult)
{
    this->deciderResult = deciderResult;
}

double UserControlInfo_Base::getBlerTh() const
{
    return this->blerTh;
}

void UserControlInfo_Base::setBlerTh(double blerTh)
{
    this->blerTh = blerTh;
}

double UserControlInfo_Base::getBlerValue() const
{
    return this->blerValue;
}

void UserControlInfo_Base::setBlerValue(double blerValue)
{
    this->blerValue = blerValue;
}

unsigned short UserControlInfo_Base::getTxMode() const
{
    return this->txMode;
}

void UserControlInfo_Base::setTxMode(unsigned short txMode)
{
    this->txMode = txMode;
}

unsigned int UserControlInfo_Base::getFrameType() const
{
    return this->frameType;
}

void UserControlInfo_Base::setFrameType(unsigned int frameType)
{
    this->frameType = frameType;
}

double UserControlInfo_Base::getTxPower() const
{
    return this->txPower;
}

void UserControlInfo_Base::setTxPower(double txPower)
{
    this->txPower = txPower;
}

double UserControlInfo_Base::getD2dTxPower() const
{
    return this->d2dTxPower;
}

void UserControlInfo_Base::setD2dTxPower(double d2dTxPower)
{
    this->d2dTxPower = d2dTxPower;
}

unsigned int UserControlInfo_Base::getTotalGrantedBlocks() const
{
    return this->totalGrantedBlocks;
}

void UserControlInfo_Base::setTotalGrantedBlocks(unsigned int totalGrantedBlocks)
{
    this->totalGrantedBlocks = totalGrantedBlocks;
}

class UserControlInfoDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_isNr,
        FIELD_carrierFrequency,
        FIELD_acid,
        FIELD_cw,
        FIELD_txNumber,
        FIELD_ndi,
        FIELD_isCorruptible,
        FIELD_isBroadcast,
        FIELD_deciderResult,
        FIELD_blerTh,
        FIELD_blerValue,
        FIELD_txMode,
        FIELD_frameType,
        FIELD_txPower,
        FIELD_d2dTxPower,
        FIELD_totalGrantedBlocks,
    };
  public:
    UserControlInfoDescriptor();
    virtual ~UserControlInfoDescriptor();

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

Register_ClassDescriptor(UserControlInfoDescriptor)

UserControlInfoDescriptor::UserControlInfoDescriptor() : omnetpp::cClassDescriptor("UserControlInfo", "LteControlInfo")
{
    propertynames = nullptr;
}

UserControlInfoDescriptor::~UserControlInfoDescriptor()
{
    delete[] propertynames;
}

bool UserControlInfoDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UserControlInfo_Base *>(obj)!=nullptr;
}

const char **UserControlInfoDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UserControlInfoDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname, "customize")) return "true";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UserControlInfoDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 16+basedesc->getFieldCount() : 16;
}

unsigned int UserControlInfoDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_isNr
        FD_ISEDITABLE,    // FIELD_carrierFrequency
        FD_ISEDITABLE,    // FIELD_acid
        FD_ISEDITABLE,    // FIELD_cw
        FD_ISEDITABLE,    // FIELD_txNumber
        FD_ISEDITABLE,    // FIELD_ndi
        FD_ISEDITABLE,    // FIELD_isCorruptible
        FD_ISEDITABLE,    // FIELD_isBroadcast
        FD_ISEDITABLE,    // FIELD_deciderResult
        FD_ISEDITABLE,    // FIELD_blerTh
        FD_ISEDITABLE,    // FIELD_blerValue
        FD_ISEDITABLE,    // FIELD_txMode
        FD_ISEDITABLE,    // FIELD_frameType
        FD_ISEDITABLE,    // FIELD_txPower
        FD_ISEDITABLE,    // FIELD_d2dTxPower
        FD_ISEDITABLE,    // FIELD_totalGrantedBlocks
    };
    return (field >= 0 && field < 16) ? fieldTypeFlags[field] : 0;
}

const char *UserControlInfoDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "isNr",
        "carrierFrequency",
        "acid",
        "cw",
        "txNumber",
        "ndi",
        "isCorruptible",
        "isBroadcast",
        "deciderResult",
        "blerTh",
        "blerValue",
        "txMode",
        "frameType",
        "txPower",
        "d2dTxPower",
        "totalGrantedBlocks",
    };
    return (field >= 0 && field < 16) ? fieldNames[field] : nullptr;
}

int UserControlInfoDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'i' && strcmp(fieldName, "isNr") == 0) return base+0;
    if (fieldName[0] == 'c' && strcmp(fieldName, "carrierFrequency") == 0) return base+1;
    if (fieldName[0] == 'a' && strcmp(fieldName, "acid") == 0) return base+2;
    if (fieldName[0] == 'c' && strcmp(fieldName, "cw") == 0) return base+3;
    if (fieldName[0] == 't' && strcmp(fieldName, "txNumber") == 0) return base+4;
    if (fieldName[0] == 'n' && strcmp(fieldName, "ndi") == 0) return base+5;
    if (fieldName[0] == 'i' && strcmp(fieldName, "isCorruptible") == 0) return base+6;
    if (fieldName[0] == 'i' && strcmp(fieldName, "isBroadcast") == 0) return base+7;
    if (fieldName[0] == 'd' && strcmp(fieldName, "deciderResult") == 0) return base+8;
    if (fieldName[0] == 'b' && strcmp(fieldName, "blerTh") == 0) return base+9;
    if (fieldName[0] == 'b' && strcmp(fieldName, "blerValue") == 0) return base+10;
    if (fieldName[0] == 't' && strcmp(fieldName, "txMode") == 0) return base+11;
    if (fieldName[0] == 'f' && strcmp(fieldName, "frameType") == 0) return base+12;
    if (fieldName[0] == 't' && strcmp(fieldName, "txPower") == 0) return base+13;
    if (fieldName[0] == 'd' && strcmp(fieldName, "d2dTxPower") == 0) return base+14;
    if (fieldName[0] == 't' && strcmp(fieldName, "totalGrantedBlocks") == 0) return base+15;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UserControlInfoDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",    // FIELD_isNr
        "double",    // FIELD_carrierFrequency
        "unsigned char",    // FIELD_acid
        "unsigned char",    // FIELD_cw
        "unsigned char",    // FIELD_txNumber
        "bool",    // FIELD_ndi
        "bool",    // FIELD_isCorruptible
        "bool",    // FIELD_isBroadcast
        "bool",    // FIELD_deciderResult
        "double",    // FIELD_blerTh
        "double",    // FIELD_blerValue
        "unsigned short",    // FIELD_txMode
        "unsigned int",    // FIELD_frameType
        "double",    // FIELD_txPower
        "double",    // FIELD_d2dTxPower
        "unsigned int",    // FIELD_totalGrantedBlocks
    };
    return (field >= 0 && field < 16) ? fieldTypeStrings[field] : nullptr;
}

const char **UserControlInfoDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_txMode: {
            static const char *names[] = { "enum", "enum",  nullptr };
            return names;
        }
        case FIELD_frameType: {
            static const char *names[] = { "enum", "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *UserControlInfoDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_txMode:
            if (!strcmp(propertyname, "enum")) return "TxMode";
            if (!strcmp(propertyname, "enum")) return "TxMode";
            return nullptr;
        case FIELD_frameType:
            if (!strcmp(propertyname, "enum")) return "LtePhyFrameType";
            if (!strcmp(propertyname, "enum")) return "LtePhyFrameType";
            return nullptr;
        default: return nullptr;
    }
}

int UserControlInfoDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UserControlInfo_Base *pp = (UserControlInfo_Base *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *UserControlInfoDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UserControlInfo_Base *pp = (UserControlInfo_Base *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UserControlInfoDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UserControlInfo_Base *pp = (UserControlInfo_Base *)object; (void)pp;
    switch (field) {
        case FIELD_isNr: return bool2string(pp->isNr());
        case FIELD_carrierFrequency: return double2string(pp->getCarrierFrequency());
        case FIELD_acid: return ulong2string(pp->getAcid());
        case FIELD_cw: return ulong2string(pp->getCw());
        case FIELD_txNumber: return ulong2string(pp->getTxNumber());
        case FIELD_ndi: return bool2string(pp->getNdi());
        case FIELD_isCorruptible: return bool2string(pp->isCorruptible());
        case FIELD_isBroadcast: return bool2string(pp->isBroadcast());
        case FIELD_deciderResult: return bool2string(pp->getDeciderResult());
        case FIELD_blerTh: return double2string(pp->getBlerTh());
        case FIELD_blerValue: return double2string(pp->getBlerValue());
        case FIELD_txMode: return enum2string(pp->getTxMode(), "TxMode");
        case FIELD_frameType: return enum2string(pp->getFrameType(), "LtePhyFrameType");
        case FIELD_txPower: return double2string(pp->getTxPower());
        case FIELD_d2dTxPower: return double2string(pp->getD2dTxPower());
        case FIELD_totalGrantedBlocks: return ulong2string(pp->getTotalGrantedBlocks());
        default: return "";
    }
}

bool UserControlInfoDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    UserControlInfo_Base *pp = (UserControlInfo_Base *)object; (void)pp;
    switch (field) {
        case FIELD_isNr: pp->setIsNr(string2bool(value)); return true;
        case FIELD_carrierFrequency: pp->setCarrierFrequency(string2double(value)); return true;
        case FIELD_acid: pp->setAcid(string2ulong(value)); return true;
        case FIELD_cw: pp->setCw(string2ulong(value)); return true;
        case FIELD_txNumber: pp->setTxNumber(string2ulong(value)); return true;
        case FIELD_ndi: pp->setNdi(string2bool(value)); return true;
        case FIELD_isCorruptible: pp->setIsCorruptible(string2bool(value)); return true;
        case FIELD_isBroadcast: pp->setIsBroadcast(string2bool(value)); return true;
        case FIELD_deciderResult: pp->setDeciderResult(string2bool(value)); return true;
        case FIELD_blerTh: pp->setBlerTh(string2double(value)); return true;
        case FIELD_blerValue: pp->setBlerValue(string2double(value)); return true;
        case FIELD_txMode: pp->setTxMode((TxMode)string2enum(value, "TxMode")); return true;
        case FIELD_frameType: pp->setFrameType((LtePhyFrameType)string2enum(value, "LtePhyFrameType")); return true;
        case FIELD_txPower: pp->setTxPower(string2double(value)); return true;
        case FIELD_d2dTxPower: pp->setD2dTxPower(string2double(value)); return true;
        case FIELD_totalGrantedBlocks: pp->setTotalGrantedBlocks(string2ulong(value)); return true;
        default: return false;
    }
}

const char *UserControlInfoDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *UserControlInfoDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UserControlInfo_Base *pp = (UserControlInfo_Base *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

