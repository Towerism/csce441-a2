SRCS := $(wildcard *.cc) \
        $(wildcard **/*.cc)
OBJS := $(SRCS:.cc=.o)
DEP := $(OBJS:.o=.d)
EXECUTABLE ?= main

CXXFLAGS ?= -std=c++11 -Wall --pedantic -I.
LDFLAGS ?= -lglut -lGL -lGLU
CXX ?= g++
RM ?= rm -rf

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CXX) $(LDFLAGS) $^ -o $@

%.d: %.cc
	@$(CXX) $(CXXFLAGS) $< -MM -MT $(@:.d=.o) >$@

.PHONY: clean
clean:
	$(RM) $(OBJS) $(DEP) $(EXECUTABLE)

-include $(DEP)
