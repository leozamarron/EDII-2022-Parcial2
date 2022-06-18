/*
Objetivo: almacenar en una lista simple la información relativa a un conjunto de datos genéricos
Autor: LZR
Fecha: 18/06/2022
Nota(s): proponga la(s) estructura(s) necesaria(s):
*/

typedef struct nodo{
    GEN ptrListaGen;
    struct nodo *puntero;
}*LISTA;

typedef struct
{
    int tipo;
    void *ptrGen;
}GEN;