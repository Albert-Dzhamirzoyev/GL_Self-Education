CC=g++
CFLAGS= -Wall
SOURCES=main.cpp functional.cpp
OBJECTS=$(SOURCES:.cpp=.o)
TARGET=dircont

$(TARGET): $(OBJECTS)
	$(CC) $(FLAGS) -o $(TARGET) $(OBJECTS)

$(OBJECTS): $(SOURCES)
	$(CC) $(CFLAGS) -c $(SOURCES)

clean:
	rm -f *.o $(TARGET)
