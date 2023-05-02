CC = g++
CFLAGS = -g -Wall

TARGET = main

all: $(TARGET)

$(TARGET): Main.o Fraction.o
	$(CC) $(CFLAGS) $^ -o $(TARGET)

Main.o: Main.cpp
	$(CC) $(CFLAGS) -c $< -o $@

Fraction.o: Fraction.cpp Fraction.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)

debug: $(TARGET)
	gdb $(TARGET)

.PHONY: all clean debug
