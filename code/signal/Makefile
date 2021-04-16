.PHONY:clean all
CC = gcc
CFLAGS = -Wall -g
BIN = sigqueue_recv sigqueue_send
all:$(BIN)
%.o:%.c
	$(CC)  $(CFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)
