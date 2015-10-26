/*	Program: Binary Search Tree implementation
*	Author: Ankit Srivastava
*	Date: 10/26/2015
*/

#include <iostream>

using namespace std;

// One node of the binary search tree
struct node
{
	int data;
	node* left;
	node* right;
};

// Binary Search Tree
class bst
{
public:
	bst();
	~bst();
	void insert(int d);
	bool search(int key);
	void print();
private:
	node *root;
	node* create_node(int d);
	void insert(int d, node *leaf);
	bool search(int key, node *leaf);
	void destroy_tree(node *leaf);
	void print(node *leaf);
};

// Constructor
bst::bst()
{
	root = NULL;
}

// Destructor
bst::~bst()
{
	destroy_tree(root);
}

// Destroy Tree
void bst::destroy_tree(node *leaf)
{
	if (leaf != NULL)
	{
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

void bst::insert(int d)
{
	insert(d, root);
}

// Insert Tree
void bst::insert(int d, node *leaf)
{
	if (leaf == NULL)
	{
		node *newnode = create_node(d);
		leaf = newnode;
		root = newnode;
	}
	else if (d < leaf->data)
	{
		if (leaf->left == NULL)
		{
			node *newnode = create_node(d);
			leaf->left = newnode;
		}
		else
		{
			insert(d, leaf->left);
		}
	}
	else
	{
		if (leaf->right == NULL)
		{
			node *newnode = create_node(d);
			leaf->right = newnode;
		}
		else
		{
			insert(d, leaf->right);
		}
	}
}

// Create new node
node* bst::create_node(int d)
{
	node *newnode = new node();
	newnode->data = d;
	newnode->left = NULL;
	newnode->right = NULL;

	return newnode;
}

bool bst::search(int key)
{
	return search(key, root);
}

// Search key
bool bst::search(int key, node *leaf)
{
	if (leaf == NULL)
	{
		return false;
	}
	else if (key == leaf->data)
	{
		return true;
	}
	else
	{
		if (key > leaf->data)
		{
			return search(key, leaf->right);
		}
		else
		{
			return search(key, leaf->left);
		}
	}
}

// Print tree
void bst::print()
{
	print(root);
}

void bst::print(node *leaf)
{
	if (leaf == NULL)
	{
		return;
	}
	else
	{
		print(leaf->left);
		cout << leaf->data << " -> ";
		print(leaf->right);
	}
}

int main()
{
	int size;
	int elem;

	cout << "Enter number of elements: ";
	cin >> size;

	bst *obj = new bst();

	for (int i = 0; i < size; i++)
	{
		cout << "Element " << i + 1 << " : ";
		cin >> elem;
		obj->insert(elem);
	}

	cout << "Tree : " << endl;
	obj->print();
	cout << endl;

	cout << "Enter element to search: ";
	cin >> elem;
	if (obj->search(elem))
	{
		cout << "Element " << elem << " found!" << endl;
	}
	else
	{
		cout << "Element " << elem << " not found.." << endl;
	}

	delete obj;
	system("pause");
}