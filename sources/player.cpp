#include <stdio.h>
#include <stdlib.h>
#include "../headers/player.h"
#include "../headers/mat_gen.h"
#include "../headers/memoryalloc.h"
#include "../headers/memoryalloc.h"


//this function makes the list of first 10 players ordered by score into a txt file//
void text(struct player_stats player)                                              //
{                                                                                  //
    FILE *pf_ptr;                                                                  //
    FILE *temp_ptr;                                                                //
    int scor, i=0, k=0;                                                            //
    char nume[20];                                                                 //
    pf_ptr=fopen("players.txt", "a+");                                             //
    temp_ptr=fopen("temp.txt", "w+");                                              //
    while(fscanf(pf_ptr, "%s %d", nume, &scor) > 0)                                //
    {                                                                              //
        if(player.score>scor)                                                      //
        {                                                                          //
            if((i<10)&&(k<1))                                                      //
            {                                                                      //
                fprintf(temp_ptr, "%s %d\n", player.name, player.score);           //
                i+=1;                                                              //
                k+=1;                                                              //
            }                                                                      //
            if(i<10)                                                               //
            {                                                                      //
                fprintf(temp_ptr, "%s %d\n", nume, scor);                          //
                i+=1;                                                              //
            }                                                                      //
        }                                                                          //
        else if(i<10)                                                              //
        {                                                                          //
            fprintf(temp_ptr, "%s %d\n", nume, scor);                              //
            i+=1;                                                                  //
        }                                                                          //
    }                                                                              //
    if((fscanf(pf_ptr, "%s %d", nume, &scor) == 0)||((k==0)&&(i<10)))              //
        fprintf(temp_ptr, "%s %d\n", player.name, player.score);                   //
    fclose(pf_ptr);                                                                //
    fclose(temp_ptr);                                                              //
    remove("players.txt");                                                         //
    rename("temp.txt", "players.txt");                                             //
}                                                                                  //
/////////////////////////////////////////////////////////////////////////////////////


//this functions analyze the possibility of the player to move in a certain direction//
                                                                                     //
//possibility of moving up//                                                         //
int move_up(int *matrix,int n,int a,int b)                                           //
{                                                                                    //
    if(get_matrix_element( matrix,n,a-1,b)==0)                                       //
        return 1;                                                                    //
    else                                                                             //
        return 0;                                                                    //
}                                                                                    //
                                                                                     //
//possibility of moving left//                                                       //
int move_left(int *matrix,int n,int a,int b)                                         //
{                                                                                    //
    if(get_matrix_element(matrix,n,a,b-1)==0)                                        //
        return 1;                                                                    //
    else                                                                             //
        return 0;                                                                    //
}                                                                                    //
                                                                                     //
//possibility of moving down//                                                       //
int move_down(int *matrix,int n,int a,int b)                                         //
{                                                                                    //
    if(get_matrix_element(matrix,n,a+1,b)==0)                                        //
        return 1;                                                                    //
    else                                                                             //
        return 0;                                                                    //
}                                                                                    //
                                                                                     //
//possibility of moving right//                                                      //
int move_right(int *matrix,int n,int a,int b)                                        //
{                                                                                    //
    if(get_matrix_element(matrix,n,a,b+1)==0)                                        //
        return 1;                                                                    //
    else                                                                             //
        return 0;                                                                    //
}                                                                                    //
///////////////////////////////////////////////////////////////////////////////////////


//this function is responsible with keeping the track of the tray, nr of moves and lives of the player//
void tray(int *matrix,int n,int a,int b,int a1,int b1,struct player_stats *player)                    //
{                                                                                                     //
    player->nr_moves++;                                                                               //
    int z;                                                                                            //
    if (get_matrix_element(matrix,n,a,b)==0)                                                          //
    {                                                                                                 //
        z=0;                                                                                          //
        element_change_matrix(matrix,n,a,b,3);                                                        //
        element_change_matrix(matrix,n,a1,b1,2);                                                      //
    }                                                                                                 //
    if (get_matrix_element(matrix,n,a,b)==2)                                                          //
    {                                                                                                 //
        z+=1;                                                                                         //
        if(z==2)                                                                                      //
        player->lives--;                                                                              //
        element_change_matrix(matrix,n,a,b,3);                                                        //
        element_change_matrix(matrix,n,a1,b1,0);                                                      //
    }                                                                                                 //
}                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////
