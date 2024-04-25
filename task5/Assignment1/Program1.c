#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned int marks : 3;
    unsigned int roll_number : 4;
    unsigned int age : 8;
    char *name;
    char *address;
}student_info;


void print_student_info(student_info *students);

int main(){
    student_info students[15];

    students[0].roll_number = 0;
        students[0].name = "ahmed0" ;
        students[0].address = "10th of ramadan" ;
        students[0].age = 21;
        students[0].marks = 10;

        students[1].roll_number = 1;
        students[1].name = "ahmed1" ;
        students[1].address = "zagazig" ;
        students[1].age = 21;
        students[1].marks = 2;

        students[2].roll_number = 2;
        students[2].name = "ahmed2" ;
        students[2].address = "belbies" ;
        students[2].age = 21;
        students[2].marks = 1;

        students[3].roll_number = 3;
        students[3].name = "ahmed3" ;
        students[3].address = "6 of october" ;
        students[3].age = 21;
        students[3].marks = 0;

        students[4].roll_number = 4;
        students[4].name = "ahmed4" ;
        students[4].address = "badr" ;
        students[4].age = 21;
        students[4].marks = 9;

        students[5].roll_number = 5;
        students[5].name = "ahmed5" ;
        students[5].address = "alex" ;
        students[5].age = 21;
        students[5].marks = 12;

        students[6].roll_number = 6;
        students[6].name = "ahmed6" ;
        students[6].address = "cairo" ;
        students[6].age = 21;
        students[6].marks = 8;

        students[7].roll_number = 7;
        students[7].name = "ahmed7" ;
        students[7].address = "10th of ramadan" ;
        students[7].age = 21;
        students[7].marks = 3;

        students[8].roll_number = 8;
        students[8].name = "ahmed8" ;
        students[8].address = "10th of ramadan" ;
        students[8].age = 21;
        students[8].marks = 8;

        students[9].roll_number = 9;
        students[9].name = "ahmed9" ;
        students[9].address = "zagazig" ;
        students[9].age = 21;
        students[9].marks = 7;

        students[10].roll_number = 10;
        students[10].name = "ahmed10" ;
        students[10].address = "10th of ramadan" ;
        students[10].age = 21;
        students[10].marks = 10;

        students[11].roll_number = 11;
        students[11].name = "ahmed11" ;
        students[11].address = "diarb negm" ;
        students[11].age = 21;
        students[11].marks = 5;

        students[12].roll_number = 12;
        students[12].name = "ahmed12" ;
        students[12].address = "10th of ramadan" ;
        students[12].age = 21;
        students[12].marks = 6;

        students[13].roll_number = 13;
        students[13].name = "ahmed13" ;
        students[13].address = "zifta" ;
        students[13].age = 21;
        students[13].marks = 4;

        students[14].roll_number = 14;
        students[14].name = "ahmed14" ;
        students[14].address = "10th of ramadan" ;
        students[14].age = 21;
        students[14].marks = 9;

    print_student_info(students);
    printf("\n\nSize of struct = %d\n\n", sizeof(student_info));

}

void print_student_info(student_info *students) {
    for (int i = 0; i < 15; ++i) {
        printf("Student %d:\n", i + 1);
        printf("Roll Number: %d\n", students[i].roll_number);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Address: %s\n", students[i].address);
        printf("Marks: %d\n", students[i].marks);
        printf("\n");
    }
}
