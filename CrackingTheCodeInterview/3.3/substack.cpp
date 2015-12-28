/*	Program: Implement a stack using 'k' sub-stacks of fixed length
*	Author: Ankit Srivastava
*
*	Date: 12/28/2015
*/

#include "substack.h"

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

// Program execution starts here
int main()
{
	substack<int> *obj = new substack<int>(5);

	obj->push(1);
	obj->push(2);
	obj->push(3);
	obj->push(4);
	obj->push(5);

	cout << "Pop: " << obj->pop() << endl;
	cout << "Pop: " << obj->pop() << endl;
	cout << "Pop: " << obj->pop() << endl;

	cout << "Is Full: " << obj->isfull() << endl;

	obj->push(3);
	obj->push(4);
	obj->push(5);
	obj->push(6);
	
	cout << "Pop: " << obj->pop() << endl;

	cout << "Is Full: " << obj->isfull() << endl;

	delete obj;

	return 0;
}