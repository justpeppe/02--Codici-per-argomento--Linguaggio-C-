// Esempio slide 19
// Leggiamo i dati dentro il file .txt e poniamo le persone dentro un array
#include <stdio.h>
#define DIM 30

typedef struct {
    char cognome[31];
    char nome[31];
    char sesso[2];
    int anno;
} modello_persona;

int main() {

    int k = 0;
    modello_persona vettore_persone[DIM];

    // Apriamo il file in lettura
    FILE* dati = fopen("02_Esercizio_persone.txt","r");

    // Verifichiamo l'apertura
    if ( dati == NULL ) {
        perror("File non aperto correttamente");
        return 1;
    } else {
        // Leggiamo i dati dal file
        while (k < DIM && fscanf(dati, "%30s %30s %1s %d", 
                vettore_persone[k].cognome, 
                vettore_persone[k].nome, 
                vettore_persone[k].sesso, 
                &vettore_persone[k].anno) == 4) {
            k++;
        }
        fclose(dati);
    }

    // Stampa dei dati letti
    for (int i = 0; i < k; i++) {
        printf("%s %s %s %d\n", vettore_persone[i].cognome, vettore_persone[i].nome, vettore_persone[i].sesso, vettore_persone[i].anno);
    }

    printf("\n\n");
    return 0;   
}