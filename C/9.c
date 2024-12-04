#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 
Lab 9: Using Standard Library Functions for Complex Operations
============================================================

This lab introduces various functions from the C standard library, including:
- srand() and rand() for generating random numbers
- time() for getting current time in seconds since January 1, 1970
- fopen(), fprintf(), fscanf() for file input/output operations
- strcpy() to copy strings

The following code is an intentionally broken example to introduce you to common issues in C programs.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[20];
} Student;

void printStudent(Student student) {
    printf("ID: %d\n", student.id);
    printf("Name: %s\n", student.name); // incorrect way to access string member
}

int main() {
    srand(time(NULL)); // seed random number generator with current time

    FILE *fp = fopen("students.txt", "w"); // attempt to write to file without checking if it exists
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    Student students[10];

    for (int i = 0; i < 10; i++) { 
        strcpy(students[i].name, "John Doe"); // incorrect way to copy string
        fprintf(fp, "%d %s\n", i, students[i].name);
    }

    fclose(fp); // attempt to close file without checking if it was successfully opened

    return 0;
}

// Commented out section for exercises
/* 
Exercises to try:
1. Replace the code inside 'printStudent' function with a correct way to access string member using pointer arithmetic.
2. Change the code inside 'main()' function to use fscanf() instead of fprintf() to read from file and store in struct members.
3. Add error handling for fopen(), fclose() and fscanf() to print an error message if these functions fail.
*/

