#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"

int menu(){
    int opt1;
    printf("------------DESEMPENHO ALGORITMOS DE ORDENACAO------------\n");
    printf("\n1-BubbleSort\n2-InsertionSort\n3-SelectionSort\n4-ShellSort\n5-MergeSort\n6-QuickSort\n7-HeapSort\n8-RadixSort\n9-TimSort\n10-BeadSort\n11-CountingSort");
    printf("\n\nInforme o algoritmo a ser testado:\n");
    scanf("%d", &opt1);

    return opt1;
}

int submenu(){
    int opt2;
    printf(" \n1 - 1.000 elementos \n2 - 5.000 elementos \n3 - 10.000 elementos \n4 - 20.000 elementos \n5 - 50.000 elementos \n6 - 100.000 elementos \n7 - 1.000.000 elementos");
    printf("\n\nInforme quantidade de elementos a serem ordenados:\n");
    scanf("%d", &opt2);

    return opt2;
}
