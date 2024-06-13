CXX = g++
CXXFLAGS = -Wall -std=c++11

TARGET = test_stack
SRCS = main.cpp stack.cpp
OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(OBJS) $(TARGET)

all:$(TARGET)

.PHONY:clean all