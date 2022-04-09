#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "Algoritmos.h"

#define MIL 1000
#define CINCO_MIL 5000
#define DEZ_MIL 10000
#define VINTE_MIL 20000
#define CINQUENTA_MIL 50000
#define CEM_MIL 100000
#define UM_MILHAO 1000000

int menu();
int submenu();
int selecionaQuantidade(int qtde);
void preencherVetorAsc(int *vetor, int tamanho);
void preencherVetorDesc(int *vetor, int tamanho);
void embaralhaVetor(int *vetor, int tamanho);
double mediaDeTempo(int tamanho, int algoritmo, int *vetor);
double calcularMediaDeTempo(double *tempo);
double selecionaAlgortimo(int algoritmo, int *vetor, int tamanho);
double melhorCaso(int algoritmo, int tamanho, int *vetor);
double piorCaso(int algoritmo, int tamanho, int *vetor);
void exibirTempo(double tempo, char texto[]);

int main(){
    srand((unsigned)time(NULL));

    int algoritmo, tamanho, *vetor;

    algoritmo = menu();
    tamanho = submenu();
    tamanho = selecionaQuantidade(tamanho);

    vetor = malloc(sizeof(int) * tamanho);

    exibirTempo(mediaDeTempo(tamanho, algoritmo, vetor), "media");
    exibirTempo(melhorCaso(algoritmo, tamanho, vetor), "no melhor");
    exibirTempo(piorCaso(algoritmo, tamanho, vetor), "no pior");

    free(vetor);
    return 0;
}

int menu(){
    int opt1;
    printf("------------DESEMPENHO ALGORITMOS DE ORDENACAO------------\n");
    printf("\n1-BubbleSort\n2-InsertionSort\n3-SelectionSort\n4-ShellSort\n5-MergeSort\n6-QuickSort\n7-HeapSort\n8-RadixSort\n9-TimSort\n10-BeadSort\n11-CountingSort");
    printf("\n\nInforme o algoritmo a ser testado:\n");
    scanf("%d", &opt1);

    return opt1;
}

int submenu(){
    int opt2;
    printf(" \n1 - 1.000 elementos \n2 - 5.000 elementos \n3 - 10.000 elementos \n4 - 20.000 elementos \n5 - 50.000 elementos \n6 - 100.000 elementos \n7 - 1.000.000 elementos");
    printf("\n\nInforme quantidade de elementos a serem ordenados:\n");
    scanf("%d", &opt2);

    return opt2;
}

int selecionaQuantidade(int qtde) {
    switch(qtde){
        case 1:
            return MIL;
            break;

        case 2:
            return CINCO_MIL;
            break;

        case 3:
            return DEZ_MIL;
            break;

        case 4:
            return VINTE_MIL;
            break;

        case 5:
            return CINCO_MIL;
            break;

        case 6:
            return CEM_MIL;
            break;
        case 7:
            return UM_MILHAO;
            break;
    }
}

void preencherVetorAsc(int *vetor, int tamanho) {
    for(int i = 0; i <= tamanho; i++) {
        vetor[i] = i;
    }
}

void preencherVetorDesc(int *vetor, int tamanho) {
    int i = 0;
    for(int j = tamanho; j >= 0; j--) {
        vetor[i] = j;
        i++;
    }
}

void embaralhaVetor(int *vetor, int tamanho) {
    for(int i = tamanho; i > 0; i--) {
        int j = rand() % (i + 1);
        int tmp = vetor[j];
        vetor[j] = vetor[i];
        vetor[i] = tmp;
    }
}

double mediaDeTempo(int tamanho, int algoritmo, int *vetor) {
    double *tempo = malloc(sizeof(double) * 10);

    for(int i = 0; i <= 10; i++) {
        preencherVetorAsc(vetor, tamanho);
        embaralhaVetor(vetor, tamanho);

        tempo[i] = selecionaAlgortimo(algoritmo, vetor, tamanho);
    }

    double media = calcularMediaDeTempo(tempo);
    free(tempo);

    return media;
}

double calcularMediaDeTempo(double *tempo) {
    double media;

    for(int i = 0; i <= 10; i++) {
        media += tempo[i];
    }

    return media / 10;
}

double selecionaAlgortimo(int algoritmo, int *vetor, int tamanho) {
    struct timeval Tempo_antes, Tempo_depois;

    switch(algoritmo){
        case 1:
            gettimeofday(&Tempo_antes, NULL);
            ordenaBubbleSort(vetor, tamanho);
            gettimeofday(&Tempo_depois, NULL);
            break;

        case 2:
            gettimeofday(&Tempo_antes, NULL);
            ordenaInsertionSort(vetor, tamanho);
            gettimeofday(&Tempo_depois, NULL);
            break;

        case 3:
            gettimeofday(&Tempo_antes, NULL);
            ordenaSectionSort(vetor, tamanho);
            gettimeofday(&Tempo_depois, NULL);
            break;

        case 4:
            gettimeofday(&Tempo_antes, NULL);
            ordenaShellSort(vetor, tamanho);
            gettimeofday(&Tempo_depois, NULL);
            break;

        case 5:
            gettimeofday(&Tempo_antes, NULL);
            ordenaMergeSort(vetor, tamanho);
            gettimeofday(&Tempo_depois, NULL);
            break;

        case 6:
            gettimeofday(&Tempo_antes, NULL);
            ordenaQuickSort(vetor, 0, tamanho - 1);
            gettimeofday(&Tempo_depois, NULL);
            break;

        case 7:
            gettimeofday(&Tempo_antes, NULL);
            ordenaHeapSort(vetor, tamanho);
            gettimeofday(&Tempo_depois, NULL);
            break;

        case 8:
            gettimeofday(&Tempo_antes, NULL);
            ordenaRadixSort(vetor, tamanho);
            gettimeofday(&Tempo_depois, NULL);
            break;

        case 9:
            gettimeofday(&Tempo_antes, NULL);
            ordenaTimSort(vetor, tamanho);
            gettimeofday(&Tempo_depois, NULL);
            break;

        case 10:
            gettimeofday(&Tempo_antes, NULL);
            ordenaBeadSort(vetor, tamanho);
            gettimeofday(&Tempo_depois, NULL);
            break;

        case 11:
            gettimeofday(&Tempo_antes, NULL);
            ordenaCoutingSort(vetor, tamanho);
            gettimeofday(&Tempo_depois, NULL);
            break;
    }

    return (Tempo_depois.tv_sec + Tempo_depois.tv_usec / 1000000.0) -
                 (Tempo_antes.tv_sec + Tempo_antes.tv_usec / 1000000.0);
}

double melhorCaso(int algoritmo, int tamanho, int *vetor) {
    preencherVetorAsc(vetor, tamanho);
    return selecionaAlgortimo(algoritmo, vetor, tamanho);
}

double piorCaso(int algoritmo, int tamanho, int *vetor) {
    preencherVetorDesc(vetor, tamanho);
    return selecionaAlgortimo(algoritmo, vetor, tamanho);
}

void exibirTempo(double tempo, char texto[]) {
    printf("\nO tempo %s caso e: %f\n", texto, tempo);
}
