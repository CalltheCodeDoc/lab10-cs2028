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

	


	virtual void AddItem(T* inval);
	virtual T* RemoveItem(T* inval);
	virtual T* GetItem(T* inval);
	virtual int GetLength();

//private:
	unsigned long key;
	int hash(T inval);
	int SIZE;
	T** table;
	int length;



	/*
	bool operator == (const Hash& rhs) const;

	bool operator > (const Hash& rhs) const;
	bool operator < (const Hash& rhs) const;
	bool operator != (const Hash& rhs) const;
	bool operator >= (const Hash& rhs) const;
	bool operator <= (const Hash& rhs) const;
	*/
};
#endif