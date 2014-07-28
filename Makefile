CC = g++
CC_FLAGS = -Wall -g -std=c++11

EXEC = GBMU
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
LIBS_MAC = -I/Library/Frameworks/SDL2.framework/Headers -framework SDL2 -framework Cocoa
LIBS_WIN = -I../SDL2-2.0.3/i686-w64-mingw32/include -L../SDL2-2.0.3/i686-w64-mingw32/lib -lmingw32 -lSDL2main -lSDL2

win: $(OBJECTS)
	$(CC) $(LIBS_MAC) $(OBJECTS) -o $(EXEC)

mac: $(OBJECTS)
	$(CC) $(LIBS_MAC) $(OBJECTS) -o $(EXEC)

%.o: %.cpp
	$(CC) -c $(CC_FLAGS) $< -o $@

clean:
	rm -f $(EXEC) $(OBJECTS)	