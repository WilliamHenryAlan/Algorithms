CXX = g++
CXXFLAGS = -Wall -std=c++11

TARGET = exec
SRCS = main.cpp
OBJS = main.o

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o:main.cpp

clean:
	rm -f $(OBJS) $(TARGET)

all:$(TARGET)

.PHONY:clean all