// 2 5 21 8 10 1 4  16  3
// 2 1 5  8 4  3 21 10 16
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    bool blocked;
    int num;
}vector;

void modifica(FILE *, char *, int, int);

int main(int argc, char * argv[]){
    
    if(argc < 2){
	    fprintf(stderr, "Errore: Parametri insufficienti");
	    return -1;
    }
    FILE * fp = fopen(argv[1], "r");
    if(!fp){
        fprintf(stderr, "Errore: Impossibile aprire il file");
        return -1;
    }
    int arg1 = 3, arg2 = 9;
    modifica(fp,argv[1], arg1, arg2);
}

void modifica(FILE * fp, char * name, int arg1, int arg2){
    int intero;
    int dim = 0;
    vector * arr = malloc(sizeof(vector));
    while(fscanf(fp, "%d ", &intero) == 1){
        dim++;
        arr = (vector *) realloc(arr, dim *sizeof(vector));
        arr[dim - 1].num = intero;
        arr[dim - 1].blocked = false;
        printf("%d ", intero);
    }
    int count1 = 0, count2 = 0;
    for(int i = 0; i < dim; i++){
        if(arr[i].num < arg1)
            count1++;
        if(arr[i].num > arg2)
            count2++;
    }
    for(int i = 0; i < count1; i++){
        if(arr[i].num < arg1)
            arr[i].blocked = true;
    }
    for(int i = count1; i < dim - count2 - 1; i++){
        if((arr[i].num >= arg1) && (arr[i].num <= arg2))
            arr[i].blocked = true;
    }
    for(int i = dim - count2 -1; i < dim; i++){
        if( arr[i].num > arg2)
            arr[i].blocked = true;
    }
    printf("\n");
    //controllo
    for(int i = 0; i < dim; i++)
        if(arr[i].blocked)
            printf("[%d] ", arr[i].num);
        else
            printf("%d ", arr[i].num);
    printf("\ncount1: %d, count2: %d, dim: %d", count1, count2, dim);
    for(int i = 0; i < dim; i++){
        if(!arr[i].blocked){
            for(int j = i+1; j < dim ; j++){
                if(arr[i].num > arr[j].num && !arr[j].blocked){
                    int temp = arr[j].num;
                    arr[j].num = arr[i].num;
                    arr[i].num = temp;
                }
            }
        }
    }
    fp = fopen("test.txt", "w"); //utilizzare la seconda opzione per riaprire lo stesso file.
    //fp = freopen(name, "w", fp);
    for(int i = 0; i < dim; i++)
        fprintf(fp, "%d ", arr[i].num);

    printf("\n");
}
