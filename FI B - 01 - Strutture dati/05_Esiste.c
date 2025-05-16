// Slide 47
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

//verifica se l'elemento esiste oppure no (ricerca esaustiva)
//restituisce 1 se l'elemento non esiste, 0 altrimenti
int esiste(struct node* head, int key) {
    //posso usare head per scorrere la lista perché è una copia
    //scorro fino alla fine
    while (head != NULL) {
        //l'elemento contenuto nel nodo attuale è quello che sto cercando?
        if (head->data == key) {
            //se si allora restituisco 1
            return 1;
        } else {
            //se no vado al nodo successivo
            head = head->next;
        }
    }
    //sono arrivato alla fine della lista quindi l'elemento non esiste
    return 0;
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
    int result = esiste(head, 22);
    if(result) {
        printf("L'elemento %d esiste in lista!\n", 22);
    } else {
        printf("L'elemento %d non esiste in lista!\n", 22);
    }

    //ricerco un elemento che esiste
    result = esiste(head, 1);
    if(result) {
        printf("L'elemento %d esiste in lista!\n", 1);
    } else {
        printf("L'elemento %d non esiste in lista!\n", 1);
    }
}