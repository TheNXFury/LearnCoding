#include <stdio.h>

/* 
Lab 5: Using Various Loops and Data Types to Calculate Fibonacci Sequence
=====================================================================

This lab introduces the usage of if statements, while loops, for loops, and various data types in C programming language.
It also covers a practical example of using these concepts to calculate the Fibonacci sequence.

Broken Sample Code:
--------------------

The following code is an intentionally broken example to introduce you to common issues in C programs.
*/
#include <stdio.h>

int main(void)
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    int a = 0, b = 1;
    for (int i = 0; i < n; i++) { // incorrect loop condition
        printf("%d\n", i); // print the iteration number instead of the Fibonacci sequence

        int temp; // declare temporary variable to store the previous value in the sequence
        if (i > 1) {
            temp = a + b;
            a = b;
            b = temp;
        }
    }

    return 0;
}

/* 
Exercises to try:
1. Replace the loop condition with a correct one that prints all Fibonacci numbers up to n.
2. Change the code inside the for loop to print the actual Fibonacci number instead of the iteration number.
3. Add an else clause to handle cases where the input is not a positive integer.
*/

