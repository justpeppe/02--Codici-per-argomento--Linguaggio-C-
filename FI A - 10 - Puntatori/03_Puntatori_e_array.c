#include <stdio.h>
#include <stdlib.h>

int main() {
    char v[4] = {'m', 'e', 'l', 'a'};
    char *p;
    p = v; // Il puntatore punta all'inizio dell'array
    p++;   // Incrementa il puntatore per puntare al secondo elemento
    printf("%c\n", *p); // Stampa il carattere puntato da 'p' con posizione p++ (quindi la e in posizione 1)
    return 0;
}