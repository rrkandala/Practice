#include "LinkedList.h"

template <class T>
LinkedList<T>::LinkedList() : _pHead(NULL)
{}

template <class T>
LinkedList<T>::LinkedList(T val)
{
	_pHead = new Node<T>(val);
}

template <class T>
LinkedList<T>::~LinkedList()
{
}

template <class T>
void LinkedList<T>::add(T val)
{
	Node<T> *newnode = new Node<T>(val);
	Node<T> *p = _pHead;
	
	if(p == NULL)
	{
		_pHead = newnode;
	}
	else
	{
		while(p->_pNext != NULL)
		{
			p = p->_pNext;
		}
		
		p->_pNext = newnode;
	}
}

template <class T>
void LinkedList<T>::traverse()
{
	Node<T> *p = _pHead;
	
	if(p == NULL)
	{
		cout << "The list is empty!" << endl;
		return;
	}
	
	cout << "LinkedList: ";
	
	while (p != NULL)
	{
		cout << p->_value << "->";
		p = p->_pNext;
	}
	
	cout << endl;
}