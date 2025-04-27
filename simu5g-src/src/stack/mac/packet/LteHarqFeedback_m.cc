//
// Generated file, do not edit! Created by nedtool 5.6 from stack/mac/packet/LteHarqFeedback.msg.
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
#include "LteHarqFeedback_m.h"

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

Register_Class(LteHarqFeedback)

LteHarqFeedback::LteHarqFeedback() : ::inet::FieldsChunk()
{
    this->setChunkLength(inet::B(1));

}

LteHarqFeedback::LteHarqFeedback(const LteHarqFeedback& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

LteHarqFeedback::~LteHarqFeedback()
{
}

LteHarqFeedback& LteHarqFeedback::operator=(const LteHarqFeedback& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void LteHarqFeedback::copy(const LteHarqFeedback& other)
{
    this->acid = other.acid;
    this->cw = other.cw;
    this->result = other.result;
    this->fbMacPduId = other.fbMacPduId;
    this->d2dFeedback = other.d2dFeedback;
}

void LteHarqFeedback::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->acid);
    doParsimPacking(b,this->cw);
    doParsimPacking(b,this->result);
    doParsimPacking(b,this->fbMacPduId);
    doParsimPacking(b,this->d2dFeedback);
}

void LteHarqFeedback::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->acid);
    doParsimUnpacking(b,this->cw);
    doParsimUnpacking(b,this->result);
    doParsimUnpacking(b,this->fbMacPduId);
    doParsimUnpacking(b,this->d2dFeedback);
}

unsigned char LteHarqFeedback::getAcid() const
{
    return this->acid;
}

void LteHarqFeedback::setAcid(unsigned char acid)
{
    handleChange();
    this->acid = acid;
}

unsigned char LteHarqFeedback::getCw() const
{
    return this->cw;
}

void LteHarqFeedback::setCw(unsigned char cw)
{
    handleChange();
    this->cw = cw;
}

bool LteHarqFeedback::getResult() const
{
    return this->result;
}

void LteHarqFeedback::setResult(bool result)
{
    handleChange();
    this->result = result;
}

long LteHarqFeedback::getFbMacPduId() const
{
    return this->fbMacPduId;
}

void LteHarqFeedback::setFbMacPduId(long fbMacPduId)
{
    handleChange();
    this->fbMacPduId = fbMacPduId;
}

bool LteHarqFeedback::getD2dFeedback() const
{
    return this->d2dFeedback;
}

void LteHarqFeedback::setD2dFeedback(bool d2dFeedback)
{
    handleChange();
    this->d2dFeedback = d2dFeedback;
}

class LteHarqFeedbackDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_acid,
        FIELD_cw,
        FIELD_result,
        FIELD_fbMacPduId,
        FIELD_d2dFeedback,
    };
  public:
    LteHarqFeedbackDescriptor();
    virtual ~LteHarqFeedbackDescriptor();

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

Register_ClassDescriptor(LteHarqFeedbackDescriptor)

LteHarqFeedbackDescriptor::LteHarqFeedbackDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(LteHarqFeedback)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

LteHarqFeedbackDescriptor::~LteHarqFeedbackDescriptor()
{
    delete[] propertynames;
}

bool LteHarqFeedbackDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<LteHarqFeedback *>(obj)!=nullptr;
}

const char **LteHarqFeedbackDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *LteHarqFeedbackDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int LteHarqFeedbackDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int LteHarqFeedbackDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_acid
        FD_ISEDITABLE,    // FIELD_cw
        FD_ISEDITABLE,    // FIELD_result
        FD_ISEDITABLE,    // FIELD_fbMacPduId
        FD_ISEDITABLE,    // FIELD_d2dFeedback
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *LteHarqFeedbackDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "acid",
        "cw",
        "result",
        "fbMacPduId",
        "d2dFeedback",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int LteHarqFeedbackDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'a' && strcmp(fieldName, "acid") == 0) return base+0;
    if (fieldName[0] == 'c' && strcmp(fieldName, "cw") == 0) return base+1;
    if (fieldName[0] == 'r' && strcmp(fieldName, "result") == 0) return base+2;
    if (fieldName[0] == 'f' && strcmp(fieldName, "fbMacPduId") == 0) return base+3;
    if (fieldName[0] == 'd' && strcmp(fieldName, "d2dFeedback") == 0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *LteHarqFeedbackDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned char",    // FIELD_acid
        "unsigned char",    // FIELD_cw
        "bool",    // FIELD_result
        "long",    // FIELD_fbMacPduId
        "bool",    // FIELD_d2dFeedback
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **LteHarqFeedbackDescriptor::getFieldPropertyNames(int field) const
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

const char *LteHarqFeedbackDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int LteHarqFeedbackDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    LteHarqFeedback *pp = (LteHarqFeedback *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *LteHarqFeedbackDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LteHarqFeedback *pp = (LteHarqFeedback *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string LteHarqFeedbackDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LteHarqFeedback *pp = (LteHarqFeedback *)object; (void)pp;
    switch (field) {
        case FIELD_acid: return ulong2string(pp->getAcid());
        case FIELD_cw: return ulong2string(pp->getCw());
        case FIELD_result: return bool2string(pp->getResult());
        case FIELD_fbMacPduId: return long2string(pp->getFbMacPduId());
        case FIELD_d2dFeedback: return bool2string(pp->getD2dFeedback());
        default: return "";
    }
}

bool LteHarqFeedbackDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    LteHarqFeedback *pp = (LteHarqFeedback *)object; (void)pp;
    switch (field) {
        case FIELD_acid: pp->setAcid(string2ulong(value)); return true;
        case FIELD_cw: pp->setCw(string2ulong(value)); return true;
        case FIELD_result: pp->setResult(string2bool(value)); return true;
        case FIELD_fbMacPduId: pp->setFbMacPduId(string2long(value)); return true;
        case FIELD_d2dFeedback: pp->setD2dFeedback(string2bool(value)); return true;
        default: return false;
    }
}

const char *LteHarqFeedbackDescriptor::getFieldStructName(int field) const
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

void *LteHarqFeedbackDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    LteHarqFeedback *pp = (LteHarqFeedback *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(LteHarqFeedbackMirror)

LteHarqFeedbackMirror::LteHarqFeedbackMirror() : ::LteHarqFeedback()
{
    this->setD2dFeedback(true);

}

LteHarqFeedbackMirror::LteHarqFeedbackMirror(const LteHarqFeedbackMirror& other) : ::LteHarqFeedback(other)
{
    copy(other);
}

LteHarqFeedbackMirror::~LteHarqFeedbackMirror()
{
}

LteHarqFeedbackMirror& LteHarqFeedbackMirror::operator=(const LteHarqFeedbackMirror& other)
{
    if (this == &other) return *this;
    ::LteHarqFeedback::operator=(other);
    copy(other);
    return *this;
}

void LteHarqFeedbackMirror::copy(const LteHarqFeedbackMirror& other)
{
    this->d2dSenderId = other.d2dSenderId;
    this->d2dReceiverId = other.d2dReceiverId;
    this->pduLength = other.pduLength;
}

void LteHarqFeedbackMirror::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::LteHarqFeedback::parsimPack(b);
    doParsimPacking(b,this->d2dSenderId);
    doParsimPacking(b,this->d2dReceiverId);
    doParsimPacking(b,this->pduLength);
}

void LteHarqFeedbackMirror::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::LteHarqFeedback::parsimUnpack(b);
    doParsimUnpacking(b,this->d2dSenderId);
    doParsimUnpacking(b,this->d2dReceiverId);
    doParsimUnpacking(b,this->pduLength);
}

long LteHarqFeedbackMirror::getD2dSenderId() const
{
    return this->d2dSenderId;
}

void LteHarqFeedbackMirror::setD2dSenderId(long d2dSenderId)
{
    handleChange();
    this->d2dSenderId = d2dSenderId;
}

long LteHarqFeedbackMirror::getD2dReceiverId() const
{
    return this->d2dReceiverId;
}

void LteHarqFeedbackMirror::setD2dReceiverId(long d2dReceiverId)
{
    handleChange();
    this->d2dReceiverId = d2dReceiverId;
}

long LteHarqFeedbackMirror::getPduLength() const
{
    return this->pduLength;
}

void LteHarqFeedbackMirror::setPduLength(long pduLength)
{
    handleChange();
    this->pduLength = pduLength;
}

class LteHarqFeedbackMirrorDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_d2dSenderId,
        FIELD_d2dReceiverId,
        FIELD_pduLength,
    };
  public:
    LteHarqFeedbackMirrorDescriptor();
    virtual ~LteHarqFeedbackMirrorDescriptor();

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

Register_ClassDescriptor(LteHarqFeedbackMirrorDescriptor)

LteHarqFeedbackMirrorDescriptor::LteHarqFeedbackMirrorDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(LteHarqFeedbackMirror)), "LteHarqFeedback")
{
    propertynames = nullptr;
}

LteHarqFeedbackMirrorDescriptor::~LteHarqFeedbackMirrorDescriptor()
{
    delete[] propertynames;
}

bool LteHarqFeedbackMirrorDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<LteHarqFeedbackMirror *>(obj)!=nullptr;
}

const char **LteHarqFeedbackMirrorDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *LteHarqFeedbackMirrorDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int LteHarqFeedbackMirrorDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int LteHarqFeedbackMirrorDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_d2dSenderId
        FD_ISEDITABLE,    // FIELD_d2dReceiverId
        FD_ISEDITABLE,    // FIELD_pduLength
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *LteHarqFeedbackMirrorDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "d2dSenderId",
        "d2dReceiverId",
        "pduLength",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int LteHarqFeedbackMirrorDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'd' && strcmp(fieldName, "d2dSenderId") == 0) return base+0;
    if (fieldName[0] == 'd' && strcmp(fieldName, "d2dReceiverId") == 0) return base+1;
    if (fieldName[0] == 'p' && strcmp(fieldName, "pduLength") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *LteHarqFeedbackMirrorDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "long",    // FIELD_d2dSenderId
        "long",    // FIELD_d2dReceiverId
        "long",    // FIELD_pduLength
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **LteHarqFeedbackMirrorDescriptor::getFieldPropertyNames(int field) const
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

const char *LteHarqFeedbackMirrorDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int LteHarqFeedbackMirrorDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    LteHarqFeedbackMirror *pp = (LteHarqFeedbackMirror *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *LteHarqFeedbackMirrorDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LteHarqFeedbackMirror *pp = (LteHarqFeedbackMirror *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string LteHarqFeedbackMirrorDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LteHarqFeedbackMirror *pp = (LteHarqFeedbackMirror *)object; (void)pp;
    switch (field) {
        case FIELD_d2dSenderId: return long2string(pp->getD2dSenderId());
        case FIELD_d2dReceiverId: return long2string(pp->getD2dReceiverId());
        case FIELD_pduLength: return long2string(pp->getPduLength());
        default: return "";
    }
}

bool LteHarqFeedbackMirrorDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    LteHarqFeedbackMirror *pp = (LteHarqFeedbackMirror *)object; (void)pp;
    switch (field) {
        case FIELD_d2dSenderId: pp->setD2dSenderId(string2long(value)); return true;
        case FIELD_d2dReceiverId: pp->setD2dReceiverId(string2long(value)); return true;
        case FIELD_pduLength: pp->setPduLength(string2long(value)); return true;
        default: return false;
    }
}

const char *LteHarqFeedbackMirrorDescriptor::getFieldStructName(int field) const
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

void *LteHarqFeedbackMirrorDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    LteHarqFeedbackMirror *pp = (LteHarqFeedbackMirror *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

