#include<stdio.h>
#include<stdlib.h>


// Here we will simply create a circular linked list. 

struct Node {

    int data;
    struct Node * next;

};



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



    return 0;
}