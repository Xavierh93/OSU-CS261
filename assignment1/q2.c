/* CS261- Assignment 1 - Q.2*/
/* Name:
 * Date:
 * Solution description:
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int foo(int* a, int* b, int c)
{
    /* Increment a */
    a++;
    
    /* Decrement  b */
    b--;
    
    /* Assign a+b to c */
    c = *a + *b;
    
    /* Return c */
    return c;
}

int main(){
    /* Declare three integers x,y and z and initialize them randomly to values in [0,10] */
    srand(time(NULL));
    int x = rand() % 11;
    int y = rand() % 11;
    int z = rand() % 11;
    
    /* Print the values of x, y and z */
    printf("The value of x is %d\n", x);
    printf("The value of y is %d\n", y);
    printf("The value of z is %z\n", z);
    
    /* Call foo() appropriately, passing x,y,z as parameters */
    int value = foo(&x, &y, z);
    
    /* Print the values of x, y and z */
    printf("The value of x is %d\n", x);
    printf("The value of y is %d\n", y);
    printf("The value of z is %z\n", z);
    
    /* Print the value returned by foo */
    printf("The value returned by foo is %d\n", value);
    
    
    return 0;
}
