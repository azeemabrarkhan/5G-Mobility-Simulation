//
// Generated file, do not edit! Created by nedtool 5.6 from common/LteCommonEnum.msg.
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
#include "LteCommonEnum_m.h"

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

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("Direction");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("Direction"));
    e->insert(DL, "DL");
    e->insert(UL, "UL");
    e->insert(D2D, "D2D");
    e->insert(D2D_MULTI, "D2D_MULTI");
    e->insert(UNKNOWN_DIRECTION, "UNKNOWN_DIRECTION");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("LteMod");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("LteMod"));
    e->insert(_QPSK, "_QPSK");
    e->insert(_16QAM, "_16QAM");
    e->insert(_64QAM, "_64QAM");
    e->insert(_256QAM, "_256QAM");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("FeedbackType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("FeedbackType"));
    e->insert(ALLBANDS, "ALLBANDS");
    e->insert(PREFERRED, "PREFERRED");
    e->insert(WIDEBAND, "WIDEBAND");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("FbPeriodicity");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("FbPeriodicity"));
    e->insert(PERIODIC, "PERIODIC");
    e->insert(APERIODIC, "APERIODIC");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("RbAllocationType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("RbAllocationType"));
    e->insert(TYPE2_DISTRIBUTED, "TYPE2_DISTRIBUTED");
    e->insert(TYPE2_LOCALIZED, "TYPE2_LOCALIZED");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("GateDirection");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("GateDirection"));
    e->insert(IN_GATE, "IN_GATE");
    e->insert(OUT_GATE, "OUT_GATE");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("LteTrafficClass");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("LteTrafficClass"));
    e->insert(CONVERSATIONAL, "CONVERSATIONAL");
    e->insert(STREAMING, "STREAMING");
    e->insert(INTERACTIVE, "INTERACTIVE");
    e->insert(BACKGROUND, "BACKGROUND");
    e->insert(UNKNOWN_TRAFFIC_TYPE, "UNKNOWN_TRAFFIC_TYPE");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("GrantType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("GrantType"));
    e->insert(FITALL, "FITALL");
    e->insert(FIXED_, "FIXED_");
    e->insert(URGENT, "URGENT");
    e->insert(UNKNOWN_GRANT_TYPE, "UNKNOWN_GRANT_TYPE");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("LteRlcType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("LteRlcType"));
    e->insert(TM, "TM");
    e->insert(UM, "UM");
    e->insert(AM, "AM");
    e->insert(UNKNOWN_RLC_TYPE, "UNKNOWN_RLC_TYPE");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("UlTransmissionMapTTI");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("UlTransmissionMapTTI"));
    e->insert(PREV_TTI, "PREV_TTI");
    e->insert(CURR_TTI, "CURR_TTI");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("LteD2DMode");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("LteD2DMode"));
    e->insert(IM, "IM");
    e->insert(DM, "DM");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("ApplicationType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("ApplicationType"));
    e->insert(VOIP, "VOIP");
    e->insert(VOD, "VOD");
    e->insert(WEB, "WEB");
    e->insert(CBR, "CBR");
    e->insert(FTP, "FTP");
    e->insert(GAMING, "GAMING");
    e->insert(FULLBUFFER, "FULLBUFFER");
    e->insert(UNKNOWN_APP, "UNKNOWN_APP");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("SchedDiscipline");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("SchedDiscipline"));
    e->insert(DRR, "DRR");
    e->insert(PF, "PF");
    e->insert(MAXCI, "MAXCI");
    e->insert(MAXCI_MB, "MAXCI_MB");
    e->insert(MAXCI_OPT_MB, "MAXCI_OPT_MB");
    e->insert(MAXCI_COMP, "MAXCI_COMP");
    e->insert(ALLOCATOR_BESTFIT, "ALLOCATOR_BESTFIT");
    e->insert(UNKNOWN_DISCIPLINE, "UNKNOWN_DISCIPLINE");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("PilotComputationModes");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("PilotComputationModes"));
    e->insert(MIN_CQI, "MIN_CQI");
    e->insert(MAX_CQI, "MAX_CQI");
    e->insert(AVG_CQI, "AVG_CQI");
    e->insert(MEDIAN_CQI, "MEDIAN_CQI");
    e->insert(ROBUST_CQI, "ROBUST_CQI");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("TxMode");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("TxMode"));
    e->insert(SINGLE_ANTENNA_PORT0, "SINGLE_ANTENNA_PORT0");
    e->insert(SINGLE_ANTENNA_PORT5, "SINGLE_ANTENNA_PORT5");
    e->insert(TRANSMIT_DIVERSITY, "TRANSMIT_DIVERSITY");
    e->insert(OL_SPATIAL_MULTIPLEXING, "OL_SPATIAL_MULTIPLEXING");
    e->insert(CL_SPATIAL_MULTIPLEXING, "CL_SPATIAL_MULTIPLEXING");
    e->insert(MULTI_USER, "MULTI_USER");
    e->insert(UNKNOWN_TX_MODE, "UNKNOWN_TX_MODE");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("TxDirectionType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("TxDirectionType"));
    e->insert(ANISOTROPIC, "ANISOTROPIC");
    e->insert(OMNI, "OMNI");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("FeedbackGeneratorType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("FeedbackGeneratorType"));
    e->insert(IDEAL, "IDEAL");
    e->insert(REAL, "REAL");
    e->insert(DAS_AWARE, "DAS_AWARE");
    e->insert(UNKNOW_FB_GEN_TYPE, "UNKNOW_FB_GEN_TYPE");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("Plane");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("Plane"));
    e->insert(MAIN_PLANE, "MAIN_PLANE");
    e->insert(MU_MIMO_PLANE, "MU_MIMO_PLANE");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("DeploymentScenario");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("DeploymentScenario"));
    e->insert(INDOOR_HOTSPOT, "INDOOR_HOTSPOT");
    e->insert(URBAN_MICROCELL, "URBAN_MICROCELL");
    e->insert(URBAN_MACROCELL, "URBAN_MACROCELL");
    e->insert(RURAL_MACROCELL, "RURAL_MACROCELL");
    e->insert(SUBURBAN_MACROCELL, "SUBURBAN_MACROCELL");
    e->insert(UNKNOW_SCENARIO, "UNKNOW_SCENARIO");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("Remote");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("Remote"));
    e->insert(MACRO, "MACRO");
    e->insert(RU1, "RU1");
    e->insert(RU2, "RU2");
    e->insert(RU3, "RU3");
    e->insert(RU4, "RU4");
    e->insert(RU5, "RU5");
    e->insert(RU6, "RU6");
    e->insert(UNKNOWN_RU, "UNKNOWN_RU");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("LtePhyFrameType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("LtePhyFrameType"));
    e->insert(DATAPKT, "DATAPKT");
    e->insert(BROADCASTPKT, "BROADCASTPKT");
    e->insert(FEEDBACKPKT, "FEEDBACKPKT");
    e->insert(HANDOVERPKT, "HANDOVERPKT");
    e->insert(HARQPKT, "HARQPKT");
    e->insert(GRANTPKT, "GRANTPKT");
    e->insert(RACPKT, "RACPKT");
    e->insert(D2DMODESWITCHPKT, "D2DMODESWITCHPKT");
    e->insert(UNKNOWN_TYPE, "UNKNOWN_TYPE");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("RanNodeType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("RanNodeType"));
    e->insert(INTERNET, "INTERNET");
    e->insert(ENODEB, "ENODEB");
    e->insert(GNODEB, "GNODEB");
    e->insert(UE, "UE");
    e->insert(UNKNOWN_NODE_TYPE, "UNKNOWN_NODE_TYPE");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("CoreNodeType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("CoreNodeType"));
    e->insert(ENB, "ENB");
    e->insert(PGW, "PGW");
    e->insert(SGW, "SGW");
    e->insert(GNB, "GNB");
    e->insert(UPF, "UPF");
    e->insert(GTPENDPOINT, "GTPENDPOINT");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("LteSubFrameType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("LteSubFrameType"));
    e->insert(NORMAL_FRAME_TYPE, "NORMAL_FRAME_TYPE");
    e->insert(MBSFN, "MBSFN");
    e->insert(PAGING, "PAGING");
    e->insert(BROADCAST, "BROADCAST");
    e->insert(SYNCRO, "SYNCRO");
    e->insert(ABS, "ABS");
    e->insert(UNKNOWN_FRAME_TYPE, "UNKNOWN_FRAME_TYPE");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("X2MsgType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("X2MsgType"));
    e->insert(ABS_INFO, "ABS_INFO");
    e->insert(ABS_STATUS_INFO, "ABS_STATUS_INFO");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("BsrType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("BsrType"));
    e->insert(SHORT_BSR, "SHORT_BSR");
    e->insert(D2D_SHORT_BSR, "D2D_SHORT_BSR");
    e->insert(D2D_MULTI_SHORT_BSR, "D2D_MULTI_SHORT_BSR");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("HarqAcknowledgment");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("HarqAcknowledgment"));
    e->insert(HARQNACK, "HARQNACK");
    e->insert(HARQACK, "HARQACK");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("TxHarqPduStatus");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("TxHarqPduStatus"));
    e->insert(TXHARQ_PDU_BUFFERED, "TXHARQ_PDU_BUFFERED");
    e->insert(TXHARQ_PDU_WAITING, "TXHARQ_PDU_WAITING");
    e->insert(TXHARQ_PDU_EMPTY, "TXHARQ_PDU_EMPTY");
    e->insert(TXHARQ_PDU_SELECTED, "TXHARQ_PDU_SELECTED");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("RxHarqPduStatus");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("RxHarqPduStatus"));
    e->insert(RXHARQ_PDU_EMPTY, "RXHARQ_PDU_EMPTY");
    e->insert(RXHARQ_PDU_EVALUATING, "RXHARQ_PDU_EVALUATING");
    e->insert(RXHARQ_PDU_CORRECT, "RXHARQ_PDU_CORRECT");
    e->insert(RXHARQ_PDU_CORRUPTED, "RXHARQ_PDU_CORRUPTED");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("EnbType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("EnbType"));
    e->insert(MACRO_ENB, "MACRO_ENB");
    e->insert(MICRO_ENB, "MICRO_ENB");
)

