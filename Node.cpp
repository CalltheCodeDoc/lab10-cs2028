#include "Node.h"

using namespace std;
//constructor
template <typename T>
Node<T>::Node(T* inval, Node* hinter) {
	//this assumes its always added at the trailing tail
	data = inval;
	if (hinter == nullptr) {
		prev = nullptr;
	}
	else {
		prev = hinter;
	}
	next = nullptr;
}
//destructor
template <typename T>
Node<T>::~Node() {

}

