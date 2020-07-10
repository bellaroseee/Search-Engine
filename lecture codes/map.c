#include <stdio.h>

#define LEN 4

int negate(int num) {return -num;}
int square(int num) {return num*num;}

// perform operation pointed to on each array element
void map(int a[], int len, int (* op)(int n)) {
  for (int i = 0; i < len; i++) {
    a[i] = (*op)(a[i]);  // dereference function pointer
  }
}

int main(int argc, char** argv) {
  int arr[LEN] = {-1, 0, 1, 2};
  int (* op)(int n);  // function pointer called 'op'
  op = square;  // assign to function
                // function name returns addr (like array)
  map(arr, LEN, op);
  for (int i = 0; i < LEN; i++) {
    printf("%d%c", arr[i], i == (LEN-1) ? '\n' : ' ');
  }
}
