/*
Question: Write a C program to implement binary search tree.
Instructions: 1. Insert
              2. Inorder Traversal
              3. Preorder Traversal
              4. Postorder Traversal
              5. Exit
              Input/output
              Enter your choice: 2
              Tree is Empty
              Enter your choice: 1
              Enter Data to Insert: 15
              Enter your choice: 1
              Enter Data to Insert: 12
              Enter your choice: 1
              Enter Data to Insert: 14
              Enter your choice: 1
              Enter Data to Insert: 13
              Enter your choice: 1
              Enter Data to Insert: 11
              Enter your choice: 1
              Enter Data to Insert: 17
              Enter your choice: 1
              Enter Data to Insert: 16
              Enter your choice: 2
              Inorder: 11 12  13 14 15 16 17
              Enter your choice: 3
              Preorder: 15 12 11 14 13 17 16
              Enter your choice: 4
              Postorder: 11 13 14 12 16 17 15
              Enter your choice: 5
*/

//My Approach/Solution:
#include <stdio.h>
#include <stdlib.h>

struct NODE {
    int VALUE;
    struct NODE *LEFT, *RIGHT;
} *ROOT = NULL;

int insertNode () {
    printf ("Enter Data to Insert: ");
    int data;
    scanf ("%d", &data);
    struct NODE *store = (struct NODE*) malloc (sizeof (struct NODE));
    store -> VALUE = data;
    store -> LEFT = store -> RIGHT = NULL;
    if (ROOT == NULL) {
        ROOT = store;
    }
    else {
        struct NODE *temp = ROOT;
        while (temp != NULL) {
            if (data < temp -> VALUE) {
                if (temp -> LEFT == NULL) {
                    temp -> LEFT = store;
                    break;
                }
                temp = temp -> LEFT;
            }
            else {
                if (temp -> RIGHT == NULL) {
                    temp -> RIGHT = store;
                    break;
                }
                temp = temp -> RIGHT;
            }
        }
    }
    return 0;
}

void inorderTraversal (struct NODE *temp) {
    if (temp != NULL) {
        inorderTraversal (temp -> LEFT);
        printf ("%d ", temp -> VALUE);
        inorderTraversal (temp -> RIGHT);
    }
}

void preorderTraversal (struct NODE *temp) {
    if (temp != NULL) {
        printf ("%d ", temp -> VALUE);
        preorderTraversal (temp -> LEFT);
        preorderTraversal (temp -> RIGHT);
    }
}

void postorderTraversal (struct NODE *temp) {
    if (temp != NULL) {
        postorderTraversal (temp -> LEFT);
        postorderTraversal (temp -> RIGHT);
        printf ("%d ", temp -> VALUE);
    }
}

int main () {
    int choice;
    do {
        /*
        printf ("************************\n");
        printf ("********* MENU *********\n");
        printf ("************************\n");
        printf ("1. Insert\n");
        printf ("2. Inorder Traversal\n");
        printf ("3. Preorder Traversal\n");
        printf ("4. Postorder Traversal\n");
        printf ("5. Exit \n\n");
        */
        printf ("Enter your choice: ");
        scanf ("%d", &choice);
        switch (choice) {
            case 1: insertNode ();
                    break;
            case 2: if (ROOT == NULL) {
                        printf ("Tree is Empty\n");
                    }
                    else {
                        printf ("Inorder: ");
                        inorderTraversal (ROOT);
                        printf ("\n");
                    }
                    break;
            case 3: if (ROOT == NULL) {
                        printf ("Tree is Empty\n");
                    }
                    else {
                        printf ("Preorder: ");
                        preorderTraversal (ROOT);
                        printf ("\n");
                    }
                    break;
            case 4: if (ROOT == NULL) {
                        printf ("Tree is Empty\n");
                    }
                    else {
                        printf ("Postorder: ");
                        postorderTraversal (ROOT);
                        printf ("\n");
                    }
                    break;
            case 5: exit (0);
                    break;
            default: continue;
        }
    }while (choice);
    return 0;
}
