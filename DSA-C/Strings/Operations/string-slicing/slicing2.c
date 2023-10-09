#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main() {

    int size = 100;

    char *str, *input_str, *separated_str;

    int f_index, l_index; 

    int i, j, f_len, input_len, sep_len, total_len = 0;

    str = (char *)malloc(size * sizeof(char));
    input_str = (char *)malloc(size * sizeof(char));
    separated_str = (char *)malloc(size * sizeof(char));

    printf("Enter the main text: ");
    gets(str);

    printf("Enter the string to be entered in the main text: ");
    gets(input_str);

    printf("Enter the positon where the new string should be entered: ");
    scanf("%d", &f_index);
    printf("\n");

    input_len = strlen(input_str);

    l_index = strlen(str);

    // separate the strings into two parts.

    sep_len = l_index - f_index; // length of the separated string.

    // first we separate the string after the given position.

    for(i=f_index; i<l_index; i++) {

        separated_str[j] = str[i];
        j++;

        if (j == sep_len) {
            separated_str[j] = '\0'; // terminating the substring after slicing is done. 
        }
        
    }

    str[f_index] = '\0'; // terminating the original string after that position.

    f_len = strlen(str); // length of the new original string.


    // now we merge all 3 strings in the correct order.

    total_len = f_len + input_len; // length after adding the strings.
    j=0;

    for(i=f_index; i<total_len; i++) {

        str[i] = input_str[j];
        j++;

    } // merge original str with input str.

    f_index = i; // where iteration last stopped after adding input string.

    j = 0;

    total_len = total_len + sep_len; // adding the length of the separated string.
    printf("Length of new string: %d\n", total_len);

    for(i=f_index; i<total_len; i++) {

        str[i] = separated_str[j];
        j++;

    } // merge separated str with the previous str.

    str[i] = '\0'; // terminating the main string.
    
    printf("The new string is: ");

    puts(str);


    // cleanup 

    free(input_str);
    free(separated_str);
    free(str);

    return 0;
}