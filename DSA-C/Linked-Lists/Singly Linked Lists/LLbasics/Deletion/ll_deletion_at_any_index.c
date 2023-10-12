#include<stdio.h>
#include<stdlib.h>

// Here we will delete at a given index of the linked list.

struct Node {

    int data;
    struct Node *next; // pointer which will point to the next node.

};


void LLtraversal(struct Node *ptr) {

    // will take in the head as the argument.
    // keep looping until ptr reaches NULL

    while (ptr != NULL) {

        printf("%d\n", ptr->data);
        ptr = ptr->next; // accessing the next node.
    }


}

struct Node * deleteAtAnyIndex(struct Node * head, int index) {

    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *q = (struct Node *)malloc(sizeof(struct Node));

    ptr = head;
    int i = 0;

    while(i!=index-1) { 

        ptr = ptr->next; // traverse till before the given index.

        i++;


    }

    q = ptr->next;
    ptr->next = q->next;

    free(q);


    return head;

    
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


    // let's delete at the second index of the linked list.

    head = deleteAtAnyIndex(head, 2);

    LLtraversal(head);
    
    /*
    OUTPUT:
            7
            11
            66
    */



    return 0;
}