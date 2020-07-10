/*
  Copyright 2020 Bella Rose
  name : Bella Rose
  UW email : brose714@uw.edu
*/

#include <stdio.h>     /* printf */
#include <stdint.h>    /* int64_t */
#include <stdlib.h>    /* EXIT_SUCCESS */
#include <inttypes.h>  /* PRId64 */

// iterates through the entries of first array
// use insertion sort to insert the entries into the second array
// in ascending, with duplicate, sorted order.
void CopyAndSort(int64_t arr[], int64_t dest[], int size);

// insertion sort implementation
void insertionSort(int64_t val, int index, int64_t dest[]);

// printing out the result according to the format
void printArray(int size, int64_t dest[]);

int main() {
  int size = 11;
  int64_t arr[11]= {3, 2, -5, 8, 17, 6, 1, 7, 8, -8, 6};
  int64_t dest[11];

  CopyAndSort(arr, dest, size);
  printArray(size, dest);
  return EXIT_SUCCESS;
}

void CopyAndSort(int64_t arr[], int64_t dest[], int size) {
  for (int i = 0; i < size; i++) {
    insertionSort(arr[i], i, dest);
  }
}

void insertionSort(int64_t val, int index, int64_t dest[]) {
  // determines whether need to shift the array
  while (index > 0 && dest[index-1] > val) {
    dest[index] = dest[index-1];
    index--;
  }
  // set the value at the appropriate index
  dest[index] = val;
}

void printArray(int size, int64_t dest[]) {
  for (int i = 0; i < size; i++) {
    printf("%" PRId64 "%c", dest[i], (i == size-1)? '\n' : ' ');
  }
}
