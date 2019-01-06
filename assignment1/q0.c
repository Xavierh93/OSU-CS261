/* CS261- Assignment 1 - Q.0*/
/* Name: Xavier Hollingsworth
 * Date: 04/17/18
 * Solution description:
 */

#include <stdio.h>

void fooA(int* iptr)
{
    /*Print the value of iptr*/
    printf("The value pointed to by iptr %d\n", *iptr);
    
    /*Print the address pointed to by iptr*/
    printf("The address pointed to by iptr is %p\n", iptr);
    
    /*Print the address of iptr itself*/
    printf("The address of iptr is %p\n", &iptr);
    
    /*Change the value of iptr itself*/
    *iptr = 100;
    
}

int main() {
    
    /*declare an integer x and initialize it randomly to a value in [0,10] */
    int lower = 0;
    int upper = 10;
    int x = 0;
    x = (rand() + lower) % (upper + 1);
    
    /*Print the address and value of x*/
    printf("The address of x is %d\n", &x);
    printf("The value of x is %d\n", x);
    
    /*Call fooA() with the address of x*/
    fooA(&x);
    
    /*Print the value of x*/
    printf("The value of x is %d\n", x);
    printf("The address of x is %d\n", &x);
    
    /*Yes it is different because the function fooA edited the value stored at the address x. */
    
    return 0;
}
