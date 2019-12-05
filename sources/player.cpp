#include <stdio.h>
#include <stdlib.h>
#include "../headers/player.h"
#include "../headers/mat_gen.h"
#include "../headers/memoryalloc.h"
#include "../headers/memoryalloc.h"

int move_up(int *matrix,int n,int a,int b)
{
    if(get_matrix_element( matrix,n,a-1,b)==0)
        return 1;
    else
        return 0;
}

int move_left(int *matrix,int n,int a,int b)
{
    if(get_matrix_element(matrix,n,a,b-1)==0)
        return 1;
    else
        return 0;
}

int move_down(int *matrix,int n,int a,int b)
{
    if(get_matrix_element(matrix,n,a+1,b)==0)
        return 1;
    else
        return 0;
}

int move_right(int *matrix,int n,int a,int b)
{
    if(get_matrix_element(matrix,n,a,b+1)==0)
        return 1;
    else
        return 0;
}

int tray(int *matrix,int n,int a,int b,int a1,int b1)
{
    if (get_matrix_element(matrix,n,a,b)==0)
    {
        element_change_matrix(matrix,n,a,b,3);
        element_change_matrix(matrix,n,a1,b1,2);
    }
    if (get_matrix_element(matrix,n,a,b)==2)
    {
        element_change_matrix(matrix,n,a,b,3);
        element_change_matrix(matrix,n,a1,b1,0);
    }
}
