#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NOMI 3
typedef struct nodo{
    char nomeAzienda[41];
    float quotazione;
    float variazione;
    struct nodo * next;
}aziendaQuot;

typedef aziendaQuot * lista;

lista aggiorna(lista, char[], float);
void stampaLista(lista testa);
lista aggiungi_in_coda(lista , char [], float);

int main(){
    lista testa = NULL;
    char nomiAziende[NOMI][41] ={"Apple", "Microsoft", "Zen"};
    float quotazioni[NOMI] = {3.00, 4.00, 5.00};
    for(int i = 0; i < NOMI; i++)
        testa = aggiungi_in_coda(testa, nomiAziende[i], quotazioni[i]);
    stampaLista(testa);
    //provo con una nuova azienda
    testa = aggiorna(testa, "Pippo", 13.00);
    printf("Prima aggiunta\n");
    stampaLista(testa);
    //provo aggiornando l'azienda
    printf("Seconda variazione\n");
    testa = aggiorna(testa, "Apple", 1.00);
    stampaLista(testa);


}

lista aggiorna(lista testa, char nome[41], float quot){
    lista cur, prev;
    //for che devo utilizzare nel punto giusto
    for(cur = testa, prev = NULL; cur != NULL && strcmp(cur -> nomeAzienda, nome) < 0; prev = cur, cur = cur -> next);
    if(strcmp(cur -> nomeAzienda, nome) == 0){
        cur -> variazione = quot - cur -> quotazione;
        cur -> quotazione = quot;
    }
    else{
        lista new = (lista)malloc(sizeof(aziendaQuot));
        strcpy(new->nomeAzienda, nome);
        new -> quotazione = quot;
        new -> variazione = 0;
        if(prev == NULL){ //aggiornando la testa
            new -> next = testa;
            return new;
        }
        //ricollego le parti
        new-> next = cur;
        prev -> next = new; 
        return testa;
    }
}

//funzioni ausiliarie
lista aggiungi_in_coda(lista testa, char nome[41], float quot){
    lista cursore = testa;
    lista new = (lista)malloc(sizeof(aziendaQuot));
    strcpy(new->nomeAzienda, nome);
    new -> quotazione = quot;
    new -> variazione = 0;
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



void stampaLista(lista testa){
    while(testa!= NULL){
        printf("Nome: %-10s  Quotazione: %-5.2f  Variazione: %-6.2f\n", testa->nomeAzienda, testa-> quotazione, testa -> variazione);
        testa = testa->next;
    }
    printf("\n");
}

