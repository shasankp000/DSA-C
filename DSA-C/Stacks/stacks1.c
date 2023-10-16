#include<stdio.h>
#include<stdlib.h>

// Here we will define a Stack ADT (abstract data type) using arrays.

// All 3 operations, Push, Pop and Peek are defined here.

// I also developed a custom data type named Bool which records a single integer value of either 0 or 1.

// This was done as a fun purpose so skip the bool datatype if you can't understand it.

struct Bool {

    int value;

};


struct Stack {

    int size; // total size of the stack array.
    int usize; // used size in terms of array index within the stack.
    int top; // the top element of the stack.
    int *arr; // this will point to our actual array.
    int cursor; // records the current free position for element to be pushed within the stack.

};


int isFull(struct Stack * sp) {


    // 0 means False, 1 means True.

    struct Bool * bool = malloc(sizeof(struct Bool)); 

    if (sp->usize == sp->size-1) {

        bool->value = 1;

    }

    else {

        bool->value = 0;

    }


    return bool->value;

}



int isEmpty(struct Stack * sp) {


    // 0 means False, 1 means True.

    struct Bool * bool = malloc(sizeof(struct Bool)); 

    if (sp->top == -1) {

        bool->value = 1;

    }

    else {

        bool->value = 0;

    }


    return bool->value;

}

void Peek(struct Stack * sp) {

    if (sp->top == -1) {

        printf("Stack empty!");

    }

    else {

        printf("top = %d \n", sp->top);


    }


}


void Pop(struct Stack * sp) {


    if (sp->top==-1) {

       printf("Stack empty! \n");

    }

    else {

        sp->usize--;

        int j = sp->usize;

        sp->top = sp->arr[j];

    }


}


void Push(struct Stack * sp,  int data) {

    int i = sp->cursor;

    sp->usize = i;

    // check for overflow condition.

    if (sp->arr[i] == sp->top) {
    
        printf("Stack overflow! \n");

    } 

    else {
        
        if (sp->top==-1) {

            // Stack is empty right now and first element can be inserted.

            sp->arr[i] = data;
            sp->top = data;
            sp->cursor++;

        }

        else {

            // already an element exists

            sp->arr[i] = data;
            sp->top = data;
            sp->cursor++; // increased by 1 incase further push operations is done.
            
        }


    }

    
    
}

void StackTraverse(struct Stack * stack_p) {
    
    int total_len = stack_p->usize;
    int top = stack_p->top;
    int i = 0;

    for (i = 0; i <= total_len ; i++) {
        
        if (top==-1) {
            
            printf("Stack empty! \n");
            break;

        }


        printf("%d \n", stack_p->arr[i]);

    }


}


int main() {

    int max_size = 8;

    int bool_val;

    struct Stack * sp;

    sp = malloc(sizeof(struct Stack));

    sp->size = max_size;

    sp->top = -1; // since the array is empty right now, top is set to -1

    sp->arr = (int *)malloc(sp->size * sizeof(int)); // dynamically creating the integer array.

    // Setting the current free index and current used size.

    sp->cursor = 0;
    sp->usize = 0;

    // let's populate the stack.

    Push(sp, 1);
    Push(sp, 2);
    Push(sp, 3);
    Push(sp, 4);
    Push(sp, 5);
    Push(sp, 6);
    Push(sp, 7);
    Push(sp, 8);


    Peek(sp); // print the value of the top element.


    // Check whether the stack is empty or full .

    bool_val = isEmpty(sp);


    if (bool_val) { printf("Stack is empty! \n"); } else { printf("Stack is not empty! \n"); }


    bool_val = isFull(sp);


    if (bool_val) { printf("Stack is full! \n"); } else { printf("Stack is not full! \n"); }


    // Lastly traverse through the entire stack.

    printf("The elements in the stack are: \n");

    StackTraverse(sp); 


    return 0;
}