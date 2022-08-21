// Luan Rodrigues
// Atencao: as anotacoes valem para o codigo abaixo delas ou ao lado

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "iteradorLista.h"

iteradorLista primeiro(lista *l){
  iteradorLista i;
  i.posicao = l->sentinela->proximo;
  i.estrutura = l;
  return i;
}
iteradorLista ultimo(lista *l){
  iteradorLista i;
  i.posicao = l->sentinela->anterior;
  i.estrutura = l;
  return i;
}

int acabou(iteradorLista *i){
  return i->posicao == i->estrutura->sentinela;
}

T elemento(iteradorLista *i){
  if (!acabou(i))
    return i->posicao->valor;

  else
    return 0;
}

//gives the last element
int proximo(iteradorLista *i){
  if( !acabou(i) ) {
    i->posicao = i->posicao->proximo;
    return 1;
  }
  return 0;
}

iteradorLista procurarPosicao(lista* l, unsigned posicao){
  iteradorLista it = primeiro(l);
  for(int i = 0; i < posicao; i++){
    proximo(&it);
  }

  return it;
}

void removerElemento(iteradorLista *i){
  Node* node = i->posicao;
  node->anterior->proximo = node->proximo;
  node->proximo->anterior = node->anterior;
  i->estrutura-> quantidade --;
  free(node);
}


