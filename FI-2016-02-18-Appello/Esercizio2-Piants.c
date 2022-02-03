#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10

char* numero_binario(int n, int* dim);
int main(){
    int dim;

    printf("%s\n", numero_binario(5, &dim));
    printf("%s\n", numero_binario(256, &dim));
    printf("%s\n", numero_binario(192, &dim));

    return 0;
}

char* numero_binario(int n, int* dim){
    char* array = NULL;

    if(n / 2 == 0){
        array = (char*) malloc(2 * sizeof(char));
        array[0] = '1';
        array[1] = '\0';
        *dim = 2;
        return array;
    }

    array = numero_binario(n / 2, dim);
    array = (char*) realloc(array, ++(*dim));
    array[*dim - 2] = n % 2 + '0';

    return array;
}