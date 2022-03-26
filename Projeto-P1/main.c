#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Algoritmos.h"

#define MIL 1000
#define CINCO_MIL 5000
#define DEZ_MIL 10000
#define VINTE_MIL 20000
#define CINQUENTA_MIL 50000
#define CEM_MIL 100000

void preencherVetor(int *vetor, int tamanho);
void embaralhaVetor(int *vetor, int tamanho);
void testarAlgoritmo(int tamanho);

int main(){
    srand((unsigned)time(NULL));

    testarAlgoritmo(MIL);

    return 0;
}

void preencherVetor(int *vetor, int tamanho) {
    for(int i = 0; i <= tamanho; i++) {
        vetor[i] = i;
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

void testarAlgoritmo(int tamanho) {
    int *vetor = malloc(sizeof(int) * tamanho);

    for(int i = 0; i <= 10; i++) {
        preencherVetor(vetor, tamanho);
        embaralhaVetor(vetor, tamanho);
        ordenaBubbleSort(vetor, tamanho);
    }

    free(vetor);
}
