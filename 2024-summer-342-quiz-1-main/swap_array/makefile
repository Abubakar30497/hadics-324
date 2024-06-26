CC=g++
FLAG=-Wall -std=c++17
EXE=css342_quiz_swap_array

# Source and header files (From GPT)
# From my understanding as gpt explained it, we are
# defining variables for source and header files so we
# can run them simultaneously.
SRCS=main.cpp
HDRS=util.hpp

# Object files (From GPT)
OBJS=$(SRCS:.cpp=.o)

all: $(EXE)

%.o: %.cpp $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

clean:
	rm *.x *.o $(EXE)
