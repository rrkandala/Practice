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
	void PartitionList(int x);
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

void LinkedList::PartitionList(int x)
{
	Node *prev = head;
	Node *curr = head;

	while (curr != NULL)
	{
		if (curr->data < x)
		{
			Insert(curr->data);
		}

		curr = curr->next;
	}

	Node *temp = head;

	while (temp != NULL && temp->next != prev)
	{
		temp = temp->next;
	}

	if (temp != NULL)
	{
		prev = temp;
		curr = temp->next;

		while (curr != NULL)
		{
			if (curr->data <= x)
			{
				prev->next = curr->next;
			}
			else
			{
				prev = curr;
			}

			curr = curr->next;
		}
	}
}

int main()
{
	int x = 0;
	LinkedList l;

	cout << "Enter partition value: ";
	cin >> x;

	l.Insert(5);
	l.Insert(1);
	l.Insert(4);
	l.Insert(3);
	l.Insert(2);

	cout << "Linked List: " << endl;
	l.Print();

	cout << "After Partition around " << x << ", Linked List: " << endl;
	l.PartitionList(x);
	l.Print();

	return 0;
}