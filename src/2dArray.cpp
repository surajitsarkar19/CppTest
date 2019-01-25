#include <iostream>
#include <iomanip>

using namespace std;

void method1(int r, int c)
{
    printf("\nSingle element array test\n");
    int *arr = (int *)malloc(r * c * sizeof(int)); 
  
    int i, j, count = 0; 
    for (i = 0; i <  r; i++) 
      for (j = 0; j < c; j++) 
         *(arr + i*c + j) = ++count; 
  
    for (i = 0; i <  r; i++)
    {
        for (j = 0; j < c; j++) 
         printf("%2d ", *(arr + i*c + j));
        printf("\n");
    }
    
    free(arr);
}

void method2(int r, int c)
{
    printf("\nUsing pointer to pointer\n");
    int **arr = (int**)malloc(r*sizeof(int*));
    int i,j,count=0;
    for(i = 0; i<c; i++)
        arr[i] = (int*)malloc(c*sizeof(int));

    //insert
    for(i=0 ;i<r; i++)
        for(j=0; j<c; j++)
            arr[i][j] = ++count;

    //display
    for(i=0 ;i<r; i++)
    {
        for(j=0; j<c; j++)
            printf("%2d ", arr[i][j]);
        printf("\n");
    }

    //delete individual row and base pointer
    for(i = 0; i<r; i++)
        free(arr[i]);

    //free(arr);
}

void method3(int r, int c)
{
    cout<<endl<<"c++ way of dynamic allocation"<<endl;
    // dynamic allocation
    int** ary = new int*[r];
    for(int i = 0; i < r; ++i)
        ary[i] = new int[c];
    int count=0;
    // fill
    for(int i = 0; i < r; ++i)
        for(int j = 0; j < c; ++j)
        ary[i][j] = ++count;
    
    // print
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        cout <<setw(2)<< ary[i][j]<<" ";
        cout<<endl;
    }
    
    // free
    for(int i = 0; i < r; ++i)
        delete [] ary[i];
    delete [] ary;
}

int main()
{
    cout<<"----------Dynamic 2d array test---------"<<endl;
    method1(5,6);
    method2(5,6);
    method3(5,6);
    return 1;
}