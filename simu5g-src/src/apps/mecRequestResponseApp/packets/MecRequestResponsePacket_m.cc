//
// Generated file, do not edit! Created by nedtool 5.6 from apps/mecRequestResponseApp/packets/MecRequestResponsePacket.msg.
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
#include "MecRequestResponsePacket_m.h"

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

Register_Class(MecRequestResponsePacket)

MecRequestResponsePacket::MecRequestResponsePacket() : ::inet::FieldsChunk()
{
}

MecRequestResponsePacket::MecRequestResponsePacket(const MecRequestResponsePacket& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

MecRequestResponsePacket::~MecRequestResponsePacket()
{
}

MecRequestResponsePacket& MecRequestResponsePacket::operator=(const MecRequestResponsePacket& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void MecRequestResponsePacket::copy(const MecRequestResponsePacket& other)
{
    this->sno = other.sno;
    this->reqTimestamp = other.reqTimestamp;
    this->respTimestamp = other.respTimestamp;
    this->bsId = other.bsId;
    this->appId = other.appId;
    this->srcAddress = other.srcAddress;
    this->srcPort = other.srcPort;
    this->destAddress = other.destAddress;
    this->destPort = other.destPort;
}

void MecRequestResponsePacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->sno);
    doParsimPacking(b,this->reqTimestamp);
    doParsimPacking(b,this->respTimestamp);
    doParsimPacking(b,this->bsId);
    doParsimPacking(b,this->appId);
    doParsimPacking(b,this->srcAddress);
    doParsimPacking(b,this->srcPort);
    doParsimPacking(b,this->destAddress);
    doParsimPacking(b,this->destPort);
}

void MecRequestResponsePacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->sno);
    doParsimUnpacking(b,this->reqTimestamp);
    doParsimUnpacking(b,this->respTimestamp);
    doParsimUnpacking(b,this->bsId);
    doParsimUnpacking(b,this->appId);
    doParsimUnpacking(b,this->srcAddress);
    doParsimUnpacking(b,this->srcPort);
    doParsimUnpacking(b,this->destAddress);
    doParsimUnpacking(b,this->destPort);
}

unsigned int MecRequestResponsePacket::getSno() const
{
    return this->sno;
}

void MecRequestResponsePacket::setSno(unsigned int sno)
{
    handleChange();
    this->sno = sno;
}

double MecRequestResponsePacket::getReqTimestamp() const
{
    return this->reqTimestamp;
}

void MecRequestResponsePacket::setReqTimestamp(double reqTimestamp)
{
    handleChange();
    this->reqTimestamp = reqTimestamp;
}

double MecRequestResponsePacket::getRespTimestamp() const
{
    return this->respTimestamp;
}

void MecRequestResponsePacket::setRespTimestamp(double respTimestamp)
{
    handleChange();
    this->respTimestamp = respTimestamp;
}

int MecRequestResponsePacket::getBsId() const
{
    return this->bsId;
}

void MecRequestResponsePacket::setBsId(int bsId)
{
    handleChange();
    this->bsId = bsId;
}

int MecRequestResponsePacket::getAppId() const
{
    return this->appId;
}

void MecRequestResponsePacket::setAppId(int appId)
{
    handleChange();
    this->appId = appId;
}

const char * MecRequestResponsePacket::getSrcAddress() const
{
    return this->srcAddress.c_str();
}

void MecRequestResponsePacket::setSrcAddress(const char * srcAddress)
{
    handleChange();
    this->srcAddress = srcAddress;
}

int MecRequestResponsePacket::getSrcPort() const
{
    return this->srcPort;
}

void MecRequestResponsePacket::setSrcPort(int srcPort)
{
    handleChange();
    this->srcPort = srcPort;
}

const char * MecRequestResponsePacket::getDestAddress() const
{
    return this->destAddress.c_str();
}

void MecRequestResponsePacket::setDestAddress(const char * destAddress)
{
    handleChange();
    this->destAddress = destAddress;
}

int MecRequestResponsePacket::getDestPort() const
{
    return this->destPort;
}

void MecRequestResponsePacket::setDestPort(int destPort)
{
    handleChange();
    this->destPort = destPort;
}

class MecRequestResponsePacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_sno,
        FIELD_reqTimestamp,
        FIELD_respTimestamp,
        FIELD_bsId,
        FIELD_appId,
        FIELD_srcAddress,
        FIELD_srcPort,
        FIELD_destAddress,
        FIELD_destPort,
    };
  public:
    MecRequestResponsePacketDescriptor();
    virtual ~MecRequestResponsePacketDescriptor();

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

Register_ClassDescriptor(MecRequestResponsePacketDescriptor)

MecRequestResponsePacketDescriptor::MecRequestResponsePacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MecRequestResponsePacket)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

MecRequestResponsePacketDescriptor::~MecRequestResponsePacketDescriptor()
{
    delete[] propertynames;
}

bool MecRequestResponsePacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MecRequestResponsePacket *>(obj)!=nullptr;
}

const char **MecRequestResponsePacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *MecRequestResponsePacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int MecRequestResponsePacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 9+basedesc->getFieldCount() : 9;
}

unsigned int MecRequestResponsePacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_sno
        FD_ISEDITABLE,    // FIELD_reqTimestamp
        FD_ISEDITABLE,    // FIELD_respTimestamp
        FD_ISEDITABLE,    // FIELD_bsId
        FD_ISEDITABLE,    // FIELD_appId
        FD_ISEDITABLE,    // FIELD_srcAddress
        FD_ISEDITABLE,    // FIELD_srcPort
        FD_ISEDITABLE,    // FIELD_destAddress
        FD_ISEDITABLE,    // FIELD_destPort
    };
    return (field >= 0 && field < 9) ? fieldTypeFlags[field] : 0;
}

const char *MecRequestResponsePacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "sno",
        "reqTimestamp",
        "respTimestamp",
        "bsId",
        "appId",
        "srcAddress",
        "srcPort",
        "destAddress",
        "destPort",
    };
    return (field >= 0 && field < 9) ? fieldNames[field] : nullptr;
}

int MecRequestResponsePacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "sno") == 0) return base+0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "reqTimestamp") == 0) return base+1;
    if (fieldName[0] == 'r' && strcmp(fieldName, "respTimestamp") == 0) return base+2;
    if (fieldName[0] == 'b' && strcmp(fieldName, "bsId") == 0) return base+3;
    if (fieldName[0] == 'a' && strcmp(fieldName, "appId") == 0) return base+4;
    if (fieldName[0] == 's' && strcmp(fieldName, "srcAddress") == 0) return base+5;
    if (fieldName[0] == 's' && strcmp(fieldName, "srcPort") == 0) return base+6;
    if (fieldName[0] == 'd' && strcmp(fieldName, "destAddress") == 0) return base+7;
    if (fieldName[0] == 'd' && strcmp(fieldName, "destPort") == 0) return base+8;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *MecRequestResponsePacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",    // FIELD_sno
        "double",    // FIELD_reqTimestamp
        "double",    // FIELD_respTimestamp
        "int",    // FIELD_bsId
        "int",    // FIELD_appId
        "string",    // FIELD_srcAddress
        "int",    // FIELD_srcPort
        "string",    // FIELD_destAddress
        "int",    // FIELD_destPort
    };
    return (field >= 0 && field < 9) ? fieldTypeStrings[field] : nullptr;
}

const char **MecRequestResponsePacketDescriptor::getFieldPropertyNames(int field) const
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

const char *MecRequestResponsePacketDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int MecRequestResponsePacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    MecRequestResponsePacket *pp = (MecRequestResponsePacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *MecRequestResponsePacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    MecRequestResponsePacket *pp = (MecRequestResponsePacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MecRequestResponsePacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    MecRequestResponsePacket *pp = (MecRequestResponsePacket *)object; (void)pp;
    switch (field) {
        case FIELD_sno: return ulong2string(pp->getSno());
        case FIELD_reqTimestamp: return double2string(pp->getReqTimestamp());
        case FIELD_respTimestamp: return double2string(pp->getRespTimestamp());
        case FIELD_bsId: return long2string(pp->getBsId());
        case FIELD_appId: return long2string(pp->getAppId());
        case FIELD_srcAddress: return oppstring2string(pp->getSrcAddress());
        case FIELD_srcPort: return long2string(pp->getSrcPort());
        case FIELD_destAddress: return oppstring2string(pp->getDestAddress());
        case FIELD_destPort: return long2string(pp->getDestPort());
        default: return "";
    }
}

bool MecRequestResponsePacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    MecRequestResponsePacket *pp = (MecRequestResponsePacket *)object; (void)pp;
    switch (field) {
        case FIELD_sno: pp->setSno(string2ulong(value)); return true;
        case FIELD_reqTimestamp: pp->setReqTimestamp(string2double(value)); return true;
        case FIELD_respTimestamp: pp->setRespTimestamp(string2double(value)); return true;
        case FIELD_bsId: pp->setBsId(string2long(value)); return true;
        case FIELD_appId: pp->setAppId(string2long(value)); return true;
        case FIELD_srcAddress: pp->setSrcAddress((value)); return true;
        case FIELD_srcPort: pp->setSrcPort(string2long(value)); return true;
        case FIELD_destAddress: pp->setDestAddress((value)); return true;
        case FIELD_destPort: pp->setDestPort(string2long(value)); return true;
        default: return false;
    }
}

const char *MecRequestResponsePacketDescriptor::getFieldStructName(int field) const
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

void *MecRequestResponsePacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    MecRequestResponsePacket *pp = (MecRequestResponsePacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

