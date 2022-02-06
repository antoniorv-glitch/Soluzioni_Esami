#include <stdio.h>
#include <stdlib.h>

typedef struct EL{
    int dato;
    struct EL * next;
}nodo;

typedef nodo * lista;
lista aggiungi_in_coda(lista, int);
lista modifica_dalla_fine(lista, int, int);
void stampalista(lista);
int main(){
    lista testa;
    int array[6] ={1, 6, 2, 3, 1, 10};
    for(int i = 0; i < 6; i++){
        testa = aggiungi_in_coda(testa, array[i]);
    }
    stampalista(testa);
    testa = modifica_dalla_fine(testa, 4, 3);
    stampalista(testa);
}

lista modifica_dalla_fine(lista K, int val, int k){
    lista new = (lista) malloc(sizeof(nodo));
    new -> dato = val;
    new -> next = NULL;
    if(!K) return new;
    for(lista cursore = K, prev = NULL; cursore != NULL; prev = cursore, cursore = cursore -> next){
        lista explorer;
        int i;
        for(explorer = cursore, i = 1; i < k && explorer != NULL; i++, explorer = explorer -> next );
        if(explorer == NULL){
            if(prev == NULL){
                new -> next = K;
                return new;
            }
            else{
                new -> next = cursore;
                prev -> next = new;
                return K;
            }
        }
    }
}
//funzioni ausiliarie

lista aggiungi_in_coda(lista testa, int intero){
    lista new = (lista) malloc(sizeof(nodo));
    new -> next = NULL;
    new -> dato = intero;
    if(!testa) return new;
    lista cursore;
    for(cursore = testa; cursore -> next != NULL; cursore = cursore -> next);
    cursore -> next = new;
    return testa;
}

void stampalista(lista testa){
    for(lista cursore = testa; cursore != NULL; cursore = cursore -> next){
        printf("%d, ", cursore-> dato);
    }
    printf("\n");
}