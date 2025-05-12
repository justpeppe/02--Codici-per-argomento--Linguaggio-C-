// Slide 72
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Creiamo due vettori uno di 3 e l'altro di 2 interi con malloc
    int *vettoreA = NULL;
    vettoreA = (int *)malloc(3*sizeof(int));
    int *vettoreB = NULL;
    vettoreB = (int *)malloc(2*sizeof(int));

    // Riempiamo questi vettori
    *vettoreA = 1;
    *(vettoreA+1) = 2;
    *(vettoreA+2) = 3;
    *(vettoreB) = 4;
    *(vettoreB+1) = 5;

    // Creiamo il nuovo array
    int *vettoreC = NULL;
    int dimensione1 = 3, dimensione2 = 2 ;
    vettoreC = (int *)malloc((dimensione1+dimensione2)*sizeof(int));

    //Riempiamolo
    int indiceA, indiceB, indiceC;

    // Inseriamo prima il vettore A e poi il vettore B
    for (indiceC = 0; indiceC < (dimensione1+dimensione2); indiceC++)
    {
        for(indiceA = 0; indiceA < dimensione1; indiceA++)
        {
            *(vettoreC+indiceC) = vettoreA[indiceA];
            indiceC++;
        }

        for(indiceB = 0; indiceB < dimensione2; indiceB++)
        {
            *(vettoreC+indiceC) = vettoreB[indiceB];
            indiceC++;
        }
    }

    // Stampiamo il vettore
    printf("Il vettore C e\' il seguente: ");
    for(indiceC = 0; indiceC < (dimensione1+dimensione2); indiceC++)
    {
        printf("%d", vettoreC[indiceC]);
    }

    printf("\n\n");
    return 0;
}