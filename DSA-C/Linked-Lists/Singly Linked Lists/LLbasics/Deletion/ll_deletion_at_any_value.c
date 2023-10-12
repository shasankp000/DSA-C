#include<stdio.h>
#include<stdlib.h>

// Here we will delete a node of the linked list by tracking it's value/data.

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

struct Node * deleteAtAnyValue(struct Node * head, int value) {

    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *q = (struct Node *)malloc(sizeof(struct Node));

    ptr = head; // set this to head
    q = head->next; // set this to the next node.
    
    while(q->next!=NULL) {

        ptr=ptr->next;
        q=q->next;

        if (q->data == value) {
            
            break; // value found, exit loop.

        }


    }

    ptr->next = q->next; // set the next of ptr to the next of next node(q).
    free(q); // free the node next of ptr.

    return head;

   

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


    // let's delete the node whose value is 41 of the linked list.

    head = deleteAtAnyValue(head, 41);

    LLtraversal(head);
    /*
    OUTPUT:
            7
            11
            66
    */



    return 0;
}