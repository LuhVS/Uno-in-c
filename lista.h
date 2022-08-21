// Luan Rodrigues
// Atencao: as anotacoes valem para o codigo abaixo delas ou ao lado

#ifndef LISTA_C
#define LISTA_C

// Tipo de elemento da lista ou key da lista:
// Pode ser alterado para tipos simples como int, long, char, double 
typedef int T;

// Estrutura node para encadeamento duplo:
// Contem um elemento e os ponteiros para os vizinhos
struct node{
  T valor;
  struct node *anterior, *proximo;
};

typedef struct node Node;

// Estrutura lista com sentinela:
// Guarda um ponteiro para sentinela e quantidade de elementos da lista
typedef struct{
  Node *sentinela;
  unsigned quantidade;
}lista;

// Deve ser a primeria funcao executada
// Define os atributos iniciais da lista de entrada como parametro
// finaliza o programa se não houver memoria
void inicializarLista(lista* d);

// Retorna 1 se a lista estiver cheia
// Retorna 2 se a lista nao estiver cheia
int listaVazia(lista* d);

// Funcoes de insercao de elemento
// finaliza o programa se não houver memoria
void inserirInicioLista(lista* d, T data);
void inserirFinalLista(lista* d, T data);

// Funcoes de remocao:
// De ser verificado se a lista esta vazia antes 
// Retornam o respective elemento retirado
// finaliza o programa se a lista estiver vazia antes da remoção 
T removerInicioLista(lista* d);
T removerFinalLista(lista* d);

// Remove todos os elementos da lista;
// Deve ser usada se a lista ainda sera usada 
void limparLista(lista* d);

// Remove todos os elementos da lista e libera a memoria;
// Deve ser usado se a lista nao for mais usada 
void destruirLista(lista* d);

#endif