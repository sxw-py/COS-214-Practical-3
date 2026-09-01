CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra

SRCS := $(filter-out main.cpp, $(wildcard *.cpp))
OBJS := $(SRCS:.cpp=.o)
TARGET := eventflow

all: $(TARGET)

$(TARGET): main.o $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)

run: $(TARGET)
	./$(TARGET)

valgrind: $(TARGET)
	valgrind --leak-check=full ./$(TARGET)

.PHONY: all clean run valgrind
