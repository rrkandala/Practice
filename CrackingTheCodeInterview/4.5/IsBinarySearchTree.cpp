/* Program: Implement a function to check if a binary tree is a binary search tree
 * Author: Ankit Srivastava
 * Date: 9/16/2016
 */
 
#include <iostream>

using namespace std;

// Node in the binary tree
template <class T>
class Node
{
	public:
		T data;
		Node<T> *left;
		Node<T> *right;

		Node();
		Node(T d);
};

template <class T>
Node<T>::Node()
{
	data = 0;
	left = NULL;
	right = NULL;
}

template <class T>
Node<T>::Node(T d)
{
	data = d;
	left = NULL;
	right = NULL;
}

template <class T>
class BinaryTree
{
	private:
		T min;
		bool isBst = true;
	
	public:
		Node<T> *root;
		BinaryTree();
		void Insert(T d);
		void PreOrder(Node<T> *temp);
		void InOrder(Node<T> *temp);
		void PostOrder(Node<T> *temp);
		bool IsBinarySearchTree();
		void CheckBst(Node<T> *temp);
};

template <class T>
BinaryTree<T>::BinaryTree()
{
	root = NULL;
}

template <class T>
void BinaryTree<T>::Insert(T d)
{
	Node<T> *newNode = new Node<T>(d);
	
	if(root == NULL)
	{
		root = newNode;
	}
	else
	{
		Node<T> *temp = root;
		while(true)
		{
			if(temp->data > d)
			{
				if(temp->left != NULL)
				{
					temp = temp->left;
				}
				else
				{
					temp->left = newNode;
					break;
				}
			}
			else
			{
				if(temp->right != NULL)
				{
					temp = temp->right;
				}
				else
				{
					temp->right = newNode;
					break;
				}
			}
		}
	}
}

template <class T>
void BinaryTree<T>::PreOrder(Node<T> *temp)
{
	if(temp == NULL)
	{
		return;
	}
	else
	{
		cout << temp->data << endl;
		PreOrder(temp->left);
		PreOrder(temp->right);
	}
}

template <class T>
void BinaryTree<T>::InOrder(Node<T> *temp)
{
	if(temp == NULL)
	{
		return;
	}
	else
	{
		InOrder(temp->left);
		cout << temp->data << endl;
		InOrder(temp->right);
	}
}

template <class T>
void BinaryTree<T>::PostOrder(Node<T> *temp)
{
	if(temp == NULL)
	{
		return;
	}
	else
	{
		PostOrder(temp->left);
		PostOrder(temp->right);
		cout << temp->data << endl;
	}
}

template <class T>
bool BinaryTree<T>::IsBinarySearchTree()
{
	Node<T> *temp = root;
	
	while(temp->left != NULL)
	{
		temp = temp->left;
	}
	
	min = temp->data;
	
	InOrder(root);
	
	CheckBst(root);
	
	if(isBst)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
void BinaryTree<T>::CheckBst(Node<T> *temp)
{
	if(temp == NULL || isBst == false)
	{
		return;
	}
	else
	{
		CheckBst(temp->left);
	
		if(temp->data < min && isBst == true)
		{
			isBst = false;
		}
		else
		{
			min = temp->data;
		}
	
		CheckBst(temp->right);
	}
}

int main()
{
	BinaryTree<double> bt;
	
	bt.Insert(5.1);
	bt.Insert(1.1);
	bt.Insert(2.1);
	bt.Insert(3.1);
	bt.Insert(4.1);
	
	cout << "Is Binary Search Tree " << (bt.IsBinarySearchTree() == false ? ": False" : ": True") << endl;
	
	return 0;
}