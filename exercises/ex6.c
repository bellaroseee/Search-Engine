/*
  Copyright 2020 Bella Rose
  name : Bella Rose
  UW email : brose714@uw.edu
*/

#include <stdio.h>   /* fopen, fseek, ftell, fread, fclose */
#include <stdlib.h>  /* EXIT_FAILURE, EXIT_SUCCESS */
#include <stdint.h>  /* int64_t */

int main(int argc, char** argv) {
  int64_t size;

  // check bogus inputs
  if (argc != 2) {
    printf("Please enter filename.\n");
    return EXIT_FAILURE;
  }

  char* fName = argv[1];

  FILE * fStream = fopen(fName, "rb");
  // check if successfuly open file
  if (fStream == NULL) {
    printf("Unable to open file.\n");
    return EXIT_FAILURE;
  }

  // get the file size from begining to end of file
  // have the origin to be the end of file
  if (fseek(fStream, 0, SEEK_END) != 0) {
    printf("Reposition failure.\n");
    return EXIT_FAILURE;
  }
  // size returned in bytes
  size = ftell(fStream);
  if (size == -1) {
    printf("Fail to get file size.\n");
    return EXIT_FAILURE;
  }

  // print the file content in reverse order
  for (int64_t i = size-1; i >= 0; i--) {
    char c;
    // "position" is set i away from beginng
    fseek(fStream, i, SEEK_SET);
    // read 1 character at a time
    if (fread((void*) &c, sizeof(char), 1, fStream) != 1) {
      printf("Reading error.\n");
      return EXIT_FAILURE;
    }
    printf("%c", c);
  }
  fclose(fStream);

  return EXIT_SUCCESS;
}


// file is opened in binary mode so that ftell can return
// the number of bytes from the beginning of file
