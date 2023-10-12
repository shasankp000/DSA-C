#include<stdio.h>
#include<stdlib.h>

// Here we will delete the last node of the linked list.

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

struct Node * deleteAtEnd(struct Node * head) {

    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    struct Node *q = (struct Node *)malloc(sizeof(struct Node));

    p = head; // copy the memory of head to p.
    q = head->next; // this will copy the memory of the next node.

    while (q->next!=NULL) {

        p = p->next; // traverse till second last node..
        q = q->next; // traverse till NULL. 
        // loop exits at NULL.

    }

    p->next = NULL; // set the next of previous node to NULL.

    // delete q which is the last node.

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


    // let's delete at the end of the linked list.

    head = deleteAtEnd(head);

    LLtraversal(head);
    /*
    OUTPUT:
            7
            11
            41
    */



    return 0;
}