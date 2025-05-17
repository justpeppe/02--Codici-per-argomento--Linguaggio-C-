#include <stdio.h>      // Libreria standard per input/output
#include <stdlib.h>     // Libreria per allocazione dinamica della memoria
#include "01_Pila.h"    // Header file con la definizione della pila

// Crea una pila vuota
// Parametro: puntatore a stack (stack* pila) per modificare la pila principale
// Restituisce 0 (successo)
int crea_pila(stack* pila) {
    *pila = NULL;       // Inizializza la pila come vuota
    return 0;
}

// Inserisce un nuovo elemento in cima alla pila (push)
// Parametri: puntatore a stack (stack* pila) per modificare la pila, int elem valore da inserire
// Restituisce 0 se successo, 1 se errore di allocazione
int push(stack* pila, int elem) {
    stack new_top = (stack)malloc(sizeof(struct node)); // Alloca memoria per il nuovo nodo
    if (new_top == NULL) return 1;                      // Controlla se l'allocazione è andata a buon fine
    new_top->data = elem;                               // Assegna il valore al campo data
    new_top->next = *pila;                              // Collega il nuovo nodo alla vecchia cima
    *pila = new_top;                                    // Aggiorna la cima della pila
    return 0;                                           // Successo
}

// Estrae l'elemento in cima alla pila (pop)
// Parametri: puntatore a stack (stack* pila) per modificare la pila, puntatore a int (int* elem) dove salvare il valore estratto
// Restituisce 1 se la pila è vuota, 0 altrimenti
int pop(stack* pila, int* elem) {
    if (is_empty(*pila)) return 1;                      // Se la pila è vuota, restituisce 1
    *elem = (*pila)->data;                              // Salva il valore della cima in elem
    stack top = *pila;                                  // Salva il nodo da eliminare
    *pila = (*pila)->next;                              // Aggiorna la cima della pila
    free(top);                                          // Libera la memoria del nodo estratto
    return 0;                                           // Successo
}

// Verifica se la pila è vuota
// Parametro: stack pila (puntatore alla cima)
// Restituisce 1 se vuota, 0 altrimenti
int is_empty(stack pila) {
    return pila == NULL ? 1 : 0;
}

// Stampa tutti gli elementi della pila
// Parametro: stack pila (puntatore alla cima)
// Non modifica la pila
void print(stack pila) {
    if (is_empty(pila)) {
        printf("Pila vuota!\n");
        return;
    }
    printf("Pila attuale:\n");
    while (pila != NULL) {
        printf("%d\n", pila->data); // Stampa il valore del nodo corrente
        pila = pila->next;          // Passa al nodo successivo
    }
}