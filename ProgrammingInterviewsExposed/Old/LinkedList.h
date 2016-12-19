#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <iostream>

using namespace std;

template <class T>
class Node
{
	public:
		T data;
		Node<T> *next;
		
		Node();
		Node(T d);
};

template <class T>
class LinkedList
{
	private:
		Node<T> *root;
		Node<T>* CreateNode(T d);
	
	public:
		LinkedList();
		~LinkedList();
		void Insert(T d);
		void Print();
};

#endif