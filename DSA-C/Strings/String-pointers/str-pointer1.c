#include<stdio.h>
#include<string.h>
#include<stdlib.h>


// Program to a string into another string.
// same as accessing the elements of an integer array with a pointer.


int main() {

    int size = 100;

    char *str, *copy_str;
    char *pstr, *pcopy_str;

    str = malloc(size * sizeof(char));
    copy_str = malloc(size * sizeof(char));

    pstr = str; // pointing pstr towards str array
    pcopy_str = copy_str; // same as pstr.

    printf("Enter the string: "); 
    gets(str); // Hello World!
    printf("\n");

    int input_len = strlen(str);

    // reallocating memory of the strings according to string length.

    str = realloc(str, input_len+1);
    copy_str = realloc(copy_str, input_len+1);

    while (*pstr != '\0') {
        
        *pcopy_str = *pstr; // copying the value of pstr over to pcopy_str.

        pstr++, pcopy_str++; // moving on to the address of the next char.

        // loop continues until pstr doesn't encounter null pointer.

    }

    // pcopy_str at the end of string, let's terminate it with the null pointer.

    *pcopy_str = '\0';

    printf("The copied text is: ");

    puts(copy_str); // Hello World!


    // cleanup

    free(str);
    free(copy_str);


    return 0;
}