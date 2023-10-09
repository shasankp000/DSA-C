#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {

    int size = 100;

    char *source_str; //char array pointer.

    char *dest_str; //char array pointer.

    source_str = (char *)malloc(size * sizeof(char)); // allocate memory of the char array.

    dest_str = (char *)malloc(size * sizeof(char)); // allocate memory of the char array.

    int i, j, s_len, d_len, total_len = 0;

    printf("Enter the source(starting) string: ");
    gets(source_str);
    printf("\n");
    
    printf("Enter the destination(ending) string: ");
    gets(dest_str);
    printf("\n");

    s_len = strlen(source_str);
    d_len = strlen(dest_str);

    total_len = s_len + d_len; 


    for(i=s_len; i<total_len; i++) {

        source_str[i] = dest_str[j];
        j++;

        if (i>=total_len) {
            source_str[i] = '\0'; //adding null pointer to terminate the string.
        }

    }

    for (i=0; i<total_len; i++) {
         
        printf("%c", source_str[i]);
    };

    // cleanup

    free(source_str); // free the memory occupied by the array.
    free(dest_str); // free the memory occupied by the array.

    // does the same job as append1.c only much faster and consumes lesser memory.

    return 0;
}