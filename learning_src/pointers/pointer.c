#include <stdio.h>

int main () {

    int  var1;
    char var2[10];

    printf("Address of var1 variable: %x\n", &var1  );
    printf("Address of var2 variable: %x\n", &var2  );

    int  var = 20;   /* actual variable declaration */
    int  *ip = &var;        /* pointer variable declaration */

    ip = &var;  /* store address of var in pointer variable*/

    printf("Address of var variable: %x\n", &var  );

    /* address stored in pointer variable */
    printf("Address stored in ip variable: %x\n", ip );

    /* access the value using the pointer */
    printf("Value of *ip variable: %d\n", *ip );

    int  *ptr = NULL;

    printf("The value of ptr is : %x\n", ptr  );
   
   return 0;
}

// if(ptr)     /* succeeds if p is not null */
// if(!ptr)    /* succeeds if p is null */