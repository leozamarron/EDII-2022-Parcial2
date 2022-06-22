/*
Objetivo: Con base en la estructura siguiente, escribir una función para crear un nodo:
Autor: LZR
Fecha: 18/06/2022
Nota(s): codigo de la funcion.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodoFracc
{
  int num;
  int den;
  struct nodoFracc *sigFracc; 
} *FRACC;

int creaNodo(FRACC *cab, int numerador, int denom);
void muestraFracc(FRACC cab);
void calculaSuma(FRACC cab);
int insIni(FRACC *cab, int numerador, int denom);

int main()
{
  FRACC fracc;
  insIni(&fracc, 3, 5);
  insIni(&fracc, 4, 2);
  calculaSuma(fracc);
  muestraFracc(fracc);
}

int insIni(FRACC *cab, int numerador, int denom) {
  int res = 0;
  FRACC nuevo;
  res = creaNodo(&nuevo, numerador, denom);
  if (res) {
    nuevo->sigFracc = *cab;
    *cab = nuevo;
  }
  return res;
}

//Crea un nuevo nodo
int creaNodo(FRACC *cab, int numerador, int denom) {
  int res = 0;
  *cab = (FRACC)malloc(sizeof(struct nodoFracc));

  if (*cab) {
    (*cab)->num = numerador;
    (*cab)->den = denom;
    (*cab)->sigFracc = NULL;
    res = 1;
  }
  return res;
}

void muestraFracc(FRACC cab) 
{
  for(; cab; cab = cab->sigFracc)
    printf("%d/%d \n", cab->num, cab->den);
}

void calculaSuma(FRACC cab)
{
  int numT = cab->num, denT = cab->den;
  cab = cab->sigFracc;
  for(; cab; cab = cab->sigFracc){
    numT = numT * cab->den + denT * cab->num;
    denT = denT * cab->den;
  }
  printf("%d/%d ", numT, denT);
}