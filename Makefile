CXX=g++
CXXFLAGS= -std=c++14 -Wall -g -MMD 
EXEC=sorcery
CCFILES=$(wildcard *.cc)
OBJECTS=${CCFILES:.cc=.o}
DEPENDS=${CCFILEs:.cc=.d}

${EXEC}:${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean
clean:
	rm ${EXEC} ${OBJECTS} ${DEPENDS}
