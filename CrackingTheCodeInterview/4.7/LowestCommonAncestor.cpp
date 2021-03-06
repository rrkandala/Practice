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
	Node<T> *parent;

	Node();
	Node(T d);
};

template <class T>
Node<T>::Node()
{
	data = 0;
	left = NULL;
	right = NULL;
	parent = NULL;
}

template <class T>
Node<T>::Node(T d)
{
	data = d;
	left = NULL;
	right = NULL;
	parent = NULL;
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
	Node<T>* LowestCommonAncestor(Node<T> *temp1, Node<T> *temp2);
	Node<T>* LCA(T n1, T n2);
	Node<T>* FindLCA(Node<T>* temp1, T n1, T n2);
	bool BinaryTree<T>::Covers(Node<T> temp, T n);
	void TestLCA();
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

	if (root == NULL)
	{
		root = newNode;
	}
	else
	{
		Node<T> *temp = root;
		while (true)
		{
			if (temp->data > d)
			{
				if (temp->left != NULL)
				{
					temp = temp->left;
				}
				else
				{
					temp->left = newNode;
					temp->left->parent = temp;
					break;
				}
			}
			else
			{
				if (temp->right != NULL)
				{
					temp = temp->right;
				}
				else
				{
					temp->right = newNode;
					temp->right->parent = temp;
					break;
				}
			}
		}
	}
}

template <class T>
void BinaryTree<T>::PreOrder(Node<T> *temp)
{
	if (temp == NULL)
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
	if (temp == NULL)
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
	if (temp == NULL)
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

	while (temp->left != NULL)
	{
		temp = temp->left;
	}

	min = temp->data;

	InOrder(root);

	CheckBst(root);

	if (isBst)
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
	if (temp == NULL || isBst == false)
	{
		return;
	}
	else
	{
		CheckBst(temp->left);

		if (temp->data < min && isBst == true)
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

template <class T>
void BinaryTree<T>::TestLCA()
{
	Node<T> *res = LCA(5.1, 3.1);

	cout << "The root of 3.1 and 5.1 is << " << res->data << endl;
}

template <class T>
Node<T>* BinaryTree<T>::LowestCommonAncestor(Node<T> *temp1, Node<T> *temp2)
{
	int h1 = 0;
	int h2 = 0;

	Node<T> *t1 = new Node<T>();
	Node<T> *t2 = new Node<T>();

	t1 = temp1;
	t2 = temp2;

	while (temp1->parent != NULL)
	{
		h1++;
		temp1 = temp1->parent;
	}

	temp1 = t1;

	while (temp2->parent != NULL)
	{
		h2++;
		temp2 = temp2->parent;
	}

	temp2 = t2;

	cout << "h1=" << h1 << endl;
	cout << "h2=" << h2 << endl;

	while (h1 != h2)
	{
		if (h1 > h2)
		{
			temp1 = temp1->parent;
			h1--;
		}
		else
		{
			temp2 = temp2->parent;
			h2--;
		}
	}

	while (temp1->parent != temp2->parent)
	{
		temp1 = temp1->parent;
		temp2 = temp2->parent;
	}

	return temp1->parent;
}

template <class T>
Node<T>* BinaryTree<T>::LCA(T n1, T n2)
{
	return FindLCA(root, n1, n2);
}

template <class T>
bool BinaryTree<T>::Covers(Node<T> temp, T n)
{
	if (temp == null)
	{
		return false;
	}
	
	if (temp->data == n)
	{
		return true;
	}

	return Covers(temp->left, n) || Covers(temp->right, n);
}

template <class T>
Node<T>* BinaryTree<T>::FindLCA(Node<T>* temp, T n1, T n2)
{
	if (temp == NULL)
	{
		return NULL;
	}
	else
	{
		if (temp->data == n1 || temp->data == n2)
		{
			return temp;
		}

		Node<T> *left_lca = FindLCA(temp->left, n1, n2);
		Node<T> *right_lca = FindLCA(temp->right, n1, n2);

		if (left_lca != NULL && right_lca != NULL)
		{
			return temp;
		}

		return (left_lca != NULL) ? left_lca : right_lca;
	}
}

int main()
{
	BinaryTree<double> bt;

	bt.Insert(6.1);
	bt.Insert(4.1);
	bt.Insert(2.1);
	bt.Insert(5.1);
	bt.Insert(1.1);
	bt.Insert(3.1);
	bt.Insert(7.1);

	cout << "Is Binary Search Tree " << (bt.IsBinarySearchTree() == false ? ": False" : ": True") << endl;

	bt.TestLCA();

	return 0;
}