#include <stdio.h>
#include <string.h>

int main(){
    char stringa[25]= "abc(defg)hmn(pq)";
    printf("%s", stringa);
    //modifichiamo la stringa
    int i = 0;
    while(stringa[i]!= '\0'){
        //se troviamo una parantesi con almeno un elemento dentro
        if(stringa[i] == '(' && stringa[i+1] != ')'){
            i++;//andiamo avanti di uno
            int j = i, k =i; //ci salviamo due indici, uno di destinazione della copia dopo l'asterisco 
            //il secondo come sorgente, tutto questo per spostare le lettere dalla parantesi tonda chiusa
            //agli elementi posti dopo l'asterisco. Ad esempio:
            //a(bc)de\0 ')' va in nel posto di b+1, 'e' va nel posto di b + 2 e così via, mentre b diventa il nuovo asterisco
            stringa[j++] = '*'; //rinomino il primo elemento e mi sposto sull'inzio dell'arrivo della copia
            while(stringa[++k] != ')'); //sposto k sull'inzio degli elementi da spostare
            while(stringa[k] != '\0'){
                stringa[j++] = stringa[k++]; //copio gli elementi
            }
            stringa[j] = '\0'; //chiudo la stringa
        }
        i++;
    }
    printf("\n%s", stringa);

}