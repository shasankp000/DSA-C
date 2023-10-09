#include<stdio.h>


int main() {

    //declaring and initializing a string.

    char str1[] = "Hello World!"; // H e l l o  W o r l d ! \0 <- null pointer

    // Reading strings.

    // scanf() can be used but it terminates at whitespaces so not good for sentences.
    // if scanf() is used, ampersand is not needed before the variable.

    // using getchar() to get a char. getch() works as well.

    char str2[10];
    int i=0;
    char input_char;

    input_char = getchar(); // get a char.

    printf("Enter string (termination at whitespaces): \n");
    while(input_char != '*') {

        str2[i] = input_char;
        i++;
        input_char = getchar(); // get the next char
        printf("\n");

    }

    str2[i] = '\0'; // Terminate the string with null char.

    // Using getchar() we have to deliberately append a null pointer at the end of the string.

    // Functions like getch() and getche() automatically do that.


    return 0;
}