#include <stdio.h>

/* 
Lab 3: For Loops and Nested Loops
=================================

This lab introduces the usage of for loops in C programming language.
It also covers the concept of nesting loops to perform more complex operations.

Broken Sample Code:
--------------------

The following code is an intentionally broken example to introduce you to common issues in C programs.
*/
#include <stdio.h>

int main(void)
{
    int i;
    for (i = 0; i <= 5; i++) // outer loop
    {
        printf("Iteration %d\n", i);
        
        int j; // declare inner loop variable
        /* 
        The following while loop is intended to print the numbers from 1 to 10.
        However, it has a logical error and will run indefinitely.
        */
        while (i <= 5) { // incorrect condition for the inner loop
            printf("Inner Iteration %d\n", j);
            
            /* 
            The following line is intended to increment the variable j,
            but it has a syntax error. It should be written as 'j++;'
            */
            int k = j++;
        }
    }

    return 0;
}

/* 
Exercises to try:
1. Replace the condition in the while loop with a correct one that makes the loop terminate after printing numbers from 1 to 10.
2. Change the syntax of the line 'int k = j++' to increment the variable 'j'.
3. Add an if statement inside the for loop to print "This is iteration number %d" when i equals to 5.
*/

