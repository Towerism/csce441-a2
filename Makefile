SRCS := $(wildcard *.cc) \
        $(wildcard color/*.cc) \
        $(wildcard delegate/*.cc) \
        $(wildcard entity/*.cc) \
        $(wildcard shape/*.cc) \
        $(wildcard tween/*.cc)
OBJECTS := $(SRCS:.cc=.o)
DEP := $(OBJECTS:.o=.d)
EXECUTABLE ?= main

CXXFLAGS ?= -std=c++11 -Wall --pedantic -I.
LDFLAGS ?= -lglut -lGL -lGLU
CXX ?= g++
RM ?= rm -rf

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

%.d: %.cc
	@$(CXX) $(CXXFLAGS) $< -MM -MT $(@:.d=.o) >$@

.PHONY: clean
clean:
	$(RM) $(OBJECTS) $(DEP) $(EXECUTABLE)

-include $(DEP)
