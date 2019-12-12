#include <stdio.h>
#include <stdlib.h>
#include "../headers/solver.h"
#include "../headers/memoryalloc.h"
#include "../headers/printing.h"

 coordinates *path;
 int dim_path;
 coordinates stak;

 void clean_matrix (int *matrix,int n)
{
    for(int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
        {
            if (get_matrix_element(matrix,n,i,j)==3 || get_matrix_element(matrix,n,i,j)==2)
                element_change_matrix(matrix,n,i,j,0);
        }
}



void push(coordinates *&path,int *dim_path,coordinates stak)
{
    if(path==NULL)
    {
        (*dim_path)++;
        path=(coordinates *)malloc(sizeof(coordinates));
        path[0]=stak;
    }
    else
    {
        (*dim_path)++;
        path=(coordinates *)realloc(path,*dim_path*sizeof(coordinates));
        path[*dim_path-1]=stak;
    }
}
void pop(coordinates *&path,int *dim_path)
{
    (*dim_path)--;
    path=(coordinates *)realloc(path,(*dim_path)*sizeof(coordinates));
}

void init_dfs()
{
    path=NULL;
    dim_path=0;
    stak.x=2;
    stak.y=2;
    push(path,&dim_path,stak);
}

 void search_and_move (int i,int j, int *matrix, int n) //searches for neighbors of 0 and moves in their place
    {
        printf ("Enters the search function");

    if (get_matrix_element(matrix,n,i+1,j)==0) //if down is o
             {
               element_change_matrix(matrix,n,i,j,4);
               stak.x=i;
               stak.y=j;
               i+=1;
               push(path,&dim_path,stak);
               search_and_move(i,j,matrix,n);

              }

        else if (get_matrix_element(matrix,n,i,j+1)==0)  //if right is 0
           {
                 element_change_matrix(matrix,n,i,j,4);
                 stak.x=i;
                 stak.y=j;
                 j+=1;
                 push(path,&dim_path,stak);
                 search_and_move(i,j,matrix,n);
            }
        else  if (get_matrix_element(matrix,n,i-1,j)==0) //if up is0
            {
                element_change_matrix(matrix,n,i,j,4);
                stak.x=i;
                stak.y=j;
                i-=1;
                push(path,&dim_path,stak);
                search_and_move(i,j,matrix,n);

            }
        else if (get_matrix_element(matrix,n,i,j-1)==0) //if left is 0
            {
                element_change_matrix(matrix,n,i,j,4);
                stak.x=i;
                stak.y=j;
                push(path,&dim_path,stak);
                j-=1;
                search_and_move(i,j,matrix,n);
            }
        else
        {
           pop(path,&dim_path);
           search_and_move(path[dim_path].x, path[dim_path].y,matrix,n);
        }


    }

    void dfs_algorithm()

    {
        if (dim_path<1)
        printf("There is no path \n");

        else
       search_and_move(stak.x,stak.y,matrix,n) ; //not declared ?

      for(int number_of_steps=0; number_of_steps<dim_path; number_of_steps++)
     {
        printf("The path is this one: \n");
        printf(" X Coordinate is: %d ", path[number_of_steps].x);
        printf(" Y Coordinate is: %d ", path[number_of_steps].y);
        //update pointer to point at next element of the array of struct
        printf("\n");
     }
        }



