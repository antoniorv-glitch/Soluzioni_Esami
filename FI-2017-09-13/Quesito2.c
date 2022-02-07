#include <stdio.h>
#define N 6
int prodotto(int[], int , int );

int main(){
    int a[]={4, 2, 2, 1, 5, 6};
    printf("%d\n", prodotto(a,3,10));
    printf("%d\n", prodotto(a,3,16));
}

int prodotto(int a[], int n, int target){
    if(n > N){
        printf("Errore: numero n troppo elevato" );
        return 0;
    }
    if(n == -1)
        return (target == 1)?1:0;
    else return prodotto(a, n-1, target/a[n]);
}