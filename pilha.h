// Luan Rodrigues
// Atencao: as anotacoes valem para o codigo abaixo delas ou ao lado

#ifndef PILHA_C
#define PILHA_C

// Tipo de elemento da pilha ou key da pilha:
// Pode ser alterado para tipos simples como int, long, char, double 
typedef int T;

// Estrutura pilha para alocação dinamica com quantidade maxima temporaria
// Seu tamanho maximo pode mudar durante a execução se necessario
typedef struct{
  unsigned topo, nMax;
  T* vetor;
}pilha;

// Deve ser a primeira funcao usando pilha
// Define atributos iniciais de uma pilha
// Tamanho maximo inicial de 8 elementos
// Retorna 1 se for possivel inicializar
// Retorna 0 se não
int inicializarPilha(pilha* p);

// Retorna 1 se pilha vazia
// Retorna 0 se não
int pilhaVazia(pilha* p);

// Retorna 1 se pilha Cheia
// Retorna 0 se não
int pilhaCheia(pilha* p);

// Adiciona elemento (data) ao todo da pilha
// Retorna 1 se for possivel adicionar
// Retorna 0 se não
// Pode alterar tamanho maximo da pilha se precisar
int empilhar(pilha* p, T data);

// Remove um elemento do topo da pilha
// Retorna valor do elemento se removido
// Retorna 0 se pilha vazia 
// Pode altarear tamanho maximo da pilha
// retorna -1 se houver problema no ajuste do tamanho
T desempilhar(pilha* p);

// Retira todos os elementos da pilha
// NAO desaloca o espaço da pilha
// Pode alterar tamanho maximo da pilha
// Usar se a pilha ainda sera utilizada
void limparPilha(pilha* p);

// Retira todos os elementos da pilha
// Desaloca o espaço da pilha
// Usar se a pilha não sera mais utilizada
void destruirPilha(pilha* p);

// Retorna elemento no topo sem retirar da pilha
// Retorna 0 se não for possivel
T topoPilha(pilha *p);

#endif