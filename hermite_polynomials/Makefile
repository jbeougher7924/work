CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp HermiteMatrix.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=hermite_matrix

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(EXECUTABLE) $(OBJECTS)
