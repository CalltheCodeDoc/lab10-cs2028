#include "ChainHash.h"
#include "LinkedList.h"
#include "Hash.h"
#include <string>
#include <iostream>
#include <math.h>

using namespace std;

template <typename T>
ChainHash<T>::ChainHash() : Hash<T>() {

	//Remember this derives from the base class so some of this is unecessary
	this->SIZE = 100;
	this->table = new LinkedList<T>*[SIZE];
	for (int i = 0; i < SIZE; i++) {
		table[i] = new LinkedList<T>();
		//table[i]->head = nullptr;
	}
	this->items = 0;
}

template <typename T>
ChainHash<T>::ChainHash(int size) : Hash<T>(size) {
	//Remember this derives from the base class so some of this is unecessary
	this->SIZE = size;
	this->table = new LinkedList<T>*[SIZE];
	for (int i = 0; i < size; i++) {
		table[i] = new LinkedList<T>();
		//table[i]->head = nullptr;
	}
	this->items = 0;
}

template <typename T>
ChainHash<T>::~ChainHash() {
}



template <typename T>
void ChainHash<T>::AddItem(T* inval) {
	int base_index = hash(*inval);
	this->table[base_index%SIZE]->AddItem(inval);
	this->items++;
}

template <typename T>
T* ChainHash<T>::RemoveItem(T* inval) {
	int base_index = hash(*inval);
	
	Node<T>* temp = table[base_index % SIZE]->GetItem(inval, table[base_index % SIZE]->head);
	this->items--;
	/*
	try {
		Node<T>* temp = table[base_index % SIZE]->GetItem(inval, table[base_index % SIZE]->head);
		this->items--;
		return temp;
		//this doesn't delete it right?
	}
	catch () {
		"Item not here";
	}
	*/
	return temp->data;
}

template <typename T>
T* ChainHash<T>::GetItem(T* inval) {
	int base_index = hash(*inval);
	Node<T>* temp = table[base_index % SIZE]->FindItem(inval, table[base_index % SIZE]->head);
	this->numComparisons += table[base_index % SIZE]->numRecursions;
	if (temp == nullptr)
		return nullptr;
	else
		return temp->data;
}

template <typename T>
int ChainHash<T>::GetLength() {
	return items;
}

template <typename T>
int ChainHash<T>::hash(T inval) {
	int computation;
	//string stringify = to_string(inval);
	std::ostringstream oss;
	if constexpr (std::is_pointer<T>::value) {
		oss << *inval;
	}
	else {
		oss << inval;
	}
	std::string stringify = oss.str();
	long value = 0;

	for (auto x : stringify) {
		value += static_cast<int>(x);
	}
	
	computation = value % SIZE;  
	return computation;
}

