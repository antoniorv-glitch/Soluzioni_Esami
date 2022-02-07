#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#define N 10

// Il programma deve essere realizzato in modo modulare secondo i seguenti requisiti:
// 1. La funzione main deve ricevere come argomenti della linea di comando il nome dei due file utilizzati
// dal programma, quello da cui leggere le stringhe da analizzare e quello di output. Deve poi leggere in
// input dall’utente la stringa per la quale trovare gli anagrammi nel file (4 punti).
// 2. Una funzione dovrà essere dedicata a leggere le stringhe dal file; si supponga che nel file le parole siano
// memorizzate una per riga e che la lunghezza massima di ogni parola sia di 10 caratteri (6 punti).
// 3. Una funzione dovrà essere dedicata ad analizzare ogni singola parola per verificarne se è anagramma
// della parola specificata dall’utente. Se la parola letta è un anagramma, la funzione dovrà scriverla nel
// file di ouptut. (10 punti).
// N.B: Nell’analisi degli anagrammi e’ possibile far uso di un array aggiuntivo. Se necessario, è possibile far uso
// anche di altre funzioni oltre a quelle richieste dai punti precedenti.

typedef struct EL{
    char parola[N];
    struct EL * next;
}nodo;

typedef nodo * lista;


lista Input(FILE *);
void Output(FILE *, lista, char []);
void ListaFree(lista);

int main(int argc, char * argv[]){
    if(argc < 3){
        fprintf(stderr, "Errore: Parametri insufficienti\n");
        return -1;
    }
    FILE * fin = fopen(argv[1], "r");
    FILE * fout = fopen(argv[2], "w");
    if(!(fin && fout)){
        fprintf(stderr, "Errore: Impossibile aprire uno dei due file\n");
        return -1;
    }
    char analisi[N];
    printf("Inserisci la parola da analizzare: ");
    scanf("%s", analisi);
    lista testa = Input(fin);
    Output(fout, testa, analisi);
    fclose(fin);
    fclose(fout);
    ListaFree(testa);
        
}


lista Input(FILE * fp){
    lista testa = NULL;
    if(feof(fp)) return testa; // file vuoto
    testa = (lista) malloc(sizeof(nodo));
    testa->next = NULL;
    fscanf(fp, "%s", testa -> parola);
    lista cursore = testa;
    while(!feof(fp)){
        lista new = (lista) malloc(sizeof(nodo));
        new -> next = NULL;
        fscanf(fp, "%s", new -> parola);
        cursore -> next = new;
        cursore = cursore -> next;
    }
    return testa;
}





void Output(FILE *fp, lista testa, char analisi[]){
    char copia[N];
    for(lista cursore = testa; cursore != NULL; cursore = cursore -> next){
        if(strnlen(cursore -> parola, N) == strnlen(analisi, N)){
            strcpy(copia, analisi);
            bool trovato = true;
            for(int i = 0; i < strlen(cursore -> parola) && trovato; i++ ){
                trovato = false;
                for(int j = 0; j < strlen(analisi) && !trovato; j++){
                    if(cursore -> parola[i] == copia[j]){
                        copia[j] = '\0';
                        trovato = true;
                    }
                }
            }
            if(trovato){
                fprintf(fp, "%s\n", cursore -> parola);
            }
        }
    }
}



void ListaFree(lista testa){
    if(testa == NULL){
        return ;
    }
    ListaFree(testa->next);
    free(testa);
}