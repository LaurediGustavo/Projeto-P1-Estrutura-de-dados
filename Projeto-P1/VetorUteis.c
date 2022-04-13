#include <stdio.h>
#include <stdlib.h>
#include "VetorUteis.h"

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

int *alocarMemoriaInteiro(int tamanho) {
    int *vetor = (int*) malloc(sizeof(int) * tamanho);

    if (vetor == NULL) {
        printf("Espaco insuficiente!");
        exit(1);
    }

    return vetor;
}

double *alocarMemoriaDouble(int tamanho) {
    double *vetor = (double*) malloc(sizeof(double) * tamanho);

    if (vetor == NULL) {
        printf("Espaco insuficiente!");
        exit(1);
    }

    return vetor;
}
