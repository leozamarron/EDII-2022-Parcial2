#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int info;
    struct nodo *sigNodo;
}*PILA;

int crearNodo(PILA *cab, int dato);
int push(PILA *cab);
void setup(PILA *f);
int pop(PILA *f);

int main()
{
    PILA Pila;
    int r;
    int valor;

    setup(&Pila);
    r = push(&Pila);
    r = push(&Pila);
    r = push(&Pila);
    r = push(&Pila);

    r = pop(&Pila);
    r = pop(&Pila);
    r = pop(&Pila);
    r = pop(&Pila);

    return 0;
}

int crearNodo(PILA *cab, int dato) {
    int res = 0;
    *cab = (PILA)malloc(sizeof(struct nodo));

    if (*cab) {
        (*cab)->info = dato;
        (*cab)->sigNodo = NULL;
        res = 1;
    }
    return res;
}

void setup(PILA *cab)
{
    *cab = NULL;
}

int push(PILA *cab) {
    int res = 0;
    int dato;

    printf("Dame un dato: ");
    scanf("%d", &dato);

    PILA nuevo;
    res = crearNodo(&nuevo, dato);
    if (res) {
        nuevo->sigNodo = *cab;
        *cab = nuevo;
        res = 1;
    }
    return res;
}

int pop(PILA *cab)
{
    int res = 0;
    PILA aux;

    if(*cab)
    {
        aux = *cab;
        *cab = aux->sigNodo;
        res = aux->info;
        free(aux);
        printf("El dato que salio fue: %d\n", res);
    }
    return res;
}