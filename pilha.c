// Luan Rodrigues
// Atencao: as anotacoes valem para o codigo abaixo delas ou ao lado

#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

int inicializarPilha(pilha* p) {
  // Tentando alocar memoria para o vetor da pilha
  unsigned maximoInicial = 8; 
  T* vetor = (T*) malloc(maximoInicial* sizeof(T));
  if (vetor == NULL)
    return 0; // Se não ha memoria, recuar

  // Definindo atributos iniciais da pilha:
  p->vetor = vetor;
  p->topo = 0;
  p->nMax = maximoInicial;
  
  return 1;
}

int pilhaVazia(pilha* p) {
  // Retorna 1 somente se o topo for nulo
  return !(p->topo);
}

int pilhaCheia(pilha* p) {
  // Retorna 1 somente se o topo ultrapassar o valor maximo
  return (p->topo >= p->nMax);
}

int resizePilha(pilha *p, unsigned novoMax) {
  // Tentando alocar memoria para o novo vetor:
  T* novoVetor = (T*) malloc (novoMax * sizeof(T));
  if (novoVetor == NULL)
    return 0; // Recuando se não houver memoria

  // Transferindo elementos para o novo vetor: 
  for (int i = 0; i < p->topo; i++)
    novoVetor[i] = p->vetor[i];

  // Substituindo antigo vetor pelo novo:
  free (p->vetor);
  p->vetor = novoVetor;
  p->nMax = novoMax;
  return 1;
}

int empilhar(pilha* p, T data) { 
  if(pilhaCheia(p))
    // Tentando ajustar tamanho maximo: 
    if (!resizePilha(p, p->nMax*2))
      return 0; // Recuando se nao houver memoria

  // Adicionando elemento ao topo da pilha:
  p->vetor[p->topo] = data;
  p->topo++;
  return 1; // indica sucesso ao empilhar
}

T desempilhar(pilha* p) {
  if(!pilhaVazia(p)) {
    // Salvando dado do topo e o removendo da pilha:
    T descarte = p->vetor[p->topo-1];
    p->topo--;
  
    // Diminuindo tamanho da pilha na memoria se possivel:  
    if( p->topo > 0 && p->nMax > 8 && p->topo <= p->nMax/4)
      if(!resizePilha(p, p->nMax/2))
        return -1; // Indica erro ao reajudar tamanhanho maximo da pilha
    
    return descarte; // Indica sucesso na remoção do elemento
  }

  else
    return 0; // Indica pilha vazia
}

void limparPilha(pilha* p){
  p->topo = 0;
  resizePilha(p, 8); // Tamanho minimo para o limite de elementos
}

void destruirPilha(pilha* p){
  p->topo = 0;
  free(p->vetor);
}

T topoPilha(pilha* p){
  T value = desempilhar(p);
  
  if(value)
    empilhar(p, value);
  
  return value;
  
}
