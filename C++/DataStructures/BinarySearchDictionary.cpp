#include "BinarySearchDictionary.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

BinarySearchDictionary::BinarySearchDictionary() {
	_maxEntries = 100;
	_n = 0;
	_array = new BinSearchEntry[_maxEntries];
	_isSorted = true;
}
BinarySearchDictionary::~BinarySearchDictionary() {
	delete [] _array;
}
void BinarySearchDictionary::insert(char* key, void* data) {
	//check if array is full
	if (_n >= _maxEntries)
	{
		//array is full, must resize
		_maxEntries *= 2;
		BinSearchEntry * newArray = new BinSearchEntry[_maxEntries];
		//copy content into new array
		for (int i = 0; i < _n; ++i)
		{
			newArray[i] = _array[i];
		}
		//delete old array
		delete [] _array;
		//set _array to new array
		_array = newArray;
	}
	BinSearchEntry * newEntry = new BinSearchEntry;
	newEntry->_key = key;
	newEntry->_data = data;
	_array[_n] = *newEntry;
	_n++;
	_isSorted = false;
}
void* BinarySearchDictionary::lookup(char*key) {
	if (!_isSorted){
		//heapsort(_array); //would have to make heapsort take in BinSearchEntry* ptr
		_isSorted = true;
	}
	int low = 0;
	int high = _n - 1;

	while(low <= high) {
        int mid = (low+high)/2;
        int result = strcmp(key, _array[mid]._key);
        if(result == 0) {
            // Found item
            return _array[mid]._data;
        }
        else if(result < 0) {
            // key-mid < 0
            high = mid-1;
        }
        else { // result > 0
            // key-mid > 0
            // key is in the higher side --> modify low to mid
            low = mid+1;
        }
    }
    //Didn't find anything
    return NULL;
}
bool BinarySearchDictionary::remove(char*key) {

}
void BinarySearchDictionary::print(){
	BinSearchEntry * ptr = _array;
	for (int i = 0; i < _n; ++i){
		printf("%s\n", ptr->_key);
		ptr++;
	}
}
int main(int argc, char const *argv[])
{
	BinarySearchDictionary * b = new BinarySearchDictionary();
	b->insert((char*)"William", (void*)"huang");
	b->print();
	return 0;
}