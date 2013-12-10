CC=gcc
CXX=g++

# Debug flags
#
#CXXOPTIONS=-Wall -ggdb -DDEBUG

# Optimized flags
#
CXXOPTIONS=-pedantic -Wall -O3

.cpp.o:
	$(CXX) $(CXXOPTIONS) -c $^ -o $@

.c.o:
	$(CXX) $(CXXOPTIONS) -c $^ -o $@

CCSRCS=
CXXSRCS=standardavl.cpp Point.cpp

OBJS=${CCSRCS:.c=.o} ${CXXSRCS:.cpp=.o}

all: standardavl genpoints

standardavl: ${OBJS}
	$(CXX) -o $@ ${OBJS}

genpoints: genpoints.o Point.o
	$(CXX) -o $@ genpoints.o Point.o

clean:
	rm -f ${OBJS} standardavl genpoints
