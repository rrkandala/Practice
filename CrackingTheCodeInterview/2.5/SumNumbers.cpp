#include <iostream>
#include <vector>
#include <algorithm>

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
	vector<int> SumNumbers(LinkedList h1, LinkedList h2);
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

vector<int> LinkedList::SumNumbers(LinkedList h1, LinkedList h2)
{
	Node *t1 = h1.head;
	Node *t2 = h2.head;

	int q = 0, r = 0, s = 0;

	vector<int> v;

	while (t1 != NULL || t2 != NULL)
	{
		if (t1 != NULL)
		{
			s = t1->data;
		}

		if (t2 != NULL)
		{
			s = s + t2->data;
		}

		s = s + q;
		r = s % 10;
		q = s / 10;

		v.push_back(r);

		if (t1 != NULL)
		{
			t1 = t1->next;
		}
		
		if (t2 != NULL)
		{
			t2 = t2->next;
		}

		s = 0;
	}

	reverse(v.begin(), v.end());

	return v;
}

int main()
{
	LinkedList l1, l2;

	l1.Insert(6);
	l1.Insert(1);
	l1.Insert(7);

	l2.Insert(2);
	l2.Insert(9);
	l2.Insert(5);
	l2.Insert(5);

	LinkedList l;

	vector<int> v= l.SumNumbers(l1, l2);

	cout << "Sum of numbers: ";
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it;
	}

	cout << endl;

	return 0;
}