#include <stdio.h>
#include <stdlib.h>


struct coordinates
    {
      int x,y;
    };

int main ()
{
    n=1;
    struct coordinates visited[]; //visited array is the stack;
    struct coordinates *ptr_to_array ;
    struct coordinates ptr_to_array= /*struct coordinates*/ visited;//equals to struct coordinates *ptr_to_array=&visited[0];
    ptr_to_array=(struct coordinates*)malloc(n*sizeof(struct coordinates));

}



    void push(int *ptr_to_array, int i, int j,n)

    {
       struct coordinates wolly
       wolly.x=i;
       wolly.y=j;
       ptr_to_array=(struct coordinates*)realloc(n+1)*sizeof(struct coordinates));
       ptr_to_array[n+1]=wolly;

    }

   void pull (int *ptr_to_array, int i, int j, n)

   {
      free(ptr_to_array[n]);
      ptr_to_array=(struct coordinates*)realloc((n-1)*sizeof(struct coordinates));

   }


    int dfs_algorithm ()
    {

    int i=2;
    int j=1; //starts from the wall so the 2.2 can be placed in the stack/ptr_to_array
    while (struct coordinates.x!=(n-1) && struct coordinates.y!=(n-1)) //trebuie sa aiba o functie recursiva si returneaza stackul de final;
    {
         void search_and_move;
         for(i=0;i<n;i++)
         return ptr_to_array[i];
    }
    }

    void search_and_move (int i,int y) //searches for neighbors of 0 and moves in their place
    {
    if (get_matrix_element(*matrix,n,i+1,j)==0) //if down is o
             {
              element_change_matrix(*matrix,n,i,j,3);
              push(*ptr_to_array,i,j,n);
              i=i+1;
              search_and_move(i,j);
              }

        else if (get_matrix_element(matrix,n,i,j+1)==0)  //if right is 0
           {
                 element_change_matrix(matrix,n,i,j,3);
                 push(ptr_to_array,i,j,n);  //this freaking 'n' needs some damn definition and see if it changes, as wanted, its value
                j=j+1;
                 search_and_move(i,j);
            }
        else  if (get_matrix_element(matrix,n,i-1,j)==0) //if up is0
            {
                element_change_matrix(matrix,n,i,j,3);
                push(ptr_to_array,i,j,n);
                i=i-1;
                search_and_move(i,j);
            }
        else if (get_matrix_element(matrix,n,i,j-1)==0) //if left is 0
            {
                element_change_matrix(matrix,n,i,j,3);
                push(ptr_to_array,i,j,n);
                j=j-1;
                search_and_move(i,j);
            }
        else
        {
           pull(ptr_to_array,i,j,n);
           search_and_move(ptr_to_array[n]->x, ptr_to_array[n]->y);
        }


    }

