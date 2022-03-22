#include <stdio.h>
#include <stdlib.h>
#include "Algoritmos.h"

void ordenaMergeSort(int *vetor1, int tamanho) {
    int *vetor2 = malloc(sizeof(int) * tamanho);
    sort(vetor1, vetor2, 0, tamanho - 1);
    free(vetor2);
}

void merge(int *vetor1, int *vetor2, int start, int mid, int end) {
    int i = start, j = mid+1, k = 0;

    while(i <= mid && j <= end) {
        if(vetor1[i] <= vetor1[j]) {
            vetor2[k] = vetor1[i];
            k += 1; i += 1;
        }
        else {
            vetor2[k] = vetor1[j];
            k += 1; j += 1;
        }
    }

    while(i <= mid) {
        vetor2[k] = vetor1[i];
        k += 1; i += 1;
    }

    while(j <= end) {
        vetor2[k] = vetor1[j];
        k += 1; j += 1;
    }

    for(i = start; i <= end; i += 1) {
        vetor1[i] = vetor2[i - start];
    }
}

void sort(int *vetor1, int *vetor2, int start, int end) {
    if(start < end) {
        int mid = (start + end) / 2;
        sort(vetor1, vetor2, start, mid);
        sort(vetor1, vetor2, mid + 1, end);
        merge(vetor1, vetor2, start, mid, end);
    }
}
