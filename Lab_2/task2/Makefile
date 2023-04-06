CC = g++
CFLAGS = -g -Wall

TARGET = main

all: $(TARGET)

$(TARGET): main.o Fraction.o
	$(CC) $(CFLAGS) $^ -o $(TARGET)

main.o: main.cpp main.h
	$(CC) $(CFLAGS) -c $< -o $@

Fraction.o: Fraction.cpp Fraction.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)

debug: $(TARGET)
	gdb $(TARGET)

.PHONY: all clean debug
