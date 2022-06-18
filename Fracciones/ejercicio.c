/*
Objetivo: Con base en la estructura siguiente, escribir una función para crear un nodo:
Autor: LZR
Fecha: 18/06/2022
Nota(s): codigo de la funcion.
*/

typedef struct nodoFracc
{
  int num;
  int den;
  struct nodoFracc *sigFracc; 
} *FRACC;

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