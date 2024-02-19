CC = g++
CFLAGS = -std=c++11 -Wall
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
