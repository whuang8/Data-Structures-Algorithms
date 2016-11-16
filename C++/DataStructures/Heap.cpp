#include "Heap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Heap::Heap(int maxSize){
	_maxSize = maxSize;
	_heap = new int[_maxSize];
	_last = 0;
}

Heap::~Heap(){
	delete [] _heap;
}

int parent(int node){
	return (node-1)/2;
}
int left(int node){
	return node*2 + 1;
}
int right(int node){
	return node * 2 + 2;
}


bool Heap::insert(int data){
	if (_last == _maxSize)
	{
		//heap is full
		return false;
	}
	//insert node at end of heap
	_heap[_last] = data;
	_last++;

	//sort heap
	int child = _last - 1;
	int p = parent(child);

	while(child > 0){
		if (_heap[child] < _heap[p]){
			//swap
			int temp = _heap[child];
			_heap[child] = _heap[p];
			_heap[p] = temp;
			child = p;
			p = parent(child);
		}
		else{
			//no swapping needed
			break;
		}
	}
	return true;

}
bool Heap::removeMin(int &data){
	//check in heap is empty
	if (_last == 0){
		//heap is empty
		return false;
	}
	//heap not empty
	data = _heap[0];
	//replace head node with last node
	_heap[0] = _heap[--_last];

	//sort heap
	int parent = 0;
	int l = left(parent);
	int r = right(parent);

	while(l < _last){
		int minChild = l;
		//check if right child is less than left
		if (r < _last && _heap[r] < _heap[l]){
			minChild = r;
		}
		if (_heap[minChild] < _heap[parent]){
			//swap
			int temp = _heap[minChild];
			_heap[minChild] = _heap[parent];
			_heap[parent] = temp;
			parent = minChild;
			l = left(parent);
			r = right(parent);
		}
		else{
			//nothing to swap
			break;
		}
	}
	return true;
}

// int main(int argc, char const *argv[])
// {
// 	Heap *h = new Heap(1000);
// 	h->insert(2);
// 	h->insert(3);
// 	h->insert(4);
// 	h->insert(27);
// 	h->insert(51);
// 	h->insert(23);
// 	h->insert(-94);
// 	int data;
// 	for (int i = 0; i < 7; ++i)
// 	{
// 		h->removeMin(data);
// 		printf("%d\n",data );
// 	}
// 	return 0;
// }