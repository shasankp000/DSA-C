// Writing strings.

#include<stdio.h>

int main() {

    // Using printf()
    // Using puts()
    // Using putchar()

    char str1[] = "Hello world!";

    // speicifications can be added for string slicing in printf.

    printf("%5.5s", str1); // prints the first five characters. 

    // "5.<index>s"

    // By default the characters are right justified.

    printf("\n");

    // for left justification.

    printf("%-5.5s", str1); // prints the first five characters. 

    printf("\n");

    // puts()

    puts(str1); // is a simple function which overcomes the drawbacks of printf function

    // prints the entire string in the array.

    printf("\n");

    // using putchar() function repeatedly to print a list of single characters.

    int i = 0;

    while(str1[i] != '\0') {

        putchar(str1[i]); // Print the character at that index on the screen.
        i++;

    }

    

    return 0;
}