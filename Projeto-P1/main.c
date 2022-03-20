#include <stdio.h>
#include <stdlib.h>
#include "Algoritmos.h"

int main(){
    int v[4] = {4, 3, 2, 1};

    ordenaBubbleSort(v, 4);

    for(int i = 0; i < 4; i++) {
        printf("%d", v[i]);
    }

    printf("\n\n");

    int v1[4] = {4, 3, 2, 1};

    ordenaInsertionSort(v1, 4);

    for(int i = 0; i < 4; i++) {
        printf("%d", v1[i]);
    }

    printf("\n\n");

    int v2[4] = {4, 3, 2, 1};

    ordenaInsertionSort(v2, 4);

    for(int i = 0; i < 4; i++) {
        printf("%d", v2[i]);
    }

    return 0;
}
