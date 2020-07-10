/*
  Copyright 2020 Bella Rose
  name : Bella Rose
  UW email : brose714@uw.edu
*/

#ifndef VECTOR_H_
#define VECTOR_H_

#include <stddef.h>   /* size_t */
#include <stdbool.h>  /* bool */

// general pointer to the element in vector.
typedef void* element_t;

// vector data structure. arry is the elements in the vector
typedef struct vector_st {
  size_t length;
  element_t *arry;
} *vector_t;

// Initialize vector of size n
// On success, return vector_t with an initial length of n.
// On failure, returns NULL.  Assumes v != NULL.
vector_t VectorAllocate(size_t n);

// Frees the memory allocated for the vector_t.  Assumes v != NULL.
void VectorFree(vector_t v);

// Sets the nth element of v to be e.  Returns the previous nth element_t in
// prev. Freeing e is the responsibility of the user, not the vector_t.
// Returns true iff successful.  Assumes v != NULL.
bool VectorSet(vector_t v, int index, element_t e, element_t *prev);

// Returns the element at the given index within v.  Assumes v != NULL.
element_t VectorGet(vector_t v, int index);

// Returns the length of v.  Assumes v != NULL.
size_t VectorLength(vector_t v);

#endif  // VECTOR_H_
