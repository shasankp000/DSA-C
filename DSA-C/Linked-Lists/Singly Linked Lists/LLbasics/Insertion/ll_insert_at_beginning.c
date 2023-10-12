#include<stdio.h>
#include<stdlib.h>

// Insertion of a node in the beginning of the linked list.


struct Node {

    int data;
    struct Node *next;

};

void LLtraversal(struct Node *ptr) {

    // will take in the head as the argument.
    // keep looping until ptr reaches NULL

    while (ptr != NULL) {

        printf("%d\n", ptr->data);
        ptr = ptr->next; // accessing the next node.
    }


}


int main() {


    struct Node * head; // head node.
    struct Node * second;
    struct Node * third;
    struct Node * fourth;

    // allocating memory from the heap.


    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));



    // assigning data and linking the nodes.

    head->data = 7; // same as head.data = 7;
    head->next = second; // pointing towards second node.

    second->data = 11;
    second->next = third;

    third->data = 41;
    third->next = fourth;

    fourth->data = 66;
    fourth->next = NULL; // terminating LINKED LIST here.

    // let's insert a new node at the beginning.

    // create a new node and allocate the memory.

    struct Node *new_head; // new head node.
    new_head = (struct Node *)malloc(sizeof(struct Node));


    new_head->data = 5;
    new_head->next = head; // point it towards existing head.


    LLtraversal(new_head);

    /*
    OUTPUT:
            5
            7
            11
            41
            66
    */


    return 0;
}