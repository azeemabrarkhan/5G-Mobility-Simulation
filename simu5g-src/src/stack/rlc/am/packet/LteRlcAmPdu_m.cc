//
// Generated file, do not edit! Created by nedtool 5.6 from stack/rlc/am/packet/LteRlcAmPdu.msg.
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
#include "LteRlcAmPdu_m.h"

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

LteRlcAmPdu_Base::LteRlcAmPdu_Base() : ::LteRlcPdu()
{
}

LteRlcAmPdu_Base::LteRlcAmPdu_Base(const LteRlcAmPdu_Base& other) : ::LteRlcPdu(other)
{
    copy(other);
}

LteRlcAmPdu_Base::~LteRlcAmPdu_Base()
{
}

LteRlcAmPdu_Base& LteRlcAmPdu_Base::operator=(const LteRlcAmPdu_Base& other)
{
    if (this == &other) return *this;
    ::LteRlcPdu::operator=(other);
    copy(other);
    return *this;
}

void LteRlcAmPdu_Base::copy(const LteRlcAmPdu_Base& other)
{
    this->amType = other.amType;
    this->txNumber = other.txNumber;
    this->firstSn = other.firstSn;
    this->lastSn = other.lastSn;
}

void LteRlcAmPdu_Base::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::LteRlcPdu::parsimPack(b);
    doParsimPacking(b,this->amType);
    doParsimPacking(b,this->txNumber);
    doParsimPacking(b,this->firstSn);
    doParsimPacking(b,this->lastSn);
    // field bitmap is abstract -- please do packing in customized class
}

void LteRlcAmPdu_Base::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::LteRlcPdu::parsimUnpack(b);
    doParsimUnpacking(b,this->amType);
    doParsimUnpacking(b,this->txNumber);
    doParsimUnpacking(b,this->firstSn);
    doParsimUnpacking(b,this->lastSn);
    // field bitmap is abstract -- please do unpacking in customized class
}

unsigned short LteRlcAmPdu_Base::getAmType() const
{
    return this->amType;
}

void LteRlcAmPdu_Base::setAmType(unsigned short amType)
{
    handleChange();
    this->amType = amType;
}

unsigned short LteRlcAmPdu_Base::getTxNumber() const
{
    return this->txNumber;
}

void LteRlcAmPdu_Base::setTxNumber(unsigned short txNumber)
{
    handleChange();
    this->txNumber = txNumber;
}

int LteRlcAmPdu_Base::getFirstSn() const
{
    return this->firstSn;
}

void LteRlcAmPdu_Base::setFirstSn(int firstSn)
{
    handleChange();
    this->firstSn = firstSn;
}

int LteRlcAmPdu_Base::getLastSn() const
{
    return this->lastSn;
}

void LteRlcAmPdu_Base::setLastSn(int lastSn)
{
    handleChange();
    this->lastSn = lastSn;
}

class LteRlcAmPduDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_amType,
        FIELD_txNumber,
        FIELD_firstSn,
        FIELD_lastSn,
        FIELD_bitmap,
    };
  public:
    LteRlcAmPduDescriptor();
    virtual ~LteRlcAmPduDescriptor();

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

Register_ClassDescriptor(LteRlcAmPduDescriptor)

LteRlcAmPduDescriptor::LteRlcAmPduDescriptor() : omnetpp::cClassDescriptor("LteRlcAmPdu", "LteRlcPdu")
{
    propertynames = nullptr;
}

LteRlcAmPduDescriptor::~LteRlcAmPduDescriptor()
{
    delete[] propertynames;
}

bool LteRlcAmPduDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<LteRlcAmPdu_Base *>(obj)!=nullptr;
}

const char **LteRlcAmPduDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *LteRlcAmPduDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname, "customize")) return "true";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int LteRlcAmPduDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int LteRlcAmPduDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_amType
        FD_ISEDITABLE,    // FIELD_txNumber
        FD_ISEDITABLE,    // FIELD_firstSn
        FD_ISEDITABLE,    // FIELD_lastSn
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_bitmap
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *LteRlcAmPduDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "amType",
        "txNumber",
        "firstSn",
        "lastSn",
        "bitmap",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int LteRlcAmPduDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'a' && strcmp(fieldName, "amType") == 0) return base+0;
    if (fieldName[0] == 't' && strcmp(fieldName, "txNumber") == 0) return base+1;
    if (fieldName[0] == 'f' && strcmp(fieldName, "firstSn") == 0) return base+2;
    if (fieldName[0] == 'l' && strcmp(fieldName, "lastSn") == 0) return base+3;
    if (fieldName[0] == 'b' && strcmp(fieldName, "bitmap") == 0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *LteRlcAmPduDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned short",    // FIELD_amType
        "unsigned short",    // FIELD_txNumber
        "int",    // FIELD_firstSn
        "int",    // FIELD_lastSn
        "bool",    // FIELD_bitmap
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **LteRlcAmPduDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_amType: {
            static const char *names[] = { "enum", "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *LteRlcAmPduDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_amType:
            if (!strcmp(propertyname, "enum")) return "LteAmType";
            if (!strcmp(propertyname, "enum")) return "LteAmType";
            return nullptr;
        default: return nullptr;
    }
}

int LteRlcAmPduDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    LteRlcAmPdu_Base *pp = (LteRlcAmPdu_Base *)object; (void)pp;
    switch (field) {
        case FIELD_bitmap: return pp->getBitmapArraySize();
        default: return 0;
    }
}

const char *LteRlcAmPduDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LteRlcAmPdu_Base *pp = (LteRlcAmPdu_Base *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string LteRlcAmPduDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LteRlcAmPdu_Base *pp = (LteRlcAmPdu_Base *)object; (void)pp;
    switch (field) {
        case FIELD_amType: return enum2string(pp->getAmType(), "LteAmType");
        case FIELD_txNumber: return ulong2string(pp->getTxNumber());
        case FIELD_firstSn: return long2string(pp->getFirstSn());
        case FIELD_lastSn: return long2string(pp->getLastSn());
        case FIELD_bitmap: return bool2string(pp->getBitmap(i));
        default: return "";
    }
}

bool LteRlcAmPduDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    LteRlcAmPdu_Base *pp = (LteRlcAmPdu_Base *)object; (void)pp;
    switch (field) {
        case FIELD_amType: pp->setAmType((LteAmType)string2enum(value, "LteAmType")); return true;
        case FIELD_txNumber: pp->setTxNumber(string2ulong(value)); return true;
        case FIELD_firstSn: pp->setFirstSn(string2long(value)); return true;
        case FIELD_lastSn: pp->setLastSn(string2long(value)); return true;
        case FIELD_bitmap: pp->setBitmap(i,string2bool(value)); return true;
        default: return false;
    }
}

const char *LteRlcAmPduDescriptor::getFieldStructName(int field) const
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

void *LteRlcAmPduDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    LteRlcAmPdu_Base *pp = (LteRlcAmPdu_Base *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

