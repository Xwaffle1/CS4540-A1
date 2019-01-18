#include "stdio.h"
#include "structs.h"
void readFile(zipTowns arrs, FILE * infile, int * length){
  printf("%s\n", "Read File called.");
  char buffer[255];
  while(fgets(buffer, 255, infile)) {
    printf("%s", buffer);
  }

}
