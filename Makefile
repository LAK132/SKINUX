CXX = /usr/bin/g++-7

CPPVER = c++14

APP = libSkinux.so

COMPOPT = -ldl -pthread -fpic
LINKOPT = -shared

# APP = skinux.a

# COMPOPT = -ldl -pthread
# LINKOPT =

OUTDIR = out
BINDIR = bin

LIBDIR = lib
LIBS =

DBGCOMPOPT =
DBGLINKOPT =

RELCOMPOPT =
RELLINKOPT =

SOURCES = src

src_SRC = ./src
src_OBJ = skinux.cpp 
src_INC = include

# -------------------
# Start build script:
# -------------------
ALL_OBJ = $(foreach src,$(SOURCES),$(foreach obj,$($(src)_OBJ),$(BINDIR)/$(src)$(obj).o))

.PHONY: debug
debug: $(foreach obj,$(ALL_OBJ),debug-$(obj))
	$(call LINK_TEMPLATE,$(LINKOPT) $(DBGLINKOPT))

release: $(foreach obj,$(ALL_OBJ),release-$(obj))
	$(call LINK_TEMPLATE,$(LINKOPT) $(RELLINKOPT))

define LINK_TEMPLATE =
$(CXX) -std=$(CPPVER) -o $(OUTDIR)/$(APP) $(ALL_OBJ) $(foreach libdir,$(LIBDIR),-L$(libdir)) $(foreach lib,$(LIBS),-l$(lib)) $(COMPOPT) $(1)
endef

define COMPILE_TEMPLATE =
debug-$(2)$(3).o: $(1)/$(3)
	$(CXX) -std=$(CPPVER) -c -o $(2)$(3).o $(1)/$(3) $(4) $(COMPOPT) $(DBGCOMPOPT)
release-$(2)$(3).o: $(1)/$(3)
	$(CXX) -std=$(CPPVER) -c -o $(2)$(3).o $(1)/$(3) $(4) $(COMPOPT) $(RELCOMPOPT)
endef

$(foreach src,$(SOURCES),$(foreach obj,$($(src)_OBJ),$(eval $(call COMPILE_TEMPLATE,$($(src)_SRC),$(BINDIR)/$(src),$(obj),$(foreach inc,$($(src)_INC),-I$(inc))))))

clean:
	rm -f $(ALL_OBJ)