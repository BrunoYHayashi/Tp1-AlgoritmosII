#ifndef Heap
#define Heap

struct paciente {
    char nome[50];
    int prioridade; //Max heap
}; 

/*
Sacode o heap, elemento de heap[1] percorre o heap até se encontrar. 
Essa versão do SacodeHeap é adaptada ao resto do código para sua reutilização,
por isso "i" é passado como parâmetro
*/
void SacodeHeap (int i, int tam, struct paciente *heap[]);

/*
Tenta alocar a heap
Em caso de falha, retorna NULL
em caso de sucesso, retorna o ponteiro para ponteiro da heap
*/  
struct paciente **InicHeap(int N, int *tam);

/*Troca o ponteiro de dois pacientes*/
void TrocaPacientes (struct paciente **a, struct paciente **b);

/*essa funcao eh o insere heap para o heapfy*/
void InsereHeap(struct paciente *heap[], int tam);

/*insere novo elemento na heap e retorna 1 em caso de sucesso e 0 caso contrario*/
int InsereNovoHeap(struct paciente *heap[], struct paciente *p, int tam);

/*
remove um elemento da heap
retorna o ponteiro para o paciente removido, em caso do vetor estar vazio, retorna NULL
*/
struct paciente *RemoveHeap(struct paciente *heap[], int *tam);

/*transforma o vetor em uma heap*/
void Heapfy(struct paciente *heap[], int N);

/*retorna 0 se o vetor nao for heap e 1 em caso contrario*/
int ChecaHeap(struct paciente *heap[], int tam);

/*imprime os elementos da heap*/
void ImprimeHeap(struct paciente *heap[], int tam);

/*ordena a heap utilizando o Heap Sort*/
void HeapSort(struct paciente *heap[], int N);

/*altera a prioridade do paciente indicado pelo parametro nome[]*/
int AlteraHeap(struct paciente *heap[], char nome[], int prioridade, int tam);

#endif