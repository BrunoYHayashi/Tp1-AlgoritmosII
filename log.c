#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

#define MAX 5

void HeapInsere(struct paciente *heap[], char nome[], int prio, int tam, int max){

    if(tam+1 > max){
        printf("impossivel inserir o paciente %s de prioridade %d na heap, heap esta cheia", nome,prio);
        return;
    }

    if(!InsereNovoHeap(heap,nome,prio,tam,max)){
        printf("erro ao alocar paciente");
        return;
    }

    printf("Paciente %s de prioridade %d foi inserido na heap", nome, prio);
}

void HeapAtualiza(struct paciente *heap[], char nome[], int prio, int tam){
    if(!AlteraHeap(heap,nome,prio,tam)){
        printf("Nao foi possivel alterar a prioridade - paciente nao existe ou ");
        return;
    }
    printf("Prioridade do paciente %s alterada para %d com sucesso", nome,prio);
}

void HeapOrdena(struct paciente *heap[], char nome[], int prio, int tam){
    int n_comp = 0, n_trocas = 0;

    HeapSort(heap,tam,&n_comp,&n_trocas);
    printf("Heap Sort fez %d comparacoes e %d trocas", n_comp, n_trocas);
}

int main(){
    struct paciente **heap;
    char nome[50];
    int tam, prio, n_comp, n_trocas; /*tam é o tamanho util da heap*/
    printf("===================================================================");
    printf("Inicio da execucao do programa de teste");
    printf("===================================================================");

    InicHeap(MAX,&tam);
    if(tam == 0)
        printf("Heap vazia");

    printf("Insere 5 pacientes na heap\n");
    strycpy(nome, "Marchiorato");
    prio = 1;
    HeapInsere(heap,nome,prio,tam,MAX);
    printf("HEAP: ");
    ImprimeHeap(heap,tam);

    strycpy(nome, "Elisa");
    prio = 2;
    HeapInsere(heap,nome,prio,tam,MAX);
    printf("HEAP: ");
    ImprimeHeap(heap,tam);

    strycpy(nome, "Rafael");
    prio = 3;
    HeapInsere(heap,nome,prio,tam,MAX);
    printf("HEAP: ");
    ImprimeHeap(heap,tam);

    strycpy(nome, "Nicolas");
    prio = 2;
    HeapInsere(heap,nome,prio,tam,MAX);
    printf("HEAP: ");
    ImprimeHeap(heap,tam);

    strycpy(nome, "Kedlin");
    prio = 1;
    HeapInsere(heap,nome,prio,tam,MAX);
    printf("HEAP: ");
    ImprimeHeap(heap,tam);

    printf("Tenta inserir mais um paciente");
    strycpy(nome, "Juliano");
    prio = 1;
    HeapInsere(heap,nome,prio,tam,MAX);
    printf("HEAP: ");
    ImprimeHeap(heap,tam);

    strcpy(nome, "Marchiorato");
    prio = 3;
    HeapAtualiza(heap,nome,prio,tam);
    printf("HEAP: ");
    ImprimeHeap(heap,tam);

    strcpy(nome, "Rafael");
    prio = 1;
    HeapAtualiza(heap,nome,prio,tam);
    printf("HEAP: ");
    ImprimeHeap(heap,tam);

    printf("Ordena Heap em ordem crescente de prioridade");
    HeapOrdena(heap,nome,prio,tam);
    printf("HEAP ORDENADA: ");
    ImprimeHeap(heap,tam);

    printf("Volta o vetor a uma Heap");
    Heapfy(heap,tam,&n_comp,&n_trocas);
    printf("Heapfy fez %d comparacoes e %d trocas", n_comp,n_trocas);



}

