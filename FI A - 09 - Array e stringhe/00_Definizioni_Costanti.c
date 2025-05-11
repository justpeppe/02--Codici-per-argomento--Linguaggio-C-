// Esempio di utilizzo della costante nel calcolo dell'area di un cerchio
#include <stdio.h>
#include <math.h>


// Come si definiscono le costanti in C? 
// Utilizziamo il comando #define per definire le costanti
// Definiziamo la costante PiGreco
#define PI 3.14159 


// Possiamo utilizzare anche const per definire le costanti
// Definizione di una costante con const
const float PI2 = 3.14159; 


int main() {
    // Dichiarazione delle variabili double cioè con virgola mobile
    float radius, area; 

    // Chiediamo all'utente di inserire il raggio del cerchio
    printf("Inserisci il raggio del cerchio: ");
    scanf("%f", &radius);

    // Calcoliamo l'area del cerchio utilizzando la costante PI
    area = PI * radius * radius;

    // Stampiamo l'area del cerchio
    printf("L'area del cerchio con raggio scelto %.2f è: %.2f\n", radius, area);

    return 0;
}