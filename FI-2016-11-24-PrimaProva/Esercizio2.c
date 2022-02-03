
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define N 5
typedef struct {
    char codiceEsame [5];
    char nomeEsame [51];
    char dataIscrizione[11];
}iscrizione;

typedef iscrizione sessione[N];
int esami_comuni(sessione, sessione);
void stampastruct(sessione);
int main(){
    sessione appelliInvernali =
    {{ "085A", "Analisi Matematica", "31/01/2016"},
    {"084B", "Fondamenti di Informatica", "04/02/2016"},
    {"085A", "Analisi Matematica", "15/02/2016"},
    {"072N","Geometria e Algebra Lineare", "16/02/2016"},
    {"072N", "Geometria e Algebra Lineare", "24/02/2016"}};
    sessione appelliEstivi =
    {{"084B", "Fondamenti di Informatica", 30/06/2016},
    {"012B","Fisica","04/07/2016"},
    {"065Z", "Elettrotecnica", "05/07/2016" },
    {"065Z", "Elettrotecnica", "15/07/2016"},
    {"085A" ,"Analisi Matematica", "18/07/2016"}};
    printf("Il numero di esami in comune sono: %d\n", esami_comuni(appelliInvernali, appelliEstivi));
    stampastruct(appelliInvernali);
    stampastruct(appelliEstivi);
}

int esami_comuni(sessione a, sessione b){
    int n_esami = 0;
    bool ripetuto;
    bool skip[N] ={0}; //array con le posizioni delgi elementi da skippare
    for(int i = 0; i < N; i++){
        ripetuto = false;
        for(int j = 0; j < N; j++){
            if(!skip[j]){
                if(strcmp(a[i].codiceEsame, b[j].codiceEsame) == 0){
                    skip[j]  = true; //alla prossima iterazione quell'elemento sarà da saltare
                    if(!ripetuto) //se l'elemento non è gia saltato in questa iterazione
                        n_esami++;
                    ripetuto = true;
                }
            }
        }
    }
    return n_esami;
}

void stampastruct(sessione a){
    for(int i = 0; i < N; i++){
        printf("%5s, ", a[i].codiceEsame);
    }
    printf("\n");
}