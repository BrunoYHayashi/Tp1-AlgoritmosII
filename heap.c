#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct paciente {
    char nome[50];
    int prioridade; //Max heap
}; 

static void SacodeHeap (int tam, struct paciente *heap[]){
    int i=2;
    struct paciente *AUX;

    while (i<=tam){
        if ((i< tam) && (heap[i]->prioridade < heap [i+1]->prioridade))
            i++;
        if (heap[i/2]->prioridade >= heap[i]->prioridade)
            break;
        AUX= heap[i/2];
        heap[i/2]= heap[i];
        heap[i]= AUX;
        i=i*2;
    }
}

struct paciente **InicHeap(int N){ //N é o número máximo do vetor
    struct paciente **heap;
    
    if(!(heap=malloc(sizeof (struct paciente*)* N))) //cria um vetor de ponteiros para struct paciente
        return NULL;
        
    return heap; //retorna o ponteiro do vetor, esse aponta para uma struct paciente.
}

void InsereHeap(struct paciente *heap[], int tam){ //*heap[] = **heap. 
    int i=tam+1;
    struct paciente *AUX;

    while (i>1 && heap[i/2]->prioridade < heap[i]->prioridade){
        AUX= heap[i/2];
        heap[i/2]= heap[i];
        heap[i] = AUX;
        i= i/2;
    };
}

int RemoveHeap(struct paciente *heap[], int *tam){
    int i;
    struct paciente *pacienteRemovido;

    pacienteRemovido = heap[1];
    for (i=1; i<*tam; i++)
        heap[i] = heap[i+1];

    free (pacienteRemovido);
    pacienteRemovido = NULL;

    *tam= *tam -1;
    Heapfy(heap, *tam);
}


void Heapfy(struct paciente *heap[], int N){
    int i;
    for (i=1; i<N; i++)
        InsereHeap (heap, i);
}

int ChecaHeap(struct paciente *heap[], int tam){
    int i;
    for (i=tam; i>1; i--) 
        if (heap[i]->prioridade > heap[i/2]->prioridade)
            return 0;
    return 1;  
}

void ImprimeHeap(struct paciente *heap[], int tam){
    int i;
    for (i=1; i<=tam; i++)
        printf("%s \n", heap[i]->nome);
}

void HeapSort(struct paciente *heap[], int N){
    int i;
    struct paciente *AUX;

    Heapfy(heap, N);
    for (i=N; i>1; i--) {
        AUX= heap[1]; 
        heap[1] = heap[i];
        heap[i] = AUX;
        SacodeHeap (i-1, heap);
    }
}

int AlteraHeap(struct paciente *heap[], char nome[], int prioridade, int tam){
    int i;

    i=1;
    while (strcmp(nome, heap[i]->nome)!= 0 && i<=tam){
        i=i+1;
    }

    if (i>tam)
        return 0;

    heap[i]->prioridade = prioridade;
    
    Heapfy(heap, tam);
}