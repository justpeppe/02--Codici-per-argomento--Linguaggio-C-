#include <string.h>
#include <stdio.h>

int main() {

    // Definiamo due stringhe come array di caratteri
    char stringa1[] = "parola";
    char stringa2[] = "ciao";

    // Stampiamole
    puts(stringa1);
    puts(stringa2);

    // Leggiamo la lunghezza delle due parole
    int lunghezza1 = strlen(stringa1);
    int lunghezza2 = strlen(stringa2);

    // Stampiamo la lunghezza
    printf("\n");
    printf("La prima parola e\' composta da %d caratteri\n", lunghezza1);
    printf("La seconda parola e\' composta da %d caratteri\n", lunghezza2);

    // Sostituiamo la prima stringa con la seconda
    printf("\n");
    printf("Con strcpy la seconda stringa viene copiata nella prima: %s\n", strcpy(stringa1,stringa2));
    printf("Adesso le due stringhe sono uguali: %s %s\n", stringa1, stringa2);

    // Inizializziamo di nuovo tutto correttamente
    char stringa3[30] = "parola"; // mi serve un array più grande che poi possa contenere lunghezza1+lunghezza2 elementi
    char stringa4[] = "ciao";
     
    // Concateniamo le due stringhe
    printf("\n");
    printf("Con strcat concateniamo le due stringe: %s", strcat(stringa3,stringa4) );

    printf("\n\n");
    return 0;
}