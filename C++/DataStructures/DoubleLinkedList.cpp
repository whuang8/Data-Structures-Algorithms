#include "DoubleLinkedList.h"
#include <stdlib.h>
#include <stdio.h>

DoubleLinkedList::DoubleLinkedList(){
	_sentinel = new DoubleLinkedListNode;
	_sentinel->_next = _sentinel;
	_sentinel->_previous = _sentinel;
}
DoubleLinkedList::~DoubleLinkedList(){
	delete [] _sentinel;
}

void DoubleLinkedList::insertFront(char* key, int value){
	//creat new node
	DoubleLinkedListNode *newNode = new DoubleLinkedListNode;

	//set newNode values
	newNode->_key = key;
	newNode->_value = value;

	//if list is empty
	if (_sentinel->_next == _sentinel){
		_sentinel->_next = newNode;
		_sentinel->_previous = newNode;
		newNode->_next = _sentinel;
		newNode->_previous = _sentinel;
		return;
	}

	//list not empty
	newNode->_next = _sentinel->_next;
	newNode->_previous = _sentinel;
	//redirect sentinel's _next and the first element's _last
	_sentinel->_next->_previous = newNode;
	_sentinel->_next = newNode;
	return;
}

void DoubleLinkedList::insertEnd(char* key, int value){
	//creat new node
	DoubleLinkedListNode *newNode = new DoubleLinkedListNode;

	//set newNode values
	newNode->_key = key;
	newNode->_value = value;

	//if list is empty
	if (_sentinel->_next == _sentinel){
		_sentinel->_next = newNode;
		_sentinel->_previous = newNode;
		newNode->_next = _sentinel;
		newNode->_previous = _sentinel;
		return;
	}

	//list not empty
	newNode->_next = _sentinel;
	newNode->_previous = _sentinel->_previous;

	//redirect sentinel's _next and the first element's _last
	_sentinel->_previous->_next = newNode;
	_sentinel->_previous = newNode;
	return;
}

bool DoubleLinkedList::removeFront(){
	//Check if list is empty
	if (_sentinel->_next == _sentinel){
		return false;
	}
	//list is not empty
	DoubleLinkedListNode *ptr = _sentinel->_next;
	//disconnect first element from list
	_sentinel->_next->_next->_previous = _sentinel;
	_sentinel->_next = _sentinel->_next->_next;
	delete ptr;
	return true;
}

bool DoubleLinkedList::removeEnd(){
	//Check if list is empty
	if (_sentinel->_next == _sentinel){
		return false;
	}
	//list is not empty
	DoubleLinkedListNode *ptr = _sentinel->_previous;
	//disconnect first element from list
	_sentinel->_previous->_previous->_next = _sentinel;
	_sentinel->_previous = _sentinel->_previous->_previous;
	delete ptr;
	return true;
}

void DoubleLinkedList::printList(){
	DoubleLinkedListNode *ptr = _sentinel->_next;
	int count = 1;
	while(ptr != _sentinel){
		printf("Node %d\nKey:%s Value:%d\n\n", count, ptr->_key, ptr->_value);
		count++;
		ptr = ptr->_next;
	}
}

int main(int argc, char const *argv[])
{
	//Test entries
	DoubleLinkedList* list = new DoubleLinkedList();
	list->insertFront((char*)"William", 20);
	list->insertFront((char*)"Joe", 19);
	list->insertFront((char*)"Jason", 18);
	list->insertFront((char*)"Niki", 21);
	list->insertFront((char*)"Jessica", 22);
	list->insertFront((char*)"Kevin", 20);
	list->insertFront((char*)"Christina", 19);
	list->insertEnd((char*)"Bill", 21);
	list->insertEnd((char*)"Samantha", 20);
	list->printList();
	list->removeFront();
	list->removeFront();
	list->removeEnd();
	list->removeEnd()
	
	list->printList();

	return 0;
}