// Quesito 3 (12 punti). 
// Si vuole definire un programma in C in grado di guidare e tracciare i movimenti di un
// robot in una certa area. L’area in cui il robot può muoversi è descritta da una mat M, di dimensione NxN. In
// particolare, il valore memorizzato in ciascun elemento M[i][j] rappresenta la quota del quadratino di superficie
// alle pos <i, j>. A partire da una posizione iniziale M[x][y], i cui indici possono essere impostati tramite
// input da tastiera, si vogliono tracciare le pos di tutte le posizioni visitate dal robot, considerando che il
// robot può muoversi secondo le seguenti regole:

// - A ogni passo, può scegliere di spostarsi di un solo quadratino nelle 8 direzioni possibili e facendo
// attenzione a non oltrepassare i limiti dell’area.
// - Per evitare pendenze difficili da affrontare, il robot sceglie la posizione di quota minima tra quelle
// adiacenti (in caso di più posizioni con lo stesso valore minimo, il robot sceglie l’ultimo ispezionato).
// -Il robot non può ritornare su posizioni già visitate.
//- Il robot si ferma se tutte le posizioni adiacenti hanno una quota superiore a un certo valore q; comunque,
// il robot si ferma dopo un numero massimo di mosse, m. I due valori q e m sono specificati tramite input da
// tastiera.

// Il programma deve acquisire i dati della mappa da un file e deve scrivere le pos del percorso del robot in
// un secondo file. I nomi dei file devono essere specificati dall’utente come argomenti della linea di comando.
// Il file della mappa è organizzato nel seguente modo (e si può assumere che non contenga errori):
// - La prima riga memorizza le dimensioni della mat.
// - Ogni riga del file memorizza una riga della mat.
// - I valori in ogni riga, inclusa la prima, sono separati da un singolo spazio.
#include <stdio.h>
#include <stdbool.h>
#define N 50

typedef struct{
    int x;
    int y;
}pos;



int main(int argc, char *argv[]){
    int mat[N][N];
    if(argc < 3){
        fprintf(stderr, "Errore: Parametri insufficienti");
        return -1;
    }

    FILE *fin = fopen(argv[1], "r");
    FILE *fout = fopen(argv[2], "w");

    if(!(fin && fout)){
        fprintf(stderr, "Errore: Impossibile aprire uno dei due file");
        return -1;
    }

    int dim;
    fscanf(fin, "%d\n", &dim);
    
    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            fscanf(fin, "%d ", &mat[i][j]);
        }
    }
    
    int q, m;
    printf("Inserire quota massima:\n");
    scanf("%d", &q);
    printf("Inserire numero massimo di mosse:\n");
    scanf("%d", &m);
    pos cur;
    printf("Inserire le coordinate iniziali:\n");
    printf("Sia la pos contenuta in [0 - %d]: ", dim-1);
    scanf("%d %d", &cur.y, &cur.x);
    mat[cur.y][cur.x] = q+1; //impedisco al robot di rimanere fermo su questa posizione
    bool blocked = false; // flag di uscita;
    int min, i = 0;
    while(i < m && !blocked){
        min = q+1; // il minimo parte dalla quota inaccessibile
        pos minimo;
        for(int q = -1; q < 2; q++){
            for(int w = -1; w < 2; w++){
                if(cur.y +q >= 0 && cur.y +q < dim && cur.x +w >= 0 && cur.x+w < dim) //le coordinate sono contenute nei parametri giusti?
                    if(mat[cur.y + q][cur.x+w] <= min){  //aggiorniamo il minimo
                        min = mat[cur.y+q][cur.x+w];
                        minimo.x = cur.x+w; // aggiorniamo le posizioni del minimo
                        minimo.y = cur.y+q;
                    }
            }
        }
        if(min <= q){
            fprintf(fout, "[%d,%d] ", minimo.y , minimo.x);
            mat[minimo.y][minimo.x] = q+1; //la posizione minima ora ha quota q+1, in questo modo risulta inaccessibile
            cur.x = minimo.x; // aggiorniamo la posizione corrente
            cur.y = minimo.y;
        }
        else blocked = true; //robot stucked
        //se siamo usciti è perchè tutte le altre posizioni hanno superato la quota massima, 
        //in quanto già utilizzate, oppure di default avevano già una quota troppo elevata
        i++;
    }
    

}

