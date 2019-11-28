/*******************************************************
 *  Authors: Man N. Darius                             *
 *  Description: Prints on the screen every thing that *
 *               IS NOT PREST.                         *
 *******************************************************/

#ifndef PRINTING_H_INCLUDED
#define PRINTING_H_INCLUDED

extern void start_menu();
extern void game_menu();

extern void draw_maze(int *matrix,long n,int start_x,int start_y,int dim_cel,int show_cel_no);
extern void temp2(int *matrix,long n);

#endif // PRINTING_H_INCLUDED
