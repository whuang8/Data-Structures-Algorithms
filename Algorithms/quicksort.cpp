#include <iostream>
using namespace std;


void quicksort(int *a, int n ) {
	//divide phase complete
	if(n < 2){
		return;
	}

	int pivot = a[n-1];
	int l = 0;
	int r = n-2;

	while(l < r){
		while(l < r && a[l] < pivot){
			l++;
		}
		while(l < r && a[r] > pivot){
			r--;
		}
		if(l < r){
			int temp = a[l];
			a[l] = a[r];
			a[r] = temp;
		}
	}
	int temp = a[l];
	a[l] = a[n-1];
	a[n-1] = temp;
	quicksort(a,l);
	quicksort(a+l+1, n-l-1);

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

	quicksort(array, 10);

	cout << "Sorted array using Merge Sort: [";
	for (i = 0; i < 9; ++i){
		cout << array[i] << ",";
	}
	cout << array[i] << "]\n";
	return 0;
}