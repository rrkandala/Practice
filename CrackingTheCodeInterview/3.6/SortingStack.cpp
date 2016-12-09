#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node *next;
};

class Stack
{
private:
	Node *head;
public:
	Stack();
	void Push(int d);
	int Pop();
	int Peek();
	bool IsEmpty();
};

Stack::Stack()
{
	head = NULL;
}

void Stack::Push(int d)
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

int Stack::Pop()
{
	if (!IsEmpty())
	{
		int d = head->data;
		head = head->next;
		return d;
	}
	else
	{
		return INT_MAX;
	}
}

int Stack::Peek()
{
	if (!IsEmpty())
	{
		return head->data;
	}
	else
	{
		return INT_MAX;
	}
}

bool Stack::IsEmpty()
{
	return head == NULL;
}

class SortingStack
{
private:
	Stack *s;
	Stack *helper;
public:
	SortingStack();
	void Insert(int d);
	void Sort();
	int Pop();
};

SortingStack::SortingStack()
{
	s = new Stack();
	helper = new Stack();
}

void SortingStack::Insert(int d)
{
	s->Push(d);
}

void SortingStack::Sort()
{
	int curr = 0;

	while (!s->IsEmpty())
	{
		curr = s->Pop();
		if (helper->IsEmpty() || (curr > helper->Peek()))
		{
			helper->Push(curr);
		}
		else
		{
			while (!helper->IsEmpty())
			{
				s->Push(helper->Pop());

				if (helper->IsEmpty() || curr > helper->Peek())
				{
					break;
				}
			}

			helper->Push(curr);
		}
	}

	s = helper;
}

int SortingStack::Pop()
{
	if (!s->IsEmpty())
	{
		return s->Pop();
	}
	else
	{
		return INT_MAX;
	}
}

int main()
{
	SortingStack s;

	s.Insert(1);
	s.Insert(5);
	s.Insert(3);
	s.Insert(2);
	s.Insert(4);
	s.Insert(6);

	s.Sort();

	cout << "Pop: " << s.Pop() << endl;
	cout << "Pop: " << s.Pop() << endl;
	cout << "Pop: " << s.Pop() << endl;
	cout << "Pop: " << s.Pop() << endl;
	cout << "Pop: " << s.Pop() << endl;
	cout << "Pop: " << s.Pop() << endl;

	return 0;
}