#include <iostream>
#include <string>
#include <math.h>
#include "Hash.h"
#include "Hash.cpp"

using namespace std;

int main() {


	//TODO:
	//1)
	//^^
	//^
	//
	//2)
	//
	//
	//3)make sure the array of linkedlists are correctly set up & accessing them works sufficiently
	//	
	//
	//4)Develop a GETITEM where the linkedlist functions get an item from list without removing it
	//
	//
	//5)Do rest of lab

	Hash<int>* hash = new Hash<int>(100);
	hash->AddItem(new int(15));
	hash->AddItem(new int(51));
	hash->AddItem(new int(150));
	hash->AddItem(new int(615));
	hash->RemoveItem(new int(15));

	

	return 0;
}