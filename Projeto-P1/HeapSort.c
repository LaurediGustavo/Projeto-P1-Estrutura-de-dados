#include <stdio.h>
#include <stdlib.h>
#include "Algoritmos.h"

void heapfy(int *vet,int n, int i)
{
    int esq =2*i+1;
    int dir =2*i+2;
    int maior,aux;

    maior = i;
    if((esq < n) && (vet[esq] > vet[maior])) {
        maior = esq;
    }

    if((dir < n) && (vet[dir] > vet[maior])) {
        maior = dir;
    }

    if(maior != i) {
        aux = vet[i];
        vet[i] = vet[maior];
        vet[maior]=aux;

        heapfy(vet, n, maior);
    }
}

void create_heap(int *vet, int n)
{
    int i;

    for(i=n/2-1; i>=0; i--){
        heapfy(vet,n,i);
    }
}

void ordenaHeapSort(int *vet, int n) {
    int aux,i;
    create_heap(vet,n);

    for(i=n-1; i>0; i--){
        aux=vet[0];
        vet[0]=vet[i];
        vet[i]=aux;
        n--;
        heapfy(vet,n,0);
    }
}
