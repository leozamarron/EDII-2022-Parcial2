#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    struct nodo *antNodo;
    int info;
    struct nodo *sigNodo;
}*LISTA;

typedef struct{
    LISTA frente;
    LISTA final;
}FILA_CAB;

void iniLista(FILA_CAB *id);
int creaNodo2(LISTA *nodo, int dato);
int insIni(FILA_CAB *cab, int dato);
int insFin(FILA_CAB *cab, int dato);
int insRef(FILA_CAB *cab, int dato, int ref);
void recorre(FILA_CAB cab, int dir);
void recorre2(FILA_CAB cab);

int main()
{
    FILA_CAB fila;

    iniLista(&fila);
    insIni(&fila, 20);
    insIni(&fila, 10);
    insIni(&fila, 30);

    recorre2(fila);

    return 0;
}

void iniLista(FILA_CAB *id)
{
    id->frente = id->final = NULL;
}

// Creacion de un nodo doble
int creaNodo2(LISTA *nodo, int dato)
{
    int res = 0;
    *nodo = (LISTA)malloc(sizeof(struct nodo));

    if(*nodo)
    {
        (*nodo)->antNodo = NULL;
        (*nodo)->sigNodo = NULL;
        (*nodo)->info = dato;
        res = 1;
    }
    return res;
}

int insIni(FILA_CAB *cab, int dato)
{
    int res;
    LISTA nuevo;
    res = creaNodo2(&nuevo, dato);
    if (res)
    {
        nuevo->sigNodo = cab->frente;
        if(!cab->frente)
            cab->final = nuevo;
        else
            cab->frente->antNodo = nuevo;
    cab->frente = nuevo;
    }
    return res;
}

int insFin(FILA_CAB *cab, int dato)
{
    int res;
    LISTA nuevo;
    res = creaNodo2(&nuevo, dato);
    if(res)
    {
        nuevo->antNodo = cab->final;
        if(!cab->frente)
            cab->frente = nuevo;
        else 
            cab->final->sigNodo = nuevo;
        cab->final = nuevo;
    }
    return res;
}

int insRef(FILA_CAB *cab, int dato, int ref)
{
    int res = 0;
    LISTA aux, nuevo;

    aux = cab->frente;
    while (aux && res != aux->info)
        aux = aux->sigNodo;
    if(aux)
    {
        res = creaNodo2(&nuevo, dato);
        if(res)
        {
            nuevo->sigNodo = aux;
            nuevo->antNodo = aux->antNodo;
            aux->antNodo = nuevo;
            if(cab->frente == aux)
                cab->frente = nuevo;
            else
                nuevo->antNodo->sigNodo = nuevo;
        }
    }
    return res;
}

void recorre(FILA_CAB cab, int dir)
{
    LISTA aux;

    aux = dir? cab.frente:cab.final;

    while (aux)
    {
        printf("%d ", aux->info);
        aux = dir? aux->sigNodo:aux->antNodo;
    }
}

void recorre2(FILA_CAB cab)
{
    char resp;
    LISTA aux;

    aux = rand()%2? cab.frente:cab.final;

    do
    {
        printf("%d\n", aux->info);
        printf("Hacia donde?");
        scanf(" %c", &resp); //i-izquierda, d-derecha, s-salida
        if(resp == 'd' && aux->sigNodo)
            aux = aux->sigNodo;
        else if(resp == 'i' && aux->antNodo)
            aux = aux->antNodo;
    } while (resp != 's');
}