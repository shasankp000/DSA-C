#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// This program searches for a particular substring in a string and if the string exists, then it's index is returned.

int main() {

    int size = 100;

    int i, j, k, s_len, input_len = 0;

    char *str, *input_str;

    // initializing the strings.

    str = malloc(size * sizeof(char));
    input_str = malloc(size * sizeof(char));

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
            j++;
            if (j == input_len) {
                printf("String search complete. \n");
                printf("String starts at index %d and ends at index %d \n", k - input_len + 1, k);
                break;
            }
        } else {
            j = 0;
        }
    }

    if (j != input_len) {
        printf("String not found.\n");
    }


    // cleanup

    free(str);
    free(input_str);


    return 0;
}