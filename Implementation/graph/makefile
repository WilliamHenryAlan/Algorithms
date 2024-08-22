CXX = g++
CXXFLAGS = -Wall -std=c++20

.PHONY:clean

TARGET = my_program
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o) 

$(TARGET):$(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
clean:
	rm -rf $(TARGET) $(OBJS)
 
