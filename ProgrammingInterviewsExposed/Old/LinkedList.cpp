/*	Program: Implement a linked list in C++
 *	Author: Ankit Srivastava
 *	Date: 9/23/2016
 */
 
#include "LinkedList.h"

template <class T>
Node<T>::Node()
{
	data = 0;
	next = NULL;
}

template <class T>
Node<T>::Node(T d)
{
	data = d;
	next = NULL;
}

template <class T>
LinkedList<T>::LinkedList()
{
	root = NULL;
}

template <class T>
LinkedList<T>::~LinkedList()
{
	Node<T> *prev = root;
	Node<T> *nextNode;
	
	while(prev != NULL)
	{
		nextNode = prev->next;
		delete prev;
		prev = nextNode;
	}
}

template <class T>
Node<T>* LinkedList<T>::CreateNode(T d)
{
	Node<T> *newNode = new Node<T>(d);
	
	return newNode;
}

template <class T>
void LinkedList<T>::Insert(T d)
{
	Node<T> *node = CreateNode(d);
	
	if(root == NULL)
	{
		root = node;
	}
	else
	{
		node->next = root;
		root = node;
	}
}

template <class T>
void LinkedList<T>::Print()
{
	Node<T> *trav = root;
	
	while(trav != NULL)
	{
		cout << trav->data << "->";
		trav = trav->next;
	}
	
	cout << "\n";
}

int main()
{
	LinkedList<int> lst;
	
	lst.Insert(1);
	lst.Insert(2);
	lst.Insert(3);
	lst.Insert(4);
	lst.Insert(5);
	
	lst.Print();
	
	return 0;
}