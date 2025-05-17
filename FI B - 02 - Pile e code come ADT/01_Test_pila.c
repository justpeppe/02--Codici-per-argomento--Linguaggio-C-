#include <stdio.h>
#include <stdlib.h>
#include "01_Pila.h"

int main() {
    stack pila;
    int elem, res;

    // Test creazione pila
    printf("Creo la pila...\n");
    crea_pila(&pila);
    if (is_empty(pila))
        printf("Pila creata correttamente (vuota).\n");
    else
        printf("Errore nella creazione della pila.\n");

    // Test push
    printf("\nInserisco 3 elementi (10, 20, 30)...\n");
    push(&pila, 10);
    push(&pila, 20);
    push(&pila, 30);
    print(pila);

    // Test is_empty
    printf("\nLa pila e' vuota? %s\n", is_empty(pila) ? "Si" : "No");

    // Test pop
    printf("\nEstraggo un elemento dalla pila...\n");
    res = pop(&pila, &elem);
    if (res == 0)
        printf("Elemento estratto: %d\n", elem);
    else
        printf("Errore: pila vuota!\n");
    print(pila);

    // Estraggo tutti gli elementi
    printf("\nEstraggo tutti gli elementi rimanenti...\n");
    while (!is_empty(pila)) {
        pop(&pila, &elem);
        printf("Estratto: %d\n", elem);
    }
    print(pila);

    // Test pop su pila vuota
    printf("\nProvo a estrarre da pila vuota...\n");
    res = pop(&pila, &elem);
    if (res == 1)
        printf("Pop fallito: pila vuota.\n");
    else
        printf("Errore: doveva fallire!\n");

    // Test print su pila vuota
    printf("\nStampa pila vuota:\n");
    print(pila);

    return 0;
}