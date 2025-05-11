// Leggiamo un solo carattere da tastiera con getchar e lo stampiamo con putchar
#include <stdio.h>

int main() {
    char c;

    printf("Inserisci un carattere: ");
    c = getchar(); // Legge un carattere da tastiera

    printf("Hai inserito: ");
    putchar(c); // Stampa il carattere letto
    putchar('\n'); // Aggiunge una nuova riga

    return 0;
}