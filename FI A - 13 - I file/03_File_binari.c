// Slide 41
// Salvare in un file binario dal nome numeri.dat gli interi contenuti in un array di dieci elementi

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Creiamo il file e il vettore
    FILE *file_4;
    int vet[10] = {1,2,3,4,5,6,7,8,9,10};

    // Verifichiamo se riusciamo ad aprirlo correttamente
    if ((file_4 = fopen("03_File_binari.dat","wb"))==NULL) {
        exit(1); /* Errore di apertura */
    }
    
    // Scriviamo nel file_4 10 elementi ognuno con dimensione sizeof(int) a partire da vet (il primo elemento)
    fwrite(vet, sizeof(int), 10, file_4);

    fclose(file_4);

    // Apertura del file in lettura binaria
    file_4 = fopen("03_File_binari.dat", "rb");
    if (file_4 == NULL) {
        printf("Errore nell'apertura del file in lettura.\n");
        exit(1);
    }

    int vet_letti[10];
    fread(vet_letti, sizeof(int), 10, file_4);

    printf("Valori letti dal file binario:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", vet_letti[i]);
    }
    printf("\n");

    fclose(file_4);

}