#ifndef SOLVER_H_INCLUDED
#define SOLVER_H_INCLUDED

typedef struct
{
    int x,y;
} coordinates;


extern void push(coordinates *&path,int *dim_path,coordinates vis);
extern void pop(coordinates *&path,int *dim_path);
extern void init_dfs();
extern void dfs_algorithm();
extern void search_and_move (int i,int j, int *matrix, int n);


#endif // SOLVER_H_INCLUDED
