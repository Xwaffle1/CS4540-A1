#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readfile.h"
#include "structs.h"

void readFile(zipTowns arrs, FILE * infile, int * length){
  char zipText[6];
  char cityTown[14];
  int index = 0;
  while(fscanf(infile, "%s  %s", zipText, cityTown) > 1){
    // printf("ZIP: %s, CITY: %s\n",zipText, cityTown );
    // city * newTown = malloc(sizeof(city));
    city * newTown = &arrs.cities[index];
    int zip = atoi(zipText);
    newTown->zip = 0; // init zip for struct
    newTown->town = malloc(sizeof(strlen(cityTown) + 1)); // init town for struct
    newTown->zip = zip;


    strcpy(newTown->town, cityTown);
    arrs.cities[index] = *newTown; // Don't think I need this.
    insertTown(&newTown, arrs, index);
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

void insertTown(city ** newCity, zipTowns arrs, int length) {
  city ** towns = arrs.towns;
  city * theCity = (city *) *newCity;
	int j = length - 1;
	while (j >= 0 && strcmp(towns[j]->town, theCity->town) > 0) {
		towns[j + 1] = towns[j];
		j--;
	}
	towns[j + 1] = theCity;
}
