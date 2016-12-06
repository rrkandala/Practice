#include <iostream>

using namespace std;

class ThreeStacks
{
private:
	int *a;
	int n;
	int *top;
	int *next;
public:
	ThreeStacks();
	ThreeStacks(int size);
	void Push(int i, int d);
	int Pop(int i);
	bool IsEmpty(int i);
	int Peek(int i);
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
	next = new int[3];

	for (int i = 0; i < 3; i++)
	{
		top[i] = i;
		next[i] = i + 3;
	}
}

void ThreeStacks::Push(int i, int d)
{
	if (i > 3)
	{
		cout << "Stack number: " << i << " is greater than number of stacks = 3";
		return;
	}
	else
	{
		a[next[i-1]] = d;
	}
}

int main()
{
	int n = 0;
	cout << "Enter size of array to implement 3 stacks: ";
	cin >> n;



	return 0;
}