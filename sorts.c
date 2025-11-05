#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

int escolhePivo(int *heap[], int ini, int fim){
    int meio = (ini+fim)/2, aux;

    if(v[ini] > v[meio]){
        aux = v[ini];
        v[ini] = v[meio];
        v[meio] = aux;
    }

    if(v[meio] > v[fim]){
        aux = v[meio];
        v[fim] = v[meio];
        v[meio] = aux;

        if(v[ini] > v[meio]){
            aux = v[ini];
            v[ini] = v[meio];
            v[meio] = aux;
        }
    }

    return meio;
}

void Particao(struct paciente *heap[], int ini, int fim, int *pos_pivo, int *n_comp, int *n_trocas){
    int i = ini +1, j = fim, pivo, aux;
    pivo = escolhePivo(heap,ini,fim);

    while(i<j){
        while(i<fim && heap[i]->prioridade <= pivo){
            i++;
            (*n_comp)++;
        }
        while(j>ini && heap[j]->prioridad > pivo){
            j--;
            (*n_comp)++;
        }
        if(i<j){
            aux = heap[i];
            heap[i] = heap[j]
            heap[j] = aux;
            (*n_trocas)++;
        }
    }
    v[ini] = v[j];
    v[j] = pivo;
    *pos_pivo = j;
    (*n_trocas)++;
}

void QuickSort(struct paciente *heap[], int ini, int fim, *n_comp, *n_trocas){
    int pos_pivo;
    if(ini<fim){
        Particao(heap,ini,fim,&pos_pivo,n_comp,n_trocas);
        QuickSort(heap,ini,pos_pivo - 1, n_comp, n_trocas);
        QuickSort(heap, pos_pivo+1, fim, n_comp, n_trocas);
    }
    
}

void SelectSort(struct paciente *heap[], int tam, int *n_comp, int *n_trocas){
    int i, j, menor, n_comp, n_trocas;

    for(i=1;i<tam;i++){
        v[menor] = v[i];
        for(j=i+1;j<=tam;j++){
            (*n_comp)++;
            if(v[menor] < v[j])
                menor = j;
        }
        aux = v[menor];
        v[menor] = v[i];
        v[i] = aux;
        (*n_trocas)++;
    }
}
