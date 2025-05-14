// Esempio slide 17
#include <stdio.h>
#include <stdlib.h>

int main() {

    // definiamo l'input
    char input;
    
    // Creiamo il file in scrittura (w -> crea il file in scrittura, se già presente elimina quello precedente)
    FILE* file_1 = fopen("00_input_e_file.txt", "w");

    printf("Scrivi il testo che vuoi inserire dentro il file:\n");

    if (file_1 == NULL) {
        // Se fopen restituisce NULL allora il disco o non ha memoria o è protetto da scrittura
        // Segnaliamo e usciamo
        printf("\nNon e\' stato possibile creare il file");
        return 0;
    }
    else {
        while((input = getchar()) != EOF) // EOF -> LINUX = Ctrl+D / WINDOWS = Ctrl+Z
        {
            // Finchè non inseriamo il carattere EOF inseriamo tutto ciò che
            // viene battuto dentro file 1
            fputc(input,file_1);
        }

        // Quando usciamo dal while liberiamo le risorse allocate chiudendo il file
        fclose(file_1);
    }

    printf("\n\n");
    return 0;
}