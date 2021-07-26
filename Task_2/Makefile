CC=g++
CFLAGS= -Wall -c
LFLAGS= -o
SOURCES=main.cpp functional.cpp
OBJECTS=$(SOURCES:.cpp=.o)
TARGET=fibo

$(TARGET): $(OBJECTS)
	$(CC) $(LFLAGS) $(TARGET) $(OBJECTS)

$(OBJECTS): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES)

clean:
	rm -f *.o $(TARGET)
