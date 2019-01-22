#ifndef READFILE_H
#define READFILE_H
#include "structs.h"

extern void readFile(zipTowns arrs, FILE * infile, int * length);
extern void insertZipCode(zipTowns arrs, int length);
extern void insertTown(city * newCity, city * towns[], int length);


#endif // last line of file
