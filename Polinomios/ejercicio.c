/*
Objetivo: Con base en la estructura siguiente, escribir una función para crear un nodo:
Autor: LZR
Fecha: 18/06/2022
Nota(s): codigo de la funcion.
*/

typedef struct nodoMono
{
  float coef;
  int expo;
  struct nodoMono *sigMono;
} *MONO;

//Crea un nuevo nodo
int creaNodo(MONO *cab, int coeficiente, int exponente) {
  int res = 0;
  *cab = (MONO)malloc(sizeof(struct nodoMono));

  if (*cab) {
    (*cab)->coef = coeficiente;
    (*cab)->expo = exponente;
    (*cab)->sigMono = NULL;
    res = 1;
  }
  return res;
}