#include <stdio.h>

/* 
Lab 6: Using Functions to Organize Code and Introduce Recursion
=============================================================

This lab introduces the concept of functions in C programming language.
It also covers how to use if statements, loops, and various data types within a function.

Broken Sample Code:
--------------------

The following code is an intentionally broken example to introduce you to common issues in C programs.
*/
#include <stdio.h>

int fibonacci(int n) {
    int result = 0;
    for (int i = 0; i < n; i++) { // incorrect loop condition
        printf("%d\n", result); // print the current value instead of calculating the next value
    }
    return result;
}

void main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
    } else {
        fibonacci(n);
    }

    // Commented out section for exercises
    /* 
    Exercises to try:
    1. Replace the loop condition with a correct one that calculates the Fibonacci sequence up to n.
    2. Change the code inside the function to use recursion instead of loops.
    3. Add an else clause to handle cases where the input is not a positive integer and print an error message using printf().
    */
}

/* 
Functions: A Key Concept in C Programming
======================================

In this lab, we introduced functions as a way to organize code and reuse it.
A function takes arguments, performs some calculations or operations, and returns a result.

To use a function, you need to declare it with the return type (int, float, etc.) 
and then call it using its name followed by parentheses containing the arguments.

Note: The 'void' keyword is used as a placeholder for the main() function in this example,
      but it's not a good practice. In C programming, the main() function should have an int return type.
    */

