#include <iostream>

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
	void Insert(int d);
	void Print();
	Node* KthToLastElement(int k);
};

LinkedList::LinkedList()
{
	head = NULL;
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

Node* LinkedList::KthToLastElement(int k)
{
	int i = 0;
	Node *kth;
	Node *temp = head;

	if (k < 0)
	{
		return NULL;
	}

	while (i < k && temp != NULL)
	{
		temp = temp->next;
		i++;
	}

	kth = head;

	if (temp == NULL)
	{
		return NULL;
	}
	else
	{
		while (temp->next != NULL)
		{
			kth = kth->next;
			temp = temp->next;
		}

		return kth;
	}
}

int main()
{
	int k;
	cout << "Enter k to find kth to last element: ";
	cin >> k;

	LinkedList l;
	l.Insert(5);
	l.Insert(4);
	l.Insert(3);
	l.Insert(2);
	l.Insert(1);

	cout << "Linked List: " << endl;
	l.Print();

	Node *res = l.KthToLastElement(k);

	if (res != NULL)
	{
		cout << k << "th to last element in linked list = " << res->data << endl;
	}
	else
	{
		cout << k << "th to last element out of range in linked list" << endl;
	}

	return 0;
}