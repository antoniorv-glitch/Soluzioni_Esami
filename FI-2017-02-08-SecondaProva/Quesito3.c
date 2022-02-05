#include <stdio.h>
#include <stdlib.h>

// Quesito 3 (15 punti). Si vuole definire un programma in C, opportunamente strutturato in funzioni che, data
// una sequenza di valori interi letti da file, individui eventuali sotto-sequenze (di lunghezza minima 2) di valori
// consecutivi crescenti e le scriva in un secondo file. Per esempio, se nel file di input è memorizzata la sequenza
// 3, 5, 2, 4, 2, 8, 4, 3, 2
// allora il programma salva sul file di output le seguenti sotto-sequenze:
// 3, 5
// 2, 4
// 2, 8
// N.B.: Il programma deve essere realizzato in modo modulare, scomponendolo almeno nelle seguenti funzioni:
// 1. La funzione main: deve ricevere come argomenti della linea di comando il nome dei due file (quello di
// input e quello di output) (3 punti);
// 2. Una funzione che legga i valori dal file di input e li memorizzi in un’opportuna struttura dati (4 punti);
// 3. Una funzione che riceva in input la struttura dati creata al punto precedente e memorizzi nel file di output
// le eventuali sotto-sequenze. (8 punti);

typedef struct{
    int dimensione;
    int * array;
}array;
array leggi(FILE *);
void stampa_sottosequenze(array, FILE *);

int main (int argc, char * argv[]){
    if(argc < 3){
        fprintf(stderr, "Parametri insufficienti\n");
        return -1;
    }
    FILE * fin  = fopen(argv[1], "r");
    FILE * fout = fopen(argv[2], "w");
    if(!(fin && fout)){
        fprintf(stderr, "Impossibile aprire uno dei due file");
        return -1;
    }
    array array1 = leggi(fin);
    stampa_sottosequenze(array1, fout);
    fclose(fin);
    fclose(fout);
    
}
void stampa_sottosequenze(array array1, FILE * fp){
    int i = 0;
    while(i < array1.dimensione){
        if(i+1 <array1.dimensione && array1.array[i] < array1.array[i+1]){
            while(i+1 < array1.dimensione && array1.array[i] < array1.array[i+1]){
                fprintf(fp, "%d, ", array1.array[i]);
                i++;
            }
            fprintf(fp, "%d, ", array1.array[i]);
            fprintf(fp, "\n");
        }
        else i++;
    }
   
}

array leggi(FILE * fp){
    array array1;
    array1.array = NULL;
    int numero;
    array1.dimensione = 0;
    while(fscanf(fp, "%d,", &numero) == 1){
        array1.dimensione++;
        array1.array = (int *) realloc(array1.array, sizeof(int)*array1.dimensione);
        array1.array[array1.dimensione-1] = numero;
    }
    return array1;
}


