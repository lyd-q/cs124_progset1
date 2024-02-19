CXX=g++-10 
CXXFLAGS=-std=c++20 -O2 
INCLUDES = -I.

SRCS = main.cpp graphs.cpp
OBJS = $(SRCS:.cpp=.o)

TARGET = randmst

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
