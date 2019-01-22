CC = gcc
CFLAGS = -ggdb -Wall -pedantic -std=c11

all: Source
	mv Source a1

Source: interactive.o readfile.o Source.o

Source.o: structs.h interactive.h readfile.h

interactive.o: structs.h interactive.h

readfile.o: structs.h

run:
	./a1 zip_code_sample.txt 30

clean:
	rm -f *.o a1
