#include <stdio.h>

/* 
Lab 2: Variable Data Types and While Loop
=====================================

This lab introduces more variable data types such as float, double, boolean (using _Bool), and character.
It also covers the usage of while loops in C.

Broken Sample Code:
--------------------

The following code is an intentionally broken example to introduce you to common issues in C programs.
*/
#include <stdio.h>

int main(void)
{
    int x = 10; // declare integer variable
    float y = 3.14f; // declare floating point number
    double z = 6.28; // declare double precision floating point number
    _Bool isTrue = 1; // declare boolean variable (note: in C99 and above, _Bool type can be used)
    char name[20]; // declare character array

    printf("Value of x: %d\n", x); // print value of integer variable x
    printf("Value of y: %.2f\n", y); // print floating point number with 2 decimal places
    printf("Value of z: %lf\n", z); // print double precision floating point number

    int i = 0;
    while (i < 5) { // broken loop, missing increment statement
        /* 
        missing code here...

        */
    }

    scanf("%s", name); // read input into character array
    printf("Hello, %s!\n", name);

    return 0;
}

/* 
Exercises to try:
1. Replace the while loop condition with a more meaningful expression.
2. Add an increment statement to the while loop to make it work correctly.
3. Change the scanf() format specifier to read integer input instead of character array.
*/

