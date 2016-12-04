#include <iostream>
#include <sstream>

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
	void Reverse();
	bool IsPalindrome();
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

void LinkedList::Reverse()
{
	Node *prev = NULL;
	Node *curr = head;

	while (curr != NULL)
	{
		Node *temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}

	head = prev;
}

bool LinkedList::IsPalindrome()
{
	Node *temp = head;

	stringstream ss1;
	stringstream ss2;

	while (temp != NULL)
	{
		ss1 << temp->data;
		temp = temp->next;
	}

	Reverse();
	temp = head;

	while (temp != NULL)
	{
		ss2 << temp->data;
		temp = temp->next;
	}

	if (ss1.str().compare(ss2.str())==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	LinkedList l;

	l.Insert(5);
	l.Insert(4);
	l.Insert(4);
	l.Insert(5);

	cout << "Linked List: " << endl;
	l.Print();

	string res = l.IsPalindrome() ? "is" : "is not";

	cout << "The linked list " << res << " a palindrome" << endl;

	return 0;
}