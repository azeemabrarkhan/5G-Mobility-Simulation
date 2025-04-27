#
# OMNeT++/OMNEST Makefile for $(LIB_PREFIX)simu5g
#
# This file was generated with the command:
#  opp_makemake --make-so -f --deep -o simu5g -O out -KINET_PROJ=../../inet -DINET_IMPORT -I. -I$$\(INET_PROJ\)/src -L$$\(INET_PROJ\)/src -lINET$$\(D\)
#

# Name of target to be created (-o option)
TARGET = $(LIB_PREFIX)simu5g$(D)$(SHARED_LIB_SUFFIX)
TARGET_DIR = .

# C++ include paths (with -I)
INCLUDE_PATH = -I. -I$(INET_PROJ)/src

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS = $(LDFLAG_LIBPATH)$(INET_PROJ)/src  -lINET$(D)

# Output directory
PROJECT_OUTPUT_DIR = ../out
PROJECTRELATIVE_PATH = src
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc, .msg and .sm files
OBJS = \
    $O/apps/alert/AlertReceiver.o \
    $O/apps/alert/AlertSender.o \
    $O/apps/burst/BurstReceiver.o \
    $O/apps/burst/BurstSender.o \
    $O/apps/cbr/CbrReceiver.o \
    $O/apps/cbr/CbrSender.o \
    $O/apps/d2dMultihop/MultihopD2D.o \
    $O/apps/d2dMultihop/eventGenerator/EventGenerator.o \
    $O/apps/d2dMultihop/statistics/MultihopD2DStatistics.o \
    $O/apps/mec/warningAlert/MEWarningAlertApp.o \
    $O/apps/mec/warningAlert/UEWarningAlertApp.o \
    $O/apps/mecRequestResponseApp/MecRequestApp.o \
    $O/apps/mecRequestResponseApp/MecResponseApp.o \
    $O/apps/vod/VoDUDPClient.o \
    $O/apps/vod/VoDUDPServer.o \
    $O/apps/voip/VoipPacketSerializer.o \
    $O/apps/voip/VoIPReceiver.o \
    $O/apps/voip/VoIPSender.o \
    $O/common/LteCommon.o \
    $O/common/LteControlInfo.o \
    $O/common/binder/Binder.o \
    $O/common/blerCurves/PhyPisaData.o \
    $O/common/carrierAggregation/ComponentCarrier.o \
    $O/common/cellInfo/CellInfo.o \
    $O/common/timer/TTimer.o \
    $O/corenetwork/gtp/GtpUser.o \
    $O/corenetwork/gtp/GtpUserMsgSerializer.o \
    $O/corenetwork/gtp/GtpUserX2.o \
    $O/corenetwork/trafficFlowFilter/TrafficFlowFilter.o \
    $O/nodes/ExtCell.o \
    $O/nodes/mec/MEPlatform/GeneralServices/RadioNetworkInformation.o \
    $O/nodes/mec/MEPlatform/MEWarningAlertService/MEWarningAlertService.o \
    $O/nodes/mec/VirtualisationInfrastructure/ResourceManager.o \
    $O/nodes/mec/VirtualisationInfrastructure/VirtualisationManager.o \
    $O/stack/compManager/LteCompManagerBase.o \
    $O/stack/compManager/X2CompMsg.o \
    $O/stack/compManager/compManagerProportional/LteCompManagerProportional.o \
    $O/stack/d2dModeSelection/D2DModeSelectionBase.o \
    $O/stack/d2dModeSelection/d2dModeSelectionBestCqi/D2DModeSelectionBestCqi.o \
    $O/stack/dualConnectivityManager/DualConnectivityManager.o \
    $O/stack/dualConnectivityManager/X2DualConnectivityDataMsg.o \
    $O/stack/handoverManager/LteHandoverManager.o \
    $O/stack/handoverManager/X2HandoverControlMsg.o \
    $O/stack/ip2nic/IP2Nic.o \
    $O/stack/ip2nic/SplitBearersTable.o \
    $O/stack/mac/allocator/LteAllocationModule.o \
    $O/stack/mac/allocator/LteAllocationModuleFrequencyReuse.o \
    $O/stack/mac/amc/AmcPilotAuto.o \
    $O/stack/mac/amc/AmcPilotD2D.o \
    $O/stack/mac/amc/LteAmc.o \
    $O/stack/mac/amc/LteMcs.o \
    $O/stack/mac/amc/NRAmc.o \
    $O/stack/mac/amc/NRMcs.o \
    $O/stack/mac/amc/UserTxParams.o \
    $O/stack/mac/buffer/LteMacBuffer.o \
    $O/stack/mac/buffer/LteMacQueue.o \
    $O/stack/mac/buffer/harq/LteHarqBufferRx.o \
    $O/stack/mac/buffer/harq/LteHarqBufferTx.o \
    $O/stack/mac/buffer/harq/LteHarqProcessRx.o \
    $O/stack/mac/buffer/harq/LteHarqProcessTx.o \
    $O/stack/mac/buffer/harq/LteHarqUnitTx.o \
    $O/stack/mac/buffer/harq_d2d/LteHarqBufferMirrorD2D.o \
    $O/stack/mac/buffer/harq_d2d/LteHarqBufferRxD2D.o \
    $O/stack/mac/buffer/harq_d2d/LteHarqBufferTxD2D.o \
    $O/stack/mac/buffer/harq_d2d/LteHarqProcessMirrorD2D.o \
    $O/stack/mac/buffer/harq_d2d/LteHarqProcessRxD2D.o \
    $O/stack/mac/buffer/harq_d2d/LteHarqProcessTxD2D.o \
    $O/stack/mac/buffer/harq_d2d/LteHarqUnitTxD2D.o \
    $O/stack/mac/conflict_graph/ConflictGraph.o \
    $O/stack/mac/conflict_graph/DistanceBasedConflictGraph.o \
    $O/stack/mac/layer/LteMacBase.o \
    $O/stack/mac/layer/LteMacEnb.o \
    $O/stack/mac/layer/LteMacEnbD2D.o \
    $O/stack/mac/layer/LteMacUe.o \
    $O/stack/mac/layer/LteMacUeD2D.o \
    $O/stack/mac/layer/NRMacGnb.o \
    $O/stack/mac/layer/NRMacUe.o \
    $O/stack/mac/packet/LteMacPdu.o \
    $O/stack/mac/scheduler/LcgScheduler.o \
    $O/stack/mac/scheduler/LteScheduler.o \
    $O/stack/mac/scheduler/LteSchedulerEnb.o \
    $O/stack/mac/scheduler/LteSchedulerEnbDl.o \
    $O/stack/mac/scheduler/LteSchedulerEnbUl.o \
    $O/stack/mac/scheduler/LteSchedulerUeUl.o \
    $O/stack/mac/scheduler/NRSchedulerGnbUl.o \
    $O/stack/mac/scheduling_modules/LteAllocatorBestFit.o \
    $O/stack/mac/scheduling_modules/LteDrr.o \
    $O/stack/mac/scheduling_modules/LteMaxCi.o \
    $O/stack/mac/scheduling_modules/LteMaxCiComp.o \
    $O/stack/mac/scheduling_modules/LteMaxCiMultiband.o \
    $O/stack/mac/scheduling_modules/LteMaxCiOptMB.o \
    $O/stack/mac/scheduling_modules/LtePf.o \
    $O/stack/pdcp_rrc/ConnectionsTable.o \
    $O/stack/pdcp_rrc/layer/LtePdcpRrc.o \
    $O/stack/pdcp_rrc/layer/LtePdcpRrcEnbD2D.o \
    $O/stack/pdcp_rrc/layer/LtePdcpRrcUeD2D.o \
    $O/stack/pdcp_rrc/layer/NRPdcpRrcEnb.o \
    $O/stack/pdcp_rrc/layer/NRPdcpRrcUe.o \
    $O/stack/pdcp_rrc/layer/entity/LteRxPdcpEntity.o \
    $O/stack/pdcp_rrc/layer/entity/LteTxPdcpEntity.o \
    $O/stack/pdcp_rrc/layer/entity/NRRxPdcpEntity.o \
    $O/stack/pdcp_rrc/layer/entity/NRTxPdcpEntity.o \
    $O/stack/phy/ChannelModel/LteChannelModel.o \
    $O/stack/phy/ChannelModel/LteDummyChannelModel.o \
    $O/stack/phy/ChannelModel/LteRealisticChannelModel.o \
    $O/stack/phy/ChannelModel/NRChannelModel.o \
    $O/stack/phy/das/DasFilter.o \
    $O/stack/phy/das/RemoteAntennaSet.o \
    $O/stack/phy/feedback/LteDlFeedbackGenerator.o \
    $O/stack/phy/feedback/LteFeedback.o \
    $O/stack/phy/feedback/LteFeedbackComputation.o \
    $O/stack/phy/feedback/LteFeedbackComputationRealistic.o \
    $O/stack/phy/feedback/LteSummaryBuffer.o \
    $O/stack/phy/feedback/LteSummaryFeedback.o \
    $O/stack/phy/feedback/testFeedback/FeedbackTester.o \
    $O/stack/phy/layer/LtePhyBase.o \
    $O/stack/phy/layer/LtePhyEnb.o \
    $O/stack/phy/layer/LtePhyEnbD2D.o \
    $O/stack/phy/layer/LtePhyUe.o \
    $O/stack/phy/layer/LtePhyUeD2D.o \
    $O/stack/phy/layer/NRPhyUe.o \
    $O/stack/phy/packet/LteAirFrame.o \
    $O/stack/phy/packet/LteFeedbackPkt.o \
    $O/stack/rlc/LteRlcMux.o \
    $O/stack/rlc/am/LteRlcAm.o \
    $O/stack/rlc/am/buffer/AmRxQueue.o \
    $O/stack/rlc/am/buffer/AmTxQueue.o \
    $O/stack/rlc/am/packet/LteRlcAmPdu.o \
    $O/stack/rlc/packet/LteRlcDataPdu.o \
    $O/stack/rlc/tm/LteRlcTm.o \
    $O/stack/rlc/um/LteRlcUm.o \
    $O/stack/rlc/um/LteRlcUmD2D.o \
    $O/stack/rlc/um/entity/UmRxEntity.o \
    $O/stack/rlc/um/entity/UmTxEntity.o \
    $O/world/radio/ChannelAccess.o \
    $O/world/radio/ChannelControl.o \
    $O/world/radio/LteChannelControl.o \
    $O/x2/LteX2Manager.o \
    $O/x2/X2AppClient.o \
    $O/x2/X2AppServer.o \
    $O/x2/packet/LteX2MsgSerializer.o \
    $O/apps/alert/AlertPacket_m.o \
    $O/apps/burst/BurstPacket_m.o \
    $O/apps/cbr/CbrPacket_m.o \
    $O/apps/d2dMultihop/MultihopD2DPacket_m.o \
    $O/apps/d2dMultihop/TrickleTimerMsg_m.o \
    $O/apps/mec/warningAlert/packets/WarningAlertPacket_m.o \
    $O/apps/mecRequestResponseApp/packets/MecRequestResponsePacket_m.o \
    $O/apps/mecRequestResponseApp/packets/MigrationTimer_m.o \
    $O/apps/vod/M1Message_m.o \
    $O/apps/vod/VoDPacket_m.o \
    $O/apps/voip/VoipPacket_m.o \
    $O/common/LteCommon_m.o \
    $O/common/LteCommonEnum_m.o \
    $O/common/LteControlInfo_m.o \
    $O/common/timer/TMultiTimerMsg_m.o \
    $O/common/timer/TTimerMsg_m.o \
    $O/corenetwork/gtp/GtpUserMsg_m.o \
    $O/corenetwork/trafficFlowFilter/TftControlInfo_m.o \
    $O/nodes/mec/MEPlatform/MEAppPacket_m.o \
    $O/stack/d2dModeSelection/D2DModeSwitchNotification_m.o \
    $O/stack/mac/packet/LteHarqFeedback_m.o \
    $O/stack/mac/packet/LteMacPdu_m.o \
    $O/stack/mac/packet/LteMacSduRequest_m.o \
    $O/stack/mac/packet/LteRac_m.o \
    $O/stack/mac/packet/LteSchedulingGrant_m.o \
    $O/stack/pdcp_rrc/packet/LtePdcpPdu_m.o \
    $O/stack/pdcp_rrc/packet/LteRohcPdu_m.o \
    $O/stack/phy/packet/AirFrame_m.o \
    $O/stack/phy/packet/LteAirFrame_m.o \
    $O/stack/phy/packet/LteFeedbackPkt_m.o \
    $O/stack/rlc/LteRlcDefs_m.o \
    $O/stack/rlc/am/packet/LteRlcAmPdu_m.o \
    $O/stack/rlc/am/packet/LteRlcAmSdu_m.o \
    $O/stack/rlc/packet/LteRlcDataPdu_m.o \
    $O/stack/rlc/packet/LteRlcPdu_m.o \
    $O/stack/rlc/packet/LteRlcSdu_m.o \
    $O/x2/packet/LteX2Message_m.o \
    $O/x2/packet/X2ControlInfo_m.o

# Message files
MSGFILES = \
    apps/alert/AlertPacket.msg \
    apps/burst/BurstPacket.msg \
    apps/cbr/CbrPacket.msg \
    apps/d2dMultihop/MultihopD2DPacket.msg \
    apps/d2dMultihop/TrickleTimerMsg.msg \
    apps/mec/warningAlert/packets/WarningAlertPacket.msg \
    apps/mecRequestResponseApp/packets/MecRequestResponsePacket.msg \
    apps/mecRequestResponseApp/packets/MigrationTimer.msg \
    apps/vod/M1Message.msg \
    apps/vod/VoDPacket.msg \
    apps/voip/VoipPacket.msg \
    common/LteCommon.msg \
    common/LteCommonEnum.msg \
    common/LteControlInfo.msg \
    common/timer/TMultiTimerMsg.msg \
    common/timer/TTimerMsg.msg \
    corenetwork/gtp/GtpUserMsg.msg \
    corenetwork/trafficFlowFilter/TftControlInfo.msg \
    nodes/mec/MEPlatform/MEAppPacket.msg \
    stack/d2dModeSelection/D2DModeSwitchNotification.msg \
    stack/mac/packet/LteHarqFeedback.msg \
    stack/mac/packet/LteMacPdu.msg \
    stack/mac/packet/LteMacSduRequest.msg \
    stack/mac/packet/LteRac.msg \
    stack/mac/packet/LteSchedulingGrant.msg \
    stack/pdcp_rrc/packet/LtePdcpPdu.msg \
    stack/pdcp_rrc/packet/LteRohcPdu.msg \
    stack/phy/packet/AirFrame.msg \
    stack/phy/packet/LteAirFrame.msg \
    stack/phy/packet/LteFeedbackPkt.msg \
    stack/rlc/LteRlcDefs.msg \
    stack/rlc/am/packet/LteRlcAmPdu.msg \
    stack/rlc/am/packet/LteRlcAmSdu.msg \
    stack/rlc/packet/LteRlcDataPdu.msg \
    stack/rlc/packet/LteRlcPdu.msg \
    stack/rlc/packet/LteRlcSdu.msg \
    x2/packet/LteX2Message.msg \
    x2/packet/X2ControlInfo.msg

# SM files
SMFILES =

# Other makefile variables (-K)
INET_PROJ=../../inet

#------------------------------------------------------------------------------

# Pull in OMNeT++ configuration (Makefile.inc)

ifneq ("$(OMNETPP_CONFIGFILE)","")
CONFIGFILE = $(OMNETPP_CONFIGFILE)
else
ifneq ("$(OMNETPP_ROOT)","")
CONFIGFILE = $(OMNETPP_ROOT)/Makefile.inc
else
CONFIGFILE = $(shell opp_configfilepath)
endif
endif

ifeq ("$(wildcard $(CONFIGFILE))","")
$(error Config file '$(CONFIGFILE)' does not exist -- add the OMNeT++ bin directory to the path so that opp_configfilepath can be found, or set the OMNETPP_CONFIGFILE variable to point to Makefile.inc)
endif

include $(CONFIGFILE)

# Simulation kernel and user interface libraries
OMNETPP_LIBS = -loppenvir$D $(KERNEL_LIBS) $(SYS_LIBS)
ifneq ($(TOOLCHAIN_NAME),clangc2)
LIBS += -Wl,-rpath,$(abspath $(INET_PROJ)/src)
endif

COPTS = $(CFLAGS) $(IMPORT_DEFINES) -DINET_IMPORT $(INCLUDE_PATH) -I$(OMNETPP_INCL_DIR)
MSGCOPTS = $(INCLUDE_PATH)
SMCOPTS =

# we want to recompile everything if COPTS changes,
# so we store COPTS into $COPTS_FILE and have object
# files depend on it (except when "make depend" was called)
COPTS_FILE = $O/.last-copts
ifneq ("$(COPTS)","$(shell cat $(COPTS_FILE) 2>/dev/null || echo '')")
$(shell $(MKPATH) "$O" && echo "$(COPTS)" >$(COPTS_FILE))
endif

#------------------------------------------------------------------------------
# User-supplied makefile fragment(s)
# >>>
# inserted from file 'makefrag':
#
# Use the new message compiler introduced in OMNeT++ 5.3
#
MSGC:=$(MSGC) --msg6

#
# on Windows we have to link with the winsock2 library as it is no longer added
# to the omnetpp system libraries by default (as of OMNeT++ 5.1)
#
ifeq ($(PLATFORM),win32.x86_64)
  LDFLAGS += -lws2_32
endif

# <<<
#------------------------------------------------------------------------------

# Main target
all: $(TARGET_DIR)/$(TARGET)

$(TARGET_DIR)/% :: $O/%
	@mkdir -p $(TARGET_DIR)
	$(Q)$(LN) $< $@
ifeq ($(TOOLCHAIN_NAME),clangc2)
	$(Q)-$(LN) $(<:%.dll=%.lib) $(@:%.dll=%.lib)
endif

$O/$(TARGET): $(OBJS)  $(wildcard $(EXTRA_OBJS)) Makefile $(CONFIGFILE)
	@$(MKPATH) $O
	@echo Creating shared library: $@
	$(Q)echo >.tmp$$$$ $(OBJS) $(EXTRA_OBJS) && $(AR) .tmplib$$$$ @.tmp$$$$ && $(SHLIB_LD) -o $O/$(TARGET) $(AS_NEEDED_OFF) $(WHOLE_ARCHIVE_ON) .tmplib$$$$ $(LIBS) $(WHOLE_ARCHIVE_OFF) $(OMNETPP_LIBS) $(LDFLAGS) && rm .tmp$$$$ && rm .tmplib$$$$
	$(Q)$(SHLIB_POSTPROCESS) $O/$(TARGET)

.PHONY: all clean cleanall depend msgheaders smheaders

.SUFFIXES: .cc

$O/%.o: %.cc $(COPTS_FILE) | msgheaders smheaders
	@$(MKPATH) $(dir $@)
	$(qecho) "$<"
	$(Q)$(CXX) -c $(CXXFLAGS) $(COPTS) -o $@ $<

%_m.cc %_m.h: %.msg
	$(qecho) MSGC: $<
	$(Q)$(MSGC) -s _m.cc -MD -MP -MF $O/$(basename $<)_m.h.d $(MSGCOPTS) $?

%_sm.cc %_sm.h: %.sm
	$(qecho) SMC: $<
	$(Q)$(SMC) -c++ -suffix cc $(SMCOPTS) $?

msgheaders: $(MSGFILES:.msg=_m.h)

smheaders: $(SMFILES:.sm=_sm.h)

clean:
	$(qecho) Cleaning $(TARGET)
	$(Q)-rm -rf $O
	$(Q)-rm -f $(TARGET_DIR)/$(TARGET)
	$(Q)-rm -f $(TARGET_DIR)/$(TARGET:%.dll=%.lib)
	$(Q)-rm -f $(call opp_rwildcard, . , *_m.cc *_m.h *_sm.cc *_sm.h)

cleanall:
	$(Q)$(MAKE) -s clean MODE=release
	$(Q)$(MAKE) -s clean MODE=debug
	$(Q)-rm -rf $(PROJECT_OUTPUT_DIR)

# include all dependencies
-include $(OBJS:%=%.d) $(MSGFILES:%.msg=$O/%_m.h.d)
