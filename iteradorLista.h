// Luan Rodrigues
// Atencao: as anotacoes valem para o codigo abaixo delas ou ao lado

#ifndef ITERADORLISTA_C
#define ITERADORLISTA_C

#include "lista.h"

typedef struct{
  struct node *posicao;
  lista *estrutura;
}iteradorLista;

iteradorLista primeiro(lista *l);
iteradorLista ultimo(lista *l);

int acabou (iteradorLista *i);
T elemento(iteradorLista *i);
int proximo (iteradorLista *i);

iteradorLista procurarPosicao(lista *l, unsigned posicao);
void removerElemento(iteradorLista *i);

#endif