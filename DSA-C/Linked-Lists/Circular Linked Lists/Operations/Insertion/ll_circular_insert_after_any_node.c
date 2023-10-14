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


void insertAfterNode(int data, struct Node * prevNode) {

    struct Node * p = prevNode;

    struct Node *q = (struct Node *)malloc(sizeof(struct Node)); // new node to be inserted.
  
    q->data = data; // 71

    q->next = p->next;

    p->next = q;

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


    insertAfterNode(55, third);

    // let's insert a new node at index 2 with data = 15

    /*
    
        Output:

                7
                11
                41
                55
                66
    
    */
    
    
    LLtraversal(head);




    return 0;
}