#include <iostream>

using namespace std;

class Stack
{
private:
	int *arr;
	int size;
	int top;
public:
	Stack();
	Stack(int s);
	void Push(int d);
	int Pop();
	int Peek();
	bool IsEmpty();
	bool IsFull();
};

Stack::Stack()
{
	size = 0;
	arr = NULL;
	top = -1;
}

Stack::Stack(int s)
{
	size = s;
	arr = new int[size];

	for (int i = 0; i < size; i++)
	{
		arr[i] = 0;
	}

	top = -1;
}

void Stack::Push(int d)
{
	if (!IsFull())
	{
		top++;
		arr[top] = d;
	}
}

int Stack::Pop()
{
	if (!IsEmpty())
	{
		int d = arr[top];
		top--;
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
		return arr[top];
	}
	else
	{
		return INT_MAX;
	}
}

bool Stack::IsEmpty()
{
	return top < 0;
}

bool Stack::IsFull()
{
	return top == (size - 1);
}

class SetOfStacks : public Stack
{
private:
	Stack **s;
	int size;
	int currStack;
	int numStacks;
public:
	SetOfStacks();
	SetOfStacks(int n, int s);
	void Push(int d);
	int Pop();
	int Peek();
	bool IsEmpty();
	bool IsFull();
	int PopAt(int sn);
};

SetOfStacks::SetOfStacks()
{
	size = 0;
	s = NULL;
	currStack = 0;
	numStacks = 0;
}

SetOfStacks::SetOfStacks(int n, int k)
{
	size = k;
	numStacks = n;
	s = new Stack*[n];

	for (int i = 0; i < n; i++)
	{
		s[i] = new Stack(size);
	}

	currStack = 0;
}

void SetOfStacks::Push(int d)
{
	if (s[currStack]->IsFull() && currStack < (numStacks - 1))
	{
		currStack++;
	}

	if (currStack >= numStacks)
	{
		cout << "Stack is full!";
	}
	else
	{
		s[currStack]->Push(d);
	}	
}

int SetOfStacks::Pop()
{
	if (currStack >= 0 && s[currStack]->IsEmpty())
	{
		currStack--;
	}

	if (currStack < 0)
	{
		cout << "Stack is empty: ";
		return INT_MAX;
	}
	else
	{
		return s[currStack]->Pop();
	}
}

int SetOfStacks::Peek()
{
	if (currStack >= 0)
	{
		return s[currStack]->Peek();
	}
	else
	{
		cout << "Stack is empty: ";
		return INT_MAX;
	}
}

bool SetOfStacks::IsFull()
{
	return currStack >= (numStacks - 1) && s[currStack]->IsFull();
}

bool SetOfStacks::IsEmpty()
{
	return currStack < 0;
}

int SetOfStacks::PopAt(int sn)
{
	return s[sn]->Pop();
}

int main()
{
	SetOfStacks s(2, 3);

	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Push(4);
	s.Push(5);
	s.Push(6);
	s.Push(7);

	cout << s.PopAt(0) << endl;
	cout << s.Pop() << endl;
	cout << s.Pop() << endl;
	cout << s.Pop() << endl;
	cout << s.Pop() << endl;
	cout << s.Pop() << endl;
	cout << s.Pop() << endl;
	cout << s.Pop() << endl;

	return 0;
}