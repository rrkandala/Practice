#ifndef BINARY_TREE_H
#define BINARY_TREE_H

using namespace std;

#include <iostream>

template <class T>
class Node
{
	private:
		T data;
		Node *left;
		Node *right;
	
		void Insert(T d);
	
	public:
		Node();
		void InsertNode();
		
		void InOrder();
		
};

#endif