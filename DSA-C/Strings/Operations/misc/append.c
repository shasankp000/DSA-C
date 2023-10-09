#include<stdio.h>
#include<string.h>
// append two strings.

// can be done using strcat() which is defined in string.h

int main() {

    char source_str[100], dest_str[100];

    char result_str[100];

    int i, j, s_len, d_len, s_end = 0;

    
    printf("Enter the source(starting) string: ");
    gets(source_str);
    printf("\n");
    
    printf("Enter the destination(ending) string: ");
    gets(dest_str);
    printf("\n");

    s_len = strlen(source_str);
    d_len = strlen(dest_str);

    int total_len = s_len + d_len; 


    for (i=0; i<s_len; i++) {

        result_str[i] = source_str[i];
    };

    s_end = i;
    total_len++; // increase the total length by 1 to accomodate a white space.

    result_str[s_end] = ' ';
    s_end++; // loop will start after the whitepsace

    while(dest_str[j] != '\0') {

        result_str[s_end] = dest_str[j];
        j++;
        s_end++;

        if (s_end>=total_len) {
            result_str[s_end] = '\0';
        }

    }


    for (i=0; i<total_len; i++) {
         
        printf("%c", result_str[i]);
    };

    // algo 1, definitive and efficient but uses more memory.

    return 0;
}