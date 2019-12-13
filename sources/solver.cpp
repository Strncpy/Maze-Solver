#include <stdio.h>
#include <stdlib.h>
#include "../headers/solver.h"
#include "../headers/memoryalloc.h"

coordinates *path;
int dim_path;
coordinates stak;

void clean_matrix (int *ma,int d)
{
    for(int i=1; i<=d; i++)
        for (int j=1; j<=d; j++)
        {
            if (get_matrix_element(ma,d,i,j)==3 || get_matrix_element(ma,d,i,j)==2)
                element_change_matrix(ma,d,i,j,0);
        }
}

void init_dfs()
{
    path=NULL;
    dim_path=0;
    stak.x=3;
    stak.y=3;
    push(path,&dim_path,stak);
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

void search_and_move (int i,int j, int *matrix, int n) //searches for neighbors of 0 and moves in their place
{
    //printf ("Enters the search function\n");

    if(i==n-2&&j==n-2)
        return;

    if (get_matrix_element(matrix,n,i+1,j)==0) //if down is o
    {
        element_change_matrix(matrix,n,i,j,4);
        i+=1;
        stak.x=i;
        stak.y=j;
        push(path,&dim_path,stak);
        search_and_move(i,j,matrix,n);

    }

    else if (get_matrix_element(matrix,n,i,j+1)==0)  //if right is 0
    {
        element_change_matrix(matrix,n,i,j,4);
        j+=1;
        stak.x=i;
        stak.y=j;
        push(path,&dim_path,stak);
        search_and_move(i,j,matrix,n);
    }
    else  if (get_matrix_element(matrix,n,i-1,j)==0) //if up is0
    {
        element_change_matrix(matrix,n,i,j,4);
        i-=1;
        stak.x=i;
        stak.y=j;
        push(path,&dim_path,stak);
        search_and_move(i,j,matrix,n);

    }
    else if (get_matrix_element(matrix,n,i,j-1)==0) //if left is 0
    {
        element_change_matrix(matrix,n,i,j,4);
        j-=1;
        stak.x=i;
        stak.y=j;
        push(path,&dim_path,stak);
        search_and_move(i,j,matrix,n);
    }
    else
    {
        element_change_matrix(matrix,n,i,j,4);
        pop(path,&dim_path);
        search_and_move(path[dim_path-1].x, path[dim_path-1].y,matrix,n);
    }


}

void dfs_algorithm(int *ma,int d)
{
    init_dfs();
    clean_matrix(ma,d);
    if (dim_path<1)
        printf("There is no path \n");
    else
        search_and_move(stak.x,stak.y,ma,d);
    for(int number_of_steps=0; number_of_steps<dim_path; number_of_steps++)
    {
        element_change_matrix(ma,d,path[number_of_steps].x,path[number_of_steps].y,2);
        //printf("%d ", path[number_of_steps].x);
        //printf("%d", path[number_of_steps].y);
        //update pointer to point at next element of the array of struct
        //printf("\n");
    }
}

/*void pull (struct coordinates *ptr_to_array, int i, int j, int n)

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


}*/



