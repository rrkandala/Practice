#include <iostream>
#include <queue>

using namespace std;



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
		temp = temp->next;
	}

	cout << endl;
}

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
public:
	BinaryTree();
	~BinaryTree();
	void Insert(int d);
	void Print();
	void Print(TNode *n);
	bool Bfs(TNode *n, int s, bool found);
	bool Dfs(TNode *n, int s, bool found);
	void TreeToLinkedListArray();
};

BinaryTree::BinaryTree()
{
	root = NULL;
	lArray = new LinkedList*();
}

BinaryTree::~BinaryTree()
{
	delete root;
}

void BinaryTree::Insert(int d)
{
	if (root == NULL)
	{
		TNode *tn = new TNode();
		tn->data = d;
		tn->left = NULL;
		tn->right = NULL;
		root = tn;
	}
	else
	{
		TNode *r = root;

		while (true)
		{
			if (r->data < d && r->right == NULL)
			{
				TNode *tn = new TNode();
				tn->data = d;
				tn->left = NULL;
				tn->right = NULL;

				r->right = tn;
				break;
			}
			else if (r->data < d && r->right != NULL)
			{
				r = r->right;
			}
			else if (r->data >= d && r->left == NULL)
			{
				TNode *tn = new TNode();
				tn->data = d;
				tn->left = NULL;
				tn->right = NULL;

				r->left = tn;
				break;
			}
			else
			{
				r = r->left;
			}
		}
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
		}

		return found;
	}
}

void BinaryTree::TreeToLinkedListArray()
{
	TNode *n = root;

	if (n == NULL)
	{
		return;
	}
	else
	{
		queue<TNode *> q;
		q.push(n);
		int depth = 0;

		while (!q.empty())
		{
			int levelNodes = q.size();
			lArray[depth] = new LinkedList();

			while (levelNodes > 0)
			{
				TNode *temp = q.front();
				q.pop();

				lArray[depth]->Insert(temp->data);
				if (temp->left != NULL)
				{
					q.push(temp->left);
				}
				
				if (temp->right != NULL)
				{
					q.push(temp->right);
				}
				
				levelNodes--;
			}

			lArray[depth]->Print();
			depth++;
		}
	}
}

int main()
{
	BinaryTree bt;

	bt.Insert(3);
	bt.Insert(4);
	bt.Insert(1);
	bt.Insert(5);
	bt.Insert(2);
	bt.Insert(0);
	bt.Insert(6);

	bt.TreeToLinkedListArray();

	return 0;
}