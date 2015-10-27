/*	Program: Reverse a singly linked list
*	Author: Ankit Srivastava
*	Date: 10/27/2015
*/

#include <iostream>

using namespace std;

// One node of the linkedlist
struct node
{
	int data;
	node* next;
};

// Linked list implementation
class linkedlist
{
public:
	linkedlist();
	~linkedlist();
	void insert(int d);
	void print();
	void reverse();
private:
	node* head;
	void insert(int d, node* head);
	void print(node* head);
	void reverse(node* head);
};

// Constructor
linkedlist::linkedlist()
{
	head = NULL;
}

// Desctructor
linkedlist::~linkedlist()
{
	node *temp = head;

	while (temp != NULL)
	{
		node *next = temp->next;
		delete temp;
		temp = next;
	}
}

// Insert elements
void linkedlist::insert(int d)
{
	node *newnode = new node();
	newnode->data = d;
	newnode->next = NULL;

	if (head != NULL)
	{
		newnode->next = head;
	}

	head = newnode;
}

// Print linkedlist 
void linkedlist::print()
{
	cout << "Linked list: ";
	node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << "->";
		temp = temp->next;
	}

	cout << endl;
}

// Reverse a linked list
void linkedlist::reverse()
{
	node *prev = NULL;
	node *curr = head;
	node *next = NULL;

	while (curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	head = prev;
}

int main()
{
	linkedlist *obj = new linkedlist();

	int size = 0;
	cout << "Enter number of elements to insert: ";
	cin >> size;

	int a = 0;

	for (int i = 0; i < size; i++)
	{
		cout << "Element " << i + 1 << " : ";
		cin >> a;
		obj->insert(a);
	}

	obj->print();

	obj->reverse();

	cout << "Reversed Linked list : " << endl;
	obj->print();

	system("pause");
}