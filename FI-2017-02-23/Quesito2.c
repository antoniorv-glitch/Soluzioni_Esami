#include <stdio.h>

int c_max(int); //funzione cifra max

int main(){

    printf("%d\n", c_max(1623));

}

int c_max(int n){
    if(n == 0)
        return 0;
    return (c_max(n/10) < n%10)?n%10:c_max(n/10);
}