// Slide 45
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

int inserisci_testa(struct node** head, int elem) {
    struct node* new_head = (struct node*)malloc(sizeof(struct node));
    if (new_head == NULL) return 1;
    new_head->data = elem;
    new_head->next = *head;
    *head = new_head;
    return 0;
}

int inserisci_coda(struct node** head, int elem) {
    struct node* p;
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) return 1;
    new_node->data = elem;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
    } else {
        p = *head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = new_node;
    }
    return 0;
}

void stampa(struct node* head) {
    //non restituisce nulla
    //posso usare head per scorrere la lista
    //scorro fino alla fine e stampo
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    //dichiaro una lista vuota
    struct node* head = NULL;

    //inserisco qualche elemento in lista
    //non verifico se tutto va a buon fine
    inserisci_testa(&head, 3);
    inserisci_testa(&head, 12);
    inserisci_testa(&head, 1);
    inserisci_testa(&head, 32);

    //stampo la lista
    stampa(head);

    printf("\n\n");
}