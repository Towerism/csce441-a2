SRCS := main.cc hexagon.cc a2Object.cc eventDelegator.cc background.cc rectangle.cc
OBJECTS := $(SRCS:.cc=.o)
EXECUTABLE ?= main

CXXFLAGS ?= -std=c++11 -c -Wall --pedantic
LDFLAGS ?= -lglut -lGL -lGLU
CXX ?= g++
RM ?= rm -rf

$(EXECUTABLE): depend $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

.cc.o:
	$(CXX) $(CXXFLAGS) $< -o $@

depend: makedeps
	makedepend -f makedeps -- $(CXXFLAGS) -- $(SRCS) &>1 /dev/null

makedeps:
	touch makedeps

clean:
	$(RM) *.o $(EXECUTABLE) makedeps

.PHONY: depend clean

include makedeps
