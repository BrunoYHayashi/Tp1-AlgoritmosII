#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

int escolhePivo(int v[], int ini, int fim){
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

void Particao(int v[], int ini, int fim, int *pos_pivo, int *n_comp, int *n_trocas){
    int i = ini +1, j = fim, pivo, aux;
    pivo = escolhePivo(v,ini,fim);

    while(i<j){
        while(i<fim && v[i] <= pivo){
            i++;
            (*n_comp)++;
        }
        while(j>ini && v[j]> pivo){
            j--;
            (*n_comp)++;
        }
        if(i<j){
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            (*n_trocas)++;
        }
    }
    v[ini] = v[j];
    v[j] = pivo;
    *pos_pivo = j;
    (*n_trocas)++;
}

void QuickSort(int v[], int ini, int fim, int *n_comp, int *n_trocas){
    int pos_pivo;
    if(ini<fim){
        Particao(v,ini,fim,&pos_pivo,n_comp,n_trocas);
        QuickSort(v,ini,pos_pivo - 1, n_comp, n_trocas);
        QuickSort(v, pos_pivo+1, fim, n_comp, n_trocas);
    }
    
}

void SelectSort(int v[], int tam, int *n_comp, int *n_trocas){
    int i, j, menor, aux;   
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
/*
void HeapSort(int v[], int tam, int *n_comp, int *n_trocas){

}
*/