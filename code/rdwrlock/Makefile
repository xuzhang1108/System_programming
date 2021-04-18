.PHONY:clean all
CC = gcc
CFLAGS = -Wall -g -pthread
BIN =  rdwrlock producter_consumer
all:$(BIN)
%.o:%.c
	$(CC)  $(CFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)
