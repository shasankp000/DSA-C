#include<stdio.h>
#include<stdlib.h>

// Inserting a node in a linked list at any point.

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


    // Let's insert a node at the second position.

    struct Node * new_second;

    new_second = (struct Node *)malloc(sizeof(struct Node));

    new_second->data = 10;
    new_second->next = second;

    head->next = new_second;


    LLtraversal(head);

    /*
      OUTPUT:
    
      7 
      10
      11
      41
      66
      
     */

    return 0;
}