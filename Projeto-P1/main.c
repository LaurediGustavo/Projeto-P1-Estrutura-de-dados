#include <stdio.h>
#include <stdlib.h>
#include "Algoritmos.h"

int main(){
    int v[4] = {4, 3, 2, 1};

    ordenaTimSort(v, 4);

    for(int i = 0; i < 4; i++) {
        printf("%d", v[i]);
    }

    return 0;
}
