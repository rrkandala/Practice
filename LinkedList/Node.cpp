#include "LinkedList.h"

template <class T>
Node<T>::Node() : _pNext(NULL)
{}

template <class T>
Node<T>::Node(T val) : _value(val), _pNext(NULL)
{}

template <class T>
Node<T>::Node(T val, Node* next) : _value(val), _pNext(next)
{}

template <class T>
T Node<T>::getValue()
{
	return _value;
}

template <class T>
Node<T>* Node<T>::getNext()
{
	return _pNext;
}