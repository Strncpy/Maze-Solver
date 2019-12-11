#include <stdio.h>
#include <stdlib.h>
#include "../headers/solver.h"
#include "../headers/memoryalloc.h"

struct coordinates *ptr_to_array ;
    int n_dfs;
int *matrix_dfs;
int dim;
int init_dfs ()
{
    n_dfs=1;
    ptr_to_array=(struct coordinates*)malloc(n_dfs*sizeof(struct coordinates));

}


void push( int i, int j)

{
    realloc(ptr_to_array,(n_dfs+1)*sizeof(struct coordinates));
    ptr_to_array[n_dfs+1].x=i;
    ptr_to_array[n_dfs+1].y=j;
    n_dfs++;

}

void pull (struct coordinates *ptr_to_array, int i, int j, int n)

{
    //free(ptr_to_array[n]);
    realloc(ptr_to_array,(n_dfs-1)*sizeof(struct coordinates));
    n_dfs--;

}


int dfs_algorithm (int *mat,int n)
{
    matrix_dfs=mat;
    dim=n;
    int i=2;
    int j=1; //starts from the wall so the 2.2 can be placed in the stack/ptr_to_array


    search_and_move (i,j);
    int number_of_steps;

    //ooor//

    for(number_of_steps=0; number_of_steps<n_dfs; number_of_steps++)
    {
        printf("The path is this one: \n");
        printf(" X Coordinate is: %d \n", ptr_to_array[number_of_steps].x);
        printf(" Y Coordinate is: %d \n", ptr_to_array[number_of_steps].y);
       //update pointer to point at next element of the array of struct
        printf("\n");
    }
    n_dfs=0;
}

void search_and_move (int i,int j) //searches for neighbors of 0 and moves in their place
{
    if (get_matrix_element(matrix_dfs,dim,i+1,j)==0) //if down is o
    {
        //element_change_matrix(matrix_dfs,n_dfs,i,j,3);
        push(i,j);
        i=i+1;
        search_and_move(i,j);
    }

    else if (get_matrix_element(matrix_dfs,dim,i,j+1)==0)  //if right is 0
    {
        //element_change_matrix(matrix_dfs,n_dfs,i,j,3);
        push(i,j);  //this freaking 'n' needs some damn definition and see if it changes, as wanted, its value
        j=j+1;
        search_and_move(i,j);
    }
    else  if (get_matrix_element(matrix_dfs,dim,i-1,j)==0) //if up is0
    {
        //element_change_matrix(matrix_dfs,n_dfs,i,j,3);
        push(i,j);
        i=i-1;
        search_and_move(i,j);
    }
    else if (get_matrix_element(matrix_dfs,dim,i,j-1)==0) //if left is 0
    {
        //element_change_matrix(matrix_dfs,n_dfs,i,j,3);
        push(i,j);
        j=j-1;
        search_and_move(i,j);
    }
    else
    {
        pull(ptr_to_array,i,j,n_dfs);
        search_and_move(ptr_to_array[n_dfs].x, ptr_to_array[n_dfs].y);
    }


}



