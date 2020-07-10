/*
  name: Bella Rose
  UW email: brose714@uw.edu
*/
#include <stdio.h>     /* printf */
#include <inttypes.h>  /* uint8_t, uintptr_t, PRI.. */
#include <stdlib.h>    /* EXIT_SUCCESS */

void DumpHex(void* pData, int byteLen);

int main(int argc, char** argv) {
  char char_val = '0';
  int32_t int_val = 1;
  float float_val = 1.0;
  double double_val = 1.0;

  typedef struct {
    char char_val;
    int32_t int_val;
    float float_val;
    double double_val;
  } Ex2Struct;

  Ex2Struct struct_val = { '0', 1, 1.0, 1.0 };
  
  DumpHex(&char_val, sizeof(char));
  DumpHex(&int_val, sizeof(int32_t));
  DumpHex(&float_val, sizeof(float));
  DumpHex(&double_val, sizeof(double));
  DumpHex(&struct_val, sizeof(struct_val));

  return EXIT_SUCCESS;
}

/*
DumpHex implementation - a C function that prints, in hex,
the values of the bytes allocated to some variables
*/
void DumpHex(void* pData, int byteLen) { 
  // convince the compiler to let me access the bytes in memory, startng from void*
  uint8_t * pointer = (uint8_t *) pData;
  // use format specifier PRIxPTR to print uintptr_t
  printf("The %d bytes starting at 0x%"PRIxPTR " are: ", byteLen, (uintptr_t) pData); 
  // use loop to itearate once for each byte in the variable
  for (int i = 0; i < byteLen; i++) { 
    // using the pointer to extract the byte and print it
    // use format specifier PRIx8 to print uint8_t (pointer)
    printf("%02" PRIx8 "%s", pointer[i], (i == (byteLen-1)? "\n" : " "));
  }
}
