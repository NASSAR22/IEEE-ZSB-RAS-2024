#include <stdio.h>

struct student_info {
    int roll_number;
    char name[50];
    int age;
    char address[100];
    int marks;
};

void printStudentInfo(const struct student_info students[], int numStudents) {
    for (int i = 0; i < numStudents; ++i) {
        printf("Roll Number: %d\n", students[i].roll_number);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Address: %s\n", students[i].address);
        printf("Marks: %d\n", students[i].marks);
        printf("\n");
    }
}

int countStudentsWithLowMarks(const struct student_info students[], int numStudents, int fullMarks) {
    int count = 0;
    for (int i = 0; i < numStudents; ++i) {
        if (students[i].marks < (fullMarks * 0.6)) {
            count++;
        }
    }
    return count;
}

int main() {
    const int maxStudents = 15;
    const int fullMarks = 20;

    struct student_info students[maxStudents];
    int numStudents = 0;

    printf("Enter the information of %d students:\n", maxStudents);

    for (int i = 0; i < maxStudents; ++i) {
        printf("Student %d:\n", i + 1);

        printf("Enter Roll Number: ");
        scanf("%d", &students[i].roll_number);

        printf("Enter Name: ");
        scanf("%s", students[i].name);

        printf("Enter Age: ");
        scanf("%d", &students[i].age);

        printf("Enter Address: ");
        scanf("%s", students[i].address);

        printf("Enter Marks: ");
        scanf("%d", &students[i].marks);

        numStudents++;

        printf("\n");

        char choice;
        printf("Do you want to add another student? (y/n): ");
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }

    printf("Student Information:\n");
    printStudentInfo(students, numStudents);

    int numStudentsWithLowMarks = countStudentsWithLowMarks(students, numStudents, fullMarks);
    printf("Number of students with marks less than %d: %d\n", (int)(fullMarks * 0.6), numStudentsWithLowMarks);

    return 0;
}
