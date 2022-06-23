#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct nodo{
  int info;
  struct nodo *sigNodo;
}*LISTA;

void iniLista(LISTA *cab);
int insIniCirc(LISTA *cab, int dato);
int creaNodo(LISTA *cab, int dato);
int insIniCirc(LISTA *cab, int dato);
int capturaLista(LISTA *cab);
void muestraLista(LISTA cab);
int elimIni(LISTA *cab);

int main()
{
  LISTA lista;
  iniLista(&lista);
  capturaLista(&lista);
  muestraLista(lista);
  elimIni(&lista);

  return 0;
}

void iniLista(LISTA *cab)
{
  *cab = NULL;
}

int creaNodo(LISTA *cab, int dato) {
  int res = 0;
  *cab = (LISTA)malloc(sizeof(struct nodo));

  if (*cab) {
    (*cab)->info = dato;
    (*cab)->sigNodo = NULL;
    res = 1;
  }
  return res;
}

int insIniCirc(LISTA *cab, int dato)
{
  int res;
  LISTA nuevo, aux;
  res = creaNodo(&nuevo, dato);
  if(res)
  {
    nuevo->sigNodo = *cab;
    if(!*cab)
      nuevo->sigNodo = nuevo;
    else{
      aux = *cab;
      while(aux->sigNodo != *cab)
        aux = aux->sigNodo;
      aux->sigNodo = nuevo;
    }
    *cab = nuevo;
  }
}

int capturaLista(LISTA *cab) {
  int res, dato;
  char resP;

  do {
    printf("dato: ");
    scanf("%d", &dato);
    res = insIniCirc(cab, dato);
    if (res) {
      printf("otro? ");
      scanf(" %c", &resP);
    }
  } while(res && (resP == 's' || resP == 'S'));
  return res;
}

void muestraLista(LISTA cab)
{
  LISTA aux;
  aux = cab;
  for(; cab->sigNodo != aux; cab = cab->sigNodo)
    printf("%d ", cab->info);
  printf("%d ", cab->info);
}

int elimIni(LISTA *cab) 
{
  int res = 0;
  LISTA aux;

  if(*cab)
  {
    aux = *cab;
    while (aux->sigNodo != *cab)
      aux = aux->sigNodo;
    if(*cab == (*cab)->sigNodo)
      *cab = NULL;
    else
      *cab = (*cab)->sigNodo;
    res = aux->sigNodo->info;
    free(aux->sigNodo);
    aux->sigNodo = *cab;
  }
  return res;
}