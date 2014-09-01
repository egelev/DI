CC=g++
CFLAGS=-I. -g -O0 -Wall -Wextra

dllist: dllist.cpp
	$(CC) -o dllist dllist.cpp $(CFLAGS)

debug: CFLAGS += -g -O0 -Wall -Wextra
debug: dllist

all: dllist

clean:
	rm dllist