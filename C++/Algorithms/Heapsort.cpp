#include "Heap.h"
#include <stdlib.h>
#include <stdio.h>

void heapsort(int* array, int n){
	Heap* heap = new Heap(n);
	for (int i = 0; i < n; ++i)
	{
		heap->insert(array[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		heap->removeMin(array[i]);
	}
}

int main(int argc, char const *argv[])
{
	int arraySize = 1000;
	int * array = new int[arraySize];
	printf("%s\n","Original Array:" );
	for (int i = 0; i < arraySize; ++i)
	{
		array[i] = rand() % 10000;
		printf("%d, ",array[i] );
	}

	heapsort(array, arraySize);
	printf("\n%s\n", "Sorted array:");
	for (int i = 0; i < arraySize; ++i)
	{
		printf("%d, ", array[i]);
	}
	return 0;
}