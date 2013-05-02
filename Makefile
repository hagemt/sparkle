TAG := "SWARM"

CXXFLAGS := -Wall -Wextra -std=c++0x
CXXFLAGS += -O0 -ggdb -pedantic
CXXFLAGS += -O3 -DNDEBUG

CXX  := $(shell which g++)
DIFF := $(shell which diff) -s
RM   := $(shell which rm) -fv
SAY  := $(shell which echo) -e "[$(TAG)]"

all: swarm
	@$(SAY) "You can now install the software..."

clean:
	@$(SAY) "Cleaning generated, object, and executable files..."
	@$(RM) *.o swarm
	@$(SAY) "Cleaning up temporary test results..."
	@$(RM) test.* _.*

install: test

test: swarm

.PHONY: all clean install test

swarm: main.o Particle.o Swarm.o
	@$(SAY) "LINK $@"
	@$(CXX) $(CXXFLAGS) *.o -o $@

%.o: %.cpp
	@$(SAY) "CCXX $<"
	@$(CXX) $(CXXFLAGS) -c $< -o $@
