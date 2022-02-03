#include <stdio.h>
#define DIM 6

int vette(int [], int, int , int);
int main(){
    int array[DIM] ={10,2,3,5,2,3};
    printf("Numero vette: %d", vette(array, DIM, 0, 1));
}

//“vette”: gli elementi dell’array che sono maggiori di tutti gli elementi a essi successivi.

int vette(int array[], int dim, int cur, int check){
    //se l'array ha dimensione 1 o 0 oppure ha finito di controllare restituisce 0.
    //bisogna stare attenti perchè si deve fermare al penultimo elemento,
    if(dim < 2 || cur+1 == dim) return 0;
    //se ha finito di controllare aggiunge uno alla somma,
    //e va al prossimo elemento con il current, ma il check deve sempre
    //partire dall'elemento successivo a quello corrente.
    //infatti confrontandosi con il current la condizione successiva a quella sotto risulterebbe sempre falsa, 
    //poichè ogni elemento non è mai maggiore di se stesso.
    if(check == dim) return 1 + vette(array, dim, cur + 1 , cur + 2);

    if(array[cur] > array[check]) 
        return vette(array, dim, cur, check + 1 );
    else //rinizializzo il check e quello corrente
        return vette(array, dim, cur + 1 , cur + 2);
}