#include <stdio.h>
#include <stdlib.h>
#include "02_Code.h"

/*
 * Crea una coda vuota allocando la struttura
 * e inizializzando i puntatori head e tail a NULL.
 * Restituisce 1 in caso di problemi, 0 in caso contrario.
 */
int crea_coda(queue* coda) {
    *coda = (queue)malloc(sizeof(struct queue));
    if (*coda == NULL) return 1; // Errore di allocazione
    (*coda)->head = NULL;
    (*coda)->tail = NULL;
    return 0;
}

/*
 * Inserisce un nuovo elemento nella coda.
 * Restituisce:
 *   1 se non si può allocare la memoria del nuovo nodo,
 *   2 se il puntatore passato come parametro è NULL,
 *   0 se tutto va a buon fine.
 */
int enqueue(queue* coda, int elem) {
    if (coda == NULL || *coda == NULL) return 2; // La coda non è stata mai creata

    // Alloco il nuovo nodo per contenere l'elemento
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) return 1; // Errore di allocazione

    // Popolo il nuovo nodo con l'elemento
    new_node->data = elem;
    new_node->next = NULL; // Il nodo sarà l'ultimo in coda

    // Verifico se la coda è vuota
    if (is_empty(*coda) == 1) {
        // Se lo è, devo modificare anche head
        (*coda)->head = new_node;
    } else {
        // Se non lo è, collego il nuovo nodo in fondo
        (*coda)->tail->next = new_node;
    }
    // In entrambi i casi tail deve puntare al nuovo nodo
    (*coda)->tail = new_node;

    return 0; // Tutto è andato a buon fine
}

/*
 * Preleva l'elemento in testa alla coda e lo inserisce
 * nell'intero passato per riferimento come secondo parametro.
 * Restituisce:
 *   1 se la coda è vuota,
 *   2 se il puntatore passato come parametro è NULL,
 *   0 se tutto va a buon fine.
 */
int dequeue(queue* coda, int* elem) {
    if (coda == NULL || *coda == NULL) return 2; // La coda non è stata mai creata
    if (is_empty(*coda) == 1) return 1; // Coda vuota

    // Popolo elem con l'elemento in testa alla coda
    *elem = (*coda)->head->data;

    // Uso un puntatore di appoggio per tenere traccia del nodo da eliminare
    struct node* p = (*coda)->head;

    // Verifico se c'è un solo elemento in coda
    if ((*coda)->head->next == NULL) {
        // Se sì, devo modificare anche tail
        (*coda)->tail = NULL;
    }

    // Aggiorno la testa della coda
    (*coda)->head = (*coda)->head->next;

    // Libero la memoria del nodo che era in testa alla coda
    free(p);

    return 0; // Tutto è andato a buon fine
}

/*
 * Verifica se una coda è vuota.
 * Restituisce:
 *   1 se la coda è vuota,
 *   2 se il puntatore passato come parametro è NULL,
 *   0 in caso contrario.
 */
int is_empty(queue coda) {
    if (coda == NULL) return 2;
    if (coda->head == NULL && coda->tail == NULL)
        return 1;
    else
        return 0;
}

/*
 * Stampa il contenuto della coda.
 */
void print(queue coda) {
    if (coda == NULL) {
        printf("Coda non correttamente creata!\n");
        return;
    }

    if (is_empty(coda) == 1) {
        printf("Coda vuota!\n");
        return;
    }

    printf("Coda attuale:\n");

    // Uso un puntatore di appoggio per scorrere la coda senza modificarla
    struct node* p = coda->head;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}