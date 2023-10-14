#include<stdio.h>
#include<stdlib.h>

// Here we will create a doubly linked list.

// In a doubly linked list there are two links between the nodes, a next link which points to the next node and a back/previous link which points to the previous node.


struct Node {

    int data;
    
    struct Node * next;

    struct Node * back;

};

void LLTraversal(struct Node *head) {

    struct Node *ptr = head;


    while(ptr->next!=NULL) {

        printf("%d \n", ptr->data);
        ptr = ptr->next;

    }

    // print the data of the last node.

    printf("%d ", ptr->data);

}



int main() {

    struct Node * head, *second, *third, *fourth;

    // memory allocation.

    head = malloc(sizeof(struct Node)); // fast typing since compiler will automatically detect type at compile time.
    second = malloc(sizeof(struct Node));
    third = malloc(sizeof(struct Node));
    fourth = malloc(sizeof(struct Node));
 
    head->back = NULL;
    head->data = 7;
    head->next = second;

    second->back = head;
    second->data = 11;
    second->next = third;

    third->back = second;
    third->data = 41;
    third->next = fourth;

    fourth->back = third;
    fourth->data = 66;
    fourth->next = NULL;

    
    // let's traverse through the doubly linked list.


    LLTraversal(head);



    return 0;
}