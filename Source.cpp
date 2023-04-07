#include <iostream>
#include <string>
#include <math.h>
#include "Hash.h"
#include "Hash.cpp"
#include "LinkedList.h"
#include "LinkedList.cpp"
#include "Node.h"
#include "Node.cpp"
#include "ChainHash.h"
#include "ChainHash.cpp"
#include "InventoryItem.h"


using namespace std;

InventoryItem* searchsku2(int SKU, LinkedList<InventoryItem>* lis);



int main() {


	//TODO:
	//1)   Add getters AND SETTERS AND MAKE MAKE STUFF PRIVATE, RELY MORE ON INHERITANCE
	//^^
	//^
	//
	//2)   HAVE TO DEAL WITH PROPER DELETION OF STUFF WHEN IT DOESNT CONFLICT WITH OTHER USES
	//					thats NODEs, LINKEDLISTS, HASHES, CHAINHASHES, INVENTORYITEMS
	//
	//
	//3)			FOR LAB REPORT:
	// 
	// Task 3: Modify your test program from Lab 8, Task 3 (test program) to test your Hash Table
	//class.Include a screen shot of some of this testing in your lab report.
	//	Complete this before moving on to task 4.
	//	Task 4 : Create a derived class from your Hash table that implements a chained hash table.Use
	//	your linked list class from Lab 8, Task 1. Modify your test program from Task 3 to test this new
	//	class.Include a screen shot of some of this testing in your lab report.
	// 
	// 
	// 
	// 
	//	
	//
	//4) make GetItem and Removeitem and Finditems work with default kwargs so don't have to pass nullptr
	//  *************  OPTIONAL********** OPTIONAL ************
	// 
	//
	//5)Add exception testing and handling at all levels
	//
	//
	//6)Do the rest of the lab




	/*Task 2: Reuse the class from Lab 8, Task 2 (Class to store data).You will need to add the
		overload of the string object conversion.This object conversion should return the SKU.
		Complete this before moving on to task 3*/


	ChainHash<InventoryItem>* hash = new ChainHash<InventoryItem>(100);
	//Hash<InventoryItem>* hash = new Hash<InventoryItem>(100);
	InventoryItem* test = new InventoryItem(3879, "PS5 gaming console", 600, "UOM whatever that is", 5, 20);
	hash->AddItem(test);
	hash->AddItem(new InventoryItem(2589, "Ipad", 600, "UOM whatever that is", 5, 20));
	hash->AddItem(new InventoryItem(1687, "BeanBag Chair", 600, "UOM whatever that is", 5, 20));
	hash->AddItem(new InventoryItem(9579, "Air Jordans", 600, "UOM whatever that is", 5, 20));
	hash->AddItem(new InventoryItem(5879, "Oled TV", 600, "UOM whatever that is", 5, 20));
	hash->AddItem(new InventoryItem(589, "Palantir", 600, "UOM whatever that is", 5, 20));
	hash->AddItem(new InventoryItem(5687, "Apple PC", 600, "UOM whatever that is", 5, 20));
	hash->AddItem(new InventoryItem(4579, "XboxOne gaming console", 600, "UOM whatever that is", 5, 20));
	//InventoryItem* temporary = hash->RemoveItem(test);
	//cout << "removing this: " << temporary->GetSKU() << endl;
	InventoryItem* temporary = hash->GetItem(test);
	cout << "Getting this: " << temporary->GetSKU() << endl;
	temporary = hash->GetItem(test);
	cout << "Getting this again: " << temporary->GetSKU() << endl;
	//int* temporary = hash->RemoveItem(new int(15));
	//cout << "removing this: " << *temporary << endl;

	/*ChainHash<int>* hash = new ChainHash<int>(100);
	hash->AddItem(new int(15));
	hash->AddItem(new int(150));
	hash->AddItem(new int(615));
	hash->AddItem(new int(51));
	int* temporary= hash->RemoveItem(new int(15));
	cout <<  "removing this: " << * temporary << endl;*/



	/*Hash<int>* hash = new Hash<int>(100);
	hash->AddItem(new int(15));
	hash->AddItem(new int(51));
	hash->AddItem(new int(150));
	hash->AddItem(new int(615));
	hash->RemoveItem(new int(15));*/

	

	return 0;
}





InventoryItem* searchsku2(int SKU, LinkedList<InventoryItem>* lis) {
	Node<InventoryItem>* tempo = lis->head;
	int suk;
	while (tempo != nullptr) {
		suk = tempo->data->GetSKU();
		if (suk == SKU) {
			return tempo->data;
		}
		tempo = tempo->next;
	}
	return nullptr;

}
