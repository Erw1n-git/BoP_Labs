CC = g++
CFLAGS = -g -Wall

TARGET = main

all: $(TARGET)

$(TARGET): main.o Matrix.o
	$(CC) $(CFLAGS) $^ -o $(TARGET)

main.o: main.cpp
	$(CC) $(CFLAGS) -c $< -o $@

Matrix.o: Matrix.cpp Matrix.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)

debug: $(TARGET)
	gdb $(TARGET)

.PHONY: all clean debug
