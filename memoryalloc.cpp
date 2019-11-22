#include <stdlib.h>
#include <stdio.h>
#include <stack>
#include <math.h>
#include "memoryalloc.h"


 /*alloc memory function to use whenever a new level (size of matrix)
  is launched*/
 int *allocate_matrix (long n)
 {
     int *matrix = (int*)malloc(pow(n,2) * sizeof(int));
     return matrix;//
 }


 /*dealoc memory for the matrix when level is completed or when the hint is done*/
void dealoc_matrix(int *matrix)
 {
     if(matrix!=NULL)
        free(matrix);  /* in this case is arr */
 }

  /* returns a matrix element by its coordinates */
 int get_matrix_element(int *matrix,int n, int i,int j)
            {
               return *(matrix+n*(i-1)+j-1);
            }


void element_change_matrix(int *matrix,int n, int x,int y,int value)
{
  *(matrix+n*(x-1)+y-1)=value;
}
