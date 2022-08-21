// Luan Rodrigues
// Atencao: as anotacoes valem para o codigo abaixo delas ou ao lado

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void inicializarLista(lista* f) {
  // Tentando alocar memoria para o sentinela:
  Node *n = (Node*)malloc(sizeof(Node));
  if (n == NULL){ // Recuar se nao houver memoria 
    printf("Sem memoria para inicializar lista!");
    exit(0);
  }

  // Configurando sentinela: 
  n->anterior = n->proximo = n;
  f->sentinela = n;
  
  f->quantidade = 0;
}

int listaVazia(lista* f) {
  // Se houver 0 elemento, retorna 1:
  return !(f->quantidade); 
}

void inserirInicioLista(lista* f, T data) { 
  // Tentando alocar memoria para novo elemento:
  Node* n = (Node*) malloc(sizeof(Node));
  if (n == NULL){ // Recuar se nao houver memoria 
    printf("Sem memoria para inserir na lista!");
    exit(0);
  }
  
  // Colocando novo elemento entre o sentinela e o primeiro elemento:
  n->proximo = f->sentinela->proximo;
  n->anterior = f->sentinela;
  f->sentinela->proximo->anterior = n;
  f->sentinela->proximo = n;
  n->valor = data;
  
  f->quantidade++;
}

void inserirFinalLista(lista* f, T data) {
  // Tentado alocar memoria para novo elemento:
  Node* n = (Node*) malloc(sizeof(Node));
  if (n == NULL){ // Recuar se nao houver memoria 
    printf("Sem memoria para inserir na lista!");
    exit(0);
  }
  
  n->valor = data;

  // Colocando novo valor entre o sentinela e o ultimo elemento:
  n->anterior = f->sentinela->anterior;
  n->proximo = f->sentinela;
  f->sentinela->anterior->proximo = n;
  f->sentinela->anterior = n;

  f->quantidade++;
}

T removerInicioLista(lista* f) {
  if(!listaVazia(f)) {
    // Ponteiro para o elemento no inicio da lista e salvando seu valor;
    Node* n = f->sentinela->proximo;
    T removido = n->valor;

    // Retirando elemento inicial do encadeamento:
    f->sentinela->proximo = n->proximo;
    n->proximo->anterior = f->sentinela;
    free(n);
    
    f->quantidade--;
    return removido;
  }
    
  else { // Caso lista vazia antes da remoção
    printf("Remoção em lista vazia!");
    exit(0);
  }
}

T removerFinalLista(lista* f) {
    if(!listaVazia(f)){
    // Ponteiro para o elemento no final da lista e salvando seu valor;
    Node* n = f->sentinela->anterior;
    T removido = n->valor;

    // Retirando elemento final do encadeamento:
    f->sentinela->anterior = n->anterior;
    n->anterior->proximo = f->sentinela;

    free(n);
    f->quantidade--;
    return removido;
  }
      
  else { // Caso lista vazia antes da remoção
    printf("Remoção em lista vazia!");
    exit(0);
  }
}

void limparLista(lista* f) {
  while(!listaVazia(f))
    removerInicioLista(f);
}

void destruirLista(lista* f) {
  while(!listaVazia(f))
    removerInicioLista(f);

  free(f->sentinela);
}