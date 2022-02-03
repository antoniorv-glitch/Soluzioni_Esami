#include <stdio.h>
#include <stdlib.h>
#define N 6
#include <stdbool.h>

// Si  supponga  di  avere,  già  presente  in  memoria,  una  lista  dinamica  che  memorizza  una 
// sequenza di interi. Dopo aver dichiarato in modo opportuno il tipo del nodo e la lista, si scriva una funzione in C 
// che riceve la lista come parametro e restituisce la media dei valori della lista senza considerare però i duplicati.  
// Esempio: data la lista  
// 8 4 8 5 3 3 
// la funzione restituirà il valore 5, cioè la media di 8, 4, 5 e 3



typedef struct nodo{
    int dato;
    struct nodo*next;
}t_nodo;

typedef t_nodo * lista;


int media(lista);
lista aggiungi_in_coda(lista, int);
void stampaLista(lista testa);



int main(){
    lista testa = NULL;
    int array[1]={8};
    for(int i = 0; i < 1; i++){
        testa = aggiungi_in_coda(testa, array[i]);
    }
    //stampaLista(testa);
    printf("\n\nMedia: %d\n\n", media(testa));
    
return 0;
}


//costruisci lista
lista aggiungi_in_coda(lista testa, int valore){
    lista cursore = testa;
    lista new = (lista)malloc(sizeof(t_nodo));
    new->dato = valore;
    new->next = NULL;

    if(testa == NULL){
        return new;
    }

    while(cursore->next != NULL){
        cursore = cursore->next;
    }

    cursore->next = new;

return testa;
}

//stampa la lista
void stampaLista(lista testa){
    while(testa!= NULL){
        printf("%d  ", testa->dato);
        testa = testa->next;
    }
    printf("\n");
}





//funzione dell'eserczio
int media(lista testa){
    int somma = 0, contatore = 0;
    lista cursore2 = NULL;
    lista cursore1 = testa;
    bool SAMMY = true;
    if(testa == NULL){
        return 0;
    }
    for(cursore1 = testa; cursore1 != NULL; cursore1 = cursore1 -> next){
        SAMMY = true;
        for(cursore2 = testa; cursore2 != cursore1 && SAMMY; cursore2 = cursore2 -> next){
            if(cursore1-> dato == cursore2 -> dato){
                SAMMY = false;
            }
        }
        if(SAMMY){
            somma += cursore1 -> dato; 
            contatore++;
        }
    }  
    return somma/contatore;      
}
