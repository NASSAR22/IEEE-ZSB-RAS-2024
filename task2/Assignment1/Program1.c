#include <stdio.h>

int main() {

  int x = 10;
  char y = 'A';
  long long z = 1234567890;


  int *p1 = &x;
  char *p2 = &y;
  long long *p3 = &z;

  printf("p1 before increment: %p\n", p1);
  printf("p2 before increment: %p\n", p2);
  printf("p3 before increment: %p\n\n", p3);

  p1++;
  p2++;
  p3++;

  printf("\np1 after increment: %p \n", p1); //Incremented by sizeof(int) bytes ***int = 4 bytes***
  printf("p2 after increment: %p \n", p2); //Incremented by sizeof(char)bytes ***char = 1 byte***
  printf("p3 after increment: %p \n", p3); //Incremented by sizeof(long long) bytes ***ll = 8 bytes***

  return 0;
}
