#include<stdio.h>

// case 3: passing the entire array as an argument.

int fun1(int arr[5]) {

    printf("%d", arr[4]);

}


int main() {

    int arr[5] = {1, 2, 3, 4, 5};

    fun1(arr);


}