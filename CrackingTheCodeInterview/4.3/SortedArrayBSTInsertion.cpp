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
	void Insert(int *arr, int start, int end, int len);
	void Print(Node *n);
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

void BinarySearchTree::Insert(int *arr, int start, int end, int len)
{
	if (end < start)
	{
		return;
	}
	else
	{
		int mid = (start + end) / 2;
		Insert(arr[mid]);
		Insert(arr, start, mid - 1, len);
		Insert(arr, mid + 1, end, len);
	}
}

void BinarySearchTree::Print(Node *n)
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

void BinarySearchTree::Print()
{
	Print(root);
}

int main()
{
	BinarySearchTree b;

	int *a = new int[5];

	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	a[3] = 4;
	a[4] = 5;

	b.Insert(a, 0, 4, 5);

	b.Print();

	return 0;
}