#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};

class BinarySearchTree
{
private:
	Node *root;
public:
	BinarySearchTree();
	~BinarySearchTree();
	void Insert(int d);
	void Insert(int *arr, int len);
	void Print();
};

BinarySearchTree::BinarySearchTree()
{
	root = NULL;
}

BinarySearchTree::~BinarySearchTree()
{
	delete root;
}

void BinarySearchTree::Insert(int d)
{
	Node *newNode = new Node();
	newNode->data = d;
	newNode->left = NULL;
	newNode->right = NULL;

	if (root == NULL)
	{
		root = newNode;
	}
	else
	{
		Node *temp = root;
		bool found = false;

		while (!found)
		{
			if (temp->data <= d && temp->right == NULL)
			{
				temp->right = newNode;
				found = true;
			}
			else if(temp->data <= d && temp->right != NULL)
			{
				temp = temp->right;
			}
			else if (temp->data > d && temp->left == NULL)
			{
				temp->left = newNode;
				found = true;
			}
			else
			{
				temp = temp->left;
			}
		}
	}
}

void BinarySearchTree::Insert(int *arr, int len)
{
	
}

int main()
{
	return 0;
}