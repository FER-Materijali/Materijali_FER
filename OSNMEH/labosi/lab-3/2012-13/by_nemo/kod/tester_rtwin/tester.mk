# Abstract:
#	Real-Time Workshop template makefile for building Real-Time Windows
#	Target compatible real-time version of Simulink model using generated
#       C code and the built-in Open Watcom C/C++ Compiler.
#
# 	This makefile is designed to be used with GNU Make (gmake) which is
#       located in matlabroot/bin/win32.
#
# 	Note that this template is automatically customized by the Real-Time
#	Workshop build procedure to create "<model>.mk"
#
#       The following defines (macro names) can be used to modify the behavior
#       of the build:
#	  OPT_OPTS       - Optimization options.
#	  OPTS           - User-specified compiler options.
#         CPP_OPTS       - User-specified C++ compiler options.
#	  USER_SRCS      - Additional user objects, such as files needed by
#			   S-functions.
#	  USER_INCLUDES  - Additional include paths (i.e.
#			   "USER_INCLUDES=-Iinclude-path1;include-path2")
#                          Use a '/' as a file separator instead of '\'.
#
#       Consider using the "Build process" dialog in Real-Time Workshop
#       options page instead of trying to change OPT_OPTS here.
#
#       This template makefile is designed to be used with a system target
#       file that contains 'rtwgensettings.ProjectDirSuffix', see grt.tlc .
#
# $Revision: 1.1.6.20.2.1 $  $Date: 2009/01/05 16:44:28 $  $Author: batserve $
# Copyright 1994-2008 The MathWorks, Inc.



#------------------------ Macros read by make_rtw -----------------------------
#
# The following macros are read by the Real-Time Workshop build procedure:
#  MAKECMD         - This is the command used to invoke the make utility
#  HOST            - What platform this template makefile is targeted for
#                    (i.e. PC or UNIX)
#  BUILD           - Invoke make from the Real-Time Workshop build procedure
#                    (yes/no)?
#  SYS_TARGET_FILE - Name of system target file.
#

MAKECMD         = "C:/PROGRA~1/MATLAB/R2009a/bin/win32/gmake"
HOST            = PC
BUILD           = yes
SYS_TARGET_FILE = rtwin.tlc
MAKEFILE_FILESEP = /


#---------------------- Tokens expanded by make_rtw ---------------------------
#
# The following tokens, when wrapped with "|>" and "<|" are expanded by the
# Real-Time Workshop build procedure.
#
#  MODEL_NAME          - Name of the Simulink block diagram
#  MODEL_MODULES       - Any additional generated source modules
#  MAKEFILE_NAME       - Name of makefile created from template makefile <model>.mk
#  MATLAB_ROOT         - Path to were MATLAB is installed.
#  MATLAB_BIN          - Path to MATLAB executable.
#  S_FUNCTIONS         - List of S-functions.
#  S_FUNCTIONS_LIB     - List of S-functions libraries to link.
#  SOLVER              - Solver source file name
#  NUMST               - Number of sample times
#  TID01EQ             - yes (1) or no (0): Are sampling rates of continuous
#                        task (tid=0) and 1st discrete task equal.
#  NCSTATES            - Number of continuous states
#  BUILDARGS           - Options passed in at the command line.
#  MULTITASKING        - yes (1) or no (0): Is solver mode multitasking
#  EXT_MODE            - yes (1) or no (0): Build for external mode
#  EXTMODE_TRANSPORT   - Name of transport mechanism (e.g. tcpip, serial) for extmode
#  EXTMODE_STATIC      - yes (1) or no (0): Use static instead of dynamic mem alloc.
#  EXTMODE_STATIC_SIZE - Size of static memory allocation buffer.
#  CC_LISTING          - yes (1) or no (0): Generate assembly listings
#  REBUILD_ALL         - yes (1) or no (0): Rebuild all files

MODEL                := tester
MODULES              := rtGetInf.c rtGetNaN.c rt_nonfinite.c tester_data.c 
MAKEFILE             := tester.mk
MATLAB_ROOT          := C:/PROGRA~1/MATLAB/R2009a
MATLAB_BIN           := C:/PROGRA~1/MATLAB/R2009a/bin
S_FUNCTIONS          := 
S_FUNCTIONS_LIB      := 
SOLVER               := ode1.c
NUMST                := 2
TID01EQ              := 1
NCSTATES             := 1
BUILDARGS            :=  GENERATE_REPORT=0 EXTMODE_STATIC_ALLOC=0 EXTMODE_STATIC_ALLOC_SIZE=1000000 TMW_EXTMODE_TESTING=0
MULTITASKING         := 0
EXT_MODE             := 1
EXTMODE_TRANSPORT    := 0
CC_LISTING           := 0
REBUILD_ALL          := 0

MODELREFS            := 
SHARED_SRC           := 
SHARED_SRC_DIR       := 
SHARED_BIN_DIR       := 
SHARED_LIB           := 
TARGET_LANG_EXT      := c
OPTIMIZATION_FLAGS   := 
ADDITIONAL_LDFLAGS   := 


#--------------------------- Model and reference models -----------------------
#
MODELLIB                  := testerlib.lib
MODELREF_LINK_LIBS        := 
MODELREF_LINK_RSPFILE     := tester_ref.rsp
MODELREF_INC_PATH         := 
RELATIVE_PATH_TO_ANCHOR   := ..
MODELREF_TARGET_TYPE      := NONE


#--------------------------------- Tool Locations -----------------------------
#
SHELL   := cmd
RTWIN   := $(MATLAB_ROOT)/toolbox/rtw/targets/rtwin
OPENWAT := $(RTWIN)/openwat
CC      := $(OPENWAT)/binnt/wcc386
CPP     := $(OPENWAT)/binnt/wpp386
AS      := $(OPENWAT)/binnt/wasm
DISAS   := $(OPENWAT)/binnt/wdis
LD      := $(OPENWAT)/binnt/wlink
LIBCMD  := $(OPENWAT)/binnt/wlib
THISMAKEFILE := $(firstword $(MAKEFILE_LIST))


#------------------------ External mode ---------------------------------------
#
# To add a new transport layer, see the comments in
#   <matlabroot>/toolbox/simulink/simulink/extmode_transports.m
ifeq ($(EXT_MODE),1)
  EXT_CC_OPTS := -DEXT_MODE
endif


#------------------------------ Include Path -----------------------------
#
# MATLAB includes
REQ_INCLUDES := $(MATLAB_ROOT)/simulink/include;$(MATLAB_ROOT)/extern/include;$(MATLAB_ROOT)/rtw/c/src;$(MATLAB_ROOT)/rtw/c/src/ext_mode/common

# target-specific and compiler-specific includes
REQ_INCLUDES := $(REQ_INCLUDES);$(RTWIN)/src;$(OPENWAT)/include

# additional includes
REQ_INCLUDES := $(REQ_INCLUDES);G:/MATLAB/OSNMEC~3/tester_rtwin;G:/MATLAB/OSNMEC~3

# shared includes
ifneq ($(SHARED_SRC_DIR),)
  REQ_INCLUDES := $(REQ_INCLUDES);$(SHARED_SRC_DIR)
endif

INCLUDES := -I.;$(RELATIVE_PATH_TO_ANCHOR);$(REQ_INCLUDES)$(MODELREF_INC_PATH)


#-------------------------------- C Flags --------------------------------
#
# general compiler options
REQ_OPTS     := -zq -ei -zp8 -6r -fpi87 -zl -wx
CC_REQ_OPTS  := -wcd=202 -wcd=302 -wcd=400 -wcd=1180
CPP_REQ_OPTS := -wcd=139 -wcd=367 -wcd=389 -wcd=726

# optimization options
# do not let users change DEFAULT_OPT_OPTS
override DEFAULT_OPT_OPTS := $(if $(OPTIMIZATION_FLAGS), $(OPTIMIZATION_FLAGS), -oneatxh)
ifeq ($(CC_LISTING),1)
  ifeq ($(OPTIMIZATION_FLAGS),)
    override DEFAULT_OPT_OPTS += -d1
  endif
  CCLISTING = $(DISAS) -l -s $@
  LDLISTING := OPTION map
else
  CCLISTING :=
  LDLISTING :=
endif

OPT_OPTS ?= $(DEFAULT_OPT_OPTS)
COMMON_OPTS := $(REQ_OPTS) $(OPT_OPTS) $(OPTS) $(EXT_CC_OPTS)

REQ_DEFINES := -DUSE_RTMODEL -DMODEL=$(MODEL) -DRT -DNUMST=$(NUMST) \
               -DTID01EQ=$(TID01EQ) -DNCSTATES=$(NCSTATES) \
               -DMT=$(MULTITASKING) -D__OBSCURE_STREAM_INTERNALS

USER_INCLUDES ?=

CFLAGS   = -fo=$@ $(CC_REQ_OPTS) $(COMMON_OPTS) $(REQ_DEFINES) $(USER_INCLUDES) $(INCLUDES)
CPPFLAGS = -fo=$@ $(CPP_REQ_OPTS) $(CPP_OPTS) $(COMMON_OPTS) $(REQ_DEFINES) $(USER_INCLUDES) $(INCLUDES)


#------------------------------- Source Files ---------------------------------
#
# standard RTW target
ifeq ($(MODELREF_TARGET_TYPE),NONE)
  PRODUCT     := $(RELATIVE_PATH_TO_ANCHOR)/$(MODEL).rwd
  REQ_SRCS    := $(MODEL).$(TARGET_LANG_EXT) $(MODULES) \
                 rtwin_main.c rt_sim.c

ifeq ($(EXT_MODE),1)
  REQ_SRCS    += ext_svr.c updown_rtwin.c 
endif

# model reference RTW target
else
  PRODUCT  := $(MODELLIB)
  REQ_SRCS := $(MODULES)
endif

SRCS := $(REQ_SRCS) $(USER_SRCS) $(S_FUNCTIONS) $(SOLVER)
OBJS := $(patsubst %.c,%.obj,$(patsubst %.cpp,%.obj,$(SRCS)))

SHARED_OBJS := $(addsuffix .obj, $(basename $(wildcard $(SHARED_SRC))))


#---------------------------- Additional Libraries ----------------------------
#
LIBS := 




#-------------------------- Rules ---------------------------------------
#
# some makefile magic
COMMA := ,
EMPTY :=
SPACE := $(EMPTY) $(EMPTY)

# decide what should get built
.DEFAULT_GOAL := $(if $(filter 1,$(REBUILD_ALL)), rebuild, $(PRODUCT))

# rule to rebuild everything unconditionally
.PHONY : rebuild
rebuild :
	$(MAKE) -B -f $(THISMAKEFILE) REBUILD_ALL=0

# libraries to link with the executable
ALLLIBS := $(strip $(LIBS) $(SHARED_LIB) $(MODELREF_LINK_LIBS))
ifneq ($(ALLLIBS),)
  LDLIBS := LIBRARY $(subst $(SPACE),$(COMMA),$(strip $(ALLLIBS)))
endif

# rules for linking the executable or modelref static library
ifeq ($(MODELREF_TARGET_TYPE),NONE)
$(PRODUCT) : $(OBJS) $(ALLLIBS)
	$(LD) \
	  @$(RTWIN)\rtwin\rtwin.rsp $(LDLISTING) \
	  LIBPATH $(RTWIN)\lib;$(RTWIN)\openwat\lib386 \
	  NAME $@ \
	  FILE $(subst $(SPACE),$(COMMA),$(strip $(OBJS))) $(LDLIBS)
	$(info ### Created Real-Time Windows Target module $(notdir $@))
else
$(PRODUCT) : $(OBJS) $(SHARED_LIB)
	$(LIBCMD) -q $@ $(addprefix +,$(OBJS))
	$(info ### Created static library $(notdir $@))
endif

# rules for compiling objects
rtwin_main.obj : $(RTWIN)/src/rtwin_main.c $(THISMAKEFILE)
	$(info ### Compiling $<)
	$(CC) $(subst /,\,$(CFLAGS) $<)
	$(CCLISTING)

%.obj : $(RTWIN)/src/%.c
	$(info ### Compiling $<)
	$(CC) $(subst /,\,$(CFLAGS) $<)
	$(CCLISTING)

%.obj : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/%.c
	$(info ### Compiling $<)
	$(CC) $(subst /,\,$(CFLAGS) $<)
	$(CCLISTING)

%.obj : %.c
	$(info ### Compiling $<)
	$(CC) $(subst /,\,$(CFLAGS) $<)
	$(CCLISTING)

%.obj : %.cpp
	$(info ### Compiling $<)
	$(CPP) $(subst /,\,$(CPPFLAGS) $<)
	$(CCLISTING)

# additional sources
%.obj : $(MATLAB_ROOT)/rtw/c/src/%.c $(THISMAKEFILE)
	$(info ### Compiling $<)
	$(CC) $(subst /,\,$(CFLAGS) $<)
	$(CCLISTING)



%.obj : $(MATLAB_ROOT)/rtw/c/src/%.cpp $(THISMAKEFILE)
	$(info ### Compiling $<)
	$(CPP) $(subst /,\,$(CPPFLAGS) $<)
	$(CCLISTING)



# simulink/src helper files
%.obj : $(MATLAB_ROOT)/simulink/src/%.c
	$(info ### Compiling $<)
	$(CC) $(subst /,\,$(CFLAGS) $<)
	$(CCLISTING)

%.obj : $(MATLAB_ROOT)/simulink/src/%.cpp
	$(info ### Compiling $<)
	$(CPP) $(subst /,\,$(CPPFLAGS) $<)
	$(CCLISTING)

# model-referencing shared objects
$(SHARED_BIN_DIR)/%.obj : $(SHARED_SRC_DIR)/%.c 
	$(info ### Compiling $<)
	$(CC) $(subst /,\,$(CFLAGS) $<)
	$(CCLISTING)

$(SHARED_BIN_DIR)/%.obj : $(SHARED_SRC_DIR)/%.cpp 
	$(info ### Compiling $<)
	$(CPP) $(subst /,\,$(CPPFLAGS) $<)
	$(CCLISTING)


# model-referencing shared library
$(SHARED_LIB) : $(SHARED_OBJS)
	$(info ### Creating shared library $@)
	@if exist $@ del $@
	$(LIBCMD) -q $@ $(addprefix +,$^)
	$(info ### Created $@)


# rules for building libraries



# rules for precompiled libraries

