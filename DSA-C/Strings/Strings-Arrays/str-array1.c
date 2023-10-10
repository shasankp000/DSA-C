#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// 2d arrays are being used here.

// The main array houses arrays of strings. Each sub array is the array of characters which make up the string..
// The strings need to be sorted.


// eg 


// char name[5][10] = {"Ram", "Mohan", "Shyam", "Hari", "Gopal"};

//           1 2 3 4 5 6 7 8 9 10
 
// name[0] = R A M '\0'
// name[1] = M O H A N '\0'
// name[2] = S H Y A M '\0'
// name[3] = H A R I '\0'
// name[4] = G O P A L '\0'


// Above is a memory representation of the 2D array, better represented on page 143 of the pdf in this repo.

int main() {


    // 144

    char names[5][10], temp[10];
    int i, n, j;

    printf("Enter the number of students : ");
    scanf("%d", &n);
    printf("\n");

    // Consume the newline character left in the input buffer or else gets will read it and skip first input.
    getchar();

    for (i = 0; i < n; i++) {
        
        printf("Enter the name of student %d: ", i+1);
        gets(names[i]);
        printf("\n");

        
    }


    // Time to sort the elements of the array lexicographically(alphabetically).


    for (i = 0; i < n; i++) {

        for (j = 0; j < n-i-1 ; j++) {
            
            if (strcmp(names[j], names[j+1])>0) { // if value > 0 then this means that rstring < lstring or lstring > rstring ; value < 0 means rstring > lstring or lstring < rstring; if value = 0 this means rstring = lstring.
                
                strcpy(temp, names[j]); // strcpy copies a string into temp array.
                strcpy(names[j], names[j+1]); // overwrites previous string with the next one
                strcpy(names[j+1], temp); // copies the string contained into temp as the next string.

            }

        }
                 
    }


    printf("Names of the students in alphabetical order are: \n");
    
    for (i = 0; i < n; i++) {

        puts(names[i]);
        printf("\n");

    }


    return 0;
}