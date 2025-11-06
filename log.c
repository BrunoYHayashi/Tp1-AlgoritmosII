#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "heap.h"

#define MAX 5

void HeapInsere(struct paciente *heap[], char nome[], int prio, int *tam, int max){

    if(*tam+1 > max){
        printf("\nimpossivel inserir o paciente %s de prioridade %d na heap, heap esta cheia", nome,prio);
        return;
    }

    if(!InsereNovoHeap(heap,nome,prio,tam,max)){
        printf("\nerro ao alocar paciente");
        return;
    }

    printf("Paciente %s de prioridade %d foi inserido na heap", nome, prio);
}

void HeapAtualiza(struct paciente *heap[], char nome[], int prio, int tam){
    if(!AlteraHeap(heap,nome,prio,tam)){
        printf("Nao foi possivel alterar a prioridade - paciente nao existe ou heap nao existe");
        return;
    }
    printf("Prioridade do paciente %s alterada para %d com sucesso", nome,prio);
}

void HeapOrdena(struct paciente *heap[], int tam){
    int n_comp = 0, n_trocas = 0;

    HeapSort(heap,tam,&n_comp,&n_trocas);
    printf("Heap Sort fez %d comparacoes e %d trocas", n_comp, n_trocas);
}

void HeapRemove(struct paciente *heap[], int *tam){
    struct paciente *p;

    if(!(p = RemoveHeap(heap,tam))){
        printf("nao foi possivel remover o paciente - heap esta vazia ou nao existe");
        return;
    }

    printf("Paciente %s de prioridade %d foi removido do heap",p->nome,p->prioridade);
    free(p);
}

void HeapCheca(struct paciente *heap[], int tam){
    if(!ChecaHeap(heap,tam)){
        printf("ChecaHeap: Nao eh uma heap");
        return;
    }
    printf("ChecaHeap: Eh uma heap");
}

int main(){
    struct paciente **heap;
    char nome[50];
    int tam, prio, n_comp = 0, n_trocas = 0, i; /*tam é o tamanho util da heap*/
    printf("===================================================================\n");
    printf("Inicio da execucao do programa de teste\n");
    printf("===================================================================\n");

    printf("Tentando iniciar a heap, que pode ter no maximo %d elementos\n", MAX);
    heap = InicHeap(MAX,&tam);
    if(tam == 0)
        printf("Heap vazia\n\n");

    printf("Insere 5 pacientes na heap\n\n");
    strcpy(nome, "Marchiorato");
    prio = 1;
    HeapInsere(heap,nome,prio,&tam,MAX);
    printf("\nVeja a HEAP:\n");
    ImprimeHeap(heap,tam);
    printf("\n");

    strcpy(nome, "Elisa");
    prio = 2;
    HeapInsere(heap,nome,prio,&tam,MAX);
    printf("\nVeja a HEAP:\n");
    ImprimeHeap(heap,tam);
    printf("\n");

    strcpy(nome, "Rafael");
    prio = 3;
    HeapInsere(heap,nome,prio,&tam,MAX);
    printf("\nVeja a HEAP:\n");
    ImprimeHeap(heap,tam);
    printf("\n");

    strcpy(nome, "Nicolas");
    prio = 2;
    HeapInsere(heap,nome,prio,&tam,MAX);
    printf("\nVeja a HEAP:\n");
    ImprimeHeap(heap,tam);
    printf("\n");

    strcpy(nome, "Kedlin");
    prio = 1;
    HeapInsere(heap,nome,prio,&tam,MAX);
    printf("\nVeja a HEAP:\n");
    ImprimeHeap(heap,tam);
    printf("\n");

    printf("Tenta inserir mais um paciente\n");
    strcpy(nome, "Juliano");
    prio = 1;
    HeapInsere(heap,nome,prio,&tam,MAX);
    printf("\nVeja a HEAP:\n");
    ImprimeHeap(heap,tam);
    printf("\n");

    printf("Verificando se eh uma heap\n");
    HeapCheca(heap,tam);
    printf("\n");

    printf("Alterando a prioridade de dois pacientes\n\n");
    strcpy(nome, "Marchiorato");
    prio = 3;
    HeapAtualiza(heap,nome,prio,tam);
    printf("\nVeja a HEAP:\n");
    ImprimeHeap(heap,tam);
    printf("\n");

    strcpy(nome, "Rafael");
    prio = 1;
    HeapAtualiza(heap,nome,prio,tam);
    printf("\nVeja a HEAP:\n");
    ImprimeHeap(heap,tam);
    printf("\n");

    printf("Ordena Heap em ordem crescente de prioridade\n");
    HeapOrdena(heap,tam);
    printf("\nVeja a HEAP ORDENADA: \n");
    ImprimeHeap(heap,tam);
    printf("\n");

    printf("Volta o vetor a uma Heap\n");
    Heapfy(heap,tam,&n_comp,&n_trocas);
    printf("Heapfy fez %d comparacoes e %d trocas", n_comp,n_trocas);
    printf("\nVeja a HEAP:\n");
    ImprimeHeap(heap,tam);
    printf("\n");

    printf("Verificando se eh uma heap\n");
    HeapCheca(heap,tam);
    printf("\n\n");

    printf("Remove os 5 pacientes e tenta remover mais um\n\n");
    for(i=1;i<=6;i++){
        HeapRemove(heap,&tam);
        printf("\nHEAP:\n");
        ImprimeHeap(heap,tam);
        printf("\n");
    }

    if(tam == 0)
        printf("Heap vazia\n");

    free(heap);
    printf("\nFim do programa de teste\n");
}

