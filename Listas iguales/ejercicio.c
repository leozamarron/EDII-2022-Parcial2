#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
  int info;
  struct nodo *sig;
}*LISTA;

int igualesNodos(LISTA cab, int *dato)
{
    LISTA aux;
    int res = 0;
    if(cab)
    {
        while (cab && !res)
        {
            aux = cab;
            while (aux && !res)
            {
                aux = aux->sig;
                if (cab->info == aux->info)
                {
                    *dato = cab->info;
                    res = 1;
                }
            }
            cab = cab->sig;
        }
    }
    return res;
}

int igualesRec(LISTA cab1, LISTA cab2)
{
    int res;
    LISTA aux;

    if (!cab1 && !cab2)
        res = 1;
    else if (cab1->info == cab2->info)
        igualesRec(cab1->sig, cab2->sig);
    else
        res = 0;

    return res;
}