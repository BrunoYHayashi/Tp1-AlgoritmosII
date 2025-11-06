#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

#define MAX 5

void HeapInsere(struct paciente *heap[], char nome[], int prio, int tam, int max){

}

void HeapImprime(){

}

int main(){
    struct paciente **heap;
    char nome[50];
    int tam, prio; /*tam é o tamanho util da heap*/
    printf("===================================================================");
    printf("Inicio da execucao do programa de teste");
    printf("===================================================================");

    InicHeap(MAX,&tam);
    if(tam == 0)
        printf("Heap vazia");

    strycpy(nome, "Marchiorato");
    prio = 1;
    HeapInsere(heap,nome,prio,tam,MAX);
    ImprimeHeap(heap,tam);

    strycpy(nome, "Marchiorato");
    prio = 1;
    InsereNovoHeap(heap,nome,prio,&tam,MAX);
}

