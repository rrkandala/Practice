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
	Node* GetMid();
	void RemoveMiddleElement(Node *mid);
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

void LinkedList::RemoveMiddleElement(Node *mid)
{
	if (mid == NULL && mid->next == NULL)
	{
		return;
	}
	else
	{
		mid->data = mid->next->data;
		Node *del = mid->next;
		mid->next = mid->next->next;

		delete del;
	}
}

Node* LinkedList::GetMid()
{
	Node *temp = head;

	int len = 0;
	while (temp != NULL)
	{
		len++;
		temp = temp->next;
	}

	int i = 0;
	temp = head;
	while (i < len / 2)
	{
		temp = temp->next;
		i++;
	}

	return temp;
}

int main()
{
	LinkedList l;

	l.Insert(5);
	l.Insert(4);
	l.Insert(3);
	l.Insert(2);

	cout << "Original LinkedList: " << endl;
	l.Print();

	Node *mid = l.GetMid();

	l.RemoveMiddleElement(mid);

	cout << "LinkedList after removing mid element" << endl;
	l.Print();

	return 0;
}