#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "structs.h"
#include "interactive.h"

void doInteractive(zipTowns arrs, int length){

  int exit = 1;
  while(exit){
    printf("%s\n%s\n%s\n", "1: Quit", "2: Search for zip", "3: Search for town");
    int option;
    scanf("%d", &option);
    getchar();
    if(option == 1){
      exit = 0;
      printf("%s\n", "Goodbye!");
    }else if(option == 2){
      printf("%s\n", "Please enter a 5 Digit zip code to search for: ");
      char input[5];
      scanf("%s", input);
      int index = searchZip(arrs, input, length);
      if(index == -1){
        printf("%s was not found!\n", input);

      }else{
        printf("\nZipCode: %s is the town %s\n\n", input, arrs.cities[arrs.zips[index]].town);
      }
    }else if(option == 3){
      printf("\n%s\n\n", "Please enter the town name to search for: ");
      char input[20];
      scanf("%s", input);
      int index = searchTown(arrs, input, length);
      if(index == -1){
        printf("%s was not found!\n", input);
      }else{
        printf("\nThe town %s zipcode is %d\n\n", input, arrs.towns[index]->zip);
      }
    }else{
      printf("%s\n", "INVALID ENTRY");
    }
  }
}


int searchTown(zipTowns arrs, char search[], int length){
  int left = 0;
  int right = length;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    char * currentTown = arrs.towns[mid]->town;
    if (strcmp(currentTown, search) == 0)
        return mid;
    if (strcmp(currentTown, search) < 0)
        left = mid + 1;
    else
        right = mid - 1;
  }
  return -1;
}

int searchZip(zipTowns arrs, char search[], int length){
  int left = 0;
  int right = length;
  int zipVal = (int) atoi(search);
  while (left <= right) {
    int mid = left + (right - left) / 2;
    int currentZip = arrs.cities[arrs.zips[mid]].zip;
    if (currentZip== zipVal){
        return mid;
    }
    if (currentZip < zipVal)
        left = mid + 1;
    else
        right = mid - 1;
  }
  return -1;
}
