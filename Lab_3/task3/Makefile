CC = g++
CFLAGS = -g -Wall

TARGET = main

all: $(TARGET)

$(TARGET): Main.o FunctionObject.o
	$(CC) $(CFLAGS) $^ -o $(TARGET)

Main.o: Main.cpp
	$(CC) $(CFLAGS) -c $< -o $@

FunctionObject.o: FunctionObject.cpp FunctionObject.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)

debug: $(TARGET)
	gdb $(TARGET)

.PHONY: all clean debug
