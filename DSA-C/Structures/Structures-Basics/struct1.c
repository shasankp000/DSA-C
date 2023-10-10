#include<stdio.h>

// Structure declaration.

// using the keyword struct followed by it's name.

// struct struct-name {
//
//      data_type var-name;
//         ........
// };

// e.g

struct Person {

    int age;
    char name[100];


};



// Typedef declaration.

/*

    The typedef (derived from type definition) keyword enables the programmer to create a new data
    type name by using an existing data type.

    By using typedef, no new data is created, rather an alternate name is given to a known data type.

    
    eg


    typedef struct student {

        int r_no;
        char name[20];
        char course[20];
        float fees;
        
    };


*/




int main() {

    // initializing a struct.


    // struct struct_name struct_var = {const1, const2 ....}

    struct Person p1 = {25, "Rahul"};

    // accessing the members of a struct.


    // using the dot operator

    printf("%d \n", p1.age);
    printf("%s \n", p1.name);





    return 0;
}