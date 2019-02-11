CC = gcc
CFLAGS = -ggdb -Wall -pedantic -std=c11

a1: interactive.o readfile.o a1.o

a1.o: structs.h interactive.h readfile.h

interactive.o: structs.h interactive.h

readfile.o: structs.h readfile.h

run:
	./a1 zip_code_sample.txt 30

clean:
	rm -f *.o a1
