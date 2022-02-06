#include <stdio.h>
#define N 5

int verifica_diagonali(int[][N], int);
int main(){
    int A[][N] ={
        {1,0,0,0,2},
        {0,2,0,1,0},
        {0,0,5,0,0},
        {0,3,0,1,3},
        {1,0,0,0,3}
    };
    printf("%d\n", verifica_diagonali(A, 0));
}

int verifica_diagonali(int mat[][N], int i){
    if(i == N) //la funzione restituisce 1 se la somma delle diagonali è uguale
        return 1;

    return mat[i][i] - mat[i][N-i-1] + verifica_diagonali(mat, i+1);
}