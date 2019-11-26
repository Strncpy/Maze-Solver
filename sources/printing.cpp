/*******************************************************
 *  Authors: Man N. Darius                             *
 *  Description: Prints on the screen every thing that *
 *               IS NOT PRESET.                        *
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include "../headers/menu.h"
#include "../headers/printing.h"
#include "../headers/memoryalloc.h"

/********************************************************
*  Description: Enum for maze elements                  *
*********************************************************/
enum maze
{
    wall=1,
    start_x=140,
    start_y=140,
    dim_cel=30,
    show_cel_no=100
};

/********************************************************
*  Description: Enum for all the setting of the text    *
*********************************************************/
enum font_settings
{
    //Font sizes
    font_size_small=2,
    font_size_int_med=3,
    font_size_medium=4,
    font_size_large=6,

    //Sans Serif
    font_style=SANS_SERIF_FONT,

    //Direction of the text
    direction=0
};

/********************************************************
*  Description: Prints the START MENU of the project    *
*               AND prints the leader board AND gets    *
*               the player name                         *
*********************************************************/
void start_menu()
{
    cleardevice();

    settextstyle(font_style,direction,font_size_medium);
    outtextxy(80,50,"Solv it (WIP)");

    settextstyle(font_style,direction,font_size_int_med);
    rectangle(470,100,670,490);
    outtextxy(520,110,"LEADER");
    outtextxy(525,140,"BOARD");

    settextstyle(font_style,direction,font_size_small);
    /// TEMPORARY
    outtextxy(490,180,"1. elena");
    outtextxy(490,210,"2. fabian");
    outtextxy(490,240,"3. ");
    outtextxy(490,270,"4. ");
    outtextxy(490,300,"5. ");
    outtextxy(490,330,"6. ");
    outtextxy(490,360,"7. ");
    outtextxy(490,390,"8. ");
    outtextxy(490,420,"9. ");
    outtextxy(490,450,"10.");
    ///

    settextstyle(font_style,direction,font_size_int_med);
    outtextxy(130,130,"Remember you only have");
    outtextxy(100,160,"a limited amount of lives.");

    outtextxy(130,200,"If you get stuck press");
    outtextxy(100,230,"'H' to use a hint.");

    outtextxy(130,270,"Type 'back' and press");
    outtextxy(100,300,"'TAB' if you want to go");
    outtextxy(100,330,"back. Or type your name");
    outtextxy(100,360,"and press 'TAB'.");

    outtextxy(130,400,"Please input a name,");
    outtextxy(160,430,"NAME: ");

    char c;
    char name[11]={'\0'};
    c=getch();
    while(c!=9)
    {
        if(strlen(name)<9)
        {
            if(c!=8)
            {
                name[strlen(name)]=c;
                name[strlen(name)]='\0';
            }
            else
                name[strlen(name)-1]='\0';
            outtextxy(240,430,"                    ");
            outtextxy(240,430,name);
        }
        else
            if(c==8)
            {
                name[strlen(name)-1]='\0';
                outtextxy(240,430,"                      ");
                outtextxy(240,430,name);
            }
        c=getch();
    }

    if(strcmp(name,"back")==0)
        return;
    else
        game_menu();
}

/// TEMPORARY
void temp2(int *matrix,long n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            printf("%d ",get_matrix_element(matrix,n,i,j));
        printf("\n");
    }
}
///

/********************************************************
*  Description: Prints the GAME MENU of the project     *
*               AND deals with the movement of the maze *
*********************************************************/
void game_menu()
{
    cleardevice();

    settextstyle(font_style,direction,font_size_int_med);
    outtextxy(80,50,"LIVES");
    outtextxy(80,80,"0");

    outtextxy(220,50,"LEVEL");
    outtextxy(220,80,"0");

    outtextxy(360,50,"MOVES");
    outtextxy(360,80,"0");

    outtextxy(500,50,"NAME");
    outtextxy(500,80,"man");

    /// TEMPORARY
    long n;
    int *matrix;
    int a;
    FILE *f=fopen("maze_tmp.txt","r");
    fscanf(f,"%d",&n);
    matrix=allocate_matrix(n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            fscanf(f,"%d",&a);
            element_change_matrix(matrix,n,i,j,a);
        }
    temp2(matrix,n);
    ///

    /// TO DO CHECK FOR IN PUTS
    /// ADD: FROM WHICH CELL TO START DRAWING
    if(n<=show_cel_no)
        draw_maze(matrix,n,start_x,start_x,dim_cel,n);
    else
        draw_maze(matrix,n,start_x,start_x,dim_cel,show_cel_no);

    selection:
    if(getch()=='b')
        return;
    else
        goto selection;
}

/********************************************************
*  Description: Draws the maze                          *
*  Parameters: int *matrix - The matrix of the maze     *
*                            with 1 as wall and 0 as    *
*                            path                       *
*              int n - The dimension of the matrix      *
*              int start_x - The coordinates on the     *
*              int start_y   screen from witch to start *
*                            drawing                    *
*              int dim_cel - The dimension of the line  *
*                            in pixels (how long should *
*                            the cell be)               *
*              int show_cel_no - How many cells to show *
*                                at once                *
*********************************************************/
void draw_maze(int *matrix,long n,int start_x,int start_y,int dim_cel,int show_cel_no)
{
    int no_zero=0,cel_l=1,cel_c=1;

    line(start_x,start_y,start_x,(n/2)*dim_cel+start_x);
    line(start_x,start_y,(n/2)*dim_cel+start_x,start_x);

    for(int i=2;i<=n;i+=2)
    {
        cel_c=1;
        for(int j=2;j<=n;j+=2)
        {
            no_zero=get_matrix_element(matrix,n,i,j+1)+get_matrix_element(matrix,n,i+1,j+1)+get_matrix_element(matrix,n,i+1,j);
            printf("%d %d\n%d %d\n",get_matrix_element(matrix,n,i,j),get_matrix_element(matrix,n,i,j+1),get_matrix_element(matrix,n,i+1,j),get_matrix_element(matrix,n,i+1,j+1));
            if(no_zero==wall)
            {
                cel_c++;
                continue;
            }
            else
            {
                if(no_zero==2)
                    if(get_matrix_element(matrix,n,i,j+1)==wall)
                        line(start_x+cel_c*dim_cel,start_y+(cel_l-1)*dim_cel,start_x+cel_c*dim_cel,start_y+cel_l*dim_cel);
                    else
                        line(start_x+(cel_c-1)*dim_cel,start_y+cel_l*dim_cel,start_x+cel_c*dim_cel,start_y+cel_l*dim_cel);
                else
                {
                    line(start_x+cel_c*dim_cel,start_y+(cel_l-1)*dim_cel,start_x+cel_c*dim_cel,start_y+cel_l*dim_cel);
                    line(start_x+(cel_c-1)*dim_cel,start_y+cel_l*dim_cel,start_x+cel_c*dim_cel,start_y+cel_l*dim_cel);
                }
            }
            cel_c++;
        }
        cel_l++;
    }
}
