// Slide 53
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

struct node* ricerca(struct node* head, int key) {
    while ((head != NULL) && (head->data != key)) {
        head = head->next;
    }
    return head;
}

//trova e sostituisce un elemento esistente (ricerca esaustiva)
//restituisce 1 se l'elemento non c'è, 0 in caso di sostituzione con successo
int modifica(struct node* head, int elemento_da_trovare, int nuovo_valore) {
    //posso usare head per scorrere la lista perché è una copia
    //arrivo fino alla fine oppure fino a quando non ho trovato l'elemento
    while ((head != NULL) && (head->data != elemento_da_trovare)) {
        //scorro la lista
        head = head->next;
    }
    //se la lista era vuota oppure non ho trovato l'elemento
    if (head == NULL) {
        return 1;
    } else {
        //l'elemento esiste: sostituisco il valore
        head->data = nuovo_valore;
        //tutto è andato a buon fine
        return 0;
    }
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

    printf("Lista prima della modifica:\n");
    stampa(head);

    //modifico un elemento
    modifica(head, 12, 13);

    //stampo la lista modificata
    printf("\nLista dopo la modifica:\n");
    stampa(head);
}