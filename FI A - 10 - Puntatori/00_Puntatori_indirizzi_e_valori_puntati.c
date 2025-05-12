#include <stdio.h>

int main() {
    int valore_input; // Variabile intera che conterrà l'input dell'utente
    int *indirizzo_puntatore; // Dichiarazione di un puntatore a intero (memorizzerà un indirizzo)

    printf("Inserisci un numero da tastiera: ");
    scanf("%d", &valore_input); // Usiamo & per passare l'indirizzo di valore_input a scanf

    indirizzo_puntatore = &valore_input; // Assegniamo al puntatore l'indirizzo della variabile

    // Stampiamo l'indirizzo della variabile inserita da tastiera
    printf("L'indirizzo allocato è: %p\n", indirizzo_puntatore);

    // Stampiamo il valore puntato dall'indirizzo (usando l'operatore *)
    printf("Il valore contenuto all'indirizzo è: %d\n", *indirizzo_puntatore);

    return 0;
}
