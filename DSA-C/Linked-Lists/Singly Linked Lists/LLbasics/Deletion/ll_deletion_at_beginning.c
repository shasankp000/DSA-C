#include<stdio.h>
#include<stdlib.h>

// Here we will delete the first node of the linked list.

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

struct Node * deleteAtBeginning(struct Node * head) {

    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    ptr = head; // copy the memory of head to ptr.

    head = head->next; // set the next node as the new head.

    free(ptr); // free the memory occupied by the previous head.


    return head; // return the new head.

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


    // let's delete at the beginning of the linked list.

    head = deleteAtBeginning(head);

    LLtraversal(head);
    /*
    OUTPUT:
            11
            41
            66
    */



    return 0;
}