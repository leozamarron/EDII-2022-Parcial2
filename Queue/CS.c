#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int info;
    struct nodo *sigNodo;
}*FILA;

int crearNodo(FILA *cab, int dato);
int insQueue(FILA *pri, FILA *ult, int dato);
void iniQueue(FILA *pri, FILA *ult);
int eliminaQueue(FILA *pri, FILA *ult, int *dato);

int main()
{
    FILA primero, ultimo;
    int r;
    int valor;

    iniQueue(&primero, &ultimo);
    r = insQueue(&primero, &ultimo, 7);
    r = insQueue(&primero, &ultimo, 9);
    r = insQueue(&primero, &ultimo, 4);
    r = insQueue(&primero, &ultimo, 2);

    r = eliminaQueue(&primero, &ultimo, &valor);
    r = eliminaQueue(&primero, &ultimo, &valor);
    r = eliminaQueue(&primero, &ultimo, &valor);
    r = eliminaQueue(&primero, &ultimo, &valor);

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

void iniQueue(FILA *pri, FILA *ult)
{
    *pri = *ult = NULL;
}

int insQueue(FILA *pri, FILA *ult, int dato) {
    int res = 0;
    FILA nuevo;
    res = crearNodo(&nuevo, dato);
    if (res) {
        if(*pri)
            (*pri)->sigNodo = nuevo;
        else
            *ult = nuevo;
        *pri = nuevo;
        res = 1;
    }
    return res;
}

int eliminaQueue(FILA *pri, FILA *ult, int *dato)
{
    FILA aux;
    int res = 0;
    if (*pri)
    {
        aux = *pri;
        *pri = aux->sigNodo;
        *dato = aux->info;
        free (aux);
        res = 1;
        if(!*pri)
            *ult = *pri;
    }
    return res;
}