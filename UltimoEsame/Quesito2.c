#include <stdio.h>
#define N 5
int ricorsiva(int[], int,int);
int main(){
    int a[N] ={5,4,-1,-1,3};
    int b[N] ={7,-1,-1,-1,2};
    int c[N] ={0,0,0,0,0};
    printf("%d, %d, %d\n", ricorsiva(a,0,0), ricorsiva(b,0,0), ricorsiva(c,0,0));
}

int ricorsiva(int mat[], int i, int bilancio){
    if(i == N)
        return (bilancio > 0)?1:-1;
    if(mat[i] > 0)
        return ricorsiva(mat, i+1, bilancio+1);
    else if(mat[i] < 0)
        return ricorsiva(mat, i+1, bilancio-1);
    return ricorsiva(mat, i+1, bilancio);
}