#include <stdio.h>
#include <stdlib.h>
#include "Algoritmos.h"

void ordenaInsertionSort(int *vetor, int n) {
    int i, j, aux;

    for(i = 1; i < n; i++) {
        aux = vetor[i];
        for(j = i; (j > 0) && (aux < vetor[j - 1]); j--) {
            vetor[j] = vetor[j - 1];
        }
        vetor[j] = aux;
    }
}
