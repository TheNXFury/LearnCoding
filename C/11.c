#include <stdio.h>
#include <stdlib.h>

/* 
Lab 12: Implementing a Stack with Dynamic Memory Allocation
===========================================================

This lab introduces various functions from the C standard library, including:
- malloc(), free() for dynamic memory allocation
- linked lists with struct and pointer operations
- stack implementation using push and pop operations

The following code is an intentionally broken example to introduce you to common issues in C programs.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *stack = NULL;

void push(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) { 
        printf("Memory allocation failed.\n");
        return; // incorrect way to handle memory allocation failure
    }

    newNode->value = value;
    newNode->next = stack; // attempt to push null pointer onto stack

    if (stack != NULL) {
        Node *current = stack;
        while (current->next != NULL) { 
            current = current->next;
        }
        current->next = newNode;
    } else {
        stack = newNode;
    }

    printf("Stack size: %d\n", count(stack)); // attempt to access null pointer
}

void pop() {
    if (stack == NULL || stack->next == NULL) { 
        printf("Error: Stack is empty.\n"); // incorrect error message
        return; // incorrect way to handle empty stack
    }

    Node *temp = stack;
    stack = stack->next;

    free(temp); // attempt to free null pointer

    printf("Popped value: %d\n", temp->value); // attempt to access null pointer
}

int count(Node *stack) {
    int count = 0; 
    while (stack != NULL) { 
        count++;
        stack = stack->next;
    }

    return count;
}

void printStack() {
    Node *current = stack; 
    while (current != NULL) { 
        printf("%d\n", current->value);
        current = current->next;
    }
}

int main() {
    for (int i = 0; i < 10; i++) {
        push(i); // attempt to push null pointer onto stack
    }

    printStack(); // attempt to access null pointer

    return 0;
}

// Commented out section for exercises
/* 
Exercises to try:
1. Replace the code inside 'push' function with a correct way to handle memory allocation failure and push value onto stack.
2. Change the code inside 'pop' function to properly handle empty stack and free dynamically allocated memory before exiting.
3. Add error handling for malloc() and free() in 'count' function to print an error message if these functions fail, and clean up dynamically allocated memory before exiting.
*/

