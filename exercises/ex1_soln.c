/*
 * Copyright ©2020 Hal Perkins.  All rights reserved.  Permission is
 * hereby granted to students registered for University of Washington
 * CSE 333 for use solely during Spring Quarter 2020 for purposes of
 * the course.  No other use, copying, distribution, or modification
 * is permitted without prior written consent. Copyrights for
 * third-party components of this work must be honored.  Instructors
 * interested in reusing these course materials should contact the
 * author.
 */

#include <stdio.h>     // for printf, sscanf
#include <stdint.h>    // for int64_t, etc.
#include <inttypes.h>  // for extended integer print formats
#include <stdlib.h>    // for EXIT_SUCCESS / EXIT_FAILURE and exit

// Size of data arrays
#define ARRAY_SIZE 11

// Copy len elements from source to dest, placing elements
// in dest in non-decreasing order.
void CopyAndSort(int64_t *source, int64_t *dest, int len);

// Given that array[0..len-1] is sorted in non-decreasing order, add
// num to array in the proper place so that array[0..len] is sorted.
// precondition: len > 0.
void DoInsert(int64_t num, int64_t *array, int len);

// Print the contents of array with len elements to stdout.
void PrintArray(int64_t *array, int len);

int main(int argc, char **argv) {
  // Create an unsorted array and a second array to hold a sorted copy
  int64_t unsorted[ARRAY_SIZE] = {3, 2, -5, 8, 17, 6, 1, 7, 8, -8, 6};
  int64_t sorted[ARRAY_SIZE];

  // Copy unsorted to sorted in non-decreasing order and print result
  CopyAndSort(unsorted, sorted, ARRAY_SIZE);
  PrintArray(sorted, ARRAY_SIZE);

  // Quit
  return EXIT_SUCCESS;
}

void CopyAndSort(int64_t *source, int64_t *dest, int len) {
  // Deal with the degenerate case of a zero-length array
  // (nothing to do in that case)
  if (len == 0)
    return;

  // Insertion sort
  // Copy first element
  dest[0] = source[0];

  // Insert remaining entries in order in dest.
  for (int i = 1; i < len; i++) {
    DoInsert(source[i], dest, i);
  }
}

void DoInsert(int64_t num, int64_t *array, int len) {
  // pre: len > 0 && array[0..len-1] sorted in non-decreasing order
  int i = len;
  // inv: array[0..i-1] not checked and array[i+1..len] > num.
  while (i > 0 && array[i-1] > num) {
    array[i] = array[i-1];
    i--;
  }
  // array[0..i-1] <= num && array[i+1..len] > num
  array[i] = num;
}

void PrintArray(int64_t *array, int len) {
  for (int i = 0; i < len; i++) {
    printf("%" PRId64 "%c", array[i], i == (len-1) ? '\n' : ' ');
  }
}
