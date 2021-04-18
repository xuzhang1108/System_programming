.PHONY:clean all
CC = gcc
CFLAGS = -Wall -g -pthread
BIN =  pthread_mutex01
all:$(BIN)
%.o:%.c
	$(CC)  $(CFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)
