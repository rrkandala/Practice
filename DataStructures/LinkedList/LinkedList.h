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
		Node *next;
	
	public:
		
};

#endif