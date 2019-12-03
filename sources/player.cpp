#include <stdio.h>
#include <stdlib.h>
#include "../headers/player.h"
#include "../headers/mat_gen.h"
#include "../headers/memoryalloc.h"

struct player
{
    char name[20];
    int score;
    int lives;
    int nr_moves;
    int hints;
} player1;

int *matrix;
int move_up(int n,int a,int b)
{
    if(get_matrix_element(matrix,n,a-1,b)==0)
        return 1;
    else
        return 0;
}
int move_left(int n,int a,int b)
{
    if(get_matrix_element(matrix,n,a,b-1)==0)
        return 1;
    else
        return 0;
}
int move_down(int n,int a,int b)
{
    if(get_matrix_element(matrix,n,a+1,b)==0)
        return 1;
    else
        return 0;
}
int move_right(int n,int a,int b)
{
    if(get_matrix_element(matrix,n,a,b+1)==0)
        return 1;
    else
        return 0;
}
