#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// This program searches for a particular substring in a string and if the string exists, then it's index is returned.

int main() {

    int size = 100;

    int i, j, k, s_len, input_len = 0;

    char *str, *input_str;

    // initializing the strings.

    str = (char *)malloc(size * sizeof(char));
    input_str = (char *)malloc(size * sizeof(char));

    printf("Enter the main string: ");
    gets(str);
    printf("\n");

    printf("Enter the string which is to be searched for: ");
    gets(input_str);
    printf("\n");

    s_len = strlen(str);
    input_len = strlen(input_str);


    for (k = 0; k < s_len; k++) {
        
        if (str[k] == input_str[j]) {
            
            break; // record starting index of string.

        }

    }

    printf("%d \n", k);
    j = 0; // resetting j

    for(i=0; i<s_len; i++) {

        if (str[i] == input_str[j]) { // check for first instance of the first char of the string
            
            j++;

        }

        if (j == input_len) {
            printf("String search complete, string found.");
            break;
        }

        if (i == s_len && j == 0) {
            printf("Search result came up empty, string does not exist.");
            break;
        }


    }
    printf("\n");
    printf("It starts at index %d and ends at index %d in the main string.\n", k, i);


    // cleanup

    free(str);
    free(input_str);


    return 0;
}