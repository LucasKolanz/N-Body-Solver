CXX = g++
CXXFLAGS	= -std=c++11 -Wall
CXXTESTFLAGS = --coverage # can be used to generate files that help calculate unit test coverage
CXXGDB = -ggdb

all: main

clean:
	rm main main.o

main: main.o main.cpp numerics.h data.h
	$(CXX) $(CXXFLAGS) numerics.cpp data.cpp main.o -o main

# main: main.o main.cpp
# 	$(CXX) $(CXXFLAGS) $(CXXTESTFLAGS) main.cpp main.o -o main

#Rectangle.o: Rectangle.cpp
#	$(CXX) $(CXXFLAGS) -c Rectangle.cpp
