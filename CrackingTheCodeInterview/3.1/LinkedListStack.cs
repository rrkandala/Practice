/*	Program: Implementing a stack
 *	Author: Ankit Srivastava
 *
 *	Date: 12/26/2015
 */

using System;

namespace CrackingTheCodingInterview
{
    /// <summary>
    /// Implementation of stack using linked list
    /// </summary>
    public partial class LinkedListStack
    {
        private SinglyLinkedList top;

        /// <summary>
        /// Constructor instantiating the linked list
        /// </summary>
        public LinkedListStack()
        {
            top = new SinglyLinkedList();
        }

        /// <summary>
        /// <param name="d">Element to be pushed in stack</param>
        /// Pushing an element on top of stack
        /// </summary>
        public void Push(object d)
        {
            top.Insert(d);
        }

        /// <summary>
        /// <returns>Element popped from stack</returns>
        /// </summary>
        public object Pop()
        {
            return top.DeleteHead();
        }

        /// <summary>
		/// Gets a peek on top of stack
        /// <returns>Element on top of stack peeked </returns>
        /// </summary>
        public object Peek()
        {
            return top.PeekHead();
        }

        /// <summary>
        /// Checks if stack is empty or not
        /// <returns>true if stack is empty else false</returns>
        /// </summary>
        public bool IsEmpty()
        {
            return top.IsEmpty();
        }
    }

    internal class StackTest
    {
        static void Main()
        {
            LinkedListStack stack = new LinkedListStack();

            stack.Push(1);
            stack.Push(2);
            stack.Push(3);
            stack.Push(4);
            stack.Push(5);

            Console.WriteLine("Stack Pop: {0}", stack.Pop());
            Console.WriteLine("Stack Pop: {0}", stack.Pop());
            Console.WriteLine("Stack Pop: {0}", stack.Pop());
            Console.WriteLine("Stack Peek: {0}", stack.Peek());
            Console.WriteLine("Stack Pop: {0}", stack.Pop());

            stack.Push(6);
            Console.WriteLine("Stack Pop: {0}", stack.Pop());

            Console.ReadLine();
        }
    }
}