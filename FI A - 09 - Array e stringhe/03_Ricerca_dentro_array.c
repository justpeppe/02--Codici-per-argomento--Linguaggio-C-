// Cerchiamo un elemento in un array di interi
#include <stdio.h>
#include <stdlib.h>

// Definizione dell'array di numeri casuali
int elementi[] = { 76, 23, 45, 12, 89, 34, 56, 78, 90, 11 };

// Funzione per cercare un elemento nell'array
int cercaElemento(int array[], int dimensione, int elemento) {
    for (int i = 0; i < dimensione; i++) {
        if (array[i] == elemento) {
            return i; // Restituisce l'indice dell'elemento trovato
        }
    }
    return -1; // Restituisce -1 se l'elemento non è stato trovato
}

int main() {
    // Dichiarazione della variabile per l'elemento da cercare
    int elementoDaCercare;
    
    // Chiediamo all'utente di inserire l'elemento da cercare
    printf("Inserisci l'elemento da cercare: ");
    scanf("%d", &elementoDaCercare);
    
    // Chiamata alla funzione per cercare l'elemento nell'array con argomenti 
    // array, dimensione e elemento da cercare
    int indice = cercaElemento(elementi, 10, elementoDaCercare);
    
    // Verifica se l'elemento è stato trovato
    if (indice != -1) {
        printf("Elemento %d trovato in posizione %d\n", elementoDaCercare, indice);
    } else {
        printf("Elemento %d non trovato nell'array\n", elementoDaCercare);
    }
    
    return 0;
}