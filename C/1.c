/* 
Lab 1: Introduction to C Programming Language
=====================================================

This lab introduces the basic concepts of C programming language such as main function, variable types, 
printf() and scanf() functions.

Broken Sample Code:
--------------------

The following code is an intentionally broken example to introduce you to common issues in C programs.
*/
#include <stdio.h>

int main(void)
{
    int x = 10; // declare integer variable
    char name[20]; // declare character array

    printf(name); // print name ( incorrect usage of printf() )
    scanf(x); // read input into variable x ( incorrect usage of scanf() )

    return 0;
}

// Exercises to try:
/* 
1. Replace the line 'scanf(x)' with 'scanf("%d", &x)' and see what happens.
2. Add a prompt to tell the user to enter their name before reading it using scanf().
3. Change the printf() statement to print the value of variable x instead of an undefined string.
*/

