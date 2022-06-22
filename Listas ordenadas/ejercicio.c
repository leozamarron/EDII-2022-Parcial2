#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
  int info;
  struct nodo *sig;
}*LISTA;

int ordAsc(LISTA cab)
{
    int res = 0;
    if(cab)
    {
        res = 1;
        while (cab->sig && res)
        {
            if (cab->info > cab->sig->info)
                res = 0;
        }
    }
    return res;
}

int ordAscRec(LISTA cab)
{
    int res;
    if(cab)
    {
        if (!cab->sig)
            res = 1;
        else if (cab < cab->sig)
            ordAscRec(cab);
        else
            res = 0;
    } else
        res = 0;
    return res;
}