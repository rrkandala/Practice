#include <iostream>
#include <unordered_map>

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
	void RemoveDuplicates();
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

	if (head == NULL)
	{
		head = newNode;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}
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

void LinkedList::RemoveDuplicates()
{
	unordered_map<int, bool> m;

	Node *prev = NULL;
	Node *curr = head;

	while (curr != NULL)
	{
		if (m.find(curr->data) != m.end())
		{
			prev->next = curr->next;
		}
		else
		{
			pair<int, bool> toInsert(curr->data, true);
			m.insert(toInsert);
			prev = curr;
		}

		curr = curr->next;
	}
}

int main()
{
	LinkedList l;
	l.Insert(5);
	l.Insert(5);
	l.Insert(2);
	l.Insert(2);
	l.Insert(1);
	l.Insert(3);
	l.Insert(5);
	l.Insert(5);

	cout << "Before duplicate removal: " << endl;
	l.Print();
	l.RemoveDuplicates();
	cout << "After duplicate removal: " << endl;
	l.Print();

	return 0;
}