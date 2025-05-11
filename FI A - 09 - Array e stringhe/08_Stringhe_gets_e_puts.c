// Leggiamo dei caratteri da tastiera con gets e li stampiamo con puts (gets non funziona più oggi)
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Creiamo un array che può contenere fino a 50 caratteri (+1 per il terminatore '\0')
    char messaggio_input[51];

    puts("Inserisci un messaggio (per terminare premere invio): ");

    // Usa gets (non sicuro, solo per scopi didattici)
    gets(messaggio_input);

    puts("\nIl messaggio inserito da tastiera è:");
    puts(messaggio_input);

    return 0;
}