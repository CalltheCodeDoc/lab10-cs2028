#include "ChainHash.h"
#include "LinkedList.h"
#include "Hash.h"
#include <string>
#include <iostream>
#include <math.h>

using namespace std;

template <typename T>
ChainHash<T>::ChainHash() {

	table = new LinkedList<T>* [100];
	SIZE = 100;
	length = 0;
}

template <typename T>
ChainHash<T>::ChainHash(int size){
	SIZE = size;
	table = new LinkedList<T>*[SIZE];
}

template <typename T>
ChainHash<T>::~ChainHash() {
}

template <typename T>
bool ChainHash<T>::operator > (const ChainHash& rhs) const {
}

template <typename T>
bool ChainHash<T>::operator < (const ChainHash& rhs) const {
}

template <typename T>
bool ChainHash<T>::operator == (const ChainHash& rhs) const {
}

template <typename T>
bool ChainHash<T>::operator != (const ChainHash& rhs) const {
}

template <typename T>
void ChainHash<T>::AddItem(T* inval) {
	int base_index = hash(*inval);
	table[base_index%SIZE]->AddItem(inval);
	length++;
}

template <typename T>
T* ChainHash<T>::RemoveItem(T* inval) {
	int base_index = hash(*inval);
	/*
	try {
		Node<T>* temp = table[base_index % SIZE]->GetItem(inval, table[base_index % SIZE]->head);
		length--;
		return temp;
		//this doesn't delete it right?
	}
	catch () {
		"Item not here";
	}
	*/
}

template <typename T>
T* ChainHash<T>::GetItem(T* inval) {
	int base_index = hash(*inval);
	//Need a transverse function that gets item without removing it
	//table[base_index % SIZE]->IsInList(T * item);
}

template <typename T>
int ChainHash<T>::GetLength() {
}
