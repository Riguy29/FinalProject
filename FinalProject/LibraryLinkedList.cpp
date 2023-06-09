//implement functions for list
#ifndef LIBRARYLINKEDLIST_CPP
#define LIBRARYLINKEDLIST_CPP

#include "LibraryLinkedList.h"

//constructor
template<typename T>
LinkedList<T>::LinkedList() :head(NULL), count(0) {}

//destructor
template<typename T>
LinkedList<T>::~LinkedList()
{
	Node<T>* temp = head;
	while (head) {
		head = head->next;
		delete temp;
		temp = head;
	}
}

//Insert member function
template <typename T>

void LinkedList<T>::insertItem(const T& value) { //insert value at end of list
	Node <T>* add = newNode(value);
	if (head == NULL) {//if list is empty
		add->next = head;
		head = add;
	}
	else {//list not empty
		Node <T>* curr = head;
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = add;
	}
	count++;
}

template <typename T>
void LinkedList<T>::insertAlpha(const T& value) {
	Node <T>* add = newNode(value);
	if (head == NULL || head->data.toString().compare(value.toString()) >= 0) {
		add->next = head;
		head = add;
	}
	else {
		Node<T>* curr = head;
		while (curr->next != NULL) {
			if (curr->next->data.toString().compare(value.toString()) < 0) {
				add->next = curr->next;
				curr->next = add;
				break;
			}
			else {
				curr = curr->next;
			}
		}
	}
	count++;
}
template<typename T>
void LinkedList<T>::deleteItem(const T& value) { //delete at given value
	Node <T>* curr = head;
	if (head->data.ToString().compare(value.ToString()) == 0) {
		Node<T>* temp = head;
		head = curr->next;
		delete temp;
	}
	else {
		Node<T>* nextNode = head;
		while (curr->next != NULL) {
			if (nextNode->data.ToString().compare(value.ToString()) != 0) {
				curr->next = curr->next->next;
				break;
			}
			else {
				curr = curr->next;
			}
		}	
	}
	count--;
}

template<typename T>
void LinkedList<T>::clearList()
{
	Node<T>* curr = head;
	Node<T>* next;
	while (curr != NULL)
	{
		next = curr->next;
		delete curr;
		curr = next;
	}
	head = NULL;
	count = 0;
}

//get member function
template<typename T>
T& LinkedList<T>::getItem(int pos)const {
	
	int length = size();
	if (pos < 0 || pos > length) {
		cout << "Error! Position out of range.";
		assert(false);
	}
	else if (pos == 0) {
		return head->data;
	}
	else {
		Node<T>* curr = head;
		int currIndex = 0;
		for (int i = 0; i < pos; i++) {
			if (pos == currIndex) {
				return curr->data;
			}
			else {
				curr = curr->next;
			}

		}
		//This should never happen
		//throw exception;
		//I changed this to return the data instead of the the ToString because it was causing issues
		return curr->data;
	}
}

template<typename T>
void LinkedList<T>::search(const string& search)const {
	Node<T>* curr = head;
	if (curr->data.getTitle().find(search) != string::npos || curr->data.getAuthor().find(search) != string::npos) {
		cout << curr->data.toString() << endl;
	}
	else {
		while (curr != NULL) {
			if (curr->data.getTitle().find(search) != string::npos || curr->data.getAuthor().find(search) != string::npos) {
				cout << curr->data.toString() << endl;
			}

			curr = curr->next;
		}
	}

}
	
//get size of LinkList
template<typename T>
int LinkedList<T>::size()const {
	//return count;
	//I changed this function to give us realtime data, instead of relying on a variable to prevent errors down the line --Riley
	int count = 0;
	Node<T>* curr = head;
	while (curr != NULL) {
		curr = curr->next;
		count++;
	}
	return count;
}

//print member function
template<typename T>
void LinkedList<T>::printList()const {
	if (count == 0) {
		cout << "List is empty!" << endl;
		return;
	}
	Node<T>* curr = head;
	while (curr != NULL) {
		cout << curr->data.ToString() << endl;
		cout << endl;
		curr = curr->next;
	}
}

template<typename T>
Node<T>* LinkedList<T>::GetHead()
{
	if (head != NULL) return head;
	else return NULL;
}

//makeNode member function(private)
template<typename T>
Node<T>* LinkedList<T>::newNode(const T& value) {
	Node<T>* temp = new Node <T>;
	temp->data = value;
	temp->next = NULL;
	return temp;
}

#endif