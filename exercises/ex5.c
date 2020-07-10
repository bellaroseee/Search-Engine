/*
  Copyright 2020 Bella Rose
  name : Bella Rose
  UW email : brose714@uw.edu
*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "./Vector.h"

#define SIZE 4
#define RESIZE_SIZE 10  // Test vector length.

// Print the elements in the vector on a line.
static void PrintIntVector(vector_t v);

int main(int argc, char *argv[]) {
  size_t i;

  // Test VectorAllocate
  vector_t v = VectorAllocate(SIZE);

  if (v == NULL) {
    printf("Failed to allocate vector\n");
    return EXIT_FAILURE;
  }

  // Test VectorSet
  for (i = 0; i < RESIZE_SIZE; ++i) {
    int *x = (int*) malloc(sizeof(int));
    if (x == NULL) {
      return EXIT_FAILURE;
    }
    *x = i*i;
    element_t old;
    if (!VectorSet(v, i, x, &old)) {
      return EXIT_FAILURE;
    }
  }

  PrintIntVector(v);

  // free individual elements in the vector
  for (i = 0; i < VectorLength(v); i++) {
    free(VectorGet(v, i));
  }

  // free the pointer to length and arry
  VectorFree(v);

  return EXIT_SUCCESS;
}


static void PrintIntVector(vector_t v) {
  size_t i;
  size_t length;

  assert(v != NULL);

  // Test VectorLength
  length = VectorLength(v);
  printf("%ld\n", length);

  if (length > 0) {
    // Test VectorGet
    printf("[%d", *((int*)VectorGet(v, 0)));
    for (i = 1; i < VectorLength(v); ++i)
      printf(",%d", *((int*)VectorGet(v, i)));
    printf("]\n");
  }
}
