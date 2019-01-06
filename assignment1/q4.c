/* CS261- Assignment 1 - Q.4*/
/* Name: Xavier Hollingsworth
 * Date: 04/18/2018
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
    return ch-'a'+'A';
}


void camelCase(char* word){
    /*Convert to camelCase*/
    int size = strlen(word);
    
    for (int i = 0; i < size; i++)
    {
        if (word[i] == '_')
        {
            word[i] = toUpperCase(word[i+1]);
            for (int n = i + 1; n < size - 1; n++)
            {
                word[n] = word[n+1];            }
            size--;
        }
    }
    word[size] = 0;
}

int main(){
    /*Read the string from the keyboard */
    char str[100];
    printf("Provide a string less than 100 characters: ");
    scanf("%s", str);
    
    /*Call camelCase*/
    camelCase(str);
    
    /*Print the  string */
    printf("%s\n", str);
    return 0;
}
