#include<stdio.h>

// case 1: passing data values

int fun1(int num) {

    printf("%d", num);

}


int main() {

    int arr[5] = {1, 2, 3, 4, 5};

    fun1(arr[4]);


}