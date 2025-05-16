// Slide 40
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

int inserisci_testa (struct node** head, int elem){
    //alloco il nuovo nodo
    struct node* new_head = (struct node*)malloc(sizeof(struct node));
    
    //qualcosa è andato storto quindi restituisco 1
    if(new_head == NULL) return 1;
    
    //popolo il nuovo nodo con i dati
    new_head->data = elem;
    
    //lui diventa il primo nodo e quindi deve puntare all'attuale testa (vale anche se la testa è NULL)
    new_head->next = *head;
    
    //la testa adesso deve puntare a lui (se era NULL ora non lo è più)
    *head = new_head;

    //tutto è andato a buon fine quindi restituisco 0
    return 0;
}

int main() {
    //dichiaro un puntatore a struct node che punta a NULL (lista vuota)
    struct node* head = NULL;

    //uso direttamente inserisci_testa anche se so che la lista è vuota
    int result = inserisci_testa(&head, 3);
    //inserisco un altro elemento in testa
    result = inserisci_testa(&head, 12);

    // Controllo il valore di ritorno della funzione inserisci_testa
    if (result != 0) {
        printf("Errore nell'inserimento in testa\n");
        return 1;
    }

    //stampo la lista
    for(struct node* l = head; l != NULL; l = l->next) {
        printf("%d ", l->data);
    }

    printf("\n\n");
    return 0;
}