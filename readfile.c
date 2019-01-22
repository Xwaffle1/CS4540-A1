#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include <string.h>
#include "readfile.h"

void readFile(zipTowns arrs, FILE * infile, int * length){
  char zipText[6];
  char cityTown[14];
  int index = 0;
  while(fscanf(infile, "%s  %s", zipText, cityTown) > 1){
    printf("ZIP: %s, CITY: %s\n",zipText, cityTown );
    city * newTown = malloc(sizeof(city));
    int zip = atoi(zipText);
    newTown->zip = 0; // init zip for struct
    newTown->town = malloc(sizeof(strlen(cityTown))); // init town for struct
    newTown->zip = zip;
    strcpy(newTown->town, cityTown);
    arrs.cities[index] = *newTown; // Main Array un sorted;
    insertTown(newTown, arrs.towns, index);
    insertZipCode(arrs, index);
    index++;
  }
  *length=index;
}

void insertZipCode(zipTowns arrs, int length) {
	int j = length - 1;
  int zipVal = arrs.cities[length].zip;
	while (j >= 0 && arrs.cities[arrs.zips[j]].zip > zipVal) {
		arrs.zips[j + 1] = arrs.zips[j];
		j--;
	}
	arrs.zips[j + 1] = length;
}

void insertTown(city * newCity, city * towns[], int length) {
	int j = length - 1;
	while (j >= 0 && strcmp(towns[j]->town, newCity->town) > 0) {
		towns[j + 1] = towns[j];
		j--;
	}
	towns[j + 1] = newCity;
}
