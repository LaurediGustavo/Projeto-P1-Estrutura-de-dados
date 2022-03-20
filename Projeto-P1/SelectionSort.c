#include <stdio.h>
#include <stdlib.h>
#include "Algoritmos.h"

void ordenaSectionSort(int *vetor, int n) {
    int i, j, menor, troca;

    for(i = 0; i < n - 1; i++) {
        menor = i;

        for(j = i + 1; j < n; j++) {
            if(vetor[j] < vetor[menor]) {
                menor = j;
            }
        }
        if(i != menor) {
            troca = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = troca;
        }
    }
}
