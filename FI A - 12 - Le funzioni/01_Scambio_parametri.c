// Le funzioni hanno come ingresso una copia dei parametri perciò non posso agire
// sui valori originali, dovremo utilizzare i riferimenti (puntatori)

// Riepilogo simboli * e &
// indirizzo = &x -> mi dice in che indirizzo è salvata la variabile x
// valore = *indirizzo -> vedo il valore contenuto nell'indirizzo puntato (e posso modificarlo)

// Facciamo un esempio di voler scambiare due parametri A e B
#include <stdio.h>

// Mettiamo come tipo void perchè la funzione non restituisce nessun valore
// Come parametri attuali passiamo gli indirizzi delle funzioni
// valoreA sarebbe indirizzoValoreA che poi grazie a * diventa il valore puntato

void scambio(int* valoreA, int* valoreB) {
    int temp;
    temp = *valoreA; //memorizzo ciò che c'è in A
    *valoreA = *valoreB; //tramite riferimento levo ciò che c'è nel valoreA e lo sostituisco col valoreB
    *valoreB = temp; //tramite riferimento levo ciò che c'è nel valoreB e lo sostituisco con temp
}

int main() {

    int input1, input2;

    printf("Inserisci il primo valore: ");
    scanf("%d", &input1);
    printf("Inserisci il secondo valore: ");
    scanf("%d", &input2);

    // Come parametri vanno passati gli indirizzi di memoria per modificare i valori
    scambio(&input1, &input2);

    printf("\nI due valori sono adesso %d e %d", input1,input2);

    printf("\n\n");
    return 0;
}