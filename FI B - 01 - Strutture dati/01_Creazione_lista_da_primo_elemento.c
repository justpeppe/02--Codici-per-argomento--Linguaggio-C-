#include <stdio.h>
#include <stdlib.h>

// Slide 35
struct node{
    int data;
    struct node* next;
};

//crea una nuova lista dal suo primo elemento (prima implementazione)
//restituisce NULL in caso di fallimento, un puntatore alla testa della lista in caso contrario
struct node* crea_lista_1 (int elem){
    //alloco il nuovo nodo
    struct node* new_head = (struct node*)malloc(sizeof(struct node));
    //qualcosa e' andato storto quindi restituisco NULL
    if (new_head == NULL) return NULL;
    //popolo il nuovo nodo con i dati
    new_head->data=elem;
    //è il primo nodo ma anche l'ultimo quindi deve puntare a NULL
    new_head->next=NULL;
    //è il primo nodo quindi ne restituisco il puntatore che diventerà la testa
    return new_head;
}

// Funzione di stampa della lista
void stampa_lista(struct node* head) {
    struct node* current = head;
    while(current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main(){
    //dichiaro un puntatore a struct node che punta a NULL (lista vuota)
    struct node* head = NULL;
    //invoco la funzione per creare la lista dal suo primo elemento (l’intero 3)
    head = crea_lista_1(3);
    //verifico se c’è stato qualche errore
    if(head == NULL){
        printf("C'è stato un errore!");
        exit(1);
    }
    //se non c’è stato alcun errore allora adesso head punta alla testa della lista
    //stampo la lista
    stampa_lista(head);

    // Libero la memoria allocata
    free(head);

    return 0;
}
