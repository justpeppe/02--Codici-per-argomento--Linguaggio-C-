// Slide 50
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
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int esiste(struct node* head, int key) {
    while (head != NULL) {
        if (head->data == key) {
            return 1;
        } else {
            head = head->next;
        }
    }
    return 0;
}

//trova un elemento e ne restituisce il puntatore (ricerca esaustiva)
//restituisce NULL se l'elemento non c'è, altrimenti il puntatore al nodo trovato
struct node* ricerca(struct node* head, int key) {
    //posso usare head per scorrere la lista perché è una copia
    //arrivo fino alla fine oppure fino a quando non ho trovato l'elemento
    while ((head != NULL) && (head->data != key)) {
        //scorro la lista
        head = head->next;
    }
    //restituisco NULL oppure il puntatore al nodo contenente l'elemento cercato
    return head;
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

    //ricerco un elemento che non esiste
    struct node* elemento_trovato = ricerca(head, 22);
    if(elemento_trovato != NULL) {
        printf("L'elemento %d esiste in lista!\n", elemento_trovato->data);
    } else {
        printf("L'elemento non esiste in lista!\n");
    }

    //ricerco un elemento che esiste
    elemento_trovato = ricerca(head, 1);
    if(elemento_trovato != NULL) {
        printf("L'elemento %d esiste in lista!\n", elemento_trovato->data);
    } else {
        printf("L'elemento non esiste in lista!\n");
    }
}