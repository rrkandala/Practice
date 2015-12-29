/*	Program: Stack of stacks - Implement a stack using 'k' sub-stacks of fixed length
*	Author: Ankit Srivastava
*
*	Date: 12/28/2015
*/

#ifndef _STACK_OF_STACKS_H_
#define _STACK_OF_STACKS_H_

#include <iostream>

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

#endif