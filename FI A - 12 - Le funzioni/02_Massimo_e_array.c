// Slide 49
#include <stdio.h>

// Per assicurarci che la funzione non modifichi i valori mettiamo const così
// se dovesse succedere restituisce errore
int trovaMassimo (const int* v, int dim) {   
    int massimo = 0, i;
    for (i = 0; i < dim; i++)
    {
        if (massimo < v[i])
        {
            massimo = v[i];
        }
    }
    return massimo;
};

int main() {

    int risultato, v[] = { 10, 5, 15, 0};

    risultato = trovaMassimo(v,4);

    printf("Il valore piu\' grande e\': %d", risultato);

    printf("\n\n");
    return 0;
}
