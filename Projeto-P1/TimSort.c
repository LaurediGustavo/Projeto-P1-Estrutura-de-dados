#include <stdio.h>
#include <stdlib.h>
#include "Algoritmos.h"

#define RUN 2

void ordenaTimSort(int arr[], unsigned int size) {
    if (arr == NULL || size <= 1) return;

    for (int i=0; i < size; i+=RUN){
        insertionSort(arr, i, min(i+RUN-1, size-1));
    }

    int* temp = (int*)malloc(sizeof(int)*size);

    int l, m, r, n;
    for (n=RUN; n < size; n*=2){
        for (l=0; l < size; l+=2*n){
            m = l+n-1;
            r = min(l+2*n-1, size-1);
            if (m<r){
                mergeTimSort(arr, temp, l, m, r);
            }
        }
    }

    free(temp);
}

int min(int arg1, int arg2){
    if (arg1 <= arg2){
        return arg1;
    } else {
        return arg2;
    }
}

void mergeTimSort(int arr[], int temp[], int l, int m, int r){
    if (arr == NULL || temp == NULL) return;

    if (l > m || m+1 > r) return;

    int i = l;
    int j = m + 1;
    int start = l;

    while (i <= m && j <= r){
        if (arr[i] < arr[j]){
            temp[start++] = arr[i++];
        } else if (arr[i] == arr[j]){
            temp[start++] = arr[i++];
            temp[start++] = arr[j++];
        }
        else{
            temp[start++] = arr[j++];
        }

    }

    while (i <= m){
	    temp[start++] = arr[i++];
    }

    while (j <= r){
	    temp[start++] = arr[j++];
    }

    for (i = l; i <= r; i++){
	    arr[i] = temp[i];
    }
}

void insertionSort(int arr[], int l, int r) {
    if (arr == NULL || l>=r) return;

    int key;
    int i, j;
    for (i=l+1; i<=r; i++) {
        key = arr[i];
        j = i-1;

        while (j>=l && arr[j]>key) {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }

}
