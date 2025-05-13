#include <stdio.h>
#include <stdlib.h>

// Associamo un numero ad ogni identificativo
typedef enum {
    lun, mar, mer, gio, ven, sab, dom
} modello_giorni;

// Avremo che lun = 0, mar = 1, mer = 2; etc...