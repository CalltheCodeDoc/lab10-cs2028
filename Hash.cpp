#include "Hash.h"
#include <typeinfo>

//Constructor – This should have an overload 
// indicating the maximum
//number of items the Hash table can store.The default value is 100
template <typename T>
Hash<T>::Hash(){
	table = new T*[100];
	SIZE = 100;
	string = "Hash";
}

template <typename T>
Hash<T>::Hash(int size) {
	SIZE = size;
	table = new T*[SIZE];
}

template <typename T>
Hash<T>::~Hash(){
	delete table;
	table = nullptr;
}


//AddItem – adds an item from the list.
template <typename T>
void Hash<T>::AddItem(T* inval) {
	int count = 0;
	int base_index = hash(*inval);
	while (table[base_index%SIZE] != nullptr) { 
		count++;
		base_index++; //linear probing insertion
		if (count >= SIZE) {
			throw "TableOverflowException";
			//can not add items
		}
	}
	
	
	table[base_index] = inval;
	length++;

}


//RemoveItem – searches the list for the given item.If found, it removes it
//from the listand returns it.If not found, it returns a null pointer.
template <typename T>
T* Hash<T>::RemoveItem(T* inval) {

	int count = 0;
	int base_index = hash(*inval);
	while (table[base_index % SIZE] == nullptr || *table[base_index % SIZE] != *inval) {
		count++;
		base_index++; //linear probing insertion
		if (count >= SIZE) {
			return nullptr;
		}
	}

	T* temp = table[base_index];
	table[base_index] = nullptr;
	length--;
	return temp;
}

//GetItem – searches the list for a given item. If found, it returns a pointer
//to the item but doesn’t remove it from the list.
template <typename T>
T* Hash<T>::GetItem(T* inval) {
	int count = 0;
	int base_index = hash(*inval);
	while (table[base_index % SIZE] == nullptr ||*table[base_index % SIZE] != *inval) {
		count++;
		base_index++; //linear probing insertion
		if (count >= SIZE) {
			throw "ItemNotFoundException";
			//item not found
		}
	}
	
	return table[base_index];
}


//GetLength – returns an int indicating the number of items in the table.
template <typename T>
int Hash<T>::GetLength() {
	return length;
}



//Hash – This should be a private function that accepts a string and returns
//an int.For this, we are going to add the sum of all the ASCII values for
//the passed in stringand modulus by the maximum size of the table.
template <typename T>
int Hash<T>::hash(T inval) {
	int computation;
	long value;
	//below doesnt work because stoi doesnt work for all values or big strings
	if (typeid(inval)==typeid("hello")) {
		value = stoi(inval);
	}
	computation = ((long)value * key) % SIZE;  //need to make sure it handles strings which it doesnt at the moment
	return computation;
}



/*
template <typename T>
bool Hash<T>::operator >(const Hash& rhs) const {

}

template <typename T>
bool Hash<T>::operator < (const Hash& rhs) const {

}

template <typename T>
bool Hash<T>::operator == (const Hash& rhs) const {

}

template <typename T>
bool Hash<T>::operator != (const Hash& rhs) const {

}

template <typename T>
bool Hash<T>::operator >= (const Hash& rhs) const {

}

template <typename T>
bool Hash<T>::operator <= (const Hash& rhs) const {

}
*/