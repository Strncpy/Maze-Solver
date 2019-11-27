#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "memoryalloc.h"
#include "mat_gen.h"

struct visited
{
    int x,y;
};

visited *vi;
visited aux;

int i,j,p;
int N,V,S,E;
int v[4],k=0,s,m;

int mat(int n)
{
    srand(time(NULL));
    int *matrix;
    matrix=allocate_matrix(n);
}

int matrix_s(int n)
{
    for(i=2; i<n; i++)
    {
        for(j=2; j<n; j++)
            element_change_matrix(*matrix,n,i,j,0);
    }
    for(i=1; i<=n; i++)
    {
        element_change_matrix(*matrix,n,i,1,0);
        element_change_matrix(*matrix,n,i,n,0);
    }
    for(j=1; j<=n; j++)
    {
        element_change_matrix(*matrix,n,1,j,0);
        element_change_matrix(*matrix,n,n,j,0);
    }
    return *matrix;
}

int first_step(int i,int j)
{
    element_change_matrix(*matrix,n,i,j,0);
    aux.x=i;
    aux.y=j;
    vi[k]=aux;
    p=rand()%2;
    if(p==0)
    {
        i+=2;
        element_change_matrix(*matrix,n,i,j,0);
        k++;
        aux.x=i;
        aux.y=j;
        v[k]=aux;
    }
    else
    {
        j+=2;
        element_change_matrix(*matrix,n,i,j,0);
        k++;
        aux.x=i;
        aux.y=j;
        v[k]=aux;
    }
    return *matrix;
}

int path_an(int i,int j)
{
    N=1;
    V=1;
    S=1;
    E=1;

    if((get_matrix_element(*matrix,n,i-1,j)==0)||(get_matrix_element(*matrix,n,i-1,j-1)==0)||(get_matrix_element(*matrix,n,i-1,j+1)==0)||
            (get_matrix_element(*matrix,n,i-2,j)==0)||(get_matrix_element(*matrix,n,i-2,j-1)==0)||(get_matrix_element(*matrix,n,i-2,j+1)==0))
        N=0;
    if((get_matrix_element(*matrix,n,i,j-1)==0)||(get_matrix_element(*matrix,n,i-1,j-1)==0)||(get_matrix_element(*matrix,n,i+1,j-1)==0)||
            (get_matrix_element(*matrix,n,i,j-2)==0)||(get_matrix_element(*matrix,n,i-1,j-2)==0)||(get_matrix_element(*matrix,n,i+1,j-2)==0))
        V=0;
    if((get_matrix_element(*matrix,n,i+1,j)==0)||(get_matrix_element(*matrix,n,i+1,j-1)==0)||(get_matrix_element(*matrix,n,i+1,j+1)==0)||
            (get_matrix_element(*matrix,n,i+2,j)==0)||(get_matrix_element(*matrix,n,i+2,j-1)==0)||(get_matrix_element(*matrix,n,i+2,j+1)==0))
        S=0;
    if((get_matrix_element(*matrix,n,i,j+1)==0)||(get_matrix_element(*matrix,n,i-1,j+1)==0)||(get_matrix_element(*matrix,n,i+1,j+1)==0)||
            (get_matrix_element(*matrix,n,i,j+2)==0)||(get_matrix_element(*matrix,n,i-1,j+2)==0)||(get_matrix_element(*matrix,n,i+1,j+2)==0))
        E=0;
    return N,V,S,E;
}

int whtogo(int N,int V,int S,int E)
{
    s=0;
    if(N==1)
    {
        v[s]=1;
        s++;
    }
    if(V==1)
    {
        v[s]=2;
        s++;
    }
    if(S==1)
    {
        v[s]=3;
        s++;
    }
    if(E==1)
    {
        v[s]=4;
        s++;
    }
    return s;
}

int mov_arb(int s)
{
    p=rand()%s;
    if(s==0)
    {
        m--;
        i=vi[m].x;
        j=vi[m].y;
    }
    if(v[p]==1)
    {
        k++;
        i-=2;
        element_change_matrix(*matrix,n,i+1,j,0);
        element_change_matrix(*matrix,n,i,j,0);
        aux.x=i;
        aux.y=j;
        vi[k]=aux;
        m=k;
    }
    if(v[p]==2)
    {
        k++;
        j-=2;
        element_change_matrix(*matrix,n,i,j+1,0);
        element_change_matrix(*matrix,n,i,j,0);
        aux.x=i;
        aux.y=j;
        vi[k]=aux;
        m=k;
    }
    if(v[p]==3)
    {
        k++;
        i+=2;
        element_change_matrix(*matrix,n,i-1,j,0);
        element_change_matrix(*matrix,n,i,j,0);
        aux.x=i;
        aux.y=j;
        vi[k]=aux;
        m=k;
    }
    if(v[p]==4)
    {
        k++;
        j+=2;
        element_change_matrix(*matrix,n,i,j-1,0);
        element_change_matrix(*matrix,n,i,j,0);
        aux.x=i;
        aux.y=j;
        vi[k]=aux;
        m=k;
    }
    return *matrix;
}

int gen_mat(int n)
{
int mat(n);
int matrix_s(n);
int first_step(3,3);
int path_an(i,j);
while(!((i==3)&&(j==3)))
{
int whtogo(N,V,S,E);
int mov_arb(s);
}
return *matrix;
}
