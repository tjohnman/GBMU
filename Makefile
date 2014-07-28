CC = g++
CC_FLAGS = -w

EXEC = GBMU
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
LIBS_MAC = -I/Library/Frameworks/SDL2.framework/Headers -framework SDL2 -framework Cocoa

all: $(EXEC)

mac: $(OBJECTS)
	$(CC) $(LIBS_MAC) $(OBJECTS) -o $(EXEC)

%.o: %.cpp
	$(CC) -c $(CC_FLAGS) $< -o $@

clean:
	rm -f $(EXEC) $(OBJECTS)	