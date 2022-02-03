//librerie necessarie
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define LEN 20
//tipi di struct
typedef struct EL{
    char s[LEN];
    int frequenza;
    struct EL * next;
}nodo;

typedef nodo * lista;
//funzioni
lista frequenza(FILE *);
void stampalista(lista);

int main(int argc, char * argv[]){
    if(argc < 2){
        fprintf(stderr, "Errore: Parametri insufficienti!");
        return -1;
    }
    FILE * fp = fopen(argv[1], "r");
    if(fp == NULL){
        fprintf(stderr, "Errore: Impossibile aprire il file");
        return -1;        
    }
    lista testa;
    testa = frequenza(fp);
    stampalista(testa);
}

lista frequenza(FILE * fp){
    lista testa = NULL;
    char stringa[LEN] = {'\0'}; //importante inizializzare la stringa per assicurarci che abbia dimensione < 2
    while(!feof(fp) && strlen(stringa) < 2){
        fscanf(fp, "%s", stringa);
    }
    if(strlen(stringa) < 2){
        return testa; //in questo caso nessun elemento del file ha una stringa con lunghezza > 2
    }
    testa = (lista) malloc(sizeof(nodo));//inizializziamo la testa
    strcpy(testa -> s, stringa);
    testa -> frequenza = 1;
    while(fscanf(fp, "%s", stringa) == 1){ 
        if(strlen(stringa) >= 2){
            bool nuovo_elemento = true;
            lista cursore = testa;
            while(cursore != NULL && nuovo_elemento){
                if(strcmp(cursore -> s, stringa) == 0) //l'elemento è gia presente
                    nuovo_elemento = false;
                else
                    cursore = cursore -> next;
            }
            if(nuovo_elemento){
                lista new = (lista) malloc(sizeof(nodo));
                strcpy(new -> s, stringa);
                new -> frequenza = 1;
                //e ora la parte più tricky, inserire l'elemento nella posizione giusta
                if(strcmp(new -> s, testa  -> s) < 0){ // a < b     
                    new -> next = testa;
                    testa = new;
                }
                else{
                    lista cur, prev;
                    for(cur = testa, prev = NULL; cur !=  NULL && strcmp(new -> s, cur -> s) > 0; prev = cur, cur = cur -> next);
                    new -> next = cur;
                    prev -> next = new; //in questo modo abbiamo creato un nuovo nodo
                    
                }
            }
            else{
                cursore -> frequenza++; //il cursore si è posato sull'elemento già presente
            }
        }
    }
    return testa;
}


void stampalista(lista testa){
    if(testa == NULL){
        printf("Lista vuota\n");
        return;
    }
    for(lista cursore = testa; cursore != NULL; cursore = cursore -> next){
        printf("Parola: %s, frequenza: %d\n", cursore -> s, cursore -> frequenza);
    }
}