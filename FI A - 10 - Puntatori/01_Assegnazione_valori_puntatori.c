// NON si possono assegnare valori a un puntatore, salvo che in questi tre casi:
// 1. a un puntatore è assegnato il valore NULL (non punta a “niente”)
// 2. a un puntatore è assegnato l’indirizzo di una variabile esistente, restituito dall’operatore & ( Es. int a; int* p; p=&a; )
// 3. è eseguita un’operazione di allocazione dinamica della memoria

// Usiamo i puntatori per scambiare i valori contenuti in due variabili

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Dichiarazione delle variabili
    int temp;
    int a = 5; // Esempio di valore iniziale per 'a'
    int b = 10; // Esempio di valore iniziale per 'b'

    // Dichiarazione dei puntatori
    int* puntatore1;
    int* puntatore2;

    // Assegnazione degli indirizzi delle variabili ai puntatori
    puntatore1 = &a;
    puntatore2 = &b;

    // Scambio dei valori utilizzando i puntatori
    temp = *puntatore1;       // Salva il valore dell'indirizzo puntato in 'temp'
    *puntatore1 = *puntatore2; // Copia il valore puntato dal secondo puntatore nell'indirizzo puntato dal primo
    *puntatore2 = temp;       // Copia il valore salvato in 'temp' nell'indirizzo puntato dal secondo puntatore

    // Stampa dei risultati
    printf("Valore di a: %d\n", a);
    printf("Valore di b: %d\n", b);

    return 0;
}