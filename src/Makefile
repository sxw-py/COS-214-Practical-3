CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra

SRCS := $(filter-out main.cpp, $(wildcard *.cpp))
OBJS := $(SRCS:.cpp=.o)
TARGET := main

all: $(TARGET)

$(TARGET): main.o $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)

.PHONY: all clean
