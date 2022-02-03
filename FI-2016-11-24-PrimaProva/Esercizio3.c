#include <stdio.h>

#define N 5

typedef struct{
    int x;
    int y;
}pos;

pos posizione_sottomatrice(int [][N], int[][3]);

int main(){
    
    pos posizione;
    int A[N][N] = {
        {1,1,0,1,1},
        {0,1,0,1,0},
        {0,0,0,0,0},
        {1,1,0,0,1},
        {0,0,1,1,1}
    };
    int B[][3] ={
        {1,0,1},
        {0,0,0},
        {1,0,0},
     };
    posizione = posizione_sottomatrice(A, B);
    printf("Le coordinate della sottomatrice sono: %d, %d", posizione.x, posizione.y);
}

pos posizione_sottomatrice(int A[][N], int B[][3]){
    for(int i = 0; i < N-2; i++){
        for(int j = 0; j < N-2; j++){
            if(A[i][j] == B[0][0]){
                int trovato = 1;
                for(int k = 0; k < 3 && trovato; k++){
                    for(int g = 1; g < 3 && trovato; g++){
                        if(A[i+k][j+g] != B[k][g])
                            trovato = 0;
                    }
                }
                if(trovato){
                    pos posizione = {i, j};
                    return posizione;
                }
            }
        }
    }
}