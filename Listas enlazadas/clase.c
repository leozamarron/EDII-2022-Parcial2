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

//Inicializa la lista
void iniLista(LISTA *cab) {
  *cab = NULL;
}

//Crea un nuevo nodo
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

//Inserta al inicio de la lista de forma iterativa
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

//captura los elemmentos de la lista y los inserta en la lista al inicio
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

//Muestra la lista de forma iterativa
void muestraLista(LISTA cab) 
{
  for(; cab; cab = cab->puntero)
    printf("%d ", cab->clientes);
}

//Peso - cantidad de elementos
int cuentaLista(LISTA cab) 
{
  int i = 0;
  for(; cab; i++, cab = cab->puntero);
  return i;
}

//Costo - suma iterativo
int costo(LISTA cab) 
{
  int suma = 0;

  for(; cab; cab = cab->puntero)
    suma += cab->clientes;
  return suma;
}

// para juntar cadenas
void costoListaCadena(LISTA cab, char *frase) 
{
  frase[0] = '/0';
  while (cab)
  {
    strcat(frase, cab->clientes);
    strcat(frase, " ");
    cab = cab->puntero;
  }
}

// busca la lista de forma iterativa
int buscaLista(LISTA cab, int buscado)
{
  int res = 0;
  while (cab && buscado != cab->clientes)
    cab = cab->puntero;
  if(cab)
    res = 1;
  return res;  
}

//incrementa los datos de forma iterativa
void incrementa(LISTA cab, int h) 
{
  while (cab)
  {
    cab->clientes += h;
    cab = cab->puntero;
  }
  
}

// inserta un valor ferenciando otro valor de forma iterativa
int insRef(LISTA *cab, int dato, int ref) 
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

//Costo de la lista recursivo
void sumaListaRec(LISTA cab, int *suma) 
{
  if(cab)
  {
    sumaLista(cab->puntero, suma);
    *suma += cab->clientes;
  }
  else
    *suma = 0;
}

//Costo - suma de la lista recursivo
int sumaListaRec(LISTA cab) 
{
  int suma;
  if(!cab)
    suma = 0;
  else
    suma = cab->clientes + sumaLista(cab->puntero);
  return suma;
}

//Incrementa los datos de la lista de forma recursiva
void incrementaRec(LISTA cab, int h) 
{
  if (cab)
  {
    cab->clientes += h;
    incrementa(cab->puntero, h);
  }
}

// Busca el valor por busqueda de ordenamiento de mandera recursiva
int busqRec(LISTA cab, int buscado) 
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

// inserta final de forma iterativa
int insFinal(LISTA *cab, int dato) 
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

// inserta en el final de forma recursiva
int insFinalRec(LISTA *cab, int dato) 
{
  int res;

  if(!*cab)
    res = creaNodo(cab, dato);
  else  
    res = insFinalRec(&(*cab)->puntero, dato);

  return res;
}

// inserta por referencia de lado izquierdo un valor de manera recursiva
int insRefRec(LISTA *cab, int dato, int ref) 
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

// inserta de forma ordenada y de manera recursiva, regresa 0 si no se pudo insertar
int insOrdenadaRec(LISTA *cab, int dato, int ref) 
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

// inserta de forma ordenada sin repetir el valor de manera recursiva, regresa 0 si no se pudo insertar
int insOrdenadaSinRepetirRec(LISTA *cab, int dato, int ref) 
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
    res = insOrdenadaSinRepetirRec(&(*cab)->puntero, dato, ref);
  return res;
}

//--------------------------------------------Formas de eliminar nodos--------------------------------------------//

// Retorna 0 si no se pudo eliminar si no retorna el dato que sacamos del nodo inicial
int elimIni(LISTA *cab) 
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

// Retorna 0 si no se pudo eliminar si no retorna el dato que sacamos del nodo final
int elimFin(LISTA cab) 
{
  int res = 0;
  LISTA aux;

  if(cab)
  {
    for(; cab; cab = cab->puntero)
      aux = cab;
    aux->puntero = NULL;
    res = (cab->puntero)->clientes;
    free(cab);
  }
  return res;
}

// Retorna 0 si no se pudo elimina si no, retorna el dato que sacamos del nodo al que quiere eliminar
int elimRef(LISTA *cab, int ref)
{
  int res = 0;
  LISTA aux, auxAux, nuevo;

  aux = *cab;

  while (aux && ref != aux->clientes)
    aux = aux->puntero;
  if (aux)
  {
    if (aux == *cab)
    {
      *cab = aux->puntero; //Tambien se puede usar elimIni
      res = aux->clientes;
      free(aux);
    }
    else
    {
      auxAux = aux;
      aux = auxAux->puntero;
      res = auxAux->clientes;
      free(auxAux);
    }
  }
  return res;
}