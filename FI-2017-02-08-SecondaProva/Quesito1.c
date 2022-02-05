// Quesito 1 (5 punti). Sia data una lista dinamica, L1, che memorizza una sequenza di valori interi. Si definisca una
// funzione che, ricevuta in ingresso L1, crei e restituisca una nuova lista dinamica, L2, i cui elementi memorizzano
// i valori (senza ripetizioni) presenti in L1 e per ognuno di essi il numero di volte in cui compare in L1. Per esempio,
// se L1 memorizza la sequenza:
// 5 0 -3 2 0 0 121 -18 5
// la funzione costruirà e restituirà la seguente lista:
// (5, 2) -> (0, 3) -> (-3, 1) -> (2,1) -> (121,1) -> (-18,1)
// N.B.: Oltre a definire la funzione, si definiscano opportunamente i tipi che rappresentano gli elementi delle
// due liste.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct EL{
    int dato;
    int ripetizioni;
    struct EL* next;
}nodo;

typedef nodo * listaS; //lista SPEECIALE


typedef struct EL2{
    int dato;
    struct EL2* next;
}nodo2;

typedef nodo2 * lista;

listaS ripetizioni(lista);
lista aggiungi_in_coda(lista, int);
void stampalista(listaS);
int main(){
    lista testa = NULL;
    int input[9] = {5,0,-3,2,0,0,121, -18, 5};
    for(int i = 0; i < 9; i++)
        testa = aggiungi_in_coda(testa, input[i]);
    listaS testa2 = ripetizioni(testa);
    stampalista(testa2);
}


listaS ripetizioni(lista testa){
    listaS testa2 = NULL;
    if(!testa) return testa2;
    testa2 = (listaS) malloc(sizeof(nodo));
    testa2-> next = NULL;
    testa2 -> dato = testa -> dato;
    testa2 -> ripetizioni = 1;
    //scorro la prima lista
    for(lista cursore = testa -> next; cursore != NULL; cursore = cursore -> next){
        bool trovato = false;
        listaS cursore2; //scorro la seconda lista
        for(cursore2 = testa2; cursore2-> next != NULL && !trovato; cursore2 = cursore2 -> next){
            if(cursore2 -> dato == cursore -> dato){ // se lo trovo incremento le sue ripetizioni
                cursore2-> ripetizioni++;
                trovato = true; 
            }
        }
        if(!trovato){ //se non lo trovo lo creo e lo aggiungo in coda
            listaS new = (listaS) malloc(sizeof(nodo));
            new-> next = NULL;
            new -> dato = cursore -> dato;
            new -> ripetizioni = 1;
            cursore2 -> next = new;
        }
    }
    return testa2;
}


//funzioni ausiliari per il controllo

lista aggiungi_in_coda(lista testa, int intero){
    lista new = (lista) malloc(sizeof(nodo2));
    new -> next = NULL;
    new -> dato = intero;
    if(!testa) return new;
    lista cursore;
    for( cursore = testa; cursore -> next != NULL; cursore = cursore -> next);
    cursore -> next = new;
    return testa;
}

void stampalista(listaS testa){
    if(!testa) printf("Lista vuota\n");
    for(listaS cursore = testa; cursore != NULL; cursore = cursore -> next){
        printf("(%d, %d) -> ", cursore -> dato, cursore -> ripetizioni);
    }
}