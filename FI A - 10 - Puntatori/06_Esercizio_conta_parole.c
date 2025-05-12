// Slide 42
#include <stdio.h>
#include <string.h>

int main() {

    char frase[100];
    char *puntatore_frase = frase;
    int contatore = 0;

    printf("Inserisci una frase: ");
    fgets(frase, sizeof(frase), stdin);

    int i, lunghezza_frase = strlen(frase);
    
    for (i = 0; i < lunghezza_frase; i++)
    {
        if(frase[i] == ' ' || i == lunghezza_frase-1)
        {
            contatore++;
        }
    }

    printf("Il numero di parole e\': %d", contatore);

    printf("\n\n");
    return 0;
}