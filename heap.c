#include <stdlib.h>
#include <stdio.h>

struct paciente {
    char nome[50];
    int prioridade; //Max heap
}; 

static void SacodeHeap (int tam, struct paciente *heap[]){
    int i=2;
    struct paciente *AUX;

    while (i<=tam){
        if ((i< tam) && (heap[i] < heap [i+1]))
            i++;
        if (heap[i/2] >= heap[i])
            break;
        AUX= heap[i/2];
        heap[i/2]= heap[i];
        heap[i]= AUX;
        i=i*2;
    }
};

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
    pacienteRemovido = heap[i];
    for (i=1; i<tam; i++)
        heap[i] = heap[i+1];
    free (pacienteRemovido);
    *tam= *tam -1;
}


void Heapfy(struct paciente *heap[], int N){
    int i;
    for (i=1; i<N; i++)
        InsereHeap (i, heap);
}

int ChecaHeap(struct paciente *heap[], int tam){
    int i;
    for (i=tam; i>1; i--) 
        if (heap[i]>heap[i/2])
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

    heapfy(heap);
    for (i=N; i>1; i--) {
        AUX= heap[1]; 
        heap[1] = heap[i];
        heap[i] = AUX;
        SacodeHeap (i-1, heap);
    }
}