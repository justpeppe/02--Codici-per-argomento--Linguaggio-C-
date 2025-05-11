// Slide 30
#include <stdlib.h>
#include <stdio.h>

int main() {
    const int max = 10;
    int idx;
    char lettere[max];
    char elemento_corrente;
    int elementi = 0;
    int gia_presente;

    for (idx = 0; idx < max; idx++) {
        printf("Inserisci una lettera maiuscola: ");
        scanf(" %c", &elemento_corrente); 

        gia_presente = 0;
        for (int idx_check = 0; idx_check < elementi; idx_check++) {
            if (lettere[idx_check] == elemento_corrente) {
                printf("Lettera '%c' già presente.\n", elemento_corrente);
                gia_presente = 1;
                break; // Esci dal ciclo interno se la lettera è già presente ed evitiamo di finire tutto lo scorrimento
            }
        }

        if (gia_presente == 0) {
            lettere[elementi] = elemento_corrente;
            elementi++;
            printf("Lettera '%c' inserita correttamente.\n", elemento_corrente);
        }
    }

    printf("L'array contiene queste lettere diverse: ");
    for (idx = 0; idx < elementi; idx++) {
        printf("%c ", lettere[idx]);
    }
    printf("\n");

    return 0;
}