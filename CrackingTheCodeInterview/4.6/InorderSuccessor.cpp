#include <iostream>
#include <queue>

using namespace std;

struct Node
{
	int data;
	Node *parent;
	Node *left;
	Node *right;
};

class BinaryTree
{
private:
	Node *root;
	Node* CreateNode(int d);
	void Print(Node *n);
	bool Dfs(Node *n, int s, bool found);
public:
	BinaryTree();
	~BinaryTree();
	void BinaryTreeDestructor(Node *n);
	void Insert(int d);
	void Print();
	bool Dfs(int s, bool found);
	Node* Bfs(int s);
	int InorderSuccessor(int s);
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
	Node* newNode = new Node();
	newNode->data = d;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->parent = NULL;

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
			if (n->data >= d && n->left == NULL)
			{
				Node *newNode = CreateNode(d);
				n->left = newNode;
				newNode->parent = n;

				break;
			}
			else if (n->data >= d && n->left != NULL)
			{
				n = n->left;
			}
			else if (n->data < d && n->right == NULL)
			{
				Node *newNode = CreateNode(d);
				n->right = newNode;
				newNode->parent = n;

				break;
			}
			else
			{
				n = n->right;
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

bool BinaryTree::Dfs(int s, bool found)
{
	return Dfs(root, s, found);
}

bool BinaryTree::Dfs(Node *n, int s, bool found)
{
	if (n == NULL)
	{
		return false;
	}
	else if (found)
	{
		return found;
	}
	else
	{
		if (n->data == s)
		{
			found = true;
		}

		found = Dfs(n->left, s, found);
		found = Dfs(n->right, s, found);

		return found;
	}
}

Node* BinaryTree::Bfs(int s)
{
	if (root == NULL)
	{
		return NULL;
	}
	else
	{
		queue<Node *> q;
		q.push(root);

		while (!q.empty())
		{
			Node *temp = q.front();
			q.pop();
			if (temp->data == s)
			{
				return temp;
			}
			else
			{
				q.push(temp->left);
				q.push(temp->right);
			}
		}

		return NULL;
	}
}

int BinaryTree::InorderSuccessor(int s)
{
	Node *temp = Bfs(s);

	if (temp == NULL)
	{
		return INT_MIN;
	}
	else
	{
		if (temp->right != NULL)
		{
			temp = temp->right;

			while (temp->left != NULL)
			{
				temp = temp->left;
			}

			return temp->data;
		}
		else if(temp->parent != NULL)
		{
			while (temp->parent->left != temp && temp->parent != root)
			{
				temp = temp->parent;
			}

			if (temp->parent->left == temp)
			{
				return temp->parent->data;
			}
			else
			{
				return INT_MIN;
			}
		}
		else
		{
			return INT_MIN;
		}
	}
}

int main()
{
	BinaryTree bt;

	bt.Insert(5);
	bt.Insert(2);
	bt.Insert(8);
	bt.Insert(3);
	bt.Insert(1);
	
	cout << "Inorder successor: " << bt.InorderSuccessor(2) << endl;

	return 0;
}