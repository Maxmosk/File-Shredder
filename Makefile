.PHONY: all clean


#C programming language compiler
CC=gcc
#Compiler flags
CFLAGS=-c -w -o


all: shredd


shredd: main.o filecleaner.o
	$(CC) -w -o shredd main.o filecleaner.o

main.o: main.c
	$(CC) $(CFLAGS) main.o main.c
filecleaner.o: filecleaner.c
	$(CC) $(CFLAGS) filecleaner.o filecleaner.c

clean:
	rm -rf *.o

