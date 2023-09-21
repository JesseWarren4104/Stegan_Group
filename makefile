CC = g++
CFLAGS = -g -Wall

default: test

test:	        Steganography.o main.o
	$(CC) $(CFlags) -o test Steganography.o main.o

Steganography.o:       Steganography.cpp Steganography.h
	$(CC) $(CFLAGS) -c Steganography.cpp


main.o:	main.cpp Steganography.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) test *.o *~
