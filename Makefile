CXX = /usr/bin/g++-7		#bat CXX = vcvarsall.bat
CPPVER = c++14

APP = libSkinux.so			#bat APP = libSkinux.dll
COMPOPT = -ldl -pthread -fpic -lSDL2	#bat COMPOPT = /nologo /EHa /MD /bigobj /W2
LINKOPT = -shared			#bat LINKOPT = /nologo /DLL

# APP = skinux
# COMPOPT = -ldl -pthread
# LINKOPT =

OUTDIR = out
BINDIR = bin
LIBDIR = lib
LIBS =						#bat LIBS = SDL2main.lib SDL2.lib

DBGCOMPOPT =				#bat DBGCOMPOPT = /Zi
DBGLINKOPT =				#bat DBGLINKOPT = /DEBUG

RELCOMPOPT =				#bat RELCOMPOPT = /DNDEBUG
RELLINKOPT =				#bat RELLINKOPT =

SOURCES = src

src_SRC = ./src
src_OBJ = skinux.cpp
src_HDR = skinux.h
src_DEP =
src_INC = include /usr/include/SDL2		#bat src_INC = include include/SDL

# BUILD SCRIPT

ALL_OBJ = $(foreach src,$(SOURCES),$(foreach obj,$($(src)_OBJ),$(src)$(obj).o))
ALL_HDR = $(foreach src,$(SOURCES),$(foreach header,$($(src)_HDR),$($(src)_SRC)/$(header)))

.PHONY: all
all: release

debug: $(BINDIR) $(OUTDIR) $(foreach obj,$(ALL_OBJ),$(BINDIR)/dbg$(obj))
	$(CXX) -std=$(CPPVER) $(foreach obj,$(ALL_OBJ),$(BINDIR)/dbg$(obj)) $(foreach libdir,$(LIBDIR),-L$(libdir)) $(foreach lib,$(LIBS),-l$(lib)) $(COMPOPT) $(LINKOPT) $(DBGLINKOPT) -o $(OUTDIR)/$(APP)

release: $(BINDIR) $(OUTDIR) $(foreach obj,$(ALL_OBJ),$(BINDIR)/rel$(obj))
	$(CXX) -std=$(CPPVER) $(foreach obj,$(ALL_OBJ),$(BINDIR)/rel$(obj)) $(foreach libdir,$(LIBDIR),-L$(libdir)) $(foreach lib,$(LIBS),-l$(lib)) $(COMPOPT) $(LINKOPT) $(RELLINKOPT) -o $(OUTDIR)/$(APP)

clean: $(BINDIR)
	cd $(BINDIR) && rm -f *.o

$(OUTDIR):
	if [ ! -d $@ ]; then mkdir $@; fi
$(BINDIR):
	if [ ! -d $@ ]; then mkdir $@; fi

define COMPILE_TEMPLATE =
$(BINDIR)/dbg$(1)%.o: $(2)/% $(3)
	$(CXX) -std=$(CPPVER) -c $(4) $(COMPOPT) $(DBGCOMPOPT) -o $$@ $$<
$(BINDIR)/rel$(1)%.o: $(2)/% $(3)
	$(CXX) -std=$(CPPVER) -c $(4) $(COMPOPT) $(RELCOMPOPT) -o $$@ $$<
endef

$(foreach src,$(SOURCES),$(eval $(call COMPILE_TEMPLATE,$(src),$($(src)_SRC),$(foreach header,$($(src)_HDR),$($(src)_SRC)/$(header)) $(foreach dep,$($(src)_DEP),$(foreach depobj,$($(dep)_OBJ),$($(dep)_SRC)/$(depobj)) $(foreach dephdr,$($(dep)_HDR),$($(dep)_SRC)/$(dephdr))),$(foreach inc,$($(src)_INC),-I$(inc)) $(foreach dep,$($(src)_DEP),-I$($(dep)_SRC)))))