#include<stdio.h>
#include<stdlib.h>


// Here we will create and traverse through a circular linked list. 

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

    LLtraversal(head);


 /*
    
        Output:

                7
                11
                41
                66
    
    */

    return 0;
}