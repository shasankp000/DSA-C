#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {

    int size = 100;

    char *str, *reversed_str;

    str = (char *)malloc(size * sizeof(char));
    reversed_str = (char *)malloc(size * sizeof(char));

    int i, j, k = 0;

    printf("Enter the string: ");
    gets(str);
    printf("\n");

    j = strlen(str);

    for(i=(j-1); i>=0; i--) {

        reversed_str[k] = str[i];
        k++;


    }

    printf("The reversed string is: ");
    puts(reversed_str);


    // cleanup 

    free(str);
    free(reversed_str);


    return 0;
}