SRCS := main.cc hexagon.cc
OBJECTS := $(SRCS:.cc=.o)
EXECUTABLE ?= main

CXXFLAGS ?= -std=c++11 -c -Wall --pedantic
LDFLAGS ?= -lglut -lGL -lGLU
CXX ?= g++
RM ?= rm -rf

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $^ -o $@

.cc.o:
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	$(RM) *.o $(EXECUTABLE) 
