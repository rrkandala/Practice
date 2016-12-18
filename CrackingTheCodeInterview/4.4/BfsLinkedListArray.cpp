#include <iostream>
#include <queue>

using namespace std;

struct TNode
{
	int data;
	TNode *left;
	TNode *right;
};

class BinaryTree
{
private:
	TNode *root;
	LinkedList **lArray;
	int currDepth;
public:
	BinaryTree();
	~BinaryTree();
	void Insert(TNode *r, int d);
	void Print();
	void Print(TNode *n);
	bool Bfs(TNode *n, int s, bool found);
	bool Dfs(TNode *n, int s, bool found);
	void TreeToLinkedListArray(TNode *n);
};

BinaryTree::BinaryTree()
{
	root = NULL;
	currDepth = 0;
}

BinaryTree::~BinaryTree()
{
	delete root;
}

void BinaryTree::Insert(Node *r, int d)
{
	if (r == NULL)
	{
		TNode *tn = new TNode();
		tn->data = d;
		tn->left = NULL;
		tn->right = NULL;
	}
	else
	{
		if()
	}
}

void BinaryTree::Print(TNode *n)
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

bool BinaryTree::Dfs(TNode *n, int s, bool found)
{
	if (n == NULL || found)
	{
		return found;
	}
	else
	{
		if (n->data == s && !found)
		{
			found = true;
		}
		else
		{
			found = Dfs(n->left, s, found);
			found = Dfs(n->right, s, found);
		}

		return found;
	}
}

bool BinaryTree::Bfs(TNode *n, int s, bool found)
{
	if (n == NULL || found)
	{
		return found;
	}
	else
	{
		queue<TNode *> q;
		q.push(n);

		while (!q.empty())
		{
			if (q.front()->data == s)
			{
				found = true;
			}
			else
			{
				TNode *tn = q.front();
				q.pop();
				q.push(tn->left);
				q.push(tn->right);
			}
			
			return found;
		}
	}
}



struct Node
{
	int data;
	Node *next;
};

class LinkedList
{
private:
	Node *head;
public:
	LinkedList();
	~LinkedList();
	void Insert(int d);
	void Print();
};

LinkedList::LinkedList()
{
	head = NULL;
}

LinkedList::~LinkedList()
{
	delete head;
}

void LinkedList::Insert(int d)
{
	Node *newNode = new Node();
	newNode->data = d;
	newNode->next = NULL;

	if (head != NULL)
	{
		newNode->next = head;
	}

	head = newNode;
}

void LinkedList::Print()
{
	Node *temp = head;

	while (temp != NULL)
	{
		cout << temp->data << "->";
	}

	cout << endl;
}

int main()
{
	return 0;
}