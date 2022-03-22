#include <stdio.h>
#include <stdlib.h>
#include "Algoritmos.h"

void ordenaQuickSort(int vect[], int inicio, int fim) {
    int ini, fi, pivo, aux;

    if(inicio < fim) {
        ini = inicio;
        fi = fim;
        pivo = inicio;

        while(ini < fi) {
            while(vect[ini] <= vect[pivo] && ini < fim) {
                ini++;
            }
            while(vect[fi] > vect[pivo]) {
                fi--;
            }

            if(ini < fi) {
                aux = vect[ini];
                vect[ini] = vect[fi];
                vect[fi] = aux;
            }

            aux = vect[pivo];
            vect[pivo] = vect[fi];
            vect[fi] = aux;

            ordenaQuickSort(vect, inicio, fi - 1);
            ordenaQuickSort(vect, fi + 1, fim);
        }
    }
}
