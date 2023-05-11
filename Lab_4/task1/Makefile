CC = g++
CFLAGS = -g -Wall

TARGET = main

all: $(TARGET)

$(TARGET): main.o Student.o Group.o
	$(CC) $(CFLAGS) $^ -o $(TARGET)

main.o: main.cpp
	$(CC) $(CFLAGS) -c $< -o $@

Student.o: Student.cpp Student.h
	$(CC) $(CFLAGS) -c $< -o $@

Group.o: Group.cpp Group.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)

debug: $(TARGET)
	gdb $(TARGET)

.PHONY: all clean debug
