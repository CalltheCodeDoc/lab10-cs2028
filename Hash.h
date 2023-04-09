#pragma once
#ifndef HASH_H
#define HASH_H
#include <string>
#include <iostream>
#include <math.h>

using namespace std;

template <typename T>
class Hash {

public:

	Hash();
	Hash(int size);
	~Hash();

	

	int numComparisons;
	virtual void AddItem(T* inval);
	virtual T* RemoveItem(T* inval);
	virtual T** GetTable() const;
	virtual T* GetItem(T* inval);
	virtual int GetLength();
	virtual void Display() const;
	//gotta fix the privacy issues,  a lot of functions dont work when private
//private:
	unsigned long key;
	int hash(T inval);
	int SIZE;
	T** table;
	int length;



	
};
#endif