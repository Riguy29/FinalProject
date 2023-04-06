#ifndef LIBRARYLINKEDLIST_H
#define LIBRARYLINKEDLIST_H
#include "LibraryMedia.h"

#include <iostream>
#include <cassert> //check if the parameters passed to a function are valid, to check the return value of a 
//function or to check the array bounds among other things.

using namespace std;

//Definition of Node as a struct
template<typename T> //generic datatype
struct Node
{
	T data; //stores the data of a node
	Node <T>* next; //points to the next node in the list
};

//Definition of class LinkList
template<typename T>
class LinkedList {
private:
	Node<T>* head;
	Node<T>* newNode(const T& value);
	int count;

public:
	LinkedList();
	~LinkedList();
	void insertItem(const T& value);
	void insertAlpha(const T& value);
	void deleteItem(const T& value);
	T& getItem(int pos)const;
	int size()const;
	void printList()const;
};



#endif // !LIBRARYLINKEDLIST_H
