// Slide 18
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int ID;
    char username[20];
    char password[20];
    float saldo;
} modello_conto;

int main() {

    modello_conto conto1;

    // Mettiamo dei valori
    conto1.ID = 1;
    strcpy(conto1.username, "justpeppe"); // Inseriamo il nome utente
    strcpy(conto1.password, "password"); // Inseriamo la password
    conto1.saldo = 100.0;

    // Facciamo l'accesso
    char input_username[20], input_password[20];
    printf("Inserisci il nome utente: ");
    scanf("%19s", input_username); // Limitiamo l'input a 19 caratteri
    printf("Inserisci la password: ");
    scanf("%19s", input_password); // Limitiamo l'input a 19 caratteri

    // Verifichiamo le condizioni
    if (strcmp(input_username, conto1.username) == 0 && strcmp(input_password, conto1.password) == 0) {
        printf("Accesso effettuato con successo!\n");
        int scelta = 0;
        while(scelta != 4) {
        printf("Scegli una tra queste operazioni:\n01) Vedi saldo\n02) Preleva\n03) Deposita \n04)Esci\n");
        
        scanf("%d", &scelta);
        
        switch (scelta) {
            case 1:
                printf("Il tuo saldo è: %.2f\n", conto1.saldo);
                break;
            case 2:
                printf("Inserisci quanto vuoi prelevare: ");
                float prelievo;
                scanf("%f", &prelievo); // Aggiunto &
                if (prelievo > conto1.saldo) {
                    printf("Saldo insufficiente!\n");
                } else {
                    conto1.saldo = conto1.saldo - prelievo;
                    printf("Prelievo effettuato. Nuovo saldo: %.2f\n", conto1.saldo);
                }
                break;
            case 3:
                printf("Inserisci quanto vuoi depositare: ");
                float deposito;
                scanf("%f", &deposito); // Aggiunto &
                conto1.saldo = conto1.saldo + deposito;
                printf("Deposito effettuato. Nuovo saldo: %.2f\n", conto1.saldo);
                break;
            case 4:
                printf("Uscita effettuata correttamente");
                break;

            default:
                printf("Operazione non valida.\n");
        }
    }
    } else {
        printf("Nome utente o password errati.\n");
    }

    printf("\n\n");
    return 0;
}