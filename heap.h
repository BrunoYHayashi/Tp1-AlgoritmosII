#ifndef Heap
#define Heap

struct paciente;

struct paciente **InicHeap(int tam);

int InsereHeap(struct paciente *heap[], struct paciente *p, int tam);

int RemoveHeap(struct paciente *heap[], struct paciente *p,int tam);

void Heapfy(struct paciente *heap[], int tam);

int ChecaHeap(struct paciente *heap[], int tam);

void ImprimeHeap(struct paciente *heap[], int tam);

void HeapSort(struct paciente *heap[], int tam);

#endif