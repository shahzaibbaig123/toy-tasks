CC=gcc
CFLAGS=-Wall -g -Werror -I.

DEPS=sum.h
OBJ = sum.o main.o

LIBS=-lpthread

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
	
sumthread: $(OBJ)
	$(CC) -o $@ $^ $(LIBS)
	
clean:
	rm -f *.o sumthread
