// Confrontare due parole e vedere carattere per carattere quale viene prima nell'alfabeto
#include <stdlib.h>
#include <stdio.h>

int main () {

    char parola1[] = "Maria";
    char parola2[] = "Marta";

    int i = 0, posizione;

    for (parola1[i] != '\0'; parola2[i] != '\0'; i++ ) 
    {
        posizione = parola1[i] - parola2[i];

        if(posizione > 0)
        {
            printf("Il carattere in posizione %d della parola 1 viene prima del carattere in posizione %d della parola 2\n", i, i);
        }
        else
        {
            if (posizione == 0)
            {
                printf("Il carattere in posizione %d della parola 1 e\' uguale al carattere in posizione %d della parola 2\n", i, i);
            }
            else
            {
                printf("Il carattere in posizione %d della parola 1 viene dopo del carattere in posizione %d della parola 2\n", i, i);
            }
            
        }
    }  


    return 0;
}