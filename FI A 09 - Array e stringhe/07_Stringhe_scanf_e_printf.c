// Leggiamo dei caratteri da tastiera con scanf e li stampiamo con printf
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Creiamo un array che può contenere fino a n-1 lettere con n la dimensione dell'array (-1 perchè serve il carattere di escape)
    char messaggio_input[51];

    printf("Inserisce un messaggio (per terminare premere invio): ");
    // Con scanf se inseriamo più parole leggerà solo i caratteri fino al primo spazio poichè esso viene letto come carattere di escape
    scanf("%s", messaggio_input);
    printf("\nIl messaggio inserito da tastiera è\': %s", messaggio_input);

    return 0;
}