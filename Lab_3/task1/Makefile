CC = g++
CFLAGS = -g -Wall

TARGET = main

all: $(TARGET)

$(TARGET): Main.o HumanClasses.o
	$(CC) $(CFLAGS) $^ -o $(TARGET)

Main.o: Main.cpp
	$(CC) $(CFLAGS) -c $< -o $@

HumanClasses.o: HumanClasses.cpp HumanClasses.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)

debug: $(TARGET)
	gdb $(TARGET)

.PHONY: all clean debug
