#include<stdio.h>
#include<stdlib.h>


// Here we will insert an element at the beginning of a circular linked list. 

struct Node {

    int data;
    struct Node * next;

};


void LLtraversal(struct Node *head) {

    struct Node *ptr = head;

    while (ptr->next!=head) {
        
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }

    printf("%d", ptr->data); // print the data of the last node.


}


struct Node * insertAtBeginning(struct Node *head, int data) {

    struct Node * ptr = head;

    struct Node *q = (struct Node *)malloc(sizeof(struct Node)); // new node to be inserted.


    while(ptr->next!=head) {

        ptr = ptr->next; // traverse to the end.

    }
    

    q->data = data;
    q->next = head; // linking the new head to the old head. (now second node.)


    ptr->next = q; // linking the last node to the new head.


    return(q); // return the new head.

}



int main() {

    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;


    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));


    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 41;
    third->next = fourth;

    fourth->data = 66;
    fourth->next = head; // instead of null, fourth node connects to the head, thereby forming a circular linked list.

    // let's insert a new head with data = 5

    head = insertAtBeginning(head, 5);

    /*
    
        Output:

                5
                7
                11
                41
                66
    
    */
    
    
    LLtraversal(head);




    return 0;
}