#pragma once
#ifndef CHAINHASH_H
#define CHAINHASH_H
#include <string>
#include <iostream>
#include <math.h>
#include "Hash.h"
#include "LinkedList.h"

using namespace std;

template <typename T>
class ChainHash : public Hash<T> {
public:
	ChainHash();
	ChainHash(int size);
	~ChainHash();
	bool operator > (const ChainHash& rhs) const;
	bool operator < (const ChainHash& rhs) const;
	bool operator == (const ChainHash& rhs) const;
	bool operator != (const ChainHash& rhs) const;

	

	virtual void AddItem(T* inval) override;
	virtual T* RemoveItem(T* inval) override;
	virtual T* GetItem(T* inval) override;
	virtual int GetLength() override;
private:
	unsigned long key;
	int hash(T inval);
	LinkedList<T>** table;
	int SIZE;
	int length;

};
#endif