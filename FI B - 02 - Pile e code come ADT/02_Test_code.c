#include <stdio.h>
#include <stdlib.h>
#include "02_Code.h"

int main() {
    queue coda = NULL;
    int ret, elem;

    // 1. Creazione della coda
    ret = crea_coda(&coda);
    if (ret != 0) {
        printf("Errore nella creazione della coda!\n");
        return 1;
    }
    printf("Coda creata.\n");
    print(coda);

    // 2. Verifica se la coda è vuota
    ret = is_empty(coda);
    printf("La coda è vuota? %s\n", (ret == 1) ? "Sì" : "No");

    // 3. Inserimento di elementi nella coda (enqueue)
    printf("Inserisco 10, 20, 30 nella coda...\n");
    enqueue(&coda, 10);
    enqueue(&coda, 20);
    enqueue(&coda, 30);
    print(coda);

    // 4. Verifica se la coda è vuota dopo inserimenti
    ret = is_empty(coda);
    printf("La coda è vuota? %s\n", (ret == 1) ? "Sì" : "No");

    // 5. Prelievo di un elemento dalla coda (dequeue)
    ret = dequeue(&coda, &elem);
    if (ret == 0)
        printf("Elemento prelevato dalla coda: %d\n", elem);
    else
        printf("Errore nel prelievo dalla coda!\n");
    print(coda);

    // 6. Altri prelievi
    dequeue(&coda, &elem);
    printf("Elemento prelevato: %d\n", elem);
    dequeue(&coda, &elem);
    printf("Elemento prelevato: %d\n", elem);

    // 7. Tentativo di prelievo da coda vuota
    ret = dequeue(&coda, &elem);
    if (ret == 1)
        printf("Impossibile prelevare: la coda è vuota.\n");

    // 8. Stampa finale
    print(coda);

    // 9. Verifica finale se la coda è vuota
    ret = is_empty(coda);
    printf("La coda è vuota? %s\n", (ret == 1) ? "Sì" : "No");

    // 10. Liberazione della memoria (opzionale, non implementata nell'ADT)
    free(coda);

    return 0;
}

