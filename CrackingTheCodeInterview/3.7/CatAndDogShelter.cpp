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
	void InsertHead(int d);
	void InsertRear(int d);
	int DeleteHead();
	int DeleteRear();
	bool IsEmpty();
};

LinkedList::LinkedList()
{
	head = NULL;
}

void LinkedList::InsertHead(int d)
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

void LinkedList::InsertRear(int d)
{
	Node *newNode = new Node();
	newNode->data = d;
	newNode->next = NULL;

	Node *temp = head;

	if (IsEmpty())
	{
		head = newNode;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = newNode;
	}
}

bool LinkedList::IsEmpty()
{
	return head == NULL;
}

int LinkedList::DeleteHead()
{
	if (!IsEmpty())
	{
		int d = head->data;
		head = head->next;
		return d;
	}
	else
	{
		cout << "Queue is empty" << endl;
		return INT_MAX;
	}
}

int LinkedList::DeleteRear()
{
	if (!IsEmpty())
	{
		Node *temp = head;
		if (temp->next == NULL)
		{
			int d = temp->data;
			head = NULL;
			return d;
		}

		while (temp->next->next != NULL)
		{
			temp = temp->next;
		}

		int d = temp->next->data;
		temp->next = NULL;
		return d;
	}
	else
	{
		cout << "Queue is Empty" << endl;
		return INT_MAX;
	}
}

enum CatDog
{
	Cat = 1,
	Dog = 2
};

class CatAndDogShelter
{
private:
	LinkedList *cats;
	LinkedList *dogs;
	int last;
public:
	CatAndDogShelter();
	void Enqueue(CatDog obj, int d);
	int Dequeue();
	int DequeueCat();
	int DequeueDog();
};

CatAndDogShelter::CatAndDogShelter()
{
	cats = new LinkedList();
	dogs = new LinkedList();
	last = -1;
}

void CatAndDogShelter::Enqueue(CatDog obj, int d)
{
	if (obj == Cat)
	{
		last = Cat;
		cats->InsertRear(d);
	}
	else
	{
		last = Dog;
		dogs->InsertRear(d);
	}
}

int CatAndDogShelter::Dequeue()
{
	if (last == Cat)
	{
		return cats->DeleteHead();
	}
	else if(last == Dog)
	{
		return dogs->DeleteHead();
	}
	else
	{
		return INT_MAX;
	}
}

int CatAndDogShelter::DequeueCat()
{
	return cats->DeleteHead();
}

int CatAndDogShelter::DequeueDog()
{
	return dogs->DeleteHead();
}

int main()
{
	CatAndDogShelter cds;

	cds.Enqueue(Cat, 1);
	cds.Enqueue(Cat, 2);
	cds.Enqueue(Cat, 3);
	cds.Enqueue(Dog, 40);
	cds.Enqueue(Dog, 50);

	cout << cds.DequeueCat() << endl;
	cout << cds.DequeueDog() << endl;

	return 0;
}