#include<stdio.h>

// case 2: passing addresses of data values

int fun1(int *num) { // since addresses must be passed by a reference which are really just pointers.

    printf("%d", *num);

}


int main() {

    int arr[5] = {1, 2, 3, 4, 5};

    fun1(&arr[4]); // passing reference to the address of the value.


}