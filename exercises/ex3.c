/*
  Copyright 2020 Bella Rose
  name : Bella Rose
  UW email : brose714@uw.edu
*/
#include <stdio.h>   /* printf */
#include <stdlib.h>  /* EXIT_FAILURE, EXIT_SUCCESS*/
#include <stdint.h>  /* int16_t */

// Define a new structured type
typedef struct {
    int16_t x_coord;
    int16_t y_coord;
    int16_t z_coord;
} Point3d;

// accepts 3 int16_t values
// malloc spaces for a Point3d
// returns a pointer to the malloc'ed Point3d
// the case when malloc fails -> Point3d* will have null value
Point3d* AllocatePoint3d(int16_t x, int16_t y, int16_t z);

int main(int argc, char** argv) {
  // prevents bogus input form user
  if (argc != 1) {
    printf("Do not enter argument for ex3.\n");
    return EXIT_FAILURE;
  }
  
  // test AllocatedPoint3d
  Point3d* point = AllocatePoint3d(0, 0, 0);
  // the case when AllocatePoint3d fails
  if (point == NULL) {
    printf("Failed to allocate memory for (0,0,0).\n");
    return EXIT_FAILURE;
  }
  // verifies struct members contain correct values
  if (point->x_coord == 0 && point->y_coord == 0 && point->z_coord == 0) {
    printf("AllocatePoint3d is successful. The point is (0,0,0).\n"); 
    // frees the memory allocated
    free(point);
    return EXIT_SUCCESS;
  }

  printf("AllocatedPoint3d failed. Coordinate(s) do not match.\n");
  return EXIT_FAILURE;
}

Point3d* AllocatePoint3d(int16_t x, int16_t y, int16_t z) {
  Point3d* pointer = (Point3d*) malloc(sizeof(Point3d));
  if (pointer != NULL) {
    pointer->x_coord = x;
    pointer->y_coord = y;
    pointer->z_coord = z;
  }
  return pointer;
}
