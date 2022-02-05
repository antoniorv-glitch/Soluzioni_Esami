// Quesito 2 (8 punti). Sia data una matrice quadrata di dimensione N x N, N costante predefinita. Si definisca una
// funzione ricorsiva che, ricevuta in input la matrice, restituisca 1 se la matrice è simmetrica, 0 se non lo è.

// 1 0 0 0 
// 0 1 0 0
// 0 0 1 0
// 0 0 0 1
#define N 4
#include <stdio.h>

int simmetrica(int[][N], int, int);

int main(){
    int A[][N] ={
        {1, 3, 5 ,6},
        {3, 3, 2 ,6},
        {5, 2, 5 ,4},
        {6, 6, 4 ,6},
    };
    printf("%d\n", simmetrica(A, 0, 1));
}

int simmetrica(int mat[][N], int i, int j){
    if(i == N-1)
        return 1;
    if(j == N)
        return simmetrica(mat, i+1, i+2);
    if(mat[i][j] == mat[j][i])
        return simmetrica(mat, i, j+1);
    return 0;
}