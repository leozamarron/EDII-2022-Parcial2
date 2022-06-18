/*
Objetivo: almacenar en una lista simple la información relativa a un polinomio.
Autor: LZR
Fecha: 18/06/2022
Nota(s): proponga la(s) estructura(s) necesaria(s):
*/

typedef struct nodo{
    char polinomio[10];
    struct nodo *puntero;
}*LISTA;