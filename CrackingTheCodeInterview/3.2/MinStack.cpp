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
	if (head == NULL)
	{
		cout << "Stack is empty";
		return -1;
	}
	else
	{
		int d = head->data;
		head = head->next;
		return d;
	}
}

int Stack::Peek()
{
	if (head == NULL)
	{
		cout << "Stack is empty";
		return -1;
	}
	else
	{
		return head->data;
	}
}

bool Stack::IsEmpty()
{
	return head == NULL;
}

class MinStack : public Stack
{
private:
	Stack min;
public:
	void Push(int d);
	int Pop();
	int GetMin();
};

void MinStack::Push(int d)
{
	if (min.IsEmpty() || (!min.IsEmpty() && min.Peek() > d))
	{
		min.Push(d);
	}

	Stack::Push(d);
}

int MinStack::Pop()
{
	if (Stack::IsEmpty())
	{
		cout << "Stack is empty";
		return -1;
	}
	else
	{
		int d = Stack::Pop();
		if (!min.IsEmpty() && d == min.Peek())
		{
			min.Pop();
		}

		return d;
	}
}

int MinStack::GetMin()
{
	return min.Peek();
}

int main()
{
	MinStack s;

	s.Push(1);
	s.Push(2);
	s.Push(0);
	s.Push(4);
	s.Push(5);

	cout << "Pop: " << s.Pop() << endl;
	cout << "Min: " << s.GetMin() << endl;
	cout << "Pop: " << s.Pop() << endl;
	cout << "Pop: " << s.Pop() << endl;
	
	cout << "Min: " << s.GetMin() << endl;

	return 0;
}