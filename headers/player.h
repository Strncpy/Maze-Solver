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

extern void text (struct player_stats player);//this function makes the list of first 10 players ordered by score into a txt file//

extern int move_up(int *matrix,int n,int a,int b);//this function analyses the possibility of moving up for the player//

extern int move_left(int *matrix,int n,int a,int b);//this function analyses the possibility of moving left for the player//

extern int move_down(int *matrix,int n,int a,int b);//this function analyses the possibility of moving down for the player//

extern int move_right(int *matrix,int n,int a,int b);//this function analyses the possibility of moving right for the player//

extern void tray(int *matrix,int n,int a,int b,int a1,int b1,struct player_stats *player);//this function is responsible with
                                                                                          //keeping the track of the tray,
                                                                                          //nr of moves and lives of the player//

#endif // PLAYER_H_INCLUDED
