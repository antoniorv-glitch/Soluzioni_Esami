// Un numero n si dice Primo Troncabile a Sinistra (PTS) se n e tutti i numeri ottenuti cancellando
// ripetutamente le sue cifre più a sinistra sono primi. Per esempio, 313 è un PTS; infatti, 313 è primo, 13 è
// primo (è stata cancellata la prima cifra a sinistra), 3 è primo (sono state cancellate le prime due cifre a
// sinistra).
// Si definisca un programma in C in grado di leggere dal file una sequenza di interi e memorizzare in una
// lista dinamica ordinata i soli elementi che sono PTS. Il file è organizzato in modo da contenere un
// intero per ogni riga. Il nome del file deve essere letto come argomento della linea di comando con cui si
// esegue il programma.
// Il programma deve essere realizzato in modo modulare, scomponendolo almeno nelle seguenti
// funzioni:
// 1. La funzione main, con passaggio come argomento della linea di comando del nome del file
// contenente gli interi (3 punti);
// 2. Una funzione per verificare se un intero letto dal file è PTS. Tale funzione può anche far uso di altre
// funzioni, per esempio quella per verificare che un numero sia primo (8 punti).
// 3. Una funzione che legga dal file gli interi e memorizzi i soli PTS in una lista dinamica.
// L’inserimento deve avvenire in ordine, in modo che nella lista risultante gli interi siano elencati
// in ordine crescente (8 punti);

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct EL{
    int dato;
    struct EL * next;
}nodo;

typedef nodo * lista;

lista elementi_PTS(FILE *);
int PTS(int);
void stampalista(lista);

int main(int argc, char * argv[]){
    if(argc < 2){
        fprintf(stderr, "Errore: Parametri Insufficienti");
        return -1;
    }
    FILE * fp = fopen(argv[1], "r");
    if(fp == NULL){
        fprintf(stderr, "Errore: Impossibile aprire il file");
        return -1;
    }
    lista testa = elementi_PTS(fp);
    stampalista(testa);
}

void stampalista(lista testa){
    for(lista cursore = testa; cursore != NULL; cursore = cursore -> next)
        printf("%d->", cursore -> dato);
    printf("\n");
}
int PTS(int numero){
    while(numero != 0){
        //controlliamo se è primo
        if(numero == 1 || numero == 0)
            return 0;
        
        for(int i = 2; i < sqrt(numero); i++)
            if(numero%i == 0)
                return 0;
        //togliamo una cifra a sinistra
        int dec, copia = numero;
        for(dec = 1;  copia/10 != 0; dec*=10, copia/=10);
        numero -= copia * dec;
    }
    return 1;
}
lista elementi_PTS(FILE * fp){
    int elemento;
    lista testa = NULL;
    //inizializiamo le testa
    while(fscanf(fp, "%d", &elemento) && !testa){
        if(PTS(elemento)){
            testa = (lista) malloc(sizeof(nodo));
            testa->dato = elemento;
            testa->next =NULL;
        }
    }
    if(!testa) return testa; //file senza PTS.
    while(fscanf(fp, "%d", &elemento)  == 1){
        if(PTS(elemento)){
            lista new = (lista) malloc(sizeof(nodo));
            new -> dato = elemento;
            new -> next = NULL;
            lista cur, prev;
            //per inserire in modo ordinato
            for(cur = testa, prev = NULL; cur != NULL && cur-> dato < elemento; prev = cur, cur = cur -> next);
            if(prev == NULL){
                new -> next = testa;
                testa = new;
            }
            else{
                new -> next = cur;
                prev-> next = new;
            }
        }
    }
    return testa;
}