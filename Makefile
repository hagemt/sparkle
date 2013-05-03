TAG := "SWARM"

CXXFLAGS := -Wall -Wextra -std=c++0x
CXXFLAGS += -O0 -ggdb -pedantic
CXXFLAGS += -O3 -DNDEBUG
LDFLAGS  := -L. -lswarm

AR   := $(shell which ar) rcs
CXX  := $(shell which g++)
DIFF := $(shell which diff) -s
RM   := $(shell which rm) -fv
SAY  := $(shell which echo) -e "[$(TAG)]"

all: swarm
	@$(SAY) "You can now install the software..."

clean:
	@$(SAY) "Cleaning generated, object, and executable files..."
	@$(RM) *.o *.a *.so swarm
	@$(SAY) "Cleaning up temporary test results..."
	@$(RM) test.* _.*

install: test

test: Interval.o
	@$(CXX) $(CXXFLAGS) Interval.o -o test.interval
	@$(SAY) "TEST $<"
	./test.interval 1 2 3 4 5 6 7 8 9 0

.PHONY: all clean install test

LIBOBJECTS  := Constraint.o Goal.o
OBJECTS     := Particle.o Swarm.o

libswarm.a: $(LIBOBJECTS)
	@$(SAY) "LINK $@"
	@$(AR) $@ $(LIBOBJECTS)

swarm: libswarm.a $(OBJECTS)
	@$(SAY) "LINK $@"
	@$(CXX) $(CXXFLAGS) $(OBJECTS) $(LDFLAGS) -o $@

%.o: %.cpp
	@$(SAY) "CCXX $<"
	@$(CXX) $(CXXFLAGS) -c $< -o $@
