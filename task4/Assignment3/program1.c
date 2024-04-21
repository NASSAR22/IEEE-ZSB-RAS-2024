#include <stdio.h>

struct condition {
    int id;
    char name[50];
    char class_id;
};

int main() {
    struct condition case1;

    printf("Case 1 : Size of struct condition (id, name, class_id): %zu bytes\n", sizeof(case1));

    struct condition_edit {
        char name[50];
        int id;
        char class_id;
    };

    struct condition_edit case2;

    printf("Case 2 : Size of struct condition edit (name, id, class_id): %zu bytes\n", sizeof(case2));

    return 0;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
YES
The size of case 1 is not equal case 2 ; case1 = 56 & case2 = 60
Because padding ,so struct is made up of members. Each member has a data type. The size of a struct is made up of the sum of the sizes of all of its members, plus any padding added by the compiler for data alignment purposes The compiler also adds padding before/between/after members to ensure that certain data types are aligned on appropriate memory address boundaries.
For example, a 4-byte data type is aligned to a memory address that is divisible by 4 because alignment of multibyte values is required - attempting to access a 4-byte and it is depending on the CPU architecture and compiler.
*/
