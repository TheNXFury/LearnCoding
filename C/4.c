#include <stdio.h>

/* 
Lab 4: If Statements and Logical Operators
=====================================

This lab introduces the usage of if statements in C programming language.
It also covers the concept of logical operators to combine multiple conditions.

Broken Sample Code:
--------------------

The following code is an intentionally broken example to introduce you to common issues in C programs.
*/
#include <stdio.h>

int main(void)
{
    int score = 85;

    // Incorrect usage of if statement
    if (score > 100) {
        printf("You got an A!\n");
    }

    /* 
    The following line is intended to print "You passed" when the score is greater than or equal to 60.
    However, it has a syntax error. It should be written as 'if (score >= 60)'
    */
    if (score > 60) {
        printf("You passed\n");
    }

    // Incorrect usage of logical operators
    if ((score >= 80 && score <= 100) || (score < 0)) {
        printf("Your grade is excellent or terrible\n");
    }

    return 0;
}

/* 
Exercises to try:
1. Replace the condition in the first if statement with a correct one that prints "You got an A!" when the score is greater than or equal to 90.
2. Change the syntax of the second if statement to use the correct logical operator for combining conditions.
3. Add another else clause to print "Sorry, you didn't pass" when the score is less than 60.
*/

