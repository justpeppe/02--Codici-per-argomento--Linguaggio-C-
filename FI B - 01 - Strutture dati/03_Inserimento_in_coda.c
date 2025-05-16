// Slide 43
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

int inserisci_testa (struct node** head, int elem){
    
    struct node* new_head = (struct node*)malloc(sizeof(struct node));
    
    if(new_head == NULL) return 1;

    new_head->data = elem;
    
    new_head->next = *head;
 
    *head = new_head;

    return 0;
}

//inserisce un elemento in coda alla lista
//restituisce 0 se tutto va a buon fine, 1 in caso contrario
//valgono le stesse considerazioni fatte per inserisci_testa
int inserisci_coda(struct node** head, int elem) {

    //puntatore di appoggio
    struct node* p;
    
    //alloco il nuovo nodo
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    
    //qualcosa è andato storto quindi restituisco 1
    if(new_node == NULL) return 1;
    
    //popolo il nuovo nodo con i dati
    new_node->data = elem;
    //lui sarà l'ultimo nodo quindi deve puntare a NULL
    new_node->next = NULL;
    
    //se la lista è vuota lui sarà anche il primo quindi la testa deve puntare a lui
    if(*head == NULL) {
        *head = new_node;
    } else {
        //inizio a scorrere partendo dalla testa
        p = *head;
    
        //scorro tutta la lista
        while(p->next != NULL) {
            p = p->next;
        }
    
        //inserisco in coda
        p->next = new_node;
    }
    
    //ho finito e tutto è andato a buon fine
    return 0;
}

int main() {
    
    //dichiaro un puntatore a struct node che punta a NULL (lista vuota)
    struct node* head = NULL;

    //inserisco un elemento in lista
    int result = inserisci_testa(&head, 3);

    //controllo il valore di ritorno
    if(result != 0) {
        printf("Errore nell'inserimento in testa\n");
        return 1;
    }

    //inserisco un elemento in coda
    result = inserisci_coda(&head, 12);

    //controllo il valore di ritorno
    if(result != 0) {
        printf("Errore nell'inserimento in coda\n");
        return 1;
    }


    //stampo la lista (uso un puntatore ausiliario altrimenti perdo la posizione della testa!)
    for(struct node* l = head; l != NULL; l = l->next) {
        printf("%d ", l->data);
    }

    printf("\n\n");
    return 0;
}