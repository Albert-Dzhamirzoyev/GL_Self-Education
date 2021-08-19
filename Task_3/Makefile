CC=g++
CFLAGS= -Wall -c -std=c++11
LFLAGS= -lpthread -o
SOURCES=main.cpp functional.cpp
OBJECTS=$(SOURCES:.cpp=.o)
TARGET=dircont

$(TARGET): $(OBJECTS)
	$(CC) $(LFLAGS) $(TARGET) $(OBJECTS)

$(OBJECTS): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES)

clean:
	rm -f *.o $(TARGET)
