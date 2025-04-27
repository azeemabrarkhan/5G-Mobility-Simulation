//
// Generated file, do not edit! Created by nedtool 5.6 from nodes/mec/MEPlatform/MEAppPacket.msg.
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
#include "MEAppPacket_m.h"

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

Register_Class(MEAppPacket)

MEAppPacket::MEAppPacket() : ::inet::FieldsChunk()
{
}

MEAppPacket::MEAppPacket(const MEAppPacket& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

MEAppPacket::~MEAppPacket()
{
}

MEAppPacket& MEAppPacket::operator=(const MEAppPacket& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void MEAppPacket::copy(const MEAppPacket& other)
{
    this->sno = other.sno;
    this->timestamp = other.timestamp;
    this->type = other.type;
    this->sourceAddress = other.sourceAddress;
    this->destinationAddress = other.destinationAddress;
    this->MEModuleType = other.MEModuleType;
    this->MEModuleName = other.MEModuleName;
    this->ueAppID = other.ueAppID;
    this->requiredDisk = other.requiredDisk;
    this->requiredRam = other.requiredRam;
    this->requiredCpu = other.requiredCpu;
    this->requiredService = other.requiredService;
}

void MEAppPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->sno);
    doParsimPacking(b,this->timestamp);
    doParsimPacking(b,this->type);
    doParsimPacking(b,this->sourceAddress);
    doParsimPacking(b,this->destinationAddress);
    doParsimPacking(b,this->MEModuleType);
    doParsimPacking(b,this->MEModuleName);
    doParsimPacking(b,this->ueAppID);
    doParsimPacking(b,this->requiredDisk);
    doParsimPacking(b,this->requiredRam);
    doParsimPacking(b,this->requiredCpu);
    doParsimPacking(b,this->requiredService);
}

void MEAppPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->sno);
    doParsimUnpacking(b,this->timestamp);
    doParsimUnpacking(b,this->type);
    doParsimUnpacking(b,this->sourceAddress);
    doParsimUnpacking(b,this->destinationAddress);
    doParsimUnpacking(b,this->MEModuleType);
    doParsimUnpacking(b,this->MEModuleName);
    doParsimUnpacking(b,this->ueAppID);
    doParsimUnpacking(b,this->requiredDisk);
    doParsimUnpacking(b,this->requiredRam);
    doParsimUnpacking(b,this->requiredCpu);
    doParsimUnpacking(b,this->requiredService);
}

unsigned int MEAppPacket::getSno() const
{
    return this->sno;
}

void MEAppPacket::setSno(unsigned int sno)
{
    handleChange();
    this->sno = sno;
}

omnetpp::simtime_t MEAppPacket::getTimestamp() const
{
    return this->timestamp;
}

void MEAppPacket::setTimestamp(omnetpp::simtime_t timestamp)
{
    handleChange();
    this->timestamp = timestamp;
}

const char * MEAppPacket::getType() const
{
    return this->type.c_str();
}

void MEAppPacket::setType(const char * type)
{
    handleChange();
    this->type = type;
}

const char * MEAppPacket::getSourceAddress() const
{
    return this->sourceAddress.c_str();
}

void MEAppPacket::setSourceAddress(const char * sourceAddress)
{
    handleChange();
    this->sourceAddress = sourceAddress;
}

const char * MEAppPacket::getDestinationAddress() const
{
    return this->destinationAddress.c_str();
}

void MEAppPacket::setDestinationAddress(const char * destinationAddress)
{
    handleChange();
    this->destinationAddress = destinationAddress;
}

const char * MEAppPacket::getMEModuleType() const
{
    return this->MEModuleType.c_str();
}

void MEAppPacket::setMEModuleType(const char * MEModuleType)
{
    handleChange();
    this->MEModuleType = MEModuleType;
}

const char * MEAppPacket::getMEModuleName() const
{
    return this->MEModuleName.c_str();
}

void MEAppPacket::setMEModuleName(const char * MEModuleName)
{
    handleChange();
    this->MEModuleName = MEModuleName;
}

int MEAppPacket::getUeAppID() const
{
    return this->ueAppID;
}

void MEAppPacket::setUeAppID(int ueAppID)
{
    handleChange();
    this->ueAppID = ueAppID;
}

unsigned int MEAppPacket::getRequiredDisk() const
{
    return this->requiredDisk;
}

void MEAppPacket::setRequiredDisk(unsigned int requiredDisk)
{
    handleChange();
    this->requiredDisk = requiredDisk;
}

unsigned int MEAppPacket::getRequiredRam() const
{
    return this->requiredRam;
}

void MEAppPacket::setRequiredRam(unsigned int requiredRam)
{
    handleChange();
    this->requiredRam = requiredRam;
}

double MEAppPacket::getRequiredCpu() const
{
    return this->requiredCpu;
}

void MEAppPacket::setRequiredCpu(double requiredCpu)
{
    handleChange();
    this->requiredCpu = requiredCpu;
}

const char * MEAppPacket::getRequiredService() const
{
    return this->requiredService.c_str();
}

void MEAppPacket::setRequiredService(const char * requiredService)
{
    handleChange();
    this->requiredService = requiredService;
}

class MEAppPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_sno,
        FIELD_timestamp,
        FIELD_type,
        FIELD_sourceAddress,
        FIELD_destinationAddress,
        FIELD_MEModuleType,
        FIELD_MEModuleName,
        FIELD_ueAppID,
        FIELD_requiredDisk,
        FIELD_requiredRam,
        FIELD_requiredCpu,
        FIELD_requiredService,
    };
  public:
    MEAppPacketDescriptor();
    virtual ~MEAppPacketDescriptor();

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

Register_ClassDescriptor(MEAppPacketDescriptor)

MEAppPacketDescriptor::MEAppPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MEAppPacket)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

MEAppPacketDescriptor::~MEAppPacketDescriptor()
{
    delete[] propertynames;
}

bool MEAppPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MEAppPacket *>(obj)!=nullptr;
}

const char **MEAppPacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *MEAppPacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int MEAppPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 12+basedesc->getFieldCount() : 12;
}

unsigned int MEAppPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_sno
        0,    // FIELD_timestamp
        FD_ISEDITABLE,    // FIELD_type
        FD_ISEDITABLE,    // FIELD_sourceAddress
        FD_ISEDITABLE,    // FIELD_destinationAddress
        FD_ISEDITABLE,    // FIELD_MEModuleType
        FD_ISEDITABLE,    // FIELD_MEModuleName
        FD_ISEDITABLE,    // FIELD_ueAppID
        FD_ISEDITABLE,    // FIELD_requiredDisk
        FD_ISEDITABLE,    // FIELD_requiredRam
        FD_ISEDITABLE,    // FIELD_requiredCpu
        FD_ISEDITABLE,    // FIELD_requiredService
    };
    return (field >= 0 && field < 12) ? fieldTypeFlags[field] : 0;
}

const char *MEAppPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "sno",
        "timestamp",
        "type",
        "sourceAddress",
        "destinationAddress",
        "MEModuleType",
        "MEModuleName",
        "ueAppID",
        "requiredDisk",
        "requiredRam",
        "requiredCpu",
        "requiredService",
    };
    return (field >= 0 && field < 12) ? fieldNames[field] : nullptr;
}

int MEAppPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "sno") == 0) return base+0;
    if (fieldName[0] == 't' && strcmp(fieldName, "timestamp") == 0) return base+1;
    if (fieldName[0] == 't' && strcmp(fieldName, "type") == 0) return base+2;
    if (fieldName[0] == 's' && strcmp(fieldName, "sourceAddress") == 0) return base+3;
    if (fieldName[0] == 'd' && strcmp(fieldName, "destinationAddress") == 0) return base+4;
    if (fieldName[0] == 'M' && strcmp(fieldName, "MEModuleType") == 0) return base+5;
    if (fieldName[0] == 'M' && strcmp(fieldName, "MEModuleName") == 0) return base+6;
    if (fieldName[0] == 'u' && strcmp(fieldName, "ueAppID") == 0) return base+7;
    if (fieldName[0] == 'r' && strcmp(fieldName, "requiredDisk") == 0) return base+8;
    if (fieldName[0] == 'r' && strcmp(fieldName, "requiredRam") == 0) return base+9;
    if (fieldName[0] == 'r' && strcmp(fieldName, "requiredCpu") == 0) return base+10;
    if (fieldName[0] == 'r' && strcmp(fieldName, "requiredService") == 0) return base+11;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *MEAppPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",    // FIELD_sno
        "omnetpp::simtime_t",    // FIELD_timestamp
        "string",    // FIELD_type
        "string",    // FIELD_sourceAddress
        "string",    // FIELD_destinationAddress
        "string",    // FIELD_MEModuleType
        "string",    // FIELD_MEModuleName
        "int",    // FIELD_ueAppID
        "unsigned int",    // FIELD_requiredDisk
        "unsigned int",    // FIELD_requiredRam
        "double",    // FIELD_requiredCpu
        "string",    // FIELD_requiredService
    };
    return (field >= 0 && field < 12) ? fieldTypeStrings[field] : nullptr;
}

const char **MEAppPacketDescriptor::getFieldPropertyNames(int field) const
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

const char *MEAppPacketDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int MEAppPacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    MEAppPacket *pp = (MEAppPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *MEAppPacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    MEAppPacket *pp = (MEAppPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MEAppPacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    MEAppPacket *pp = (MEAppPacket *)object; (void)pp;
    switch (field) {
        case FIELD_sno: return ulong2string(pp->getSno());
        case FIELD_timestamp: return simtime2string(pp->getTimestamp());
        case FIELD_type: return oppstring2string(pp->getType());
        case FIELD_sourceAddress: return oppstring2string(pp->getSourceAddress());
        case FIELD_destinationAddress: return oppstring2string(pp->getDestinationAddress());
        case FIELD_MEModuleType: return oppstring2string(pp->getMEModuleType());
        case FIELD_MEModuleName: return oppstring2string(pp->getMEModuleName());
        case FIELD_ueAppID: return long2string(pp->getUeAppID());
        case FIELD_requiredDisk: return ulong2string(pp->getRequiredDisk());
        case FIELD_requiredRam: return ulong2string(pp->getRequiredRam());
        case FIELD_requiredCpu: return double2string(pp->getRequiredCpu());
        case FIELD_requiredService: return oppstring2string(pp->getRequiredService());
        default: return "";
    }
}

bool MEAppPacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    MEAppPacket *pp = (MEAppPacket *)object; (void)pp;
    switch (field) {
        case FIELD_sno: pp->setSno(string2ulong(value)); return true;
        case FIELD_type: pp->setType((value)); return true;
        case FIELD_sourceAddress: pp->setSourceAddress((value)); return true;
        case FIELD_destinationAddress: pp->setDestinationAddress((value)); return true;
        case FIELD_MEModuleType: pp->setMEModuleType((value)); return true;
        case FIELD_MEModuleName: pp->setMEModuleName((value)); return true;
        case FIELD_ueAppID: pp->setUeAppID(string2long(value)); return true;
        case FIELD_requiredDisk: pp->setRequiredDisk(string2ulong(value)); return true;
        case FIELD_requiredRam: pp->setRequiredRam(string2ulong(value)); return true;
        case FIELD_requiredCpu: pp->setRequiredCpu(string2double(value)); return true;
        case FIELD_requiredService: pp->setRequiredService((value)); return true;
        default: return false;
    }
}

const char *MEAppPacketDescriptor::getFieldStructName(int field) const
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

void *MEAppPacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    MEAppPacket *pp = (MEAppPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

