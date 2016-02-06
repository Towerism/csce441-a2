SRCS := $(wildcard *.cc)
OBJECTS := $(SRCS:.cc=.o)
DEP := $(OBJECTS:.o=.d)
EXECUTABLE ?= main

CXXFLAGS ?= -std=c++11 -Wall --pedantic
LDFLAGS ?= -lglut -lGL -lGLU
CXX ?= g++
RM ?= rm -rf

$(EXECUTABLE): depend $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

%.d: %.cc
	@$(CXX) $(CXXFLAGS) $< -MM -MT $(@:.d=.o) >$@

clean:
	$(RM) *.o $(DEP) $(EXECUTABLE)

.PHONY: depend clean

-include $(DEP)
