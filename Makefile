CXX=g++
CXXFLAGS=-Wall -pedantic-errors -g
#CXXFLAGS=-Wall -pedantic-errors -g

EXECUTABLE=ec
SOURCES=ec_ops.cpp ec.cpp
OBJECTS=$(SOURCES:.cpp=.o)
INCLUDES=-I ec_ops.h

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CXX) -o $@ $(OBJECTS) -lgmpxx -lgmp

clean:
		rm -f $(OBJECTS) $(EXECUTABLE)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c -o $@ $<

run:
		./$(EXECUTABLE)

