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
	Node* DetectCircularLinkedList(int d);
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

Node* LinkedList::DetectCircularLinkedList(int d)
{
	Node *newNode = new Node();
	newNode->data = d;
	Node *temp = head;

	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	temp->next = newNode;
	newNode->next = head->next->next->next;

	Node *slow = head;
	Node *fast = head;

	bool start = true;

	while (slow != fast || start)
	{
		start = false;

		slow = slow->next;
		fast = fast->next->next;
	}

	slow = head;
	start = true;

	while (slow != fast || start)
	{
		start = false;
		slow = slow->next;
		fast = fast->next;
	}

	return slow;
}

int main()
{
	LinkedList l;
	l.Insert(1);
	l.Insert(2);
	l.Insert(3);
	l.Insert(4);
	l.Insert(5);

	cout << "Linked List: ";
	l.Print();

	Node *start = l.DetectCircularLinkedList(6);
	cout << "Node at start of circular linked list = ";
	cout << start->data << endl;

	return 0;
}