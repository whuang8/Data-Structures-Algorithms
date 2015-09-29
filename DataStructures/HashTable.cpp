#include "HashTable.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

HashTable::HashTable(){
	_n = TableSize;
	_buckets = (HashTableEntry **)malloc(_n * sizeof(HashTableEntry));
	//set each bucket to null
	for (int i = 0; i < _n; ++i)
	{
		_buckets[i] = NULL;
	}
}

HashTable::~HashTable(){
	delete [] _buckets;
}

int HashTable::hash(char* key){
	int hashValue = 0;
	int l = strlen(key);
	for (int i = 0; i < l; ++i)
	{
		hashValue += ((i+1) * key[i]);
	}
	return hashValue % _n;
}

bool HashTable::insert(char* key, char* data){
	int i = hash(key);
	HashTableEntry * ptr = _buckets[i];
	//traverse through list
	while(ptr != NULL){
		//check if element already exists in list
		if (ptr->_key == key)
		{
			//replace data
			ptr->_data = data;
			return false;
		}
		ptr = ptr->_next;
	}
	//did not find existing element
	HashTableEntry * newEntry = new HashTableEntry;
	newEntry->_key = key;
	newEntry->_data = data;

	//check if list is empty
	if (ptr == _buckets[i]){
		//is empty
		_buckets[i] = newEntry;
		newEntry->_next = NULL;
	}
	else{
		//is not empty
		newEntry->_next = _buckets[i]->_next;
		//inserts new entry at beginning of list
		_buckets[i]->_next = newEntry;
	}

	return true;
}

bool HashTable::remove(char* key){
	int i = hash(key);
	HashTableEntry * ptr = _buckets[i];
	HashTableEntry * previous = _buckets[i];
	//traverse through list
	while(ptr != NULL){
		//check if element exists in list
		if (ptr->_key == key)
		{
			//check to see if entry is in _buckets[i]
			if (ptr == _buckets[i]){
				_buckets[i] = ptr->_next;
				delete ptr;
				return true;
			}
			previous->_next = ptr->_next;
			delete ptr;
			return true;
		}
		previous = ptr;
		ptr = ptr->_next;
	}
	//did not find entry
	return false;
}

bool HashTable::lookup(char* key, char*&data){
	int i = hash(key);
	HashTableEntry * ptr = _buckets[i];
	while(ptr != NULL){
		if(ptr->_key == key){
			data = ptr->_data;
			return true;
		}
		ptr = ptr->_next;
	}
	//didn't find key
	return false;
}

void HashTable::print(){
	HashTableEntry * ptr;
	for (int i = 0; i < _n; ++i)
	{
		ptr = _buckets[i];
		while(ptr != NULL){
			printf("%s:%s\n",ptr->_key, ptr->_data);
			ptr = ptr->_next;
		}
	}
}

int main(int argc, char const *argv[])
{
	HashTable * table = new HashTable();
	table->insert((char*)"William",(char*) "Huang");
	table->insert((char*)"Tony",(char*) "Soprano");
	table->insert((char*)"Barack",(char*) "Obama");
	table->insert((char*)"Mike",(char*) "Hunt");
	table->remove((char*)"Tony");
	table->remove((char*)"Barack");
	table->remove((char*)"Tony");
	table->print();
	char * data;
	table->lookup((char*)"William", data);
	printf("%s\n",data );
	return 0;
}