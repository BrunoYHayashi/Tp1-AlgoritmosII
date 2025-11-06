#include <stdio.h>
#include <stdlib.h>

#include "heap.h"
//#include "sorts.h"

int CadastrarPaciente(struct paciente *heap[], int *tam){
 /*   struct paciente *p;

    if(!(p = malloc(sizeof(struct paciente *)))){
        printf("nao foi possivel alocar memoria");
        return 0;
    }

    printf("Insira o nome do paciente");
    scanf("%s", p->nome);

    printf("Insira a prioridade do paciente");
    scanf("%d", &(p->prioridade));

    [*tam]++;
    heap[*tam] = p;
    InsereHeap(p,*tam);*/
}

void ChamarPaciente(struct paciente *heap[], int *tam){
    printf("removendo paciente %s de prioridade %d\n", heap[1]->nome, heap[1]->prioridade);
    RemoveHeap(heap, tam);

    printf("paciente removido");
}

void ImprimirPacientes(struct racional *heap[], int tam){
    printf("Pacientes: ");
    ImprimeHeap(heap,tam);
}

void OrdenarPacientes(){

}

void AtualizarPrioridade(){

}

void CompararSorts(){

}

int main(){
    int operacao, encerrar = 0, tam;
    struct paciente **heap;

    InicHeap(heap);
    tam = 0;

    do{
        printf("###################################################\n");
        printf("Insira o numero correspondente a operacao desejada\n");
        printf("\n1.Cadastrar novo paciente");
        printf("\n2.Chamar proximo paciente");
        printf("\n3.Imprimir todos os pacientes");
        printf("\n4.Ordenar pacientes (ordem crescente de prioridade)");
        printf("\n5.Atualizar prioridade");
        printf("\n6.Comparar algoritmos de ordenacao");
        printf("\n7.Encerrar programa\n");
        scanf("%d",&operacao);

        switch(operacao){
            case 1:
            CadastrarPaciente(heap,&tam);
            break;

            case 2:
            ChamarPaciente(heap,&tam);
            break;

            case 3:
            ImprimirPacientes();
            break;

            case 4:
            OrdenarPacientes();
            break;

            case 5:
            AtualizarPrioridade();
            break;

            case 6:
            CompararSorts();
            break;

            case 7:
            encerrar = 1;
            break;

            default:
            printf("Por favor, digite um numero valido");
        }
    }while(!encerrar);   
    return 0;
}