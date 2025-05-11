// Creiamo un array che stampa i numeri da 1 a 10
#include <stdio.h>
#include <stdlib.h>

// Definizione dell'array
int numeri[10];

// Funzione principale 
// In C, la funzione main è il punto di ingresso del programma
int main() {

    // Scritta iniziale
    printf("Numeri da 1 a 10:\n");

    // Inizializzazione dell'array
    for (int i = 0; i < 10; i++) {

        // Assegniamo il valore i+1 all'array numeri
        numeri[i] = i + 1;
        
        // Stampa del valore dell'array
        printf("%d \n", numeri[i]);
    }

    return 0;
}