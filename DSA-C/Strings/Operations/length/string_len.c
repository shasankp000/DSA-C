#include<stdio.h>

// can be done using strlen() defined in string.h
 
int main() {

    char str[100]; 
    
    int i=0, length;

    printf("Enter the string: ");

    gets(str);

    printf("\n");

    while(str[i] != '\0') {
        
        i++;
        
    };

    length = i;

    printf("The length of the string is: %d", length);

    return 0;
}