.PHONY:clean all
CC = gcc
CFLAGS = -Wall -g
BIN = fifo_unblock fifo_block fifo_write fifo_write_unblock fifo_copy_w fifo_copy_r 
all:$(BIN)
%.o:%.c
	$(CC)  $(CFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)
