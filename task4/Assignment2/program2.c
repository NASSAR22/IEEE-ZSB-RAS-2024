#include <stdio.h>
#include <string.h>

struct info {
    char name[50];
    int age;
};

int main() {

    struct info person;

    strcpy(person.name, "Ahmed Essam");
    person.age = 21;

    struct info* ptr;

    ptr = &person;

    printf("Name: %s\n", ptr->name);
    printf("Age: %d\n", ptr->age);

    return 0;
}
