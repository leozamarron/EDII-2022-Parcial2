#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct nodo{
  int info;
  struct nodo *sigNodo;
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
    (*cab)->info = dato;
    (*cab)->sigNodo = NULL;
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
    nuevo->sigNodo = *cab;
    *cab = nuevo;
    res = 1;
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
  for(; cab; cab = cab->sigNodo)
    printf("%d ", cab->info);
}

//Peso - cantidad de elementos
int cuentaLista(LISTA cab) 
{
  int i = 0;
  for(; cab; i++, cab = cab->sigNodo);
  return i;
}

//Costo - suma iterativo
int costo(LISTA cab) 
{
  int suma = 0;

  for(; cab; cab = cab->sigNodo)
    suma += cab->info;
  return suma;
}

// para juntar cadenas
void costoListaCadena(LISTA cab, char *frase) 
{
  frase[0] = '/0';
  while (cab)
  {
    strcat(frase, cab->info);
    strcat(frase, " ");
    cab = cab->sigNodo;
  }
}

// busca la lista de forma iterativa
int buscaLista(LISTA cab, int buscado)
{
  int res = 0;
  while (cab && buscado != cab->info)
    cab = cab->sigNodo;
  if(cab)
    res = 1;
  return res;  
}

//incrementa los datos de forma iterativa
void incrementa(LISTA cab, int h) 
{
  while (cab)
  {
    cab->info += h;
    cab = cab->sigNodo;
  }
  
}

// inserta un valor ferenciando otro valor de forma iterativa
int insRef(LISTA *cab, int dato, int ref) 
{
  int res = 0;
  LISTA aux, ant, nuevo;

  aux = *cab;
  while (aux && ref != aux->info)
  {
    ant = aux;
    aux = aux->sigNodo;
  }
  if (aux)
  {
    res = creaNodo(&nuevo, dato);
    if(res)
    {
      nuevo->sigNodo = aux;
      if(*cab == aux)
        *cab = nuevo;
      else
        ant->sigNodo = nuevo;
    }
  }
  return res;
}

//----------------------------------------------------------//
//-------------------------Recursividad---------------------//
//----------------------------------------------------------//

//Costo de la lista recursivo
void sumaListaRec(LISTA cab, int *suma) 
{
  if(cab)
  {
    sumaLista(cab->sigNodo, suma);
    *suma += cab->info;
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
    suma = cab->info + sumaLista(cab->sigNodo);
  return suma;
}

//Incrementa los datos de la lista de forma recursiva
void incrementaRec(LISTA cab, int h) 
{
  if (cab)
  {
    cab->info += h;
    incrementa(cab->sigNodo, h);
  }
}

// Busca el valor por busqueda de ordenamiento de mandera recursiva
int busqRec(LISTA cab, int buscado) 
{
  int res;
  if(!cab)
    res=0;
  else
    if(buscado == cab->info)
      res = 1;
    else
      res = busqRec(cab->sigNodo, buscado);
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
      while(aux->sigNodo)
        aux = aux->sigNodo;
      aux->sigNodo = nuevo;
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
    res = insFinalRec(&(*cab)->sigNodo, dato);

  return res;
}

// inserta por referencia de lado izquierdo un valor de manera recursiva
int insRefRec(LISTA *cab, int dato, int ref) 
{
  int res;
  LISTA nuevo;
  if(!*cab)
    res = 0;
  else if (ref == (*cab)->info)
  {
    res = creaNodo(&nuevo, dato);
    if (res)
    {
      nuevo->sigNodo = *cab;
      *cab = nuevo;
    }
  }
  else
    res = insRefRec(&(*cab)->sigNodo, dato, ref);
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
  else if (ref > (*cab)->info)
  {
    res = creaNodo(&nuevo, dato);
    if(res)
    {
      nuevo->sigNodo = *cab;
      *cab = nuevo;
    }
  }
  else
    res = insOrdenadaRec(&(*cab)->sigNodo, dato, ref);
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
  else if(ref == (*cab)->info)
    res = 0;
  else if(ref > (*cab)->info)
  {
    res = creaNodo(&nuevo, dato);
    if(res)
    {
      nuevo->sigNodo = *cab;
      *cab = nuevo;
    }
  }
  else
    res = insOrdenadaSinRepetirRec(&(*cab)->sigNodo, dato, ref);
  return res;
}

//--------------------------------------------------------//
//-------------------Formas de eliminar nodos-------------//
//--------------------------------------------------------//

// Retorna 0 si no se pudo eliminar si no retorna el dato que sacamos del nodo inicial
int elimIni(LISTA *cab) 
{
  int res = 0;
  LISTA aux;

  if(*cab)
  {
    aux = *cab;
    *cab = aux->sigNodo;
    res = aux->info;
    free(aux);
  }
  return res;
}

// Retorna 0 si no se pudo eliminar si no retorna el dato que sacamos del nodo final

int elimFin(LISTA *cab)
{
    int res = 0;
    LISTA aux, ant;
    if(*cab)
    {
        aux = *cab;
        while(aux->info)
        {
            ant = aux;
            aux = aux->sigNodo;
        }
        if(*cab == aux)
            *cab = NULL;
        else
           ant->sigNodo = NULL;
        free(aux);
        res = 1;
    }
    return res;
}

int elimFinRec(LISTA *cab)
{
    int res;
    if(!*cab)
        res = 0;
    else if(!(*cab)->sigNodo)
    {
        free(*cab);
        *cab = NULL;
        res = 1;
    }
    else
        res = elimFinRec (&(*cab)->sigNodo);
    return res;
}


// Retorna 0 si no se pudo elimina si no, retorna el dato que sacamos del nodo al que quiere eliminar

int elimRef(LISTA *cab, int ref)
{
    int res = 0;
    LISTA aux, ant;
    
    aux = *cab;
    while(aux && ref != aux->info)
    {
        ant = aux;
        aux = aux->sigNodo;
    }
    if(aux)
    {
        if(aux == *cab)
            *cab = aux->sigNodo;
        else
            ant->sigNodo = aux->sigNodo;
        free(aux);
        res = 1;
    }
    return res;
}

int elimRefRec(LISTA *cab, int ref)
{
    int res;
    LISTA aux;
    if(!*cab)
        res = 0;
    else if(ref == (*cab)->info)
    {
        aux = *cab;
        *cab = aux->sigNodo;
        free(aux);
        res = 1;
    }
    else
        res = elimRefRec (&(*cab)->sigNodo, ref);
    return res;
}

int elimOrdenada(LISTA *cab, int ref)
{
    int res = 0;
    LISTA aux, ant;
    while(aux && ref>aux->info)
    {
        ant = aux;
        aux = aux->sigNodo;
    }
    if(aux && ref == aux->info)
    {
        if(aux == *cab)
            *cab = aux->sigNodo;
        else
            ant->sigNodo = aux->sigNodo;
        free(aux);
        res = 1;
    }
}

int elimOrdRec(LISTA *cab, int ref)
{
    int res;
    LISTA aux;
    if(!*cab || ref < (*cab)->info)
        res = 0;
    else if(ref == (*cab)->info)
    {
        aux = *cab;
        *cab = aux->sigNodo;
        free(aux);
        res = 1;
    }
    else
        res = elimOrdRec (&(*cab)->sigNodo, ref);
    return res;
}

//--------------------------------------------------------//
//------------------------PILAS Y COLAS-------------------//
//--------------------------------------------------------//

typedef struct nodo{
  int info;
  struct nodo *sigNodo;
}*FILA;

typedef struct 
{
  FILA frente;
  FILA final;
}FILA_CA; //Filas agrupadas

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

void iniQueueCA(FILA_CA *f)
{
  f->frente = f->final = NULL;
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

//--------------------------------------------------------//
//------------------------LISTAS DOBLES-------------------//
//--------------------------------------------------------//

typedef struct nodo2{
  struct nodo *antNodo;
  int info;
  struct nodo *sigNodo;
}*LISTA_DOBLE;

typedef struct{
  LISTA_DOBLE frente;
  LISTA_DOBLE final;
}FILA_CAB;

void iniListaCS(LISTA_DOBLE *pri, LISTA_DOBLE *ult)
{
  *pri = *ult = NULL;
}

void iniListaCA(FILA_CAB *id)
{
  id->frente = id->final = NULL;
}

// Creacion de un nodo doble
int creaNodo2(LISTA_DOBLE *nodo, int dato)
{
  int res = 0;
  *nodo = (LISTA_DOBLE)malloc(sizeof(struct nodo2));

  if(*nodo)
  {
    (*nodo)->antNodo = NULL;
    (*nodo)-> sigNodo = NULL;
    (*nodo)->info = dato;
    res = 1;
  }
  return res;
}

int insIni(FILA_CAB *cab, int dato)
{
  int res;
  LISTA_DOBLE nuevo;
  res = creNodo2(&nuevo, dato);
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
  LISTA_DOBLE nuevo;
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
  LISTA_DOBLE aux, nuevo;

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
  LISTA_DOBLE aux;

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
  LISTA_DOBLE aux;

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

//--------------------------------------------------------//
//----------------------LISTAS CIRCULARES-----------------//
//--------------------------------------------------------//

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