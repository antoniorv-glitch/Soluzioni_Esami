#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct EL{
    char * parola;
    struct EL * next;
}nodo;

typedef nodo* lista;

lista leggi_file(FILE *);
void stampa_parole_valide(lista, FILE *);
int main(int argc, char * argv[]){
    if(argc < 3){
        fprintf(stderr, "Errore: parametri insufficienti! ");
        return -1;
    }
    FILE * fin = fopen(argv[1], "r");
    FILE * fout = fopen(argv[2], "w");
    if(!(fin && fout)){
        fprintf(stderr, "Errore: Impossibile utilizzare uno dei due file");
        return -1;
    }
    lista testa = leggi_file(fin);
    stampa_parole_valide(testa, fout);
    fclose(fin);
    fclose(fout);
}

lista leggi_file(FILE * fp){
    lista testa = NULL;
    int dim = 0;
    char c;
    if(fscanf(fp, "%c", &c) && c != ' ' && c != '\n'){
        testa = (lista) malloc(sizeof(nodo));
        rewind(fp);
    }
    else return testa;
    while(fscanf(fp, "%c", &c)  && c != ' ' && c != '\n'){
        dim++;
        testa -> parola = (char* ) realloc(testa -> parola, dim+1 * sizeof(char));
        testa -> parola[dim-1] = c;
    }
    testa -> parola[dim] = '\0';
    testa -> next =NULL;
    lista cursore = testa;
    while(!feof(fp)){
        dim = 0;
        lista new = (lista) malloc(sizeof(nodo));
        while(fscanf(fp, "%c", &c)  && c != ' ' && c != '\n'){
            dim++;
            new -> parola = (char* ) realloc(new -> parola, dim+1 * sizeof(char));
            new -> parola[dim-1] = c;
        }
        if(dim){
            new -> parola[dim] = '\0';
            new -> next =NULL;
            cursore -> next = new;
            cursore = cursore -> next;
        }
        else free(new);
    }
    return testa;

}

void stampa_parole_valide(lista testa, FILE * fp){
    int n_b;    //numero di b
    int n_c;    //numero di c
    int i;
    for(lista cursore = testa; cursore != NULL; cursore = cursore -> next){
        bool valida = true;
        i = 0;
        n_c = 0;
        n_b = 0;
        while(cursore -> parola[i] != '\0' && valida){
            switch(cursore -> parola[i]){
                case 'a':
                i++;
                break;
                case 'b':
                while(cursore -> parola[i] == 'b' && cursore -> parola[i] != '\0'){
                    i++;
                    n_b++;
                }
                if(n_b %2 != 0) // se il numero di b non è pari della sottosequenza allora la parola non è valida
                    valida = false;
                n_b = 0;
                break;
                case 'c':  
                while(cursore -> parola[i] == 'c' && cursore -> parola[i] != '\0'){
                    n_c++;
                    i++;
                }
                if(n_c > 2)
                    valida = false;
                n_c  = 0;
                break;
                default:
                valida = false;
                break;
            }
            
        }
        if(!valida)
            fprintf(fp, "%s ", cursore -> parola);
    }
}