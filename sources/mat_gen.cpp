#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../headers/memoryalloc.h"
#include "../headers/mat_gen.h"
#include "../headers/printing.h"

struct visited
{
    int x,y;
};

visited *vi;
visited aux;

int i,j,p,n,z,h,r,fr,fd,ra;
int N,V,S,E;
int v[4],k,s,m;
int *matrix;

void mat(int n)
{
    srand(time(NULL));
    matrix=allocate_matrix(n);
    vi=(visited*)malloc((n*n)*sizeof(visited));
}

int* matrix_s(int n)
{
    for(i=2; i<n; i++)
    {
        for(j=2; j<n; j++)
            element_change_matrix(matrix,n,i,j,1);
    }
    for(i=1; i<=n; i++)
    {
        element_change_matrix(matrix,n,i,1,0);
        element_change_matrix(matrix,n,i,n,0);
    }
    for(j=1; j<=n; j++)
    {
        element_change_matrix(matrix,n,1,j,0);
        element_change_matrix(matrix,n,n,j,0);
    }
    return matrix;
}

void path_an(int x,int y)
{
    i=x;
    j=y;

    if((i==3)&&(j==3)&&(z==0))
    {
        z=1;
        ra=rand()% n + k-n/4;
        i=vi[ra].x;
        j=vi[ra].y;
    }

    if((i==n-2)&&(j<n-2)&&(fr==0)&&(z==1))
    {
        r=0;
        for(h=j+2;h<n-2;h++)
            r=r+get_matrix_element( matrix, n, i, h);
        if(r==0)
        {
            element_change_matrix( matrix, n, i, j+1, 0);
            fr+=1;
        }
    }

    if((j==n-2)&&(i<n-2)&&(fd==0)&&(z==1))
    {
        r=0;
        for(h=i+2;h<n-2;h++)
            r=r+get_matrix_element( matrix, n, h, j);
        if(r==0)
        {
            element_change_matrix( matrix, n, i+1, j, 0);
            fd+=1;
        }
    }

    N=1;
    V=1;
    S=1;
    E=1;

    if((get_matrix_element( matrix,n,i-1,j)==0)||(get_matrix_element( matrix,n,i-1,j-1)==0)||(get_matrix_element( matrix,n,i-1,j+1)==0)||
            (get_matrix_element( matrix,n,i-2,j)==0)||(get_matrix_element( matrix,n,i-2,j-1)==0)||(get_matrix_element( matrix,n,i-2,j+1)==0))
        N=0;
    if((get_matrix_element( matrix,n,i,j-1)==0)||(get_matrix_element( matrix,n,i-1,j-1)==0)||(get_matrix_element( matrix,n,i+1,j-1)==0)||
            (get_matrix_element( matrix,n,i,j-2)==0)||(get_matrix_element( matrix,n,i-1,j-2)==0)||(get_matrix_element( matrix,n,i+1,j-2)==0))
        V=0;
    if((get_matrix_element( matrix,n,i+1,j)==0)||(get_matrix_element( matrix,n,i+1,j-1)==0)||(get_matrix_element( matrix,n,i+1,j+1)==0)||
            (get_matrix_element( matrix,n,i+2,j)==0)||(get_matrix_element( matrix,n,i+2,j-1)==0)||(get_matrix_element( matrix,n,i+2,j+1)==0))
        S=0;
    if((get_matrix_element( matrix,n,i,j+1)==0)||(get_matrix_element( matrix,n,i-1,j+1)==0)||(get_matrix_element( matrix,n,i+1,j+1)==0)||
            (get_matrix_element( matrix,n,i,j+2)==0)||(get_matrix_element( matrix,n,i-1,j+2)==0)||(get_matrix_element( matrix,n,i+1,j+2)==0))
        E=0;


    mov_arb(whtogo(N,V,S,E));

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

void  mov_arb(int s)
{
    if(s==0)
    {
        m--;
        i=vi[m].x;
        j=vi[m].y;
        return;
    }
    p=rand()%s;
    if(v[p]==1)
    {
        k++;
        i-=2;
        element_change_matrix( matrix,n,i+1,j,0);
        element_change_matrix( matrix,n,i,j,0);
        aux.x=i;
        aux.y=j;
        vi[k]=aux;
        m=k;
    }
    if(v[p]==2)
    {
        k++;
        j-=2;
        element_change_matrix( matrix,n,i,j+1,0);
        element_change_matrix( matrix,n,i,j,0);
        aux.x=i;
        aux.y=j;
        vi[k]=aux;
        m=k;
    }
    if(v[p]==3)
    {
        k++;
        i+=2;
        element_change_matrix( matrix,n,i-1,j,0);
        element_change_matrix( matrix,n,i,j,0);
        aux.x=i;
        aux.y=j;
        vi[k]=aux;
        m=k;
    }
    if(v[p]==4)
    {
        k++;
        j+=2;
        element_change_matrix( matrix,n,i,j-1,0);
        element_change_matrix( matrix,n,i,j,0);
        aux.x=i;
        aux.y=j;
        vi[k]=aux;
        m=k;
    }
}

int* gen_mat(int dim)
{
    n=dim;
    mat(n);
    matrix_s(n);
    k=0;
    m=0;
    z=0;
    fr=0;
    fd=0;
    i=n-2;
    j=n-2;
    element_change_matrix(matrix,n,i,j,0);
    aux.x=i;
    aux.y=j;
    vi[k]=aux;
    do
    {
        path_an(i,j);
    }
    while(!((i==n-2)&&(j==n-2)));
    free(vi);

    for(i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
            printf("%d ", get_matrix_element( matrix, n, i, j));
    printf("\n");
    }
    printf("\n");

    return matrix;
}
