#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {

    int size = 100;

    char *str, *substr;

    int f_index, l_index;

    int i, j, m = 0;

    str = (char *)malloc(size * sizeof(char));
    substr = (char *)malloc(size * sizeof(char));

    printf("Enter the string: ");
    gets(str);
    printf("\n");

    printf("Enter the position from which to start the substring: ");
    scanf("%d", &f_index);
    printf("\n");

    l_index = strlen(str);

    m = l_index - f_index; // length of new sub string.

    for(i=f_index; i<l_index; i++) {

        substr[j] = str[i];
        j++;

        if (j == m) {
            substr[j] = '\0'; // terminating the substring after slicing is done. 
        }
        
    }

    printf("The new substring is: ");
    puts(substr);

    // cleanup

    free(str);
    free(substr);

    return 0;
}