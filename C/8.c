#include <stdio.h>

/* 
Lab 8: Using Structs to Organize Complex Data
=============================================

This lab introduces the concept of structs in C programming language.
It also covers how to use if statements, loops, functions, arrays, pointers, and various data types within a struct.

Broken Sample Code:
--------------------

The following code is an intentionally broken example to introduce you to common issues in C programs.
*/
#include <stdio.h>

typedef struct {
    int id;
    char name[20];
    float grade;
} Student;

void printStudent(Student *student) {
    printf("ID: %d\n", student.id); // incorrect way to access struct member
    printf("Name: %s\n", student.name); // incorrect way to access struct member
    printf("Grade: %.2f\n", student.grade); // incorrect way to access struct member
}

void main() {
    Student students[10]; // dynamically allocate array of structs

    for (int i = 0; i < 10; i++) { // attempt to access array out of bounds
        printf("Enter student's ID, name and grade: ");
        scanf("%d %s %.2f", &students[i].id, students[i].name, &students[i].grade);
    }

    for (int i = 0; i < 10; i++) {
        printStudent(&students[i]); // incorrect way to pass struct pointer
    }

    // Commented out section for exercises
    /* 
    Exercises to try:
    1. Replace the code inside 'printStudent' function with a correct way to access struct members using pointers.
    2. Change the code inside 'main()' function to use array indexing instead of passing struct pointer to 'printStudent'.
    3. Add an else clause to handle cases where user input is invalid and print an error message using printf().
    */
}

/* 
Functions: A Key Concept in C Programming
======================================

In this lab, we introduced functions as a way to organize code and reuse it.

Structs: A Way to Organize Complex Data
----------------------------------------

A struct is a collection of variables of different data types stored together.
We can use structs to organize complex data such as student records,
and perform operations on each field using pointer arithmetic.

Pointers: A Way to Access Memory Addresses
-----------------------------------------

In the previous lab, we introduced pointers as a way to access memory addresses.
Now we can see how to use pointers with structs to access each field individually.
    */

