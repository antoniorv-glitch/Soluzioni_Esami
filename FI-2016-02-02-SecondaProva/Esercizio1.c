#define MAX 20
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void leggi_cruciverba(FILE *);
void ricerca_parole(char [][MAX], int , int);

int main(int argc, char * argv[]){
    if(argc < 2){
        fprintf(stderr, "Errore: Parametri insufficienti");
        return -1;
    }
    FILE * fp = fopen(argv[1], "r"); //file di input: input.txt
    if(fp == NULL){
        fprintf(stderr, "Errore: Impossibile aprire il file");
        return -1;
    }
    leggi_cruciverba(fp);
}

void leggi_cruciverba(FILE * fp){
    int righe, colonne;
    fscanf(fp, "%d %d\n", &righe, &colonne);
    if(righe > MAX || colonne > MAX){
        fprintf(stderr, "Errore: Dimensioni specificate non valide");
        return;
    }
    //inserimento del cruciverba
    char cruciverba[MAX][MAX];
    for(int i = 0; i < righe; i++){
        for(int j = 0; j < colonne; j++){
            cruciverba[i][j] = fgetc(fp);
        }
        fgetc(fp); //in questo modo togliamo anche gli \n
    }
    ricerca_parole(cruciverba, righe, colonne);
}

void ricerca_parole(char cruciverba[][MAX], int righe, int colonne){
    char parola[MAX] = {'\0'};
    int dim_parola;
    FILE * fout = fopen("file.txt", "w");
    if(fout == NULL){
        fprintf(stderr, "Errore: Impossibile utilizzare file.txt");
        return;
    }
    //scandiamo per righe
    for(int i = 0; i < righe; i++){
        dim_parola = 0;
        for(int j = 0; j < colonne; j++){
            parola[dim_parola++] = cruciverba[i][j];
            if(cruciverba[i][j] == '*'){
                parola[dim_parola - 1] = '\0'; //sostituiamo l'asterisco con il terminatore
                if(strlen(parola) >= 2)
                        fprintf(fout, "%s\n", parola);
                dim_parola = 0;
            }
        }
        parola[dim_parola] = '\0'; //chiudiamo l'ultima parola
        if(strlen(parola) >= 2)
                fprintf(fout, "%s\n", parola);
    }
    fprintf(fout, "\n");
    //situazione speculare per colonne, basta scambiare i due for
    for(int j = 0; j < colonne; j++){
        dim_parola = 0;
        for(int i = 0; i < righe; i++){
            parola[dim_parola++] = cruciverba[i][j];
            if(cruciverba[i][j] == '*'){
                parola[dim_parola - 1] = '\0';
                if(strlen(parola) >= 2)
                        fprintf(fout, "%s\n", parola);
                dim_parola = 0;
            }
        }
        parola[dim_parola] = '\0';
        if(strlen(parola) >= 2)
                fprintf(fout, "%s\n", parola);
    }
}