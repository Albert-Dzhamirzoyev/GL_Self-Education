CC=g++
CFLAGS= -Wall
SOURCES=main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
TARGET=stack

$(TARGET): $(OBJECTS)
	$(CC) $(FLAGS) -o $(TARGET) $(OBJECTS)

$(OBJECTS): $(SOURCES)
	$(CC) $(CFLAGS) -c $(SOURCES)

clean:
	rm -f *.o $(TARGET)
