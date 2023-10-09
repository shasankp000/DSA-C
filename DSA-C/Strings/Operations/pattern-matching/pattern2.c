#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// This program replaces a pattern with another pattern in a string.

// eg: replacing "def" in "abcdefgh" to "xyz" -> "abcxyzgh" 


// NOTE: This program makes use of logic implemented in the previous programs like pattern1.c, slicing2.c, append2.c


int main() {

    int size = 100;

    int i, j, k, s_len, input_len, r_len, sep_len, total_len,f_index, l_index = 0;

    char *str, *input_str, *replace_str, *sep_str;

    // initializing the strings.

    // skipping type casting for malloc this type as compiler can auto cast it.

    str = malloc(size * sizeof(char));
    input_str = malloc(size * sizeof(char));
    replace_str = malloc(size * sizeof(char));
    sep_str = malloc(size * sizeof(char));

    printf("Enter the main string: ");
    gets(str);
    printf("\n");

    printf("Enter the string which is to be replaced with: ");
    gets(input_str);
    printf("\n");

    printf("Enter the new string: ");
    gets(replace_str);
    printf("\n");

    
    s_len = strlen(str);
    input_len = strlen(input_str);
    r_len = strlen(replace_str);

    
    // reallocating memory for these two strings as their size won't change.

    input_str = (char *)realloc(input_str, input_len+1);
    replace_str = (char *)realloc(replace_str, r_len+1);
    

    // searching where the string to be replaced exists in the main string.

    for (k = 0; k < s_len; k++) {
        
        if (str[k] == input_str[j]) {
            
            break; // record starting index of string.

        }

    }
    
    j = 0; // resetting j

    for(i=0; i<s_len; i++) {

        if (str[i] == input_str[j]) { // check for first instance of the first char of the string
            
            j++;

        }

        
        if (j == input_len) {
            break;
        }

        if (i == s_len && j == 0) {
            break;
        }


    }

    // storing the first and last indexes into separate variables.

    f_index = k;
    l_index = i;

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

    // string separation complete, input string to replaced no longer exists.


    // time to merge the str, replacement string and separated string in the correct order.


    total_len = s_len + r_len; // total length of the first half.

    j = 0;

    for(i=f_index; i<total_len; i++) {

        str[i] = replace_str[j];
        j++;

    } // merge str with replacement string.

    f_index = i; // where iteration last stopped after adding replacement string.
    total_len = total_len + sep_len; // adding current length with the length of remaining half.


    j = 0;

    for(i=f_index; i<total_len; i++) {

        str[i] = sep_str[j];
        j++;

    }


    printf("The new string is: ");
    puts(str);


    //cleanup 

    free(str);
    free(input_str);
    free(replace_str);
    free(sep_str);


    return 0;
}