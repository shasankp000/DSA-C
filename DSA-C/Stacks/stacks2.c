#include<stdio.h>
#include<stdlib.h>

// Here we will define a Stack ADT using doubly linked lists.


struct Bool {

    int value;

};


struct Node {

    int data;
    struct Node * next;
    struct Node * back;


};


struct Stack {

    int size;

    int top;

    struct Node * current_ptr; // will keep track of last created node in the stack.

    struct Node * top_ptr; // will keep track of the top most node whose value is not 0

    struct Node * ptr; // will point to the head of the linked list of the stack.

};


int isEmpty(struct Node *head) {

    struct Bool * bool_val = malloc(sizeof(struct Bool));

    int val = bool_val->value;

    if (head->data == 0) {

        val = 1;
        return val;

    }

    else {

        val = 0;
        return val;

    }

}

int isFull(struct Stack * stack_ptr) {

    struct Bool * bool_val = malloc(sizeof(struct Bool));

    int val = bool_val->value;

    if (stack_ptr->current_ptr->data != 0) {

        val = 1;
        return val;

    }

    else {

        val = 0;
        return val;

    }


}


void Peek(struct Stack * stack_ptr) {

    printf("top = %d \n", stack_ptr->top_ptr->data);
}

void Pop(struct Stack * stack_ptr ) {

    stack_ptr->top = 0;

    stack_ptr->top_ptr->data = 0;

    stack_ptr->top_ptr = stack_ptr->top_ptr->back;

    stack_ptr->top = stack_ptr->top_ptr->data;


}


void Push(struct Node * head, struct Stack * stack_ptr, int data) {

    struct Node * p = head;

    struct Stack * q = stack_ptr;

    if (head->data == 0) {

        head->data = data;
        q->top = data;
        q->top_ptr = head;


    }

    else {

        struct Node * current = head;

        while (current->data != 0) {

            current = current->next;

            if (current->data == 0) {

                break;

            }

        }

        current->data = data;
        q->top = data;
        q->top_ptr = current;
        
    }


}


struct Node * CreateNode(struct Node *head, struct Stack * stack_ptr) {

    // This function will create a node with initial data set to 0.

    struct Node * p =  (struct Node *)malloc(sizeof(struct Node));

    p->back = NULL;
    p->next = NULL;
    p->data = 0;

    if (head == NULL) {

        // Linked list is empty and new node can be set as head.

        head = p;

        // printf("Head created \n");

        return head;

    }

    else {

        // Traverse to the end of the list and insert the new node


        struct Node * current = (struct Node *)malloc(sizeof(struct Node));

        current = head->next;

        if (current == NULL) { // immediate node after head is NULL

            current = p;
            current->back = head;
            head->next = current;

            stack_ptr->current_ptr = current; // stores the address of the last created node after head.

            // printf("New node after head created \n");

            return head;

        }

        else {

            struct Node * q = stack_ptr->current_ptr;

            if (q->next == NULL) {

                q->next = p;
                p->back = q;

                stack_ptr->current_ptr = p; // stores the address of the newly created node as the current node.

                // printf("New node created \n");

            }
    
            return head;

        }


    }


}

void StackTraverse(struct Node * head) {

    struct Node * p = head;

    while (p->next != NULL) {

        if (p->data != 0) {

            printf("%d \n", p->data);

        }

        else {

            break;

        }

        p = p->next;


    }




}



int main() {

    int max_size = 8;

    int i, bool_val;

    struct Stack * sp;

    sp = malloc(sizeof(struct Stack));
    
    sp->size = max_size;
    sp->ptr = NULL;

    struct Node * head = sp->ptr;

    // create the linked list.

    // create the head first.

    head = CreateNode(head, sp);

    for (i=1; i < max_size; i++) {
        
       head = CreateNode(head, sp);

    }

    
    Push(head, sp, 7);
    Push(head, sp, 11);
    Push(head, sp, 20);
    Push(head, sp, 41);
    Push(head, sp, 66);

    Peek(sp);

    Pop(sp);

    Peek(sp);


    bool_val = isEmpty(head);

    if (bool_val) { printf("Stack is empty! \n"); } else { printf("Stack is not empty! \n"); }

    bool_val = isFull(sp);

    if (bool_val) { printf("Stack is full! \n"); } else { printf("Stack is not full! \n"); }

    printf("The elements in the stack are: \n");

    StackTraverse(head); 


    return 0;
}