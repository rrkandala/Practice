#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

struct Node 
{
	int data;
	Node *left;
	Node *right;
};

class BinaryTree
{
private:
	Node *root;
	void Insert(int d, Node *n);
public:
	BinaryTree();
	void Insert(int d);
	void Print();
	void Print(Node *n);
	bool IsTreeBalanced();
	int IsTreeBalanced(Node *n);
};

BinaryTree::BinaryTree()
{
	root = NULL;
}

void BinaryTree::Insert(int d, Node *n)
{
	if (n->data > d)
	{
		if (n->left == NULL)
		{
			Node *newNode = new Node();
			newNode->data = d;
			newNode->left = NULL;
			newNode->right = NULL;

			n->left = newNode;
		}
		else
		{
			Insert(d, n->left);
		}
	}
	else if (n->data <= d)
	{
		if (n->right == NULL)
		{
			Node *newNode = new Node();
			newNode->data = d;
			newNode->left = NULL;
			newNode->right = NULL;

			n->right = newNode;
		}
		else
		{
			Insert(d, n->right);
		}
	}
}

void BinaryTree::Insert(int d)
{
	if (root != NULL)
	{
		Insert(d, root);
	}
	else
	{
		Node *newNode = new Node();
		newNode->data = d;
		newNode->left = NULL;
		newNode->right = NULL;

		root = newNode;
	}
}

bool BinaryTree::IsTreeBalanced()
{
	int hLeft = 0, hRight = 0;

	if (root == NULL)
	{
		return true;
	}
	else
	{
		hLeft = 1 + IsTreeBalanced(root->left);
		hRight = 1 + IsTreeBalanced(root->right);
		return (abs(hRight - hLeft) <= 1);
	}
}

int BinaryTree::IsTreeBalanced(Node *n)
{
	if (n == NULL)
	{
		return 0;
	}
	else
	{
		return max(1 + IsTreeBalanced(n->left), 1 + IsTreeBalanced(n->right));
	}
}

void BinaryTree::Print()
{
	Print(root);
}

void BinaryTree::Print(Node *n)
{
	if (n == NULL)
	{
		return;
	}
	else
	{
		Print(n->left);
		cout << n->data;
		Print(n->right);
	}
}

int main()
{
	BinaryTree bt;

	bt.Insert(1);
	bt.Insert(2);
	bt.Insert(3);
	bt.Insert(4);
	bt.Insert(5);

	string res = bt.IsTreeBalanced() ? " is " : " is not ";

	cout << "Binary Tree" << res << "balanced" << endl;

	return 0;
}