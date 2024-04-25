#include <stdio.h>

typedef signed char  Int8;
typedef short int    Int16;
typedef int          Int32;
typedef long int     Int64;
typedef unsigned char UInt8;
typedef unsigned short int UInt16;
typedef unsigned int  UInt32;
typedef unsigned long int UInt64;
typedef float        Float32;
typedef double       Float64;
typedef char         Char;

int main() {

  printf("Size of signed char: %d bytes\n", sizeof(Int8));
  printf("Size of short int: %d bytes\n", sizeof(Int16));
  printf("Size of int: %d bytes\n", sizeof(Int32));
  printf("Size of long int: %d bytes\n", sizeof(Int64));
  printf("Size of unsigned char: %d bytes\n", sizeof(UInt8));
  printf("Size of unsigned short int: %d bytes\n", sizeof(UInt16));
  printf("Size of unsigned int: %d bytes\n", sizeof(UInt32));
  printf("Size of unsigned long int: %d bytes\n", sizeof(UInt64));
  printf("Size of float: %d bytes\n", sizeof(Float32));
  printf("Size of double: %d bytes\n", sizeof(Float64));
  printf("Size of char: %d bytes\n", sizeof(Char));

  return 0;
}
