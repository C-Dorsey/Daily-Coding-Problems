/*
GPOE
This file contains my solution for the get products of all
other elements problem. The file cantains the solutions for
the method using division and without using division.

Author: Cohl Dorsey
*/

#include<stdio.h>

/* Functions that are used. */
void solution_with_division(int *arr, int length);
void solution_without_division(int *arr, int length);

int main(void)
{
    /* Initialized variables */
    int original[] = {1, 2, 3, 4, 5};
    int length = sizeof(original)/sizeof(int);

    /* Solutions */
    printf("Solution with division\n");
    solution_with_division(original, length);

    printf("Solution with division\n");
    solution_without_division(original, length);

    return(0);
}

/*
This function is the solution to the problem using division.
First the new array is initialized, then the product of the
numbers in the given array is calculated, then finally using
division the element of the new array is calculated and
printed.
*/
void solution_with_division(int *original, int length)
{
    int total = 1; /* Contains the sum of the products. */
    int new_arr[length]; /* The new array. */

    /* Loop that calculates the total product. */
    for(int i = 0; i < length; i++)
        total *= original[i];

    /* Loop for calculating the new array. */
    for(int j = 0; j < length; j++)
        new_arr[j] = total / original[j];

    /* Print the new array. */
    for(int k = 0; k < length; k++)
        printf("%d ", new_arr[k]);
    printf("\n");
}

/*
This function is the solution to the problem without using division.
It uses a double for loop to simultaneously keep track of the current
index as well as iterate over the original array to calculate the
product except for the one at the current index.
*/
void solution_without_division(int *original, int length)
{
    int new_arr[length]; /* The new array. */

    /* Fill new array with 1's for future multiplication. */
    for(int n = 0; n < length; n++)
        new_arr[n] = 1;

    /* The solution without using division. */
    for(int i = 0; i < length; i++) /* Keeps track of current index. */
    {
        for(int j = 0; j < length; j++) /* Calculates the total product. */
        {
            /* A check to make sure the number at the index isn't included. */
            if(j != i)
                new_arr[i] *= original[j];
        }
    }

    /* Print the new array. */
    for(int m = 0; m < length; m++)
        printf("%d ", new_arr[m]);
    printf("\n");
}
