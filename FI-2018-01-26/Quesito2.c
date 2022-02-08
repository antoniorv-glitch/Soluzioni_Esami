// Si vuole definire una funzione che legga in input da tastiera una sequenza di caratteri
// terminata dal “.” e la stampi in maniera invertita. La lunghezza della sequenza è indefinita.
// 1. Si scriva una versione iterativa.
// 2. Si scriva una versione ricorsiva.
// 3. Si spieghino i vantaggi/svantaggi dell’una e dell’altra versione (bonus: 3 punti).

#include <stdio.h>
#include <string.h>

void stampa_invertita_ricorsiva(char []);
void stampa_invertita_iterativa(char []);

int main(){
    stampa_invertita_ricorsiva("\nciaone.");
    stampa_invertita_iterativa("\nciaone.");

}
//1.
void stampa_invertita_ricorsiva(char parola[]){
    if(parola[0] == '.')
        return;
    stampa_invertita_ricorsiva(&parola[1]);
    printf("%c", parola[0]);
}
//2.
void stampa_invertita_iterativa(char parola[]){
    for(int i = strlen(parola)-2; i >= 0; i--)
        printf("%c", parola[i]);
}
//3.
// Vantaggi della versione ricorsiva:
// - codice più leggibile
// - fine
// Svantaggi della funzione ricorsiva:
// - slow as hell
// - memoria goes brrrrr


// Vantaggi della versione iterativa:
// -I'm fast as fuck boiiiiii
// - ecosostenibile consuma meno memoria
// Svantaggi della versione iterativa:
// - CoDiCe MeNo LeGgIbIlE1!1!1!