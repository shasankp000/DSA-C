#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// program to compare two strings.
// can be done by strcmp(s1, s2), which is defined in string.h

int main() {

    int size = 50;

    int i, len1, len2 = 0;

    char *str1, *str2;

    str1 = (char *)malloc(size * sizeof(char));
    str2 = (char *)malloc(size * sizeof(char));

    printf("Enter the first string: ");
    gets(str1);
    printf("\n");
    
    printf("Enter the second string: ");
    gets(str2);
    printf("\n");

    len1 = strlen(str1);
    len2 = strlen(str2);

    if (len1 == len2) {
        while (i<len1) {
            if(str1[i] == str2[i]) {

                i++;

                if (i == len1) {

                    printf("The two strings are equal");

                }

            }

            else {

                printf("The two strings are not equal");

            } 

            break;
        } 
    } 

    else {

        printf("The two strings are not equal");

    }

    // cleanup

    free(str1);
    free(str2);


    return 0;
}