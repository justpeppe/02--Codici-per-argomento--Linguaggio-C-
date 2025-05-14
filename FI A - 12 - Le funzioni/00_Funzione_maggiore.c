// Creiamo una funzione che restituisce quale dei due interi è più grande
#include <stdio.h>

// la funzione restituisce un intero perciò va dichiarata come int
// come parametri locali avremo due interi
int maggiore(int valore1, int valore2) {

    int massimo;

    if (valore1 > valore2)
    {
        massimo = valore1;
    }
    else {
        massimo = valore2;
    }

    // mettiamo come valore di ritorno il massimo
    return massimo; 
}

// Utilizziamola

int main() {

    int input1, input2, risultato;

    printf("Inserisci il primo valore: ");
    scanf("%d", &input1);
    printf("Inserisci il secondo valore: ");
    scanf("%d", &input2);

    // input1 e input2 sono i nostri parametri attuali che passeremo alla funzione
    // questo passaggio viene fatto senza puntatori perciò viene detto "passaggio per valore"
    risultato = maggiore(input1,input2); 
    // nota che il valore restituito da maggiore è int come anche risultato, se fossero stati diversi avremmo avuto problemi

    printf("\nIl valore più grande e\' %d", risultato);

    printf("\n\n");
    return 0;
}