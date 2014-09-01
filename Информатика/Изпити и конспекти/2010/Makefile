CC=g++
BIN_PATH=./bin
CFLAGS=-I. -g -O0 -Wall -Wextra

dllist.o:
	$(CC) -c dllist.cpp -o $(BIN_PATH)/dllist.o $(CFLAGS)

test: dllist.o
	$(CC) -o $(BIN_PATH)/dllist_test $(BIN_PATH)/dllist.o dllist_test.cpp

dllist_bin: dllist.o
	$(CC) -o $(BIN_PATH)/dllist.bin $(BIN_PATH)/dllist.o dllist_bin.cpp $(CFLAGS)

debug: CFLAGS += -g -O0 -Wall -Wextra
debug: dllist_bin

all: dllist_bin

clean:
	rm -f $(BIN_PATH)/dllist*
