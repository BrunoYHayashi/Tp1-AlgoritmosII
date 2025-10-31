#ifndef Heap
#define Heap

struct paciente;

/*
Tenta alocar a heap
Em caso de falha, retorna NULL 
em caso de sucesso, retorna o ponteiro para ponteiro da heap
*/

struct paciente **InicHeap(int N);

/*essa funcao eh o insere heap para o heapfy*/
void InsereHeap(struct paciente *heap[], int tam);

/*insere novo elemento na heap e retorna 1 em caso de sucesso e 0 caso contrario*/
int InsereNovoHeap(struct paciente *heap[], struct paciente *p, int tam);

/*
remove um elemento da heap
retorna 1 em caso de sucesso e 0 caso o elemento nao exista na heap
*/
void RemoveHeap(struct paciente *heap[], int *tam);

/*transforma o vetor em uma heap*/
void Heapfy(struct paciente *heap[], int tam);

/*retorna 0 se o vetor nao for heap e 1 em caso contrario*/
int ChecaHeap(struct paciente *heap[], int tam);

/*imprime os elementos da heap*/
void ImprimeHeap(struct paciente *heap[], int tam);

/*ordena a heap utilizando o Heap Sort*/
void HeapSort(struct paciente *heap[], int tam);

/*altera a prioridade do paciente indicado pelo parametro nome[]*/
void AlteraHeap(struct paciente *heap[], char nome[], int prioridade, int tam);

#endif