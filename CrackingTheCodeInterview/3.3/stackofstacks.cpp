/*	Program: Implement a stack of substacks of fixed size
*	Author: Ankit Srivastvaa
*
*	Date: 12/28/2015
*/

#include <iostream>
#include <vector>

using namespace std;

template <class T>
class substack
{
private:
	T *arr;
	int nextAvailable;
	int size;
public:
	substack(int capacity);
	~substack();
	void push(T elem);
	T pop();
	T peek();
	bool isfull();
	bool isempty();	
};

// Constructor initializing size of substack
template <class T>
substack<T>::substack(int capacity)
{
	nextAvailable = 0;
	size = capacity;
	arr = new T[capacity];
}

// Destructor freeing memory allocated by the stack implemented using array
template <class T>
substack<T>::~substack()
{
	delete[] arr;
	arr = NULL;
}

// Pushing an element on top of a substack of fixed size
template <class T>
void substack<T>::push(T elem)
{
	if (nextAvailable < size)
	{
		arr[nextAvailable] = elem;
		nextAvailable++;
	}
	else
	{
		cout << "Substack is full" << endl;
		return;
	}
}

// Popping the top element from a stack of fixed size
template <class T>
T substack<T>::pop()
{
	nextAvailable--;

	if (nextAvailable >= 0)
	{
		T del = arr[nextAvailable];
		arr[nextAvailable] = NULL;
		return del;
	}
	else
	{
		cout << "Stack is empty" << endl;
		return NULL;
	}
}

// Peeking the top element from a stack of fixed size
template <class T>
T substack<T>::peek()
{
	if (nextAvailable > 0)
	{
		return arr[nextAvailable - 1];
	}
	else
	{
		cout << "Stack is empty" << endl;
		return NULL;
	}
}

// Checking if a substack is full or not
template <class T>
bool substack<T>::isfull()
{
	return (nextAvailable == size);
}

// Checking if a substack is empty or not
template <class T>
bool substack<T>::isempty()
{
	return (nextAvailable == 0);
}

template <class T>
class SetOfStacks
{
private:
	vector<substack<T>*> setofstacks;
	int currStackIndex;
	int size;
public:
	SetOfStacks(int capacity);
	~SetOfStacks();
	void push(T elem);
	T pop();
	T peek();
	T popAt(int i);
};

// Constructor initializing a set of stacks
template <class T>
SetOfStacks<T>::SetOfStacks(int maxStackCapacity)
{
	currStackIndex = 0;
	size = maxStackCapacity;
	setofstacks.push_back(new substack<T>(maxStackCapacity));
}

// Destructor clearing set of stacks vector
template <class T>
SetOfStacks<T>::~SetOfStacks()
{
	setofstacks.clear();
}

// Pushing an element on top of a stack implemented by a set of fixed length substacks
template <class T>
void SetOfStacks<T>::push(T elem)
{
	if (!setofstacks[currStackIndex]->isfull())
	{
		setofstacks[currStackIndex]->push(elem);
	}
	else
	{
		currStackIndex++;
		setofstacks.push_back(new substack<T>(size));
		setofstacks[currStackIndex]->push(elem);
	}
}

// Popping an element from top of a stack implemented by a set of fixed length substacks
template <class T>
T SetOfStacks<T>::pop()
{
	if (!setofstacks[currStackIndex]->isempty())
	{
		return setofstacks[currStackIndex]->pop();
	}
	else
	{
		setofstacks.pop_back();
		currStackIndex--;

		if (currStackIndex >= 0)
		{
			return setofstacks[currStackIndex]->pop();
		}
		else
		{
			cout << "Stack is empty" << endl;
			return NULL;
		}
	}
}

// Peeking an element from top of a stack implemented by a set of fixed length substacks
template <class T>
T SetOfStacks<T>::peek()
{
	return setofstacks[currStackIndex]->peek();
}

// Popping from substack of specific index
template <class T>
T SetOfStacks<T>::popAt(int i)
{
	if(i < setofstacks.size() && !setofstacks[i]->isempty())
	{
		return setofstacks[i]->pop();
	}
	else
	{
		cout << "Stack is empty" << endl;
		return NULL;
	}
}

int main()
{
	SetOfStacks<int> *s = new SetOfStacks<int>(5);
	s->push(1);
	s->push(2);
	s->push(3);
	s->push(4);
	s->push(5);

	s->push(6);
	s->push(7);
	s->push(8);

	cout << s->pop() << endl;
	cout << s->pop() << endl;
	cout << s->pop() << endl;
	cout << s->popAt(1) << endl;
	cout << s->popAt(0) << endl;
	cout << s->pop() << endl;
	cout << s->pop() << endl;
	cout << s->pop() << endl;

	s->push(1);
	s->push(2);
	s->push(3);

	cout << s->pop() << endl;
	cout << s->pop() << endl;
	cout << s->pop() << endl;
	cout << s->peek() << endl;
	
	cout << s->pop() << endl;

	system("pause");
}