#include<stdio.h>
#include<stdlib.h>

// Here we will be inserting a node after a pre-existing node.
// This program is essentially the same as inserting after any index, only that it takes the existing node as a parameter.



struct Node {

    int data;
    struct Node *next;


};

void insertAfterNode(struct Node *prevNode, int data) {

    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));

    ptr->data = data;

    // link ptr to the next node after prevNode

    ptr->next = prevNode->next;

    // link the next of prevNode to ptr

    prevNode->next = ptr;


}


void LLtraversal(struct Node *ptr) {

    // will take in the head as the argument.
    // keep looping until ptr reaches NULL

    while (ptr != NULL) {

        printf("%d\n", ptr->data);
        ptr = ptr->next; // accessing the next node.
    }


}

int main() {


    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // allocating memory from the heap.

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));


    head->data = 7; // same as head.data = 7;
    head->next = second; // pointing towards second node.

    second->data = 11;
    second->next = third;

    third->data = 41;
    third->next = fourth;

    fourth->data = 66;
    fourth->next = NULL; // terminating LINKED LIST here.

    // let's insert a new node after second node.


    insertAfterNode(head, 15);

    LLtraversal(head);


    return 0;
}