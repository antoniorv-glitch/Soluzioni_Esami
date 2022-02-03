
//Esercizio 2 - Soluzione di @Piants


#include <stdio.h>


int controlla_lettere_iniziali(char [], int);
int main(){
    printf("PERA-PANE-EGO-ROSA-ALA: %d \n", controlla_lettere_iniziali("PERA-PANE-EGO-ROSA-ALA", 0));
    printf("PANE-PERA-ECO-NOIA-EGO: %d \n", controlla_lettere_iniziali("PANE-PERA-ECO-NOIA-EGO", 0));
}




int controlla_lettere_iniziali(char array[], int pos){
    if(array[pos] != '-' && array[pos] != '\0')
        return controlla_lettere_iniziali(array, pos + 1);
    if(array[pos] == '\0')
        if(array[0] == '-')
            return 1;
        else
            return 0;
    if(array[pos + 1] != array[0] || array[0] == '-')
        return 0;
    return controlla_lettere_iniziali(array + 1, pos);
}