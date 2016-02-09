SRCS := $(wildcard *.cc) \
	$(wildcard **/*.cc)
OBJS := $(SRCS:.cc=.o)
DEPS := $(OBJS:.o=.d)
EXEC ?= main

CXXFLAGS ?= -std=c++11 -Wall --pedantic -I.
LDFLAGS ?= -lglut -lGL -lGLU
CXX ?= g++
RM ?= rm -rf

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(LDFLAGS) $^ -o $@

%.d: %.cc
	@$(CXX) $(CXXFLAGS) $< -MM -MT $(@:.d=.o) >$@

.PHONY: clean
clean: clean/intermediate clean/exec

.PHONY: clean/exec
clean/exec:
	$(RM) $(EXEC)

.PHONY: clean/intermediate
clean/intermediate:
	$(RM) $(OBJS) $(DEPS)

-include $(DEPS)
