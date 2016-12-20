#include <iostream>
#include <algorithm>

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
	void Print(Node* n);
	Node* CreateNode(int d);
	void findSum(Node *node, int sum, int* path, int level);
public:
	BinaryTree();
	~BinaryTree();
	void BinaryTreeDestructor(Node *n);
	void Insert(int d);
	void Print();
	void FindSum(int sum);
	void PrintPaths(int *path, int start, int end);
	int Depth(Node *node);
};

BinaryTree::BinaryTree()
{
	root = NULL;
}

BinaryTree::~BinaryTree()
{
	BinaryTreeDestructor(root);
}

void BinaryTree::BinaryTreeDestructor(Node *n)
{
	if (n == NULL)
	{
		return;
	}
	else
	{
		BinaryTreeDestructor(n->left);
		BinaryTreeDestructor(n->right);
		delete n;
	}
}

Node* BinaryTree::CreateNode(int d)
{
	Node *newNode = new Node();
	newNode->data = d;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

void BinaryTree::Insert(int d)
{
	if (root == NULL)
	{
		Node *newNode = CreateNode(d);
		root = newNode;
	}
	else
	{
		Node *n = root;
		while (true)
		{
			if (n->data < d)
			{
				if (n->right == NULL)
				{
					n->right = CreateNode(d);
					break;
				}
				else
				{
					n = n->right;
				}
			}
			else
			{
				if (n->left == NULL)
				{
					n->left = CreateNode(d);
					break;
				}
				else
				{
					n = n->left;
				}
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
		cout << n->data;
		Print(n->right);
	}
}

void BinaryTree::findSum(Node *n, int sum, int *path, int level)
{
	if (n == NULL)
	{
		return;
	}
	else
	{
		// Insert current node into path
		path[level] = n->data;

		// Look for paths with a sum that ends at this node
		int t = 0;
		for (int i = level; i >= 0; i--)
		{
			t = t + path[i];
			if (t == sum)
			{
				PrintPaths(path, i, level);
			}
		}

		// Search nodes beneath this one
		findSum(n->left, sum, path, level + 1);
		findSum(n->right, sum, path, level + 1);
	}
}

void BinaryTree::FindSum(int sum)
{
	int depth = Depth(root);
	int *path = new int[depth];
	findSum(root, sum, path, 0);
}

void BinaryTree::PrintPaths(int *path, int start, int end)
{
	for (int i = start; i <= end; i++)
	{
		cout << path[i] << "->";
	}

	cout << endl;
}

int BinaryTree::Depth(Node *n)
{
	if (n == NULL)
	{
		return 0;
	}
	else
	{
		return 1 + max(Depth(n->left), Depth(n->right));
	}
}

int main()
{
	BinaryTree bt;

	bt.Insert(5);
	bt.Insert(3);
	bt.Insert(2);
	bt.Insert(1);
	bt.Insert(4);

	bt.Print();

	cout << "Printing all paths which sum to 5: " << endl;

	bt.FindSum(5);
	return 0;
}