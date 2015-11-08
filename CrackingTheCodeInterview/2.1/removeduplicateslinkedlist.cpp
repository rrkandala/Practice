/*	Program: Remove duplicates from an unsorted linked list
*	Author: Ankit Srivastava
*	Date: 11/7/2015
*/

#include <iostream>
#include <map>

using namespace std;

struct node
{
	int data;
	node* next;
};

class linkedlist
{
private:
	node *head;
	node* createnode(int d);
public:
	linkedlist();
	linkedlist(int d);
	~linkedlist();
	void print();
	void insert(int d);
	void removeduplicates();
	void removeduplicateswithoutbuffer();
	int kthtolastelement(int k);
};

linkedlist::linkedlist()
{
	head = NULL;
}

node* linkedlist::createnode(int d)
{
	node *newnode = new node();
	newnode->data = d;
	newnode->next = NULL;

	return newnode;
}

// Constructor
linkedlist::linkedlist(int d)
{
	node *newnode = createnode(d);
	head = newnode;
}

// Insert elements to linked list
void linkedlist::insert(int d)
{
	node *newnode = createnode(d);
	if (head != NULL)
	{
		newnode->next = head;
	}

	head = newnode;
}

// Print elements to the linked list
void linkedlist::print()
{
	node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << "->";
		temp = temp->next;
	}

	cout << endl;
}

// Destructor
linkedlist::~linkedlist()
{
	node *temp = head;
	while (head != NULL)
	{
		head = head->next;
		delete temp;
	}
}

// Remove duplicates from an unsorted linked list
void linkedlist::removeduplicates()
{
	map<int, bool> lookup;
	if (head == NULL)
	{
		return;
	}

	node *currNode = head->next;
	node *prevNode = head;
	lookup[prevNode->data] = true;
	while (currNode != NULL)
	{
		if (lookup.find(currNode->data) != lookup.end())
		{
			prevNode->next = currNode->next;
			currNode = currNode->next;
		}
		else
		{
			lookup[currNode->data] = true;
			prevNode = currNode;
			currNode = currNode->next;
		}
	}
}


// Remove duplicates from a linkedlist without the use of an additional buffer
void linkedlist::removeduplicateswithoutbuffer()
{
	if (head == NULL)
	{
		return;
	}

	node *prevNode = head;
	node *currNode;

	int max = 0;

	// Selection sort
	while (prevNode != NULL)
	{
		node *min = prevNode;
		currNode = prevNode->next;
		while (currNode != NULL)
		{
			if (min->data > currNode->data)
			{
				min = currNode;
			}

			currNode = currNode->next;
		}

		int d = min->data;
		min->data = prevNode->data;
		prevNode->data = d;

		prevNode = prevNode->next;
	}

	cout << "After sorting: " << endl;
	print();

	// Removing duplicates
	prevNode = head;
	currNode = head->next;

	while (prevNode != NULL)
	{
		while (currNode != NULL && prevNode->data == currNode->data)
		{
			prevNode->next = currNode->next;
			currNode = currNode->next;
		}

		prevNode = prevNode->next;
	}
}

int linkedlist::kthtolastelement(int k)
{
	node *currNode = head;
	node *kthnode = head->next;
	
	int counter = 0;
	
	while(kthnode != NULL)
	{
		if(counter < k)
		{
			counter++;
		}
		else
		{
			break;
		}
		
		kthnode = kthnode->next;
	}
	
	while(kthnode != NULL)
	{
		currNode = currNode->next;
		kthnode = kthnode->next;
	}
	
	return currNode->data;
}

// Program execution starts here
int main()
{
	linkedlist *obj = new linkedlist();
	obj->insert(5);
	obj->insert(4);
	obj->insert(3);
	obj->insert(2);
	obj->insert(1);

	// cout << "Linked list before duplicate removal: " << endl;
	// obj->print();
	// obj->removeduplicateswithoutbuffer();

	// cout << "Linked list after removal: " << endl;
	// obj->print();
	
	cout << "Linked list: " << endl;
	obj->print();
	cout << "2nd element from last: " << endl;
	cout << obj->kthtolastelement(1) << endl;

	system("pause");
}