/*	Program: Implement a stack which contains a min method which retreives min element of stack in constant time
 *	Author: Ankit Srivastava
 *	
 *	Date: 12/27/2015
 */

using System;

namespace CrackingTheCodingInterview
{
    /// <summary>
    /// Stack implementing an extra 'MinElement' method which retrieves the minimum element of stack in constant time
    /// </summary>
    public class MinStack
    {
        private SinglyLinkedList stack;

        private object minElement;

        /// <summary>
        /// Constructor which initializes the array implementing the stack
        /// </summary>
        public MinStack()
        {
            stack = new SinglyLinkedList();

            minElement = null;
        }

        /// <summary>
        /// <param name="d">Element 'd' to be pushed</param>
        /// Pushing an element on stack (twice in case element is l.t.e current min element) 
        /// </summary>
        public void Push(object d)
        {
            if (minElement == null || (int)d <= (int)minElement)
            {
                stack.Insert(minElement);
                stack.Insert(d);
                minElement = d;
            }
            else
            {
                stack.Insert(d);
            }
        }

        /// <summary>
        /// Pops an element off the stack. If its the min element, pop happens twice as we pushed twice. 
        /// This gives way to the next min element on the stack (which is pushed twice as well).
        /// <returns>Pops element from stack</returns>
        /// </summary>
        public object Pop()
        {
            object d = stack.DeleteHead();

            if (minElement.Equals(d))
            {
                minElement = stack.DeleteHead();
            }

            return d;
        }

        /// <summary>
        /// Peeks the top element of stack
        /// <returns>Top element of stack</returns>
        /// </summary>
        public object Peek()
        {
            return stack.PeekHead();
        }

        /// <summary>
        /// Returns the min element of stack
        /// <returns>Min element of stack</returns>
        /// </summary>
        public object Min()
        {
            return minElement;
        }

        /// <summary>
        /// Prints the linked list
        /// </summary>
        internal void Print()
        {
            stack.Print();
        }
    }

    internal class MinStackTest
    {
        static void Main()
        {
            MinStack minStack = new MinStack();

            minStack.Push(2);
            Console.WriteLine("Pushing 2 Min: {0}", minStack.Min());
            minStack.Push(6);
            Console.WriteLine("Pushing 6 Min: {0}", minStack.Min());
            minStack.Push(4);
            Console.WriteLine("Pushing 4 Min: {0}", minStack.Min());
            minStack.Push(1);
            Console.WriteLine("Pushing 1 Min: {0}", minStack.Min());
            minStack.Push(5);
            Console.WriteLine("Pushing 5 Min: {0}", minStack.Min());
            minStack.Push(1);
            Console.WriteLine("Pushing 1 Min: {0}", minStack.Min());

            minStack.Print();

            Console.WriteLine("Pop: {0} Min: {1}", minStack.Pop(), minStack.Min());
            minStack.Print();
            Console.WriteLine("Pop: {0} Min: {1}", minStack.Pop(), minStack.Min());
            minStack.Print();
            Console.WriteLine("Pop: {0} Min: {1}", minStack.Pop(), minStack.Min());
            minStack.Print();

            Console.WriteLine("Min: {0}", minStack.Min());

            Console.ReadLine();
        }
    }
}