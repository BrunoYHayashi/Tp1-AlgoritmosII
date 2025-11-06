#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "heap.h"
#include "sorts.h"

int CadastrarPaciente(struct paciente *heap[], int *tam, int N){
    const int MAX= 50; 
    char nome[MAX];
    int prioridade;

    printf("Insira o nome do paciente\n");
    fgets(nome, MAX, stdin); //lê o nome
    nome[strcspn(nome, "\n")] = 0; //reconhece a quebra de linha (ENTER)

    printf("Insira a prioridade do paciente\n");
    scanf("%d", &prioridade);

    int c; //Serve para limpar o buffer (corredor de 'coisas' que o usuário digitou. Para não quebrar)
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
    if(!heap||!tam)
        return;

    struct paciente *pacienteRemovido;

    printf("Chamando próximo paciente...\n");
    pacienteRemovido= RemoveHeap(heap, tam);

    if(pacienteRemovido==NULL){
        printf("A fila está vazia");
        return;
    }

    printf("Paciente: %s, de prioridade %d, removido da fila\n", pacienteRemovido->nome, pacienteRemovido->prioridade);
    free(pacienteRemovido);
}

void ImprimirPacientes(struct paciente *heap[], int tam){
    int x;
    x= ChecaHeap(heap,tam);

    if(!x){
        int comparacoes=0, trocas=0;
        Heapfy(heap, tam, &comparacoes, &trocas);
        printf("Heapfy fez %d comparações e %d trocas", comparacoes, trocas);
    }

    printf("Imprimindo pacientes:\n");
    ImprimeHeap(heap,tam);
}

void OrdenarPacientes(struct paciente *heap[], int tam){
    printf("Ordenando pacientes...\n");
    int comparacoes=0, trocas=0;

    HeapSort(heap, tam, &comparacoes, &trocas);
    printf("Heapfy e HeapSort juntos fizeram %d comparações e %d trocas", comparacoes, trocas);
    
    printf("Imprimindo pacientes ordenados:\n");
    ImprimeHeap(heap,tam);
}

void AtualizarPrioridade(struct paciente *heap[], int tam){
    char nome[50];
    const int MAX=50;
    int prioridade, x;

    printf("Insira o nome do paciente que deseja alterar a prioridade\n");
    fgets(nome, MAX, stdin); 
    nome[strcspn(nome, "\n")] = 0;

    printf("Insira a prioridade NOVA do paciente\n");
    scanf("%d", &prioridade);

    int c; 
    while ((c=getchar()) != '\n' && c != EOF);

    x= AlteraHeap(heap, nome, prioridade, tam);

    if(!x){
        printf("Paciente não encontrado (não existe ou foi digitado errado)");
        return;
    }
    
    printf("Prioridade do paciente %s, alterada!", nome);
}

void CompararSorts(){

}

void LiberaVetor(struct paciente *heap[], int tam){
    if(!heap)
        return;

    int i;

    for(i=1;i<=tam;i++)
        free(heap[i]);

    free(heap);
}

int main(){
    int operacao, encerrar = 0, tam; //tam= numero de pacientes no vetor
    struct paciente **heap;
    const int MAX=1024; //tamanho máximo do vetor

    tam=0;

    heap= InicHeap(MAX, &tam);

    do{
        printf("###################################################\n");
        printf("Insira o numero correspondente a operacao desejada\n");
        printf("\n1.Cadastrar novo paciente");
        printf("\n2.Chamar proximo paciente");
        printf("\n3.Imprimir todos os pacientes em heap");
        printf("\n4.Ordenar pacientes (ordem crescente de prioridade)");
        printf("\n5.Atualizar prioridade");
        printf("\n6.Comparar algoritmos de ordenacao");
        printf("\n7.Encerrar programa\n");
        scanf("%d",&operacao);

        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        switch(operacao){
            case 1:
            CadastrarPaciente(heap,&tam, MAX);
            break;

            case 2:
            ChamarPaciente(heap,&tam);
            break;

            case 3:
            ImprimirPacientes(heap, tam);
            break;

            case 4:
            OrdenarPacientes(heap, tam);
            break;

            case 5:
            AtualizarPrioridade(heap, tam);
            break;

            case 6:
            CompararSorts();
            break;

            case 7:
            LiberaVetor(heap, tam);
            encerrar = 1;
            break;

            default:
            printf("Por favor, digite um numero valido");
        }
    }while(!encerrar);   
    return 0;
}