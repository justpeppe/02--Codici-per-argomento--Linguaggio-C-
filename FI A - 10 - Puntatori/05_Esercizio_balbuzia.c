// Slide 40
#include <stdio.h>
#include <string.h>

int main() {

    // Definizione input e output
    char input[30], output[100];

    // Comandi inserimento tastiera
    printf("Inserisci una stringa da tastiera: ");
    scanf("%s", input);

    // Inizializzazione dei puntatori
    char *puntatore_input = input;
    char *puntatore_output = output;

    // Ciclo while di ripetizione
    while (*puntatore_input != '\0') {
        *puntatore_output++ = *puntatore_input; // prima copiamo l'elemento e poi avviene l'incremento della posizione
        *puntatore_output++ = *puntatore_input;
        *puntatore_output++ = *puntatore_input++;
    }

    // Terminatore della stringa
    *puntatore_output = '\0';

    // Stampa del risultato
    printf("Stringa balbuziente: %s", output);

    printf("\n\n");
    return 0;
}