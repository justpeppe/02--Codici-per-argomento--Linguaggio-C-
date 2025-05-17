#include <stdio.h>      // Inclusione della libreria standard per input/output
#include <stdlib.h>     // Inclusione della libreria standard per funzioni di allocazione dinamica

// Definizione della struttura node per la lista collegata
struct node {
    int data;               // Campo che contiene il dato (intero) del nodo
    struct node* next;      // Puntatore al nodo successivo nella lista (NULL se ultimo nodo)
};

// Funzione per inserire un elemento in testa alla lista
// Parametri: doppio puntatore a head (struct node** head) per modificare il puntatore della lista principale, int elem è il valore da inserire
// Restituisce 0 se successo, 1 se errore di allocazione
int inserisci_testa(struct node** head, int elem) {
    struct node* new_head = (struct node*)malloc(sizeof(struct node)); // Alloca memoria per il nuovo nodo
    if (new_head == NULL) return 1;                                    // Controlla se l'allocazione è andata a buon fine
    new_head->data = elem;                                             // Assegna il valore al campo data
    new_head->next = *head;                                            // Collega il nuovo nodo al vecchio primo nodo
    *head = new_head;                                                  // Aggiorna il puntatore head al nuovo nodo
    return 0;                                                          // Restituisce 0 per successo
}

// Funzione per inserire un elemento in coda alla lista
// Parametri: doppio puntatore a head per modificare la lista, int elem è il valore da inserire
// Restituisce 0 se successo, 1 se errore di allocazione
int inserisci_coda(struct node** head, int elem) {
    struct node* p;                                                    // Puntatore di appoggio per scorrere la lista
    struct node* new_node = (struct node*)malloc(sizeof(struct node)); // Alloca memoria per il nuovo nodo
    if (new_node == NULL) return 1;                                    // Controlla allocazione
    new_node->data = elem;                                             // Assegna il valore
    new_node->next = NULL;                                             // Il nuovo nodo sarà l'ultimo, quindi next = NULL
    if (*head == NULL) {                                               // Se la lista è vuota
        *head = new_node;                                              // Il nuovo nodo diventa la testa
    } else {
        p = *head;                                                     // Altrimenti scorre la lista fino all'ultimo nodo
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = new_node;                                            // Collega il nuovo nodo in fondo
    }
    return 0;                                                          // Restituisce 0 per successo
}

// Funzione per stampare tutti gli elementi della lista
// Parametro: puntatore a head (struct node* head), non modifica la lista
void stampa(struct node* head) {
    while (head != NULL) {                                             // Scorre la lista fino alla fine
        printf("%d ", head->data);                                     // Stampa il campo data del nodo corrente
        head = head->next;                                             // Passa al nodo successivo
    }
    printf("\n");                                                      // Va a capo dopo la stampa
}

// Funzione che verifica se un elemento esiste nella lista
// Parametri: puntatore a head, int key da cercare
// Restituisce 1 se trovato, 0 altrimenti
int esiste(struct node* head, int key) {
    while (head != NULL) {                                             // Scorre la lista
        if (head->data == key) {                                       // Se trova il valore
            return 1;                                                  // Restituisce 1
        } else {
            head = head->next;                                         // Altrimenti passa al prossimo nodo
        }
    }
    return 0;                                                          // Non trovato, restituisce 0
}

// Funzione che restituisce il puntatore al nodo che contiene key
// Parametri: puntatore a head, int key da cercare
// Restituisce il puntatore al nodo se trovato, NULL altrimenti
struct node* ricerca(struct node* head, int key) {
    while ((head != NULL) && (head->data != key)) {                    // Scorre la lista finché non trova il valore o arriva alla fine
        head = head->next;
    }
    return head;                                                       // Restituisce il nodo trovato o NULL
}

// Funzione per inserire un elemento in modo ordinato (crescente) nella lista
// Parametri: doppio puntatore a head per modificare la lista, int elem da inserire
// Restituisce 0 se successo, 1 se errore di allocazione
int inserisci_ordinato(struct node** head, int elem) {
    struct node* r = *head;                                            // Puntatore al nodo precedente
    struct node* q = *head;                                            // Puntatore al nodo corrente
    struct node* new_node = (struct node*)malloc(sizeof(struct node)); // Alloca memoria per il nuovo nodo
    if (new_node == NULL) return 1;                                    // Controlla allocazione
    new_node->data = elem;                                             // Assegna il valore
    new_node->next = NULL;                                             // Imposta next a NULL
    while ((q != NULL) && (q->data < elem)) {                          // Trova la posizione corretta
        r = q;
        q = q->next;
    }
    if (q == *head) {                                                  // Se deve essere inserito in testa
        new_node->next = *head;
        *head = new_node;
    } else {                                                           // Inserisce tra r e q
        r->next = new_node;
        new_node->next = q;
    }
    return 0;                                                          // Restituisce 0 per successo
}

// Funzione per cancellare un elemento dalla lista
// Parametri: doppio puntatore a head per modificare la lista, int elem da cancellare
// Restituisce 0 se successo, 1 se elemento non trovato
int cancella(struct node** head, int elem) {
    struct node* r = *head;                                            // Puntatore al nodo precedente
    struct node* q = *head;                                            // Puntatore al nodo corrente
    while ((q != NULL) && (q->data != elem)) {                         // Cerca il nodo da cancellare
        r = q;
        q = q->next;
    }
    if (q == NULL) {                                                   // Se non trovato
        return 1;                                                      // Restituisce 1
    }
    if (q == *head) {                                                  // Se è il primo nodo
        *head = (*head)->next;                                         // Aggiorna la testa
    } else {
        r->next = q->next;                                             // Collega il precedente al successivo
    }
    free(q);                                                           // Libera la memoria del nodo cancellato
    return 0;                                                          // Restituisce 0 per successo
}

// Funzione principale
int main() {
    struct node* head = NULL;                                          // Inizializza la lista come vuota (head = NULL)

    // Inserimento in testa
    inserisci_testa(&head, 3);                                         // Inserisce 3 in testa
    inserisci_testa(&head, 12);                                        // Inserisce 12 in testa
    inserisci_testa(&head, 1);                                         // Inserisce 1 in testa
    inserisci_testa(&head, 32);                                        // Inserisce 32 in testa

    printf("Lista dopo inserimenti in testa:\n");
    stampa(head);                                                      // Stampa la lista

    // Inserimento in coda
    inserisci_coda(&head, 99);                                         // Inserisce 99 in coda
    inserisci_coda(&head, 7);                                          // Inserisce 7 in coda

    printf("Lista dopo inserimenti in coda:\n");
    stampa(head);                                                      // Stampa la lista

    // Inserimento ordinato
    inserisci_ordinato(&head, 10);                                     // Inserisce 10 in ordine
    inserisci_ordinato(&head, 2);                                      // Inserisce 2 in ordine

    printf("Lista dopo inserimenti ordinati:\n");
    stampa(head);                                                      // Stampa la lista

    // Ricerca di un elemento
    struct node* elemento_trovato = ricerca(head, 22);                 // Cerca 22 nella lista
    if(elemento_trovato != NULL) {
        printf("L'elemento %d esiste in lista!\n", elemento_trovato->data);
    } else {
        printf("L'elemento 22 non esiste in lista!\n");
    }

    // Verifica esistenza
    if(esiste(head, 99)) {                                             // Verifica se 99 esiste
        printf("L'elemento 99 esiste in lista!\n");
    } else {
        printf("L'elemento 99 non esiste in lista!\n");
    }

    // Cancellazione di un elemento
    if(cancella(&head, 12) == 0) {                                     // Cancella 12 dalla lista
        printf("Elemento 12 cancellato con successo.\n");
    } else {
        printf("Elemento 12 non trovato per la cancellazione.\n");
    }

    printf("Lista dopo cancellazione di 12:\n");
    stampa(head);                                                      // Stampa la lista

    // Cancellazione di un elemento non presente
    if(cancella(&head, 100) == 0) {                                   // Prova a cancellare 100 (non presente)
        printf("Elemento 100 cancellato con successo.\n");
    } else {
        printf("Elemento 100 non trovato per la cancellazione.\n");
    }

    // Libera la memoria residua
    while (head != NULL) {                                             // Scorre la lista
        struct node* tmp = head;                                       // Salva il nodo corrente
        head = head->next;                                             // Passa al prossimo nodo
        free(tmp);                                                     // Libera la memoria del nodo corrente
    }

    return 0;                                                          // Termina il programma
}