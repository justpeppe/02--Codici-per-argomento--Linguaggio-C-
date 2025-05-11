// Prendiamo l'elemento in posizione scelta dall'utente e lo stampiamo
#include <stdio.h>
#include <stdlib.h>

// Definizione dell'array
int numeri[10];

int main() {
    // Inizializzazione dell'array
    for (int i = 0; i < 10; i++) {
        // Assegniamo il valore i+1 all'array numeri
        numeri[i] = i + 1;
    }

    // Chiediamo all'utente di inserire un numero da 1 a 10
    int posizione;
    printf("Inserisci la posizione dell'elemento da stampare (1-10): ");
    scanf("%d", &posizione);
    
    printf("L'elemento in posizione %d è: %d\n", posizione, numeri[posizione - 1]);
    // Perchè posizione - 1? Perchè gli array in C partono da 0, mentre l'utente parte da 1

    return 0;
}