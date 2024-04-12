# Compiler settings - Can change according to your needs
CXX=g++
CXXFLAGS=-Wall -g -I../
LDFLAGS=-lgtest -lgtest_main -pthread

# Files and folders
EXECUTABLE=unit_test
SOURCES=unit_test.cpp ../Vector3D.cpp
OBJECTS=$(SOURCES:.cpp=.o)

# Main target
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

# To obtain object files
%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

# Clean up
clean:
	rm -f $(EXECUTABLE) $(OBJECTS)

.PHONY: clean
