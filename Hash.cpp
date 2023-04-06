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
	for(auto x: table)
		x = nullptr;
	SIZE = MAX_SIZE;
	length = 0;
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
	delete[] table;
	table = nullptr;
}


//AddItem – adds an item from the list.
template <typename T>
void Hash<T>::AddItem(T* inval) {
	

	unsigned int base_index = hash(*inval)%SIZE;
	cout << base_index<< endl;
	//base_index = (base_index + 1) % SIZE;
	//cout << base_index << endl;
	
	//cout << table[base_index]<<endl;
	for (int i = 0; i < SIZE; i++) {
		if (table[(base_index+i)%SIZE] == nullptr) {
			base_index = (base_index + i) % SIZE;
			break;
		}
		if(i ==SIZE-1) {
			throw "TableOverflowException";
			//can not add items
		}
	}
	/*
	while (table[base_index] != nullptr) { 
		count++;
		base_index = (base_index + 1) % SIZE; //linear probing insertion
		if (count >= SIZE) {
			throw "TableOverflowException";
			//can not add items
		}
	}
	*/
	
	table[base_index] = inval;
	cout << *table[base_index] << endl;
	length++;

}


//RemoveItem – searches the list for the given item.If found, it removes it
//from the listand returns it.If not found, it returns a null pointer.
template <typename T>
T* Hash<T>::RemoveItem(T* inval) {

	/*
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
	*/





	unsigned int base_index = hash(*inval) % SIZE;
	//cout << base_index << endl;
	base_index = (base_index + 1) % SIZE;
	//cout << base_index << endl;


	cout << table[base_index] << endl;
	for (int i = 0; i < SIZE; i++) {
		if (table[(base_index + i) % SIZE] != nullptr&& *table[(base_index + i) % SIZE] == *inval) {
			base_index = (base_index + i) % SIZE;
		}
		if (i == SIZE - 1) {
			throw "ItemNotFoundException";
			//can not add items
		}
	}
	T* temp = table[base_index];
	table[base_index] = nullptr;
	cout << *table[base_index] << endl;
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
	string stringify = to_string(inval);
	/*
	std::ostringstream oss;
	if constexpr (std::is_pointer<T>::value) {
		oss << *inval;
	}
	else {
		oss << inval;
	}
	std::string stringify = oss.str();
	*/
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

//template class Hash<int>;
//template class Hash<std::string>;