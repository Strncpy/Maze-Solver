#include <stdio.h>
#include <stdlib.h>
#include "../headers/player.h"
#include "../headers/mat_gen.h"
#include "../headers/memoryalloc.h"
#include "../headers/memoryalloc.h"

void text(struct player_stats player)
{
    FILE *pf_ptr;
    FILE *temp_ptr;
    int scor, i=0, k=0;
    char nume[20];
    pf_ptr=fopen("players.txt", "a+");
    temp_ptr=fopen("temp.txt", "w+");
    while(fscanf(pf_ptr, "%s %d", nume, &scor) > 0)
    {
        if(player.score>scor)
        {
            if((i<10)&&(k<1))
            {
                fprintf(temp_ptr, "%s %d\n", player.name, player.score);
                i+=1;
                k+=1;
            }
            if(i<10)
            {
                fprintf(temp_ptr, "%s %d\n", nume, scor);
                i+=1;
            }
        }
        else if(i<10)
        {
            fprintf(temp_ptr, "%s %d\n", nume, scor);
            i+=1;
        }
    }
    if((fscanf(pf_ptr, "%s %d", nume, &scor) == 0)||(k==0))
        fprintf(temp_ptr, "%s %d\n", player.name, player.score);
    fclose(pf_ptr);
    fclose(temp_ptr);
    remove("players.txt");
    rename("temp.txt", "players.txt");
}

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
