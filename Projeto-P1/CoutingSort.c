#include <stdio.h>
#include <stdlib.h>
#include "Algoritmos.h"

void ordenaCoutingSort(int *array, int n)
{
	int i;

	int max=array[0];
	for(i = 0; i<n; i++){
		if(array[i]>max)
		max=array[i];
	}
	int VetorIndexA[max+1];

	for(i=0;i<=max;i++)	{
		VetorIndexA[i]=0;
	}

	for(i=0;i<n;i++){
		VetorIndexA[array[i]]++;
	}

	for(i=1; i<=max;i++){
		VetorIndexA[i] = VetorIndexA[i]+VetorIndexA[i-1];
	}

    int VetorIndexB[n];
	for(i=n-1; i>=0; i--){
		VetorIndexB[--VetorIndexA[array[i]]]=array[i];
	}

	for(i=0;i<n;i++){
		array[i]=VetorIndexB[i];
	}
}
