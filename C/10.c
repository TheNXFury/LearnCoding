#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
Lab 11: Using String Functions and Linked Lists
=============================================

This lab introduces various functions from the C standard library, including:
- strlen() to get length of string
- memcmp() to compare strings
- strcmp() to compare strings lexicographically
- strdup() to create a duplicate of a string
- malloc(), free() for dynamic memory allocation
- linked lists with struct and pointer operations

The following code is an intentionally broken example to introduce you to common issues in C programs.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char name[20];
    struct Node *next;
} Node;

Node *head = NULL;

void printList() {
    Node *current = head; // attempt to access null pointer
    while (current != NULL) { 
        printf("%s\n", current->name);
        current = current->next; // incorrect way to access linked list nodes
    }
}

int main() {
    for (int i = 0; i < 10; i++) {
        Node *newNode = (Node *)malloc(sizeof(Node));
        if (newNode == NULL) { 
            printf("Memory allocation failed.\n");
            return 1;
        }

        // attempt to read string without checking its length
        printf("Enter student's name: ");
        fgets(newNode->name, sizeof(newNode->name), stdin);
        newNode->next = head; // incorrect way to insert new node in linked list

        if (head != NULL) {
            Node *current = head;
            while (current->next != NULL) { 
                current = current->next;
            }
            current->next = newNode;
        } else {
            head = newNode;
        }

        printf("Length of name: %lu\n", strlen(newNode->name));
    }

    printList(); // attempt to access null pointer

    return 0;
}

// Commented out section for exercises
/* 
Exercises to try:
1. Replace the code inside 'printList' function with a correct way to access linked list nodes and print their names.
2. Change the code inside 'main()' function to use strcmp() instead of memcmp() to compare strings lexicographically.
3. Add error handling for malloc() and free() to print an error message if these functions fail, and properly clean up dynamically allocated memory before exiting.
*/

