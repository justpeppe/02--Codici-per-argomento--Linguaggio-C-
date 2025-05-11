// Slide 22
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Definiamo la costante trovato che conta gli elementi trovati
    int trovato = 0;

    // Definiamo i due array
    // Array di multipli di 10
    int size_1 = 5;
    int array_1[] = {10, 20, 30, 40, 50};
    // Array di multipli di 5
    int size_2 = 10;
    int array_2[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};

    printf("Gli elementi in comune sono:");

    // Creiamo gli indici
    int idx_1 = 0;
    int idx_2 = 0;

    // Creiamo due cicli for per scorrere i due vettori
    for (idx_1 = 0; idx_1 < size_1; idx_1++) {
        for (idx_2 = 0; idx_2 < size_2; idx_2++) {
            if (array_1[idx_1] == array_2[idx_2]) {
                trovato = trovato + 1; // Incrementa la variabile globale
                printf("\n%d", array_1[idx_1]); // Corretto il formato
            }
        }
    }

    // Stampiamo il numero di elementi trovati in comune oppure un messaggio che ci segnala che ciò non è accaduto
    if (trovato != 0) {
        printf("\nCi sono %d elementi in comune\n", trovato);
    } else {
        printf("\nNessun elemento è in comune ai due array\n");
    }

    return 0;
}
