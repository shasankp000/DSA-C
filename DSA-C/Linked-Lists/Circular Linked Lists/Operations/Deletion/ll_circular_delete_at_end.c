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


void deleteAtEnd(struct Node *head) {

    struct Node * p = head;

    struct Node *q = head->next;

    while(q->next != head) {

        q = q->next; // traverse to the last node
        p = p->next; // traverse to the node before the last node

    }

    // printf("q->data = %d \n", q->data); // 66
    // printf("p->data = %d \n", p->data); // 41


    p->next = q->next; // linking the second last node to the next of last node i.e head.

    free(q); // delete the last node.




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

    // let's delete the current last node.

    deleteAtEnd(head);

    /*
    
        Output:
                7
                11
                41
    
    */
    
    
    LLtraversal(head);




    return 0;
} 