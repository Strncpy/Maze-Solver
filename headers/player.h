#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

struct player_stats
{
    char name[20];
    int score;
    int lives;
    int nr_moves;
    int hints;
};

extern void text (struct player_stats player);
extern int move_up(int *matrix,int n,int a,int b);
extern int move_left(int *matrix,int n,int a,int b);
extern int move_down(int *matrix,int n,int a,int b);
extern int move_right(int *matrix,int n,int a,int b);
extern int tray(int *matrix,int n,int a,int b,int a1,int b1,struct player_stats *player);
#endif // PLAYER_H_INCLUDED
