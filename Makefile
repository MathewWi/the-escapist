CPP=g++
LDFLAGS=-lSDL -lSDL_image

OBJECTS=Object.o Timer.o init.o main.o

TARGET=the-escapist

all: $(TARGET)

clean:   
	rm $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS) 
	$(CPP) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

Object.o: Object.cpp
	$(CPP) $(CXXFLAGS) -c Object.cpp -o Object.o

Timer.o: Timer.cpp
	$(CPP) $(CXXFLAGS) -c Timer.cpp -o Timer.o

init.o: init.cpp
	$(CPP) $(CXXFLAGS) -c init.cpp -o init.o

main.o: main.cpp
	$(CPP) $(CXXFLAGS) -c main.cpp -o main.o