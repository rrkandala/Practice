#include <iostream>
#include <queue>
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
	queue<int> q;
public:
	BinaryTree();
	~BinaryTree();
	void Insert(int d);
	void Print(Node *n);
	void Print();
	bool IsBST();
	void IsBST(Node *n);
};

BinaryTree::BinaryTree()
{
	root = NULL;
}

BinaryTree::~BinaryTree()
{
	delete root;
}

void BinaryTree::Insert(int d)
{
	if (root == NULL)
	{
		Node *newNode = new Node();
		newNode->data = d;
		newNode->left = NULL;
		newNode->right = NULL;

		root = newNode;
	}
	else
	{
		Node *temp = root;
		while (true)
		{
			if (temp->data < d && temp->right == NULL)
			{
				Node *newNode = new Node();
				newNode->data = d;
				newNode->left = NULL;
				newNode->right = NULL;

				temp->right = newNode;
				break;
			}
			else if (temp->data < d && temp->right != NULL)
			{
				temp = temp->right;
			}
			else if (temp->data >= d && temp->left == NULL)
			{
				Node *newNode = new Node();
				newNode->data = d;
				newNode->left = NULL;
				newNode->right = NULL;

				temp->left = newNode;
				break;
			}
			else
			{
				temp = temp->left;
			}
		}
	}
}

void BinaryTree::Print()
{
	Print(root);
	cout << endl;
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
		cout << n->data << "->";
		Print(n->right);
	}
}

bool BinaryTree::IsBST()
{
	IsBST(root);

	int previous = INT_MIN;
	int curr = INT_MIN;
	bool result = true;

	while (!q.empty())
	{
		curr = q.front();
		q.pop();

		if (curr < previous)
		{
			result = false;
			break;
		}

		previous = curr;
	}

	return result;
}

 void BinaryTree::IsBST(Node *n)
{
	if (n == NULL)
	{
		return;
	}
	else
	{
		IsBST(n->left);
		q.push(n->data);
		IsBST(n->right);
	}
}

int main()
{
	BinaryTree bt;

	bt.Insert(5);
	bt.Insert(3);
	bt.Insert(7);
	bt.Insert(2);
	bt.Insert(1);
	bt.Insert(8);
	bt.Insert(9);

	bt.Print();

	string res = bt.IsBST() ? "is" : "is not";

	cout << "The binary tree " << res << " a binary search tree" << endl;

	return 0;
}