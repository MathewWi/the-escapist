CPP=g++
LDFLAGS=-lSDL -lSDL_image

SOURCES=Object.cpp Timer.cpp init.cpp main.cpp

TARGET=the-escapist

all: $(TARGET)

clean:   
	rm $(TARGET)

$(TARGET): $(OBJECTS) 
	$(CPP) $(CXXFLAGS) $(SOURCES) -o $(TARGET) $(LDFLAGS)


