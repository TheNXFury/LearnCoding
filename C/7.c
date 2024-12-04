#include <stdio.h>

/* 
Lab 7: Using Pointers and Arrays to Organize Data
=====================================================

This lab introduces the concept of pointers and arrays in C programming language.
It also covers how to use if statements, loops, functions, and various data types within a function.

Broken Sample Code:
--------------------

The following code is an intentionally broken example to introduce you to common issues in C programs.
*/
#include <stdio.h>

void printArray(int *arr, int size) {
    for (int i = 0; i <= size; i++) { // incorrect loop condition
        printf("%d ", arr[i]); // attempt to access array out of bounds
    }
}

void main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
    } else {
        int arr[n]; // dynamically allocate array size using variable 'n'
        
        for (int i = 0; i < n; i++) { // attempt to access array out of bounds
            scanf("%d", &arr[i]);
        }

        printArray(arr, n);
    }

    // Commented out section for exercises
    /* 
    Exercises to try:
    1. Replace the loop condition in 'printArray' function with a correct one that accesses all elements in the array.
    2. Change the code inside 'main()' function to use pointer arithmetic instead of indexing the array.
    3. Add an else clause to handle cases where the input is not a positive integer and print an error message using printf().
    */
}

/* 
Functions: A Key Concept in C Programming
======================================

In this lab, we introduced functions as a way to organize code and reuse it.

Pointers: A Way to Access Memory Addresses
-----------------------------------------

A pointer is a variable that stores the memory address of another variable.
We can use pointers to access array elements, allocate memory dynamically,
and perform other operations on data stored in memory.

Arrays: A Collection of Similar Data Elements
---------------------------------------------

An array is a collection of similar data elements stored in contiguous memory locations.
We can use arrays to store and manipulate collections of data.
    */

