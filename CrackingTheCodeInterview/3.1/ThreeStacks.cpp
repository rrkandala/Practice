#include <iostream>

using namespace std;

class ThreeStacks
{
private:
	int *a;
	int n;
	int free;
	int *top;
	int *next;
public:
	ThreeStacks();
	ThreeStacks(int size);
	void Push(int i, int d);
	int Pop(int i);
	bool IsEmpty(int i);
	int Peek(int i);
	bool IsFull(int i);
};

ThreeStacks::ThreeStacks()
{
	n = 0;
}

ThreeStacks::ThreeStacks(int size)
{
	n = size;
	a = new int[n];
	top = new int[3];
	next = new int[n];

	for (int i = 0; i < 3; i++)
	{
		top[i] = -1;
	}

	free = 0;
	for (int i = 0; i < n; i++)
	{
		next[i] = i + 1;
	}

	next[n - 1] = -1;	// -1 is used to indicate end of free list
}

bool ThreeStacks::IsFull(int i)
{
	return free == -1;
}

bool ThreeStacks::IsEmpty(int sn)
{
	return top[sn] == -1;
}

int ThreeStacks::Peek(int sn)
{
	return a[top[sn]];
}

void ThreeStacks::Push(int sn, int d)
{
	if (sn > 3)
	{
		cout << "Stack number: " << sn << " is greater than number of stacks = 3";
		return;
	}
	else
	{
		if (IsFull(sn))
		{
			cout << "Stack " << sn << " is full";
		}
		else
		{
			int i = free;
			// update index of free slot to index of next slot in free list
			free = next[i];
			next[i] = top[sn];
			top[sn] = i;

			// Put item in array
			a[i] = d;
		}
	}
}

int ThreeStacks::Pop(int sn)
{
	if (IsEmpty(sn))
	{
		cout << "Stack " << sn << " is empty";
		return -1;
	}
	else
	{
		int i = top[sn];
		top[sn] = next[i];
		next[i] = free;
		free = i;

		return a[i];
	}
}

int main()
{
	int n = 0;
	cout << "Enter size of array to implement 3 stacks: ";
	cin >> n;

	ThreeStacks t(n);

	t.Push(0, 1);
	t.Push(0, 2);
	t.Push(0, 3);
	t.Push(0, 4);
	t.Push(1, 5);
	t.Push(2, 6);
	t.Push(1, 7);
	t.Push(1, 8);

	cout << "Pop: " << t.Pop(0) << endl;
	cout << "Pop: " << t.Pop(0) << endl;
	cout << "Pop: " << t.Pop(0) << endl;
	cout << "Pop: " << t.Pop(0) << endl;
	cout << "Pop: " << t.Pop(0) << endl;
	cout << "Pop: " << t.Pop(1) << endl;
	cout << "Pop: " << t.Pop(1) << endl;
	cout << "Pop: " << t.Pop(1) << endl;
	cout << "Pop: " << t.Pop(2) << endl;

	return 0;
}