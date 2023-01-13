# Configure g++:
# - Default to 64 bits, but allow overriding on the command line
# - Use CXXEXTRA and LDEXTRA to allow additional flags
BITS     ?= 64
CXX       = g++
LD        = g++
# in the next two line, remove -m$(BITS) if you are running on an M1 Mac
CXXFLAGS  = -MMD -O3 -m$(BITS) -ggdb -std=c++17 -Wall -Wextra -fPIC $(CXXEXTRA)
LDFLAGS   = -m$(BITS) -lpthread -ldl $(LDEXTRA)

# Hard-coded name of the solutions folder
SDIR = solutions

# Give a name to the output folder, and ensure it is created before any
# compilation happens
ODIR      := ./obj$(BITS)
OUTFOLDER := $(shell mkdir -p $(ODIR))
BUILDIR	  := ./build
BUILTFOLDER	:= $(shell mkdir -p $(BUILDIR))

# Names of all the .o files needed to create the client executable
MANAGER_O  = $(patsubst %, $(BUILDIR)/%.o, $(MANAGER_CXX))
MANAGER_O += $(patsubst %, $(BUILDIR)/%.o, $(MANAGER_COMMON))
MANAGER_O += $(patsubst %, $(SDIR)/%.o, $(MANAGER_PROVIDED))

# Names of all the .o and .exe files to build
OFILES   = $(MANAGER_O)
EXEFILES = $(patsubst %, $(ODIR)/%.$(EXESUFFIX), $(MANAGER_MAIN))

# Names of all .d files, so we can get dependencies right
DFILES     = $(patsubst %.o, %.d, $(OFILES))

# Build 'all' by default, and don't clobber .o files after each build
.DEFAULT_GOAL = all
.PRECIOUS: $(OFILES)
.PHONY: all clean

# Typing 'make' should build all the .exe files
all: $(EXEFILES)

# Typing 'make clean' should clean up by removing $(OUTFOLDER)
clean:
	@echo Cleaning up...
	@rm -rf $(ODIR)
	@rm -rf $(BUILDIR)

# Rules for building .o files
$(BUILDIR)/%.o: src/%.cc
	@echo "[CXX] $< --> $@"
	@$(CXX) $< -o $@ -c $(CXXFLAGS)
$(BUILDIR)/%.o: lib/%.cc
	@echo "[CXX] $< --> $@"
	@$(CXX) $< -o $@ -c $(CXXFLAGS)

# Rules for building executables
$(ODIR)/$(MANAGER_MAIN).$(EXESUFFIX): $(MANAGER_O)
	@echo "[LD] $^ --> $@"
	@$(CXX) $^ -o $@ $(LDFLAGS)

# Include any dependencies we generated previously
-include $(DFILES)
