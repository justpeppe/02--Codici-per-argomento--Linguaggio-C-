#include <stdio.h>
#include <stdlib.h>

// Definiamo la struttura persona composta sia da char che da interi
struct persona{
    char nome[20];
    char cognome[20];
    int giorno; 
    int mese; 
    int anno;
}; // va messo ; alla fine delle strutture

int main() {

    // Utilizziamo questa struttura

    struct persona io;

    // Col . scegliamo che variabile cambiare
    printf("Inserisci il tuo nome: ");
    scanf("%19s", io.nome);
    printf("Inserisci il tuo cognome: ");
    scanf("%19s", io.cognome);
    printf("Inserisci il tuo giorno di nascita: ");
    scanf("%d", &io.giorno);
    printf("Inserisci il tuo mese di nascita: ");
    scanf("%d", &io.mese);
    printf("Inserisci il tuo anno di nascita: ");
    scanf("%d", &io.anno);

    // Stampiamo tutto
    printf("Ti chiami %s %s e sei nato il %d/%d/%d ", io.nome, io.cognome, io.giorno, io.mese, io.anno);

    printf("\n\n");
    return 0;
}
