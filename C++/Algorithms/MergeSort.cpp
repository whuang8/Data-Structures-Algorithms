#include <iostream>
using namespace std;


//sort an array of type int containing n elements
void mergeSort(int* array, int n){
	//base case
	if (n == 1)
		return;

	//divide phase
	int n1 = n/2;
	int n2 = n-n1;

	//allocate memory for second arr1 and arr2
	int * arr1 = new int[n1];
	int * arr2 = new int[n2];

	//Form arr1 and arr2 by copying elememnts from array
	int i;
	for(i = 0; i < n1; i++){
		arr1[i] = array[i];
	}
	for (i = 0; i < n2; ++i){
		arr2[i] = array[i+n1];		
	}

	//call mergesort recursively 
	mergeSort(arr1, n1);
	mergeSort(arr2, n2);

	//conquer
	i = 0;
	int i1 = 0;	//index for arr1
	int i2 = 0;	//index for arr2

	while(i1 < n1 && i2 < n2){
		if(arr1[i1] < arr2[i2]){
			//start meging back into arr
			array[i++] = arr1[i1++];
		}
		else{
			array[i++] = arr2[i2++];
		}
	}

	/* Reached the en of arr1 or arr2,
	merge the remaining elements. */
	for (i1;i1 < n1; i1++){
		array[i++] = arr1[i1];
	}
	for (i2; i2 < n2; i2++){
		array[i++] = arr2[i2];
	}

	//deallocate memory
	delete [] arr1;
	delete [] arr2;
}

int main(int argc, char const *argv[])
{
	int a[] = {10,6,9,2,3,11,8,15,1,4};
	int * array = a;
	int i;

	cout << "Original Array: [";
	for (i = 0; i < 9; ++i){
		cout << array[i] << ",";
	}
	cout << array[i] << "]\n";

	mergeSort(array, 10);

	cout << "Sorted array using Merge Sort: [";
	for (i = 0; i < 9; ++i){
		cout << array[i] << ",";
	}
	cout << array[i] << "]\n";
	return 0;
}