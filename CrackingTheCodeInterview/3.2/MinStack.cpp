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
	Stack *min;
public:
	Stack();
	void Push(int d);
	int Pop();
	int Peek();
	bool IsEmpty();
	int GetMin();
};

Stack::Stack()
{
	head = NULL;
	min = new Stack();
	min->head = NULL;
}

void Stack::Push(int d)
{
	Node *newNode = new Node();
	newNode->data = d;
	newNode->next = NULL;

	if (newNode->data < head->data)
	{
		min->Push(d);
	}

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

		if (d == min->head->data)
		{
			min->Pop();
		}

		head = head->next;
		return d;
	}
}

int Stack::GetMin()
{
	return min->head->data;
}

int main()
{
	Stack s;

	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Push(4);
	s.Push(5);

	cout << s.Pop() << endl;
	cout << s.Pop() << endl;
	cout << s.Pop() << endl;
	cout << s.Pop() << endl;
	cout << s.GetMin() << endl;

	return 0;
}