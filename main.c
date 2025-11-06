#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "heap.h"
//#include "sorts.h"

int CadastrarPaciente(struct paciente *heap[], int *tam, int N){
    const int MAX= 50; 
    char nome[MAX];
    int prioridade;

    printf("Insira o nome do paciente");
    fgets(nome, MAX, stdin); //lê o nome
    nome[strcspn(nome, "\n")] = 0; //reconhece a quebra de linha (ENTER)

    printf("Insira a prioridade do paciente");
    scanf("%d", &prioridade);

    int c; //Serve para limbar o buffer (corredor de 'coisas' que o usuário digitou. Para não quebrar)
    while ((c=getchar()) != '\n' && c != EOF);

    int sucesso;
    sucesso = InsereNovoHeap(heap, nome, prioridade, tam, N);

    if (!sucesso) {
        printf("Falha ao cadastrar paciente, heap cheio ou memória insuficiente.\n");
        return 0;
    }

    printf("Usuário cadastrado com sucesso!\n");
    return 1;
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