#include <stdio.h>
#include <stdlib.h>
#include "Algoritmos.h"

void ordenaQuickSort(int *vetor, int esquerda, int direita) {
    int i, j, meio, troca;
    i = esquerda;
    j= direita;
    meio = vetor[(esquerda+direita) / 2];

    while(i <= j)
    {
        while(vetor[i] < meio && i < direita)
        {
            i++;
        }

        while(vetor[j] > meio && j > esquerda)
        {
            j--;
        }

        if(i <= j)
        {
            troca = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = troca;
            i++;
            j--;
        }
    }

    if(j > esquerda)
    {
        ordenaQuickSort(vetor, esquerda, j);
    }

    if(i < direita)
    {
        ordenaQuickSort(vetor, i, direita);
    }
}
