#include<stdio.h>

// convert a lowercase string to uppercase.

int main() {

    char str[199], upper_str[100];

    int i=0;

    printf("Enter the string: ");
    gets(str);

    while (str[i] != '\0') {
        if (str[i]>='a' && str[i]<='z') {

            upper_str[i] = str[i] - 32; // subtracting 32 from the ASCII value which converts it to uppercase.

        }
        else {

            upper_str[i] = str[i]; 

        }

        i++;
    }

    upper_str[i] = '\0'; // terminating the string with a null pointer.
    printf("The string converted to uppercase is: ");
    puts(upper_str);
    

    return 0;
}