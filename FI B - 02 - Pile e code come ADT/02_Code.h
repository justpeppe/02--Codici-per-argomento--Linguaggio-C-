struct node{
    int data;
    struct node * next;
};

struct queue{
    struct node * head;
    struct node * tail;
};

typedef struct queue * queue;

int crea_coda(queue* coda); //creazione della coda

int enqueue(queue* coda, int elem); //inserimento in coda

int dequeue(queue* coda, int* elem); //prelievo dalla coda

int is_empty(queue coda); //la coda è vuota?

void print(queue coda); //stampo l'intera coda (solo per debug)