// Slide 29
#include <stdlib.h>
#include <stdio.h>

struct nodo{
    int dato;
    struct nodo* next;
};

int main(){

    //inizializzo la lista con il primo nodo che punta alla testa che è vuota
    struct nodo* head = NULL;

    //alloco l'ultimo nodo e lo aggancio a head
    struct nodo* n = (struct nodo*)malloc(sizeof(struct nodo));

    //inserisco il contenuto informativo
    n->dato = 24;

    //indico che il prossimo elemento sarà nullo
    n->next = NULL;
    
    //associo il valore corrente alla testa
    head = n;

    //alloco e inizializzo il penultimo nodo
    n = (struct nodo*)malloc(sizeof(struct nodo));

    //lui deve puntare all’attuale testa
    n->next = head;

    //ora head deve puntare a lui
    head = n;

    //e così via...
    n = (struct nodo*)malloc(sizeof(struct nodo));
    n-> dato = 12; n->next = head; head = n;
    
    n = (struct nodo*)malloc(sizeof(struct nodo));
    n-> dato = 2; n->next = head; head = n;
    
    n = (struct nodo*)malloc(sizeof(struct nodo));
    n-> dato = 7; n->next = head; head = n;
    
    n = (struct nodo*)malloc(sizeof(struct nodo));
    n-> dato = 3; n->next = head; head = n;

    //stampo la lista

    for(struct nodo* output_corrente = head; output_corrente != NULL; output_corrente = output_corrente->next) {
        printf("%d ", output_corrente->dato);
    }
    
    printf("\n");
}