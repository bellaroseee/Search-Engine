/*
  Copyright 2020 Bella Rose
  name : Bella Rose
  UW email : brose714@uw.edu
*/

#include <assert.h>   /* assert */
#include <stdbool.h>  /* bool */
#include <stdlib.h>   /* malloc, free */

#include "./Vector.h"


// Returns a copy of arry with new length newLen.  If newLen < oldLen
// then the returned array is clipped.  If newLen > oldLen, then the
// resulting array will be padded with NULL elements.
static element_t *ResizeArray(element_t *arry, size_t oldLen, size_t newLen);

vector_t VectorAllocate(size_t n) {
  assert(n > 0);

  vector_t v = (vector_t) malloc(sizeof(struct vector_st));
  // fails to malloc
  if (v == NULL) {
    return NULL;
  }

  v->arry = (element_t*) malloc(n*sizeof(element_t));
  // fails to malloc
  if (v->arry == NULL) {
    return NULL;
  }

  // successful malloc
  v->length = n;
  for (size_t i = 0; i < n; i++) {
    v->arry[i] = NULL;
  }

  return v;
}

void VectorFree(vector_t v) {
  assert(v != NULL);
  free(v->arry);
  free(v);
  v->arry = NULL;
  v = NULL;
}

bool VectorSet(vector_t v, int index, element_t e, element_t *prev) {
  assert(v != NULL);
  assert(index >= 0);

  if (index >= v->length) {
    size_t newLength = index+1;
    element_t* newArry = ResizeArray(v->arry, v->length, newLength);
    // ResizeArray fails to malloc
    if (newArry == NULL) {
      return false;
    }

    // MUST FREE OLD ARRY
    free(v->arry);
    // successful malloc
    v->arry = newArry;
    v->length = newLength;
  }

  // here, arrys are of appropriate size
  // store the value at *prev before setting it to e
  *prev = v->arry[index];
  v->arry[index] = e;

  return true;
  // when will this not be successful? -> when ResizeArray malloc fails.
}

element_t VectorGet(vector_t v, int index) {
  assert(v != NULL);
  assert(index >= 0);
  assert(index < v->length);

  return v->arry[index];
}

size_t VectorLength(vector_t v) {
  assert(v != NULL);
  return v->length;
}

static element_t *ResizeArray(element_t *arry, size_t oldLen, size_t newLen) {
  int i;
  size_t copyLen = oldLen > newLen ? newLen : oldLen;
  element_t *newArry;

  assert(arry != NULL);

  newArry = (element_t*)malloc(newLen*sizeof(element_t));

  if (newArry == NULL)
    return NULL;  // malloc error!!!

  // Copy elements to new array
  for (i = 0; i < copyLen; ++i)
    newArry[i] = arry[i];

  // Null initialize rest of new array.
  for (i = copyLen; i < newLen; ++i)
    newArry[i] = NULL;

  return newArry;
}
