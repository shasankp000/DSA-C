#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// This program deletes a pattern/string from the main string.

// eg: removing "Hello" from "Hello World" -> " World". 


// NOTE: This program makes use of logic implemented in the previous programs like pattern1.c, slicing2.c, append2.c


int main() {

    int size = 100;

    int i, j, k, l, s_len, input_len, sep_len, total_len,f_index, l_index = 0;

    char *str, *input_str, *sep_str;

    // initializing the strings.

    // skipping type casting for malloc this type as compiler can auto cast it.

    str = malloc(size * sizeof(char));
    input_str = malloc(size * sizeof(char));
    sep_str = malloc(size * sizeof(char));

    printf("Enter the main string: ");
    gets(str);
    printf("\n");

    printf("Enter the string which is to be deleted: ");
    gets(input_str);
    printf("\n");

    
    s_len = strlen(str);
    input_len = strlen(input_str);

    
    // reallocating memory for these two strings as their size won't change.

    input_str = (char *)realloc(input_str, input_len+1);

    

    for (k = 0; k < s_len; k++) {
        if (str[k] == input_str[j]) {
            j++;
            if (j == input_len) {

                // silent search algo.

                // printf("String search complete. \n");
                // printf("String starts at index %d and ends at index %d \n", k - input_len + 1, k);
                break;
            }
        } else {
            j = 0;
        }
    }

    if (j != input_len) {
        printf("String not found.\n");
    }


    // storing the first and last indexes into separate variables.

    f_index = k - input_len + 1;
    l_index = k;

    j = 0;

    // String replacment begins from here.

    // separating the string after the given ending position.

    sep_len = (s_len-1) - l_index; // finding the length of the separated string.

    for(i=(l_index+1); i<s_len; i++) {

        sep_str[j] = str[i];
        j++;

        if (j == sep_len) {
            sep_str[j] = '\0'; // terminating the substring after slicing is done. 
        }

    }

    sep_len = strlen(sep_str); // just to be on the safe side. 

    str[f_index] = '\0'; // ending the string at the first index.

    s_len = strlen(str);

    // string separation complete, string to be deleted no longer exists.


    // time to merge the str and separated string in the correct order.


    total_len = s_len + sep_len; // total length of the first half.

    j = 0;

    for(i=f_index; i<total_len; i++) {

        str[i] = sep_str[j];
        j++;

    } // merge str with separated string.

    str[i] = '\0'; // terminate the final string.

    printf("The new string is: ");
    puts(str);


    //cleanup 

    free(str);
    free(input_str);
    free(sep_str);


    return 0;
}