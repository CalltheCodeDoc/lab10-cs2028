#include "Hash.h"
#include <typeinfo>
#include <sstream>
#include <type_traits>

//Constructor – This should have an overload 
// indicating the maximum
//number of items the Hash table can store.The default value is 100
template <typename T>
Hash<T>::Hash(){
	int const MAX_SIZE = 100;
	table = new T*[MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++)
		table[i] = nullptr;
	SIZE = MAX_SIZE;
	length = 0;
	numComparisons = 0;
}

template <typename T>
Hash<T>::Hash(int const size) {
	SIZE = size;
	table = new T*[SIZE];
	for (int i = 0; i <size; i++)
		table[i] = nullptr;
}

template <typename T>
Hash<T>::~Hash(){
	for (int i = 0; i < SIZE; ++i) {
		table[i]=nullptr;
	}
	delete[] table;
	table = nullptr;
	//design decision to not delete contents of items in table, as class did not create those items
}


//AddItem – adds an item from the list.
template <typename T>
void Hash<T>::AddItem(T* inval) {
	

	unsigned int base_index = hash(*inval)%SIZE;
	
	for (int i = 0; i < SIZE; i++) {//linear probing
		if (table[(base_index+i)%SIZE] == nullptr) {
			base_index = (base_index + i) % SIZE;
			break;
		}
		if(i ==SIZE-1) {
			throw "TableOverflowException";
			//can not add items
		}
	}

	
	table[base_index] = inval;
	//cout << *table[base_index] << endl;
	length++;

}


//RemoveItem – searches the list for the given item.If found, it removes it
//from the listand returns it.If not found, it returns a null pointer.
template <typename T>
T* Hash<T>::RemoveItem(T* inval) {

	unsigned int base_index = hash(*inval) % SIZE;
	//cout << base_index << endl;
	//cout << table[base_index] << endl;

	//linear probing
	for (int i = 0; i < SIZE; i++) {

		if ((table[(base_index + i) % SIZE] != nullptr)&&( *table[(base_index + i) % SIZE] == *inval)) {
			base_index = (base_index + i) % SIZE;
			break;
		}
		if (i == SIZE - 1) {
			return nullptr;
			//can not add items
		}
	}
	T* temp = table[base_index];
	table[base_index] = nullptr;
	//cout << *table[base_index] << endl;
	length--;
	return temp;
}


template <typename T>
T** Hash<T>::GetTable() const {
	return table;
}


template <typename T>
void Hash<T>::Display() const {
	//Displays all table slots
	for (int k = 0; k < SIZE; k++) {

		if (table[k] == nullptr) {
			cout << "Slot " << k << " is Empty" << endl;
		}  
		else {
			cout << *table[k] << endl;
		}
	}
	cout << endl;
}

//GetItem – searches the list for a given item. If found, it returns a pointer
//to the item but doesn’t remove it from the list.
template <typename T>
T* Hash<T>::GetItem(T* inval) {
	unsigned int base_index = hash(*inval) % SIZE;
	//cout << table[base_index] << endl;
	//for loop to handle linear probing
	for (int i = 0; i < SIZE; i++) {
		numComparisons++;
		if ((table[(base_index + i) % SIZE] != nullptr) && (*table[(base_index + i) % SIZE] == *inval)) {
			base_index = (base_index + i) % SIZE;
			break;
		}
		if (i == SIZE - 1) {
			return nullptr;
			//can not add items
		}
	}
	return table[base_index];
}


//GetLength – returns an int indicating the number of items in the table.
template <typename T>
int Hash<T>::GetLength() {
	//returns number of items stored in table
	return length;
}



//Hash – This should be a private function that accepts a string and returns
//an int.For this, we are going to add the sum of all the ASCII values for
//the passed in stringand modulus by the maximum size of the table.
template <typename T>
int Hash<T>::hash(T inval) {

	//hash takes each digit, and sums its ascii numeric value returning that value as an index


	int computation;
	//string stringify = to_string(inval);
	
	//sends values to stream and also tests to see if inval is pointer or not
	//a way of forcing even difficult to convert items into string form
	//stringify doesn't work with all overloaded options
	std::ostringstream oss;
	if constexpr (std::is_pointer<T>::value) {
		oss << *inval;
	}
	else {
		oss << inval;
	}
	std::string stringify = oss.str();
	
	long value=0;
	//if (typeid(stringify) == typeid("Hello"))
	//{
		for (auto x : stringify) {
			value += static_cast<int>(x);
		}
	//}
	computation = value % SIZE;  //need to make sure it handles strings which it doesnt at the moment
	return computation;
}



