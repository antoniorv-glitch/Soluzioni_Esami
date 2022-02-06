#include <stdio.h>
#include <stdbool.h>
#define MAX 100

void extract_mat_sparsa(FILE *, FILE *);

int main(int argc, char * argv[]){
    if(argc < 3){
        fprintf(stderr, "Errore: parametri insufficienti");
        return -1;
    }
    FILE * fin = fopen(argv[1], "r");
    FILE * fout = fopen(argv[2], "w");
    if(!(fin && fout)){
        fprintf(stderr, "Errore: Impossibile aprire uno dei due file!");
        return -1;
    }
    extract_mat_sparsa(fin, fout);
    
}

void extract_mat_sparsa(FILE *fin, FILE *fout){
    int dominante, n_righe, n_colonne;
    fscanf(fin, "%d %d %d\n", &n_righe, &n_colonne, &dominante);
    bool inserito = true; //tutto questo esercizio lo faccio assumendo che l'elenco delle posizioni dei numeri non dominanti siano in ordine
    int elemento, riga, colonna;
    for(int i = 0; i < n_righe; i++){
        for(int j = 0; j <  n_colonne; j++){
            if(inserito){
                if(fscanf(fin, "%d %d %d\n", &riga, &colonna, &elemento)){
                    inserito = false;
                }
                else inserito = true;
            }
            if(i == riga && j == colonna){
                fprintf(fout, "%d ", elemento);
                inserito = true;
            }
            else fprintf(fout, "%d ", dominante);
        }
        fprintf(fout, "\n");
    }
}