#ifndef MEMORYALLOC_H_INCLUDED
#define MEMORYALLOC_H_INCLUDED

#include <stdio.h>

extern int *allocate_matrix(long n);
extern void dealoc_matrix(int *matrix);
extern int get_matrix_element(int *matrix,int n,int i,int j);
void element_change_matrix(int *matrix, int n, int x,int y, int value);

#endif // MEMORYALLOC_H_INCLUDED
