#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include <iostream>
#include <string>

using namespace std;

template <class T>
class Node
{
	template <class T>
	friend class LinkedList;
	
	private:
		T _value;		// Data stored in node
		Node *_pNext;	// Reference to the next node in the linked list
		
	public:
		Node();
		Node(T val);
		Node(T val, Node* next);
		
		// Getters
		T getValue();
		Node* getNext();
};

template <class T>
class LinkedList
{
	private:
		Node<T> *_pHead;	// Head node
	public:
		// Default Constructor
		LinkedList();
		
		// Constructor with value to added to list
		LinkedList(T val);
		
		// Destructor
		~LinkedList();
		
		// Add node
		void add(T val);
		
		// Traverse the list
		void traverse();
};

#endif