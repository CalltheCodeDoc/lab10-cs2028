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
string first_name[50] = {
		"John", "Jane", "Michael", "Emily", "James", "Emma", "William", "Olivia",
		"David", "Sophia", "Benjamin", "Isabella", "Lucas", "Ava", "Henry", "Mia",
		"Alexander", "Charlotte", "Sebastian", "Amelia", "Jack", "Harper",
		"Daniel", "Evelyn", "Aiden", "Abigail", "Ramona", "Morgan", "Matthew", "Emily", "Samuel", "Ella",
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
	//3)      CLEAN UP CODE, add functionality comments, remove all commented out stuff.
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
	//7)			Removeitem creates a junk value,  gotta fix that,   maybe its the stray delete doing that  
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

	bool TASK_5 = true;
	// Task 5   TEST PROGRAM
	if (TASK_5) {
		int const ARRAY_SIZE = 50; //50,150, 200, 250

		//create different hashs and lists
		//hashes for comparison, list to store objects to keep track of for later
		ChainHash<InventoryItem>* LLhash = new ChainHash<InventoryItem>(100);
		Hash<InventoryItem>* hash = new Hash<InventoryItem>(100);
		LinkedList<InventoryItem>* list = new LinkedList<InventoryItem>();
		int numcomp[4][2] = { {0} };
		//generates random values for SKU students and inserts them
		for (int i = 0; i < ARRAY_SIZE+1; i++) {
			InventoryItem* student = generateSKU();
			list->AddItem(student);
			hash->AddItem(student);
			LLhash->AddItem(student);

		}
		//finds the students skus that were generated earlier
		for (int i = 0; i < ARRAY_SIZE; i++) {
			InventoryItem* poppedstudent = list->SeeNext();
			hash->GetItem(poppedstudent);
			LLhash->GetItem(poppedstudent);
		}
		numcomp[0][0] = hash->numComparisons;
		numcomp[0][1] = LLhash->numComparisons;
		//prints out results
		cout << "Num of Comparisons: for Array Size of : " << ARRAY_SIZE << endl;
		cout << "Linear Probing: " << hash->numComparisons << endl;
		cout << "Chained Hashing: " << LLhash->numComparisons << endl;

	}







	//**********************************************************************************************
	//*********************************  TEST CODE  ***********************************************
	//**********************************************************************************************
	//CODE Below until end of main is just test code, ignore it.  though there are some functions
	// at the very bottom of code and also lab 8 stuff
	//**********************************************************************************************
	//**********************************************************************************************







	// Task 3: Modify your test program from Lab 8, Task 3 (test program) to test your Hash Table
	//class.Include a screen shot of some of this testing in your lab report.
	//	Complete this before moving on to task 4.
	//	Task 4 : Create a derived class from your Hash table that implements a chained hash table.Use
	//	your linked list class from Lab 8, Task 1. Modify your test program from Task 3 to test this new
	//	class.Include a screen shot of some of this testing in your lab report.
	
	// 
	// 
	//flip to true to activate test code
	bool manual_debug = false;

	//*********************  THIS is used for screenshots
	if (manual_debug) {

		//							TASK 4
		//ChainHash<InventoryItem>* hash = new ChainHash<InventoryItem>(100);
		//							TASK 3
		Hash<InventoryItem>* hash = new Hash<InventoryItem>(100);
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
	


















	//**************************************************************************************************************************		
	//*********************************  TEST PROGRAM FROM LAB 8  ********************************************************************************
	//**************************************************************************************************************************



	//modify this to work with your hash table class some how??????????????    
	//hoooowwwww???????????
	//for TASK 3


	bool TASK_3 = true;

	if (TASK_3) {

		system("Color 0A");
		int userresponse;
		char userresponse1;
		bool CHAINED_HASH = true;

		InventoryItem* temp2;
		
		ChainHash<InventoryItem>* list = new ChainHash<InventoryItem>(12);
		//uncomment this out to normal HASH
		// ******************************************************************************************
		//Hash<InventoryItem>* list = new Hash<InventoryItem>(12);
		
		LinkedList<InventoryItem>* lis = new LinkedList<InventoryItem>();
		//Node<InventoryItem>* temp = new Node<InventoryItem>(new InventoryItem(6879, "PS5 gaming console", 600, "UOM whatever that is", 5, 20), list->head);
		//^^^^ Don't do node<inventoryItem


		InventoryItem* item1 = new InventoryItem(3879, "PS5 gaming console", 600, "UOM whatever that is", 5, 20);
		InventoryItem* item2 = new InventoryItem(2589, "Ipad", 600, "UOM whatever that is", 5, 20);
		InventoryItem* item3 = new InventoryItem(1687, "BeanBag Chair", 600, "UOM whatever that is", 5, 20);
		InventoryItem* item4 = new InventoryItem(9579, "Air Jordans", 600, "UOM whatever that is", 5, 20);
		InventoryItem* item5 = new InventoryItem(5879, "Oled TV", 600, "UOM whatever that is", 5, 20);
		InventoryItem* item6 = new InventoryItem(589, "Palantir", 600, "UOM whatever that is", 5, 20);
		InventoryItem* item7 = new InventoryItem(5687, "Apple PC", 600, "UOM whatever that is", 5, 20);
		InventoryItem* item8 = new InventoryItem(4579, "XboxOne gaming console", 600, "UOM whatever that is", 5, 20);
		
		list->AddItem(item1);
		list->AddItem(item2);
		list->AddItem(item3);
		list->AddItem(item4);
		list->AddItem(item5);
		list->AddItem(item6);
		list->AddItem(item7);
		list->AddItem(item8);

		lis->AddItem(item1);
		lis->AddItem(item2);
		lis->AddItem(item3);
		lis->AddItem(item4);
		lis->AddItem(item5);
		lis->AddItem(item6);
		lis->AddItem(item7);
		lis->AddItem(item8);


		//list->NotYetMergeSort();
		list->Display();

		lis->Display();

		InventoryItem* temp3;


		int SKU;
		//int arrgindex;
		int quantity;
		double price;
		string uom;
		double lead;
		string desc;


		bool Isin;

		do {
			do {

				cout << "This is a test of the Hash Table class." << endl;
				//cout << "Type 1 for: LinkedList();" << endl;
				cout << "Type 2 activate destructor for the list" << endl;
				cout << "Type 3 to use AddItem(T * item) method to add an item into the Hash" << endl;
				cout << "Type 4 to use GetItem(T * item, Node<T>*ptr) method to retrieve and remove and item from the Hash" << endl;
				cout << "Type 5 to use RemoveItem(T * item, Node<T>*ptr) method to retrieve and remove and item from the Hash" << endl;
				//cout << "Type 5 to see if item is in the list using the method: IsInList(T * item)" << endl;
				//cout << "Type 6 to see if the list is empty using the method: IsEmpty()" << endl;
				cout << "Type 7 to see how many nodes are in the Hash using length attribute" << endl;
				//cout << "Type 8 to iterate forwards through the list using T* SeeNext() method" << endl;
				//cout << "Type 9 to iterate backwards through the list using  T* SeePrev() method" << endl;
				//cout << "Type 10 to use SeeAt(T*, Node<T>*ptr) method" << endl;
				//cout << "Type 11 to Reset iterator back to head pointer used for SEENEXT, SEEPREV methods" << endl;
				//cout << "Type 12 to manually sort inventory by SKU number" << endl;
				cout << "Type 13 to Display all inventory" << endl;
				//cout << "Type 14 for: void displayskus(LinkedList<InventoryItem>* lis)" << endl;
				cout << "Type 14 to terminate program" << endl;
				cin >> userresponse;
				cin.ignore();
				//getline(cin, userresponse);

			} while (userresponse > 14 || userresponse < 1);
			cin.clear();
			switch (userresponse) {
			case 1:
				//cout << "Creating empty list..." << endl;
				//LinkedList<InventoryItem>* list = new LinkedList<InventoryItem>();
				break;
				//****************************************
				//use try catches in all of these to make sure list exists first and is not empty
				//so that the program doesnt crash when it tries to access a nullptr by user being dumbdumb
			case 2:
				cout << "Deleting list..." << endl;
				//Gotta delete all ints* in the list too
				//nodes too???
				delete list;
				break;
			case 3:
				cout << "To add an item please enter the values of the inventory item:" << endl;
				cout << "integer SKU: " << endl;

				cin >> SKU;
				cin.ignore();
				//getline(cin, SKU);
				cout << "Quantity: " << endl;
				cin >> quantity;
				cin.ignore();
				cout << "Price: " << endl;
				cin >> price;
				cin.ignore();
				cout << "Unit of Measure: " << endl;
				getline(cin, uom);
				cout << "Lead Time: " << endl;
				cin >> lead;
				cin.ignore();
				cout << "Description: " << endl;
				getline(cin, desc);
				cout << "Adding item to list..." << endl;
				list->AddItem(new InventoryItem(SKU, desc, price, uom, lead, quantity));
				//list->NotYetMergeSort();
				break;

			case 4:
				cout << "Type in the SKU of the item you want to get: " << endl;
				cin >> SKU;
				cin.ignore();
				//if not available, message this to customer,
				//or just use available() method
				//Node<InventoryItem>* searchsku(int SKU, LinkedList<InventoryItem>*lis)

				try {
					InventoryItem* temp4 = searchsku2(SKU, lis);
					if (temp4 == nullptr)
					{
						throw LinkedList<InventoryItem>::ListNotFlow("Item not found in list");
					}
					else {


						temp3 = list->GetItem(temp4);
						if (temp3 == nullptr)
						{
							throw LinkedList<InventoryItem>::ListNotFlow("Item not found in list");
						}
						else {

							cout << temp3->GetPartInfo() << " Is the item retrieved " << endl;
							delete temp3;
							//temp3->data = nullptr;
							//probably should make destructor handle this stuff automatically
							//delete temp3;
							//temp3 = nullptr;

						}
					}
				}
				catch (const LinkedList<InventoryItem>::ListNotFlow& e) {
					std::cerr << "Caught MyClass::MyException: " << e.what() << std::endl;
				}
				break;
				//add additional code to display the item to the user indicating its in stock
			case 5:
				cout << "Type in the SKU of the item you want to remove: " << endl;
				cin >> SKU;
				cin.ignore();
				//if not available, message this to customer,
				//or just use available() method
				//Node<InventoryItem>* searchsku(int SKU, LinkedList<InventoryItem>*lis)

				try {
					InventoryItem* temp4 = searchsku2(SKU, lis);
					if (temp4 == nullptr)
					{
						throw LinkedList<InventoryItem>::ListNotFlow("Item not found in list");
					}
					else {


						temp3 = list->RemoveItem(temp4);
						if (temp3 == nullptr)
						{
							throw LinkedList<InventoryItem>::ListNotFlow("Item not found in list");
						}
						else {

							cout << temp3->GetPartInfo() << " Is the item retrieved " << endl;
							delete temp3;
							//temp3->data = nullptr;
							//probably should make destructor handle this stuff automatically
							//delete temp3;
							//temp3 = nullptr;

						}
					}
				}
				catch (const LinkedList<InventoryItem>::ListNotFlow& e) {
					std::cerr << "Caught MyClass::MyException: " << e.what() << std::endl;
				}
				break;
				break;
			case 50:
				//cout << "Check to see if an item is in the list." << endl;
				//cout << "Type in the SKU of the item you want to check: " << endl;
				//cin >> SKU;
				//cin.ignore();
				//Isin = list->IsInList(searchsku2(SKU, list)); //replace T * item with proper coding
				//if (Isin) {
				//	cout << "Item is in the list." << endl;
				//}
				//else {
				//	cout << "Item is not in the list." << endl;
				//}
				break;
			case 6:
				/*cout << "Check to see if the list is empty." << endl;
				cout << "It is: " << list->IsEmpty() << " that the list is empty." << endl;*/
				break;
			case 7:
				cout << "The size of the list is: " << endl;
				cout << list->length << endl;
				break;
			case 8:
				//cout << "See the next item in the list." << endl;
				//try {
				//	temp2 = list->SeeNext();
				//	if (temp2 == nullptr)
				//	{
				//		throw LinkedList<InventoryItem>::ListNotFlow("Item not found in list");
				//	}
				//	else {
				//		cout << temp2->GetPartInfo() << endl; //this sees a pointer, probably wanna see SKU or description
				//	}
				//}
				//catch (const LinkedList<InventoryItem>::ListNotFlow& e) {
				//	std::cerr << "Caught MyClass::MyException: " << e.what() << std::endl;
				//}
				break;
			case 9:
				//cout << "See the previous item in the list." << endl;
				//try {
				//	temp2 = list->SeePrev();
				//	if (temp2 == nullptr)
				//	{
				//		throw LinkedList<InventoryItem>::ListNotFlow("Item not found in list");
				//	}
				//	else {
				//		cout << temp2->GetPartInfo() << endl; //this sees a pointers; probably wanna see SKU or description
				//	}
				//}
				//catch (const LinkedList<InventoryItem>::ListNotFlow& e) {
				//	std::cerr << "Caught MyClass::MyException: " << e.what() << std::endl;
				//}
				break;
			case 10:
				//cout << "See the item at a specific location in the list." << endl;
				//cout << "Type in the SKU of the item you want to see: " << endl;
				//cin >> SKU;
				//try {
				//	//might have to change function to pay attention to SKU, not pointer
				//	InventoryItem* temp5 = searchsku2(SKU, list);
				//	if (temp5 == nullptr)
				//	{
				//		throw LinkedList<InventoryItem>::ListNotFlow("Item not found in list");
				//	}
				//	else {
				//		temp = list->SeeAt(temp5, list->head);
				//		if (temp == nullptr)
				//		{
				//			throw LinkedList<InventoryItem>::ListNotFlow("Item not found in list");
				//		}
				//		else {
				//			//temp = list->SeeAt(searchsku2(SKU, list), list->head);
				//			cout << temp->data << endl; //this sees a pointer, probably wanna see SKU or description
				//			//also replace T* with some mangled mess of data->getSKU(SKU)
				//			//*************************************************************
				//			//DUNNO WHAT YAH WANT TO SEE , the DATA, pointer, SKU?
				//		}
				//	}
				//}
				//catch (const LinkedList<InventoryItem>::ListNotFlow& e) {
				//	std::cerr << "Caught MyClass::MyException: " << e.what() << std::endl;
				//}
				break;
			case 11:
				/*cout << "Reset the iterator view of the list to 0" << endl;
				list->Reset();*/
				break;
			case 12:
				//cout << "Sort the list by SKU" << endl;
				//cout << "This should be done whenever u wanna access items after adding items." << endl;
				////***********************  
				////  OR THIS FUNCTION SHOULD BE CALLED AUTOMATICALLY everytime additems is called
				//list->NotYetMergeSort();
				//list->Display();
				break;
			case 13:
				cout << "Display the list." << endl;
				list->Display();
				break;
				//case 14:
				//	cout << "Display all the SKUS in the list." << endl;
				//	displayskus(list);
				//	break;
			case 14:
				cout << "Terminating program." << endl;
				break;
			}
			cout << "Clear text? (y/n)" << endl;
			cin >> userresponse1;
			if (userresponse1 == 'y')
				system("CLS");
		} while (userresponse != 14);





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