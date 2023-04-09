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
	for (int i = 0; i < SIZE; ++i) {
		table[i] = nullptr;
	}
	delete[] table;
	table = nullptr;
	//design decision to not delete contents of items in table, as class did not create those items
}




template <typename T>
void ChainHash<T>::Display() const {
	//Dispays all table slots and also linkedlist slots
	for (int k = 0; k < SIZE; k++) {

		if (table[k] == nullptr) {
			cout << "Slot " << k << " is Empty" << endl;
		}
		else if (table[k]->IsEmpty()) {
			cout << "Slot " << k << " is Empty" << endl;
		} else {
			cout << "Slot " << k << " Contains :" << endl;
			table[k]->Display();
		}
	}
	cout << endl;
}



template <typename T>
void ChainHash<T>::AddItem(T* inval) {
	//adds an item to a table spot and ten a linkedlist slot
	int base_index = hash(*inval);
	this->table[base_index%SIZE]->AddItem(inval);
	this->items++;
}

template <typename T>
T* ChainHash<T>::RemoveItem(T* inval) {
	//removes and returns an item from a linkedlist slot in a table slot
	int base_index = hash(*inval);
	
	Node<T>* temp = table[base_index % SIZE]->GetItem(inval, table[base_index % SIZE]->head);
	if (temp == nullptr) {
		//"No Item is removed"
	}
	else {
		this->items--;
	}
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
	//fetches an item in the linked list within a table slot, does not remove it
	int base_index = hash(*inval);
	Node<T>* temp = table[base_index % SIZE]->FindItem(inval, table[base_index % SIZE]->head);
	this->numComparisons += table[base_index % SIZE]->numRecursions;
	table[base_index % SIZE]->numRecursions = 0;
	//This samples from the specific linkedlist and its number of comparisons
	//then it resets that specific linkedlist, so it doesn't double count if that list is later sampled from again
	if (temp == nullptr)
		return nullptr;
	else
		return temp->data;
}

template <typename T>
int ChainHash<T>::GetLength() {
	//number of items stored in hash
	return items;
}

template <typename T>
int ChainHash<T>::hash(T inval) {
	//hash algorithm that sums the ascii values of each digit of the inval argument
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

