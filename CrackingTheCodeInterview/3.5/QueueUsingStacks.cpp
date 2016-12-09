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

class Queue
{
private:
	Stack *inbox;
	Stack *outbox;
public:
	Queue();
	void Enqueue(int d);
	int Dequeue();
	bool IsEmpty();
};

Queue::Queue()
{
	inbox = new Stack();
	outbox = new Stack();
}

void Queue::Enqueue(int d)
{
	if (inbox->IsEmpty())
	{
		while (!outbox->IsEmpty())
		{
			int r = outbox->Pop();
			inbox->Push(r);
		}
	}
	
	inbox->Push(d);
}

int Queue::Dequeue()
{
	while (!inbox->IsEmpty())
	{
		int d = inbox->Pop();
		outbox->Push(d);
	}

	if (!outbox->IsEmpty())
	{
		return outbox->Pop();
	}
	else
	{
		cout << "Queue is empty" << endl;
		return INT_MAX;
	}
}

int main()
{
	Queue q;

	q.Enqueue(1);
	q.Enqueue(2);
	q.Enqueue(3);
	q.Enqueue(4);
	q.Enqueue(5);

	cout << "Dequeue: " << q.Dequeue() << endl;
	cout << "Dequeue: " << q.Dequeue() << endl;
	cout << "Dequeue: " << q.Dequeue() << endl;

	q.Enqueue(6);
	q.Enqueue(7);

	cout << "Dequeue: " << q.Dequeue() << endl;
	cout << "Dequeue: " << q.Dequeue() << endl;
	cout << "Dequeue: " << q.Dequeue() << endl;
	cout << "Dequeue: " << q.Dequeue() << endl;
	cout << "Dequeue: " << q.Dequeue() << endl;

	return 0;
}