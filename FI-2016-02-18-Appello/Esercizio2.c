#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * conversione_binario(int , int);
int main(){
    printf("%s\n", conversione_binario(25, 0));
}


// Questa è la perfezione
char * conversione_binario(int n, int dim){
    if(n == 0){
        char * stringa = (char*)malloc(sizeof(char)* dim);
        for(int i  = 0; i < dim; i++) //esiste un modo per evitare l'inizializzazione del vettore?
            stringa[i] = '0';
        //stringa[dim] = '\0' WTF
        return stringa;
    }
    char * stringa = conversione_binario(n/2, ++dim);
    stringa[strlen(stringa)-dim] = n%2 + '0';
    return stringa;
}