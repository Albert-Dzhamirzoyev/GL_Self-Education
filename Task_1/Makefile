CC=g++
CFLAGS= -Wall -c -std=c++11
LFLAGS= -o
SOURCES=main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
TARGET=stack

$(TARGET): $(OBJECTS)
	$(CC) $(LFLAGS) $(TARGET) $(OBJECTS)

$(OBJECTS): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES)

clean:
	rm -f *.o $(TARGET)
