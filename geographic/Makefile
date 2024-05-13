CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++11
LIBS = -lGeographic

all: geodetic_to_geocentric_example

geodetic_to_geocentric_example: geodetic_to_geocentric_example.cpp
	$(CC) $(CFLAGS) $< -o $@ $(LIBS)

run: geodetic_to_geocentric_example
	./geodetic_to_geocentric_example

clean:
	rm -f geodetic_to_geocentric_example