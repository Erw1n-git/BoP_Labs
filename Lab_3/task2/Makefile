CC = g++
CFLAGS = -g -Wall

TARGET = main

all: $(TARGET)

$(TARGET): Main.o Function.o CustomFunction.o
	$(CC) $(CFLAGS) $^ -o $(TARGET)

Main.o: Main.cpp
	$(CC) $(CFLAGS) -c $< -o $@

Function.o: Function.cpp Function.h
	$(CC) $(CFLAGS) -c $< -o $@

CustomFunction.o: CustomFunction.cpp CustomFunction.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)

debug: $(TARGET)
	gdb $(TARGET)

.PHONY: all clean debug
