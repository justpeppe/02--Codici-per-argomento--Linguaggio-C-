// Slide 17
#include <stdio.h>
#include <stdlib.h>

struct punto{

    float coordinata_x, coordinata_y;
};

int main() {

    struct punto p1, p2;

    printf("Inserisci la coordinata X del punto 1: ");
    scanf("%f", &p1.coordinata_x);
    printf("Inserisci la coordinata Y del punto 1: ");
    scanf("%f", &p1.coordinata_y);
    printf("Inserisci la coordinata X del punto 2: ");
    scanf("%f", &p2.coordinata_x);
    printf("Inserisci la coordinata Y del punto 2: ");
    scanf("%f", &p2.coordinata_y);

    

    if (p1.coordinata_x == p2.coordinata_x && p1.coordinata_y == p2.coordinata_y)
    {
        printf("I due punti coincidono");
    }
    else 
    {
        if (p1.coordinata_x == p2.coordinata_x)
        {
            printf("I due punti hanno la stessa asse X");
        }

        if (p1.coordinata_y == p2.coordinata_y)
        {
            printf("I due punti hanno la stessa asse Y");
        }
    }

    printf("\n\n");
    return 0;
}