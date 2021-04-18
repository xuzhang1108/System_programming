.PHONY:clean all
CC = gcc
CFLAGS = -Wall -g -pthread
BIN =  pthread_attr_change
all:$(BIN)
%.o:%.c
	$(CC)  $(CFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)
