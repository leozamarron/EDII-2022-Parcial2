#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int info;
    struct nodo *sigNodo;
}*FILA;

typedef struct 
{
    FILA frente;
    FILA final;
}FILA_CA; //Filas agrupadas

int crearNodo(FILA *cab, int dato);
int insQueue(FILA_CA *cab, int dato);
void iniQueueCA(FILA_CA *f);
int eliminaQueueCA(FILA_CA *f, int *dato);

int main()
{
    FILA_CA queue;
    int r;
    int valor;

    iniQueueCA(&queue);
    r = insQueue(&queue, 7);
    r = insQueue(&queue, 9);
    r = insQueue(&queue, 4);
    r = insQueue(&queue, 2);

    r = eliminaQueueCA(&queue, &valor);
    r = eliminaQueueCA(&queue, &valor);
    r = eliminaQueueCA(&queue, &valor);
    r = eliminaQueueCA(&queue, &valor);

    return 0;
}

int crearNodo(FILA *cab, int dato) {
    int res = 0;
    *cab = (FILA)malloc(sizeof(struct nodo));

    if (*cab) {
        (*cab)->info = dato;
        (*cab)->sigNodo = NULL;
        res = 1;
    }
    return res;
}

void iniQueueCA(FILA_CA *f)
{
    f->frente = f->final = NULL;
}

int insQueue(FILA_CA *cab, int dato) {
    int res = 0;
    FILA nuevo;
    res = crearNodo(&nuevo, dato);
    if (res) {
        if(cab->frente)
            cab->final->sigNodo = nuevo;
        else
            cab->frente = nuevo;
        cab->final = nuevo;
        res = 1;
    }
    return res;
}

int eliminaQueueCA(FILA_CA *f, int *dato)
{
    FILA aux;
    int res = 0;
    if (f->frente)
    {
        aux = f->frente;
        f->frente = aux->sigNodo;
        *dato = aux->info;
        free (aux);
        res = 1;
        if(!f->frente)
            f->final = f->frente;
    }
    return res;
}