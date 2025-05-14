// Esempio slide 18
#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *file_2;
    char output;

    // Verifichiamo se riusciamo ad aprire il file
    if ((file_2 = fopen("01_Stampa_e_file.txt","r")) == NULL) {
        
        // Se non riusciamo ad aprirlo stampiamo errore e usciamo dal programma
        perror("Errore di apertura del file");
        return 0;
    } else {
        
        printf("Il file contiene questo testo:\n");
        while ((output = fgetc(file_2)) != EOF) {
            // Stampiamo carattere per carattere
            putchar(output);
        }
        // Liberiamo le risorse e chiudiamo il file
        fclose(file_2);
    }

    printf("\n\n");
    return 0;
}