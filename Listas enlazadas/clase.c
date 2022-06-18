#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct nodo{
  int clientes;
  struct nodo *puntero;
}*LISTA;

void iniLista(LISTA *cab);
int creaNodo(LISTA *cab, int dato);
int insIni(LISTA *cab, int dato);
int capturaLista(LISTA *cab);
void muestraLista(LISTA cab);

int main() {
  LISTA lista;
  iniLista(&lista);
  capturaLista(&lista);
  muestraLista(lista);

  return 0;
}

void iniLista(LISTA *cab) {
  *cab = NULL;
}

int creaNodo(LISTA *cab, int dato) {
  int res = 0;
  *cab = (LISTA)malloc(sizeof(struct nodo));

  if (*cab) {
    (*cab)->clientes = dato;
    (*cab)->puntero = NULL;
    res = 1;
  }
  return res;
}

int insIni(LISTA *cab, int dato) {
  int res = 0;
  LISTA nuevo;
  res = creaNodo(&nuevo, dato);
  if (res) {
    nuevo->puntero = *cab;
    *cab = nuevo;
  }
  return res;
}

int capturaLista(LISTA *cab) {
  int res, dato;
  char resP;

  do {
    printf("dato: ");
    scanf("%d", &dato);
    res = insIni(cab, dato);
    if (res) {
      printf("otro? ");
      scanf(" %c", &resP);
    }
  } while(res && (resP == 's' || resP == 'S'));
  return res;
}

void muestraLista(LISTA cab) 
{
  for(; cab; cab = cab->puntero)
    printf("%d ", cab->clientes);
}

int cuentaLista(LISTA cab) //Peso - cantidad de elementos
{
  int i = 0;
  for(; cab; i++, cab = cab->puntero);
  return i;
}

int costo(LISTA cab) //Costo - suma iterativo
{
  int suma = 0;

  for(; cab; cab = cab->puntero)
    suma += cab->clientes;
  return suma;
}

void costoListaCadena(LISTA cab, char *frase) // para juntar cadenas
{
  frase[0] = '/0';
  while (cab)
  {
    strcat(frase, cab->clientes);
    strcat(frase, " ");
    cab = cab->puntero;
  }
}

int buscaLista(LISTA cab, int buscado) // busca la lista de forma iterativa
{
  int res = 0;
  while (cab && buscado != cab->clientes)
    cab = cab->puntero;
  if(cab)
    res = 1;
  return res;  
}

void incrementa(LISTA cab, int h) //incrementa los datos de forma iterativa
{
  while (cab)
  {
    cab->clientes += h;
    cab = cab->puntero;
  }
  
}

int insRef(LISTA *cab, int dato, int ref) // inserta un valor ferenciando otro valor de forma iterativa
{
  int res = 0;
  LISTA aux, ant, nuevo;

  aux = *cab;
  while (aux && ref != aux->clientes)
  {
    ant = aux;
    aux = aux->puntero;
  }
  if (aux)
  {
    res = creaNodo(&nuevo, dato);
    if(res)
    {
      nuevo->puntero = aux;
      if(*cab == aux)
        *cab = nuevo;
      else
        ant->puntero = nuevo;
    }
  }
  return res;
}

//-----------------------------------------Recursividad-----------------------------//

void sumaListaRec(LISTA cab, int *suma) //Costo de la lista recursivo
{
  if(cab)
  {
    sumaLista(cab->puntero, suma);
    *suma += cab->clientes;
  }
  else
    *suma = 0;
}

int sumaListaRec(LISTA cab) //Costo - suma de la lista recursivo
{
  int suma;
  if(!cab)
    suma = 0;
  else
    suma = cab->clientes + sumaLista(cab->puntero);
  return suma;
}

void incrementaRec(LISTA cab, int h) //Incrementa los datos de la lista de forma recursiva
{
  if (cab)
  {
    cab->clientes += h;
    incrementa(cab->puntero, h);
  }
}

int busqRec(LISTA cab, int buscado) // Busca el valor por busqueda de ordenamiento de mandera recursiva
{
  int res;
  if(!cab)
    res=0;
  else
    if(buscado == cab->clientes)
      res = 1;
    else
      res = busqRec(cab->puntero, buscado);
}

int insFinal(LISTA *cab, int dato) // inserta final de forma iterativa
{
  int res;
  LISTA nuevo, aux;

  res = creaNodo(&nuevo, dato);
  if (res)
    if(!res)
      *cab = nuevo;
    else
    {
      aux = *cab;
      while(aux->puntero)
        aux = aux->puntero;
      aux->puntero = nuevo;
    }
  return res;
}

int insFinalRec(LISTA *cab, int dato) // inserta en el final de forma recursiva
{
  int res;

  if(!*cab)
    res = creaNodo(cab, dato);
  else  
    res = insFinalRec(&(*cab)->puntero, dato);

  return res;
}

int insRefRec(LISTA *cab, int dato, int ref) // inserta por referencia un valor y lo pone a la izquierda de manera recursiva
{
  int res;
  LISTA nuevo;
  if(!*cab)
    res = 0;
  else if (ref == (*cab)->clientes)
  {
    res = creaNodo(&nuevo, dato);
    if (res)
    {
      nuevo->puntero = *cab;
      *cab = nuevo;
    }
  }
  else
    res = insRefRec(&(*cab)->puntero, dato, ref);
  return res;
}

int insOrdenadaRec(LISTA *cab, int dato, int ref) // inserta de forma ordenada de manera recursiva
{
  int res;
  LISTA nuevo;
  if(!*cab)
  {
    res = creaNodo(&nuevo, dato);
    *cab = nuevo;
  }
  else if (ref > (*cab)->clientes)
  {
    res = creaNodo(&nuevo, dato);
    if(res)
    {
      nuevo->puntero = *cab;
      *cab = nuevo;
    }
  }
  else
    res = insOrdenadaRec(&(*cab)->puntero, dato, ref);
  return res;
}

int insOrdenadaSinRepetirRec(LISTA *cab, int dato, int ref) // inserta de forma ordenada sin repetir el valor de manera recursiva
{
  int res;
  LISTA nuevo;
  if(!*cab)
  {
    res = creaNodo(&nuevo, dato);
    *cab = nuevo;
  }
  else if(ref == (*cab)->clientes)
    res = 0;
  else if(ref > (*cab)->clientes)
  {
    res = creaNodo(&nuevo, dato);
    if(res)
    {
      nuevo->puntero = *cab;
      *cab = nuevo;
    }
  }
  else
    res = insOrdenadaRec(&(*cab)->puntero, dato, ref);
  return res;
}

//--------------------------------------------Formas de eliminar nodos--------------------------------------------//

int elimIni(LISTA *cab) // Retorna 0 si no se pudo eliminar si no retorna el dato que sacamos del nodo inicial
{
  int res = 0;
  LISTA aux;

  if(*cab)
  {
    aux = *cab;
    *cab = aux->puntero;
    res = aux->clientes;
    free(aux);
  }
  return res;
}

int elimFin(LISTA *cab) // Retorna 0 si no se pudo eliminar si no retorna el dato que sacamos del nodo final
{
  int res = 0;
  LISTA aux;

  if(*cab)
  {
    for(; *cab; *cab = (*cab)->puntero)
      aux = *cab;
    *cab = NULL;
    res = (aux->puntero)->clientes;
    free(aux);
  }
  return res;
}

int elimRef(LISTA *cab)
{
  int res = 0;
  LISTA aux, ant, nuevo;

  aux = *cab;
  while (aux && ref != aux->clientes)
  {
    ant = aux;
    aux = aux->puntero;
  }
  if (aux)
  {
    res = creaNodo(&nuevo, dato);
    if(res)
    {
      nuevo->puntero = aux;
      if(*cab == aux)
        *cab = nuevo;
      else
        ant->puntero = nuevo;
    }
  }
  return res;
}