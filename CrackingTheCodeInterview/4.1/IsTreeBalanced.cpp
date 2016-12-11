#include <iostream>

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

void BinaryTree::Print()
{
	Print(root);
}

int main()
{
	return 0;
}