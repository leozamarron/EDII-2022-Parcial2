typedef struct nodo{
  char fracciones[10];
  struct nodo *puntero;
}*LISTA;

typedef struct nodo{
  FRACCIONES fracciones;
  struct nodo *puntero;
}*LISTA;

typedef struct{
  int numerador;
  int denominador;
}FRACCIONES;