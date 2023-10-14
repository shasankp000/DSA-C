#include<stdio.h>
#include<stdlib.h>


// Here we will insert an element at a particular index of a circular linked list. 

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


void insertAtAnyIndex(struct Node *head, int data, int index) {

    struct Node * p = head;

    struct Node *q = (struct Node *)malloc(sizeof(struct Node)); // new node to be inserted.

    int i = 0;

    while(i!=index-1) {

        p = p->next; // traverse to the node before the node at given index.
        i++;

    }
    
  
    q->data = data; // 71

    q->next = p->next; // link the new node to the next of p.

    p->next = q; // link the next of p to the new node.

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


    insertAtAnyIndex(head, 15, 2);


    // let's insert a new node at index 2 with data = 15

    /*
    
        Output:

                7
                11
                15
                41
                66
    
    */
    
    
    LLtraversal(head);




    return 0;
}