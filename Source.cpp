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
#include <random>
#include <cstdlib>
#include <ctime>



using namespace std;

InventoryItem* searchsku2(int SKU, LinkedList<InventoryItem>* lis);
InventoryItem* generateSKU();
string first_name[48] = {
		"John", "Jane", "Michael", "Emily", "James", "Emma", "William", "Olivia",
		"David", "Sophia", "Benjamin", "Isabella", "Lucas", "Ava", "Henry", "Mia",
		"Alexander", "Charlotte", "Sebastian", "Amelia", "Jack", "Harper",
		"Daniel", "Evelyn", "Aiden", "Abigail", "Matthew", "Emily", "Samuel", "Ella",
		"Joseph", "Scarlett", "Joshua", "Grace", "Andrew", "Chloe", "Nicholas", "Victoria",
		"Christopher", "Riley", "Gabriel", "Aria", "Nathan", "Lily", "Christian", "Zoe",
		"Aaron", "Layla"
	};

	string last_name[46] = {
		"Smith", "Johnson", "Williams", "Brown", "Jones", "Garcia", "Miller", "Davis",
		"Rodriguez", "Martinez", "Hernandez", "Lopez", "Gonzalez", "Perez", "Wilson", "Anderson",
		"Thomas", "Taylor", "Moore", "Jackson", "Martin", "Lee", "Harris", "Clark", "Lewis", "Robinson",
		"Walker", "Hall", "Allen", "Young", "Hernandez", "King", "Wright", "Lopez", "Hill", "Scott",
		"Green", "Adams", "Baker", "Gonzalez", "Nelson", "Carter", "Mitchell", "Perez", "Roberts", "Turner"
	};

int main() {

	srand(time(NULL));



	
	//TODO:
	//1)   Add getters AND SETTERS AND MAKE MAKE STUFF PRIVATE, RELY MORE ON INHERITANCE
	//^^
	//^
	// 1.5)   SeeNext fixed.2 problems:  finditem actuallyed called getitem on repeat.  so it emptied list out unintentionally, causing nullptr errors
	//					something throws off the number of values by 1, so simple add one extra item than will be removed.  no more problems
	// 
	// 
	// 1.75)   MEMORY LEAKS,  gotta make deletes!!!!!!!!  DELETES TO AVoid THE LEAKS    almost rhymes
	// 
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
	// 3.5)      CLEAN UP CODE, add functionality comments, remove all commented out stuff.
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
	//6)                  implement try catches for all the nullptr exceptions        
	// 
	// 
	// 
	//
	// 
	//
	//
	//Task 5: Measure the performance of the linear probing and chained linking implementations of a
	/*hash table(similar to Lab 7 task 4).To do this, modify both classes to keep track of the number
		of times an item is compared in the chain for chained linkingiiand the number of times an
		additional index is checked for linear probing(you only need to do this for the GetItem but you
			can do it for both if that is easier).Create a test program that adds 50 randomly generated
		students(follow appropriate SKU rules) to both hash tables then calls GetItem on the same
		student.Record the total number of times the Hash Table needed to complete the 50 operations.
		Repeat this measurement with an array size of 150, 200 and 250. Include a table of the results
		from the 4 trials for the 2 different classes in your lab report*/
	//


	int const ARRAY_SIZE = 50;

	//create different hashs and lists
	//hashes for comparison, list to store objects to keep track of for later
	ChainHash<InventoryItem>* LLhash = new ChainHash<InventoryItem>(100);
	Hash<InventoryItem>* hash = new Hash<InventoryItem>(100);
	LinkedList<InventoryItem>* list = new LinkedList<InventoryItem>();
	int numcomp[4][2] = { {0} };
	//generates random values for SKU students and inserts them
	for (int i = 0; i < 51; i++) {
		InventoryItem* student = generateSKU();
		list->AddItem(student);
		hash->AddItem(student);
		LLhash->AddItem(student);

	}
	//finds the students skus that were generated earlier
	for (int i = 0; i < 50; i++) {
		InventoryItem* poppedstudent = list->SeeNext();
		hash->GetItem(poppedstudent);
		LLhash->GetItem(poppedstudent);
	}
	numcomp[0][0] = hash->numComparisons;
	numcomp[0][1] = LLhash->numComparisons;
	//prints out results
	cout << "Num of Comparisons" << endl;
	cout << "Linear Probing: " << hash->numComparisons << endl;
	cout << "Chained Hashing: " << LLhash->numComparisons << endl;









	//**********************************************************************************************
	//*********************************  TEST CODE  ***********************************************
	//**********************************************************************************************
	//CODE Below until end of main is just test code, ignore it.  though there are some functions
	// at the very bottom of code
	//**********************************************************************************************
	//**********************************************************************************************



	//flip to true to activate test code
	bool manual_debug = false;

	//*********************  THIS is used for screenshots
	if (manual_debug) {
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
	}
	



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

InventoryItem* generateSKU() {

	int SKU;
	string description;
	int third_arg;
	string fourth_arg;
	int fifth_arg;
	int sixth_arg;
	SKU = rand() % 10000;
	third_arg = rand() % 1000;
	fifth_arg = rand() % 1000;
	sixth_arg = rand() % 1000;
	description = first_name[rand() % 46] + last_name[rand() % 46];
	fourth_arg = "Simulated generated undergrads";
	if (false) {
		//flip to true to activate test code
		cout << description << endl;
		cout << SKU << endl;
		//4579, "XboxOne gaming console", 600, "UOM whatever that is", 5, 20
	}
	InventoryItem* item = new InventoryItem(SKU, description, third_arg, fourth_arg, fifth_arg, sixth_arg);
	return item;
}