# Compiler and flags
CC = g++
CFLAGS = -Wall -std=c++17

# Executable name
EXE = weird_sort

# Source and header files
SRCS = weird_sort.cpp
HDRS = weird_sort.hpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(EXE)

# Rule to compile .o files from .cpp files
%.o: %.cpp $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to link object files into an executable
$(EXE): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@
	rm -f $(OBJS)

# Clean target to remove object files and executable
clean:
	rm -f *.o $(EXE)
