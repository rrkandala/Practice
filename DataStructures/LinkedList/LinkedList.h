#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <iostream>
#include <string>

using namespace std;

template <class T>
class Node
{
	template <class T>
	friend class LinkedList;
	
	private:
		T data;
		Node* next;
	
	public:
		Node();
		Node(T val);
		Node(T val, Node* pNext);
		
		T getData();
		Node<T>* getNext();
};

template <class T>
class LinkedList
{
	private:
		Node<T> *head;
	public:
		bool addNode(T d);
		bool deleteNode(T d);
		void traverse();
		void reverse();
		bool search(T d);
};

#endif