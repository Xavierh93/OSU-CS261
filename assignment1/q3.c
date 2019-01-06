/* CS261- Assignment 1 - Q.3*/
/* Name: Xavier Hollingsworth
 * Date:04/18/2018
 * Solution description:
 */

#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include <time.h>

struct student{
    int id;
    int score;
};

void sort(struct student* students, int n){
    /*Sort the n students based on their score*/
    int currentScore, currentID;
    for (int i = 0; i < n; i++)
    {
        currentScore = (students + i) -> score;
        currentID = (students + i) -> id;
        for (int x = (i+1); x < n; x++)
        {
            if((students + x) -> score < currentScore)
            {
                (students + i) -> score = (students + x) -> score;
                (students + i) -> id = (students + x) -> id;
                (students + x) -> score = currentScore;
                (students + x) -> id = currentID;
                currentScore = (students + x) -> score;
                currentID = (students + x) -> id;
            }
        }
    }
}

int main(){
    /*Declare an integer n and assign it a value.*/
    int n = 5;
    
    /*Allocate memory for n students using malloc.*/
    struct student *students = malloc(sizeof(int) * n);
    
    /*Generate random and unique IDs and random scores for the n students, using rand().*/
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        (students + i) -> id = rand() % 6;
        (students + i) -> score = rand() % 101;
    }
    /*Print the contents of the array of n students.*/
    for (int i = 0; i < n; i ++)
    {
        printf("The id number for student %d is %d\n", i, (students + i) -> id);
        printf("The  score for student %d is %d\n", i, (students + i) -> score);
    }
    printf("\n");
    
    /*Pass this array along with n to the sort() function*/
    sort(students, n);
    
    /*Print the contents of the array of n students.*/
    for(int i = 0; i < n; i++){
        printf("The id number for student %d is %d\n", i, (students + i) -> id);
        printf("The score for student %d is %d\n", i, (students + i) -> score);
    }
    return 0;
}
