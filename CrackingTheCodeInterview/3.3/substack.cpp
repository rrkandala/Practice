/*	Program: Implement a stack using 'k' sub-stacks of fixed length
 *	Author: Ankit Srivastava
 *
 *	Date: 12/28/2015
 */
 
#include "substack.h"

template <class T>
public class substack
{
	private:
		T *arr;
		int available;
	public:
		stack(int capacity);
		~stack();
		push(T elem);
		T pop();
		T peek();
		bool isfull();
};

// Constructor initializing size of substack
substack::substack(int capacity)
{
	available = capacity;
	arr = new T[capacity];
}

// Destructor freeing memory allocated by the stack implemented using array
substack::~substack()
{
	delete[] arr;
	arr = NULL;
}

