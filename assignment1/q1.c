/* CS261- Assignment 1 - Q.1*/
/* Name: Xavier Hollingsworth
 * Date: 04/18/2018
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

struct student* allocate(){
    /*Allocate memory for ten students*/
    struct student *Students = malloc(sizeof(struct student) * 10);
    
    /*return the pointer*/
    return Students;
}

void generate(struct student* students){
    /*Generate random and unique ID and random scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        (students+i)->id = (rand() + 1) % (10 + 1);
        (students+i)->score = (rand()) % (100 + 1);
    }
    
}

void output(struct student* students){
    /*Output information about the ten students in the format:
     ID1 Score1
     ID2 score2
     ID3 score3
     ...
     ID10 score10*/
    for (int i = 0; i < 10; i++)
    {
        printf("%d %d\n", (students + i) -> id, (students + i) -> score);
    }
}

void summary(struct student* students){
    /*Compute and print the minimum, maximum and average scores of the ten students*/
    int min = 100;
    int max = 0;
    float average;
    int total = 0;
    
    for (int i = 0; i < 10; i++)
    {
        if (min > (students + i) -> score)
        {
            min = (students + i) -> score;
        }
        if (max < (students + i) -> score)
        {
            max = (students + i) -> score;
        }
        total += ((students + i) -> score);
    }
    average = total / 10;
    
    printf("The highest score is %d\n", max);
    printf("The lowest score is %d\n", min);
    printf("The average score is %.2f\n", average);
}

void deallocate(struct student* stud){
    /*Deallocate memory from stud*/
    if (stud != NULL)
    {
        free(stud);
        stud = 0;
    }
}

int main(){
    struct student* stud = NULL;
    
    /*call allocate*/
    stud = allocate(stud);
    
    /*call generate*/
    generate(stud);
    
    /*call output*/
    output(stud);
    
    /*call summary*/
    summary(stud);
    
    /*call deallocate*/
    deallocate(stud);
    return 0;
}
