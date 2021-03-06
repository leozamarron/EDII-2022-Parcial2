/*
Objetivo: Con base en la estructura siguiente, escribir una función para crear un nodo:
Autor: LZR
Fecha: 18/06/2022
Nota(s): codigo de la funcion.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct nodoGen
{
  // caracter, entero, flotante
  char nomTipo[10];
  int tipo; // 1-char, 2-int, 3-float
  void *info;
  struct nodoGen *sigGen;
} *GEN;

//Crea un nuevo nodo
int creaNodo(GEN *cab, char *nom, int tip) {
  int res = 0;
  *cab = (GEN)malloc(sizeof(struct nodoGen));

  if (*cab) {
    strcpy((*cab)->nomTipo, nom);
    (*cab)->tipo = tip;
    (*cab)->sigGen = NULL;
    res = 1;
  }
  return res;
}

int sumaInt(GEN cab)
{
  if(cab->tipo == 2)
  {
    int res;
    if (!cab)
      res = 0;
    else
      res = (int*)cab->info + suma(cab->sigGen);
    return res;
  }
}

float sumaFloat(GEN cab)
{
  if(cab->tipo == 3)
  {
    int res;
    if (!cab)
      res = 0;
    else
      res = (float*)cab->info + suma(cab->sigGen);
    return res;
  }
}

float sumaTot(GEN cab)
{
  float sumaT = 1.0 * sumaInt(cab) + sumaFloat(cab);
  return sumaT;
}