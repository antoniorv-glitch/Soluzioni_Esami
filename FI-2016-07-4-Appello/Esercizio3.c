#include <stdio.h>
#include <stdlib.h>

typedef struct EL{
    char c;
    struct EL * next;
}nodo;

typedef nodo * lista;

int verifica(FILE *);
//ausiliaria
void stampalista(lista);

int main(){
    FILE * fp1 = fopen("testo1.txt", "r");
    FILE * fp2 = fopen("testo2.txt", "r");
    FILE * fp3 = fopen("testo3.txt", "r");
    FILE * fp4 = fopen("testo4.txt", "r");
    FILE * fp5 = fopen("testo5.txt", "r");
    FILE * fp6 = fopen("testo6.txt", "r");
    FILE * fp7 = fopen("testo7.txt", "r");


    if(!(fp1 && fp2 && fp3 && fp4 && fp5 && fp6 && fp7)){
        fprintf(stderr, "Errore: Impossibile aprire uno dei file");
    }
    printf("Testo1: %d\n\n", verifica(fp1));
    printf("Testo2: %d\n\n", verifica(fp2));
    printf("Testo3: %d\n\n", verifica(fp3));
    printf("Testo4: %d\n\n", verifica(fp4));
    printf("Testo5: %d\n\n", verifica(fp5));
    printf("Testo6: %d\n\n", verifica(fp6));
    printf("Testo7: %d\n\n", verifica(fp7));

}

int verifica(FILE * fp){
    lista testa = NULL;
    char c;
    //inizializziamo la testa
    //per capire il controllo leggete pag 584 del king, introduzione del paragrafo 22.4
    if((c = getc(fp))>0){
        testa = (lista) malloc(sizeof(nodo));
        testa -> c = c;
        testa -> next = NULL;
    }
    else return 0;
    lista cursore = testa;
    
    while((c = getc(fp))>0){
        lista new = (lista) malloc(sizeof(nodo));
        new -> c = c;
        new -> next = NULL;
        cursore -> next = new;
        cursore = cursore -> next;
    }
    //controllo il contenuto dei testi mandando tutto a stampalista
    stampalista(testa);
    int verifica = 1;
    int verifica1 = 0, verifica2 = 0, verifica3  = 0;
    for(cursore = testa; cursore != NULL && verifica ; cursore = cursore -> next){
        switch (cursore->c){
            case '{':
                verifica1++;
                break;
            case '(':
                verifica2++;
                break;
            case '[':
                verifica3++;
                break;
            case '}':
                verifica1--;
                break;
            case ')':
                verifica2--;
                break;
            case ']':
                verifica3--;
                break;
        }
        verifica = (verifica1 >= 0) * (verifica2 >= 0) * (verifica3>=0);
        //se uno va in negativo verifica va a 0, ovvero è stata chiusa una parentesi mai stai aperta
    }
    //se il numero di parentesi aperte è uguale al numero di parentesi chiuse verifica sarà = 0;
    if(verifica1 == 0 && verifica2 == 0 && verifica3 == 0) return 1;
    else return 0;
}

//ausiliaria
void stampalista(lista testa){
    while(testa!= NULL){
        printf("%c", testa->c);
        testa = testa->next;
    }
}
