struct node{
    int data;
    struct node * next;
};

typedef struct node * stack;

int crea_pila(stack* pila); //creazione della pila

int push(stack* pila, int elem); //inserimento in pila

int pop(stack* pila, int* elem); //prelievo dalla pila

int is_empty(stack pila); //la pila è vuota?

void print(stack pila); //stampo l'intera pila (solo per debug)