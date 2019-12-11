#ifndef SOLVER_H_INCLUDED
#define SOLVER_H_INCLUDED

struct coordinates
{
    int x,y;
};
extern void push(int i, int j);
extern void pull (int *ptr_to_array, int i, int j, int n_dfs);
extern int dfs_algorithm (int *matrix,int dim);
extern void search_and_move (int i,int y);
extern int init_dfs ();


#endif // SOLVER_H_INCLUDED
