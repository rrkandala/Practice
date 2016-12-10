#include <iostream>
#include <string>

using namespace std;

enum CatDog
{
	Cat = 1,
	Dog = 2
};

struct Node
{
	int data;
	CatDog cd;
	Node *next;
};

class LinkedList
{
private:
	Node *head;
public:
	LinkedList();
	void InsertHead(int d, CatDog obj);
	void InsertRear(int d, CatDog obj);
	int DeleteHead();
	int DeleteRear();
	int DeleteRear(CatDog obj);
	bool IsEmpty();
};

LinkedList::LinkedList()
{
	head = NULL;
}

void LinkedList::InsertHead(int d, CatDog obj)
{
	Node *newNode = new Node();
	newNode->data = d;
	newNode->cd = obj;
	newNode->next = NULL;

	if (head != NULL)
	{
		newNode->next = head;
	}

	head = newNode;
}

void LinkedList::InsertRear(int d, CatDog obj)
{
	Node *newNode = new Node();
	newNode->data = d;
	newNode->cd = obj;
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
		string cdtemp = head->cd == Cat ? "Cat: " : "Dog: ";
		head = head->next;
		cout << cdtemp;
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
			string cdtemp = temp->cd == Cat ? "Cat: " : "Dog: ";
			head = NULL;
			cout << cdtemp;
			return d;
		}

		while (temp->next->next != NULL)
		{
			temp = temp->next;
		}

		int d = temp->next->data;
		string cdtemp = temp->cd == Cat ? "Cat: " : "Dog: ";
		temp->next = NULL;
		cout << cdtemp;
		return d;
	}
	else
	{
		cout << "Queue is Empty" << endl;
		return INT_MAX;
	}
}

int LinkedList::DeleteRear(CatDog obj)
{
	Node* last = NULL;
	Node* temp = head;
	string res;


	if (head == NULL)
	{
		cout << "Queue is empty: ";
		return INT_MAX;
	}
	else
	{
		while (temp != NULL)
		{
			if (temp->cd == obj)
			{
				last = temp;
			}

			temp = temp->next;
		}

		if (last == NULL)
		{
			if (obj == Cat)
			{
				res = "Cat: ";
			}
			else
			{
				res = "Dog: ";
			}

			cout << res << "not available";
			return INT_MAX;
		}
		else
		{
			int d = last->data;

			if (last->next != NULL)
			{
				last->data = last->next->data;
				last->next = last->next->next;
			}
			else
			{
				last = NULL;
			}

			cout << res;
			return d;
		}
	}
}

class CatAndDogShelter
{
private:
	LinkedList *catsdogs;
public:
	CatAndDogShelter();
	void Enqueue(CatDog obj, int d);
	int Dequeue();
	int DequeueCat();
	int DequeueDog();
};

CatAndDogShelter::CatAndDogShelter()
{
	catsdogs = new LinkedList();	
}

void CatAndDogShelter::Enqueue(CatDog obj, int d)
{
	catsdogs->InsertHead(d, obj);
}

int CatAndDogShelter::Dequeue()
{
	return catsdogs->DeleteRear();
}

int CatAndDogShelter::DequeueCat()
{
	return catsdogs->DeleteRear(Cat);
}

int CatAndDogShelter::DequeueDog()
{
	return catsdogs->DeleteRear(Dog);
}

int main()
{
	CatAndDogShelter cds;

	cds.Enqueue(Cat, 1);
	cds.Enqueue(Cat, 2);
	cds.Enqueue(Cat, 3);
	cds.Enqueue(Dog, 40);
	cds.Enqueue(Dog, 50);

	cout << cds.Dequeue() << endl;
	cout << cds.DequeueCat() << endl;
	cout << cds.DequeueDog() << endl;

	return 0;
}