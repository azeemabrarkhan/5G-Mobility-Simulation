#
# OMNeT++/OMNEST Makefile for $(LIB_PREFIX)ULTRAS
#
# This file was generated with the command:
#  opp_makemake --make-so -f --deep -KINET_PROJ=../../inet -KSIMU5G_PROJ=../../Simu5G-1.1.0 -DINET_IMPORT -I../data -I$$\(INET_PROJ\)/src -I. -I$$\(SIMU5G_PROJ\)/src -L$$\(INET_PROJ\)/src -L$$\(SIMU5G_PROJ\)/src -lINET$$\(D\) -lsimu5g$$\(D\)
#

# Name of target to be created (-o option)
TARGET = $(LIB_PREFIX)ULTRAS$(D)$(SHARED_LIB_SUFFIX)
TARGET_DIR = .

# C++ include paths (with -I)
INCLUDE_PATH = -I../data -I$(INET_PROJ)/src -I. -I$(SIMU5G_PROJ)/src

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS = $(LDFLAG_LIBPATH)$(INET_PROJ)/src $(LDFLAG_LIBPATH)$(SIMU5G_PROJ)/src  -lINET$(D) -lsimu5g$(D)

# Output directory
PROJECT_OUTPUT_DIR = ../out
PROJECTRELATIVE_PATH = src
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc, .msg and .sm files
OBJS = \
    $O/modules/LoadConfiguration.o \
    $O/modules/communication/AgentInfo.o \
    $O/modules/communication/NR/App/GSReceiverApp.o \
    $O/modules/communication/NR/App/GSSenderApp.o \
    $O/modules/communication/NR/App/WirelessReceiverApp.o \
    $O/modules/communication/NR/App/WirelessSenderApp.o \
    $O/modules/communication/NR/Application/TestReceiverApp.o \
    $O/modules/communication/NR/Application/TestSenderApp.o \
    $O/modules/communication/ideal/GroundWirelessInterface.o \
    $O/modules/communication/ideal/WirelessInterface.o \
    $O/modules/control/Control_PositionAttitude_NoDynamics.o \
    $O/modules/control/GNC.o \
    $O/modules/dynamics/Dynamics_NoDynamics.o \
    $O/modules/dynamics/VehicleDynamics.o \
    $O/modules/environment/ExternalDisturbances.o \
    $O/modules/groundStation/GlobalSensorFusion.o \
    $O/modules/groundStation/SituationControlCenter.o \
    $O/modules/planning/FlightScheduleManager.o \
    $O/modules/sensors/GPS.o \
    $O/modules/sensors/Radar.o \
    $O/modules/vehicle/CommunicationCoordinator.o \
    $O/modules/vehicle/LocalSensorFusion.o \
    $O/modules/vehicle/LocalSituationPicture.o \
    $O/util/AgentMobiliy.o \
    $O/util/DataTypes/Images.o \
    $O/util/DataTypes/UQuaternion.o \
    $O/util/DataTypes/URotationMatrix.o \
    $O/util/configuration/ultras_dynamic_configuration.o \
    $O/util/configuration/ultras_dynamic_configuration_test.o \
    $O/util/configuration/xpath_facade.o \
    $O/util/configuration/tinyxpath/action_store.o \
    $O/util/configuration/tinyxpath/htmlutil.o \
    $O/util/configuration/tinyxpath/lex_util.o \
    $O/util/configuration/tinyxpath/main.o \
    $O/util/configuration/tinyxpath/node_set.o \
    $O/util/configuration/tinyxpath/tinystr.o \
    $O/util/configuration/tinyxpath/tinyxml.o \
    $O/util/configuration/tinyxpath/tinyxmlerror.o \
    $O/util/configuration/tinyxpath/tinyxmlparser.o \
    $O/util/configuration/tinyxpath/tokenlist.o \
    $O/util/configuration/tinyxpath/xml_util.o \
    $O/util/configuration/tinyxpath/xpath_expression.o \
    $O/util/configuration/tinyxpath/xpath_processor.o \
    $O/util/configuration/tinyxpath/xpath_stack.o \
    $O/util/configuration/tinyxpath/xpath_static.o \
    $O/util/configuration/tinyxpath/xpath_stream.o \
    $O/util/configuration/tinyxpath/xpath_syntax.o \
    $O/messages/CreationMsg_m.o \
    $O/messages/SensorMsg_m.o \
    $O/messages/WirelessMsg_m.o \
    $O/modules/communication/NR/App/WirelessAppPacket_m.o \
    $O/modules/communication/NR/Application/TestSenderAppPacket_m.o

# Message files
MSGFILES = \
    messages/CreationMsg.msg \
    messages/SensorMsg.msg \
    messages/WirelessMsg.msg \
    modules/communication/NR/App/WirelessAppPacket.msg \
    modules/communication/NR/Application/TestSenderAppPacket.msg

# SM files
SMFILES =

# Other makefile variables (-K)
INET_PROJ=../../inet
SIMU5G_PROJ=../../Simu5G-1.1.0

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
LIBS += -Wl,-rpath,$(abspath $(INET_PROJ)/src) -Wl,-rpath,$(abspath $(SIMU5G_PROJ)/src)
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
MSGC:=$(MSGC) --msg6

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
	$(Q)$(SHLIB_LD) -o $O/$(TARGET) $(OBJS) $(EXTRA_OBJS) $(AS_NEEDED_OFF) $(WHOLE_ARCHIVE_ON) $(LIBS) $(WHOLE_ARCHIVE_OFF) $(OMNETPP_LIBS) $(LDFLAGS)
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
