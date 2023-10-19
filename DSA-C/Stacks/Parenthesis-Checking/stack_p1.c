#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Stack ADT using a doubly linked list.


// Here we are going to do pattern matching but for parenthesis in equations.

// If ( detected, push onto stack.

// If ) detected, pop from stack.

/*

 While popping, stack should not underflow. If this happens then parenthesis is unbalanced.

 At EOE (end of expression), stack should be empty. If not then parenthesis is unbalanced.

*/

struct Bool {

    int value;

};

struct Node {
	
	char data;
	struct Node * next;
	struct Node * back;

};

struct Stack {

    int size;

    char top;

    struct Node * current_ptr; // will keep track of last created node in the stack.

    struct Node * top_ptr; // will keep track of the top most node whose value is not 0

    struct Node * ptr; // will point to the head of the linked list of the stack.

};



int isEmpty(struct Node *head) {

    struct Bool * bool_val = malloc(sizeof(struct Bool));

    int val = bool_val->value;

    if (head->data == ' ') {

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

    if (stack_ptr->current_ptr->data != ' ') {

        val = 1;
        return val;

    }

    else {

        val = 0;
        return val;

    }


}


void Peek(struct Stack * stack_ptr) {

    if (stack_ptr->top_ptr == NULL) {

        printf("Stack empty! \n");

    }

    else {

        printf("top = %c \n", stack_ptr->top_ptr->data);

    }

    

}

void Pop(struct Stack * stack_ptr ) {

    if (stack_ptr->top_ptr->back == NULL) {

        stack_ptr->top = ' ';

        stack_ptr->top_ptr->data = ' ';

    }

    else {

        stack_ptr->top = ' ';

        stack_ptr->top_ptr->data = ' ';

        stack_ptr->top_ptr = stack_ptr->top_ptr->back;

        stack_ptr->top = stack_ptr->top_ptr->data;


    }


}


void Push(struct Node * head, struct Stack * stack_ptr, char data) {

    struct Node * p = head;

    struct Stack * q = stack_ptr;

    if (head->data == ' ') {

        head->data = data;
        q->top = data;
        q->top_ptr = head;


    }

    else {

        struct Node * current = head;

        while (current->data != ' ') {

            current = current->next;

            if (current->data == ' ') {

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
    p->data = ' ';

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


void StackTraverse(struct Stack * stack_ptr) {

    struct Node * head = stack_ptr->ptr;

    while(head->next != NULL) {

        printf("%c \n", head->data);
        head=head->next;

    }


}


int main() {

	int max_size = 8;

	int size = 50;

	char *str;

	str = (char *)malloc(size * sizeof(char)); // allocate the character array.


    int i, bool_val, str_len;

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


    sp->ptr = head;


    // StackTraverse(sp);

    printf("Enter the equation: ");
    gets(str);
    printf("\n");

    str_len = strlen(str);

    i = 0;
    
    while(str[i] != '\0') {
        
         if (str[i] == '(' || str[i] == '[' || str[i] == '{' ) {
            
            Push(head, sp, str[i]);

        }    

        if (str[i] == ')' || str[i] == ']' || str[i] == '}') {

            if (isEmpty(head)) {

                printf("Found an unbalanced parenthesis \n");
                
            }

            else {

                Pop(sp);

            }


        }

        i++;
    
    }

    //Reached end of expression.


    if (isEmpty(head)) {

        printf("The parentheses are balanced. \n");
                
    }

    else {

        printf("The parentheses are unbalanced. \n");


    }

    


	return 0;
}