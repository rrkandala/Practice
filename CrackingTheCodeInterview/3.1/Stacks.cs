/*	Program: Implement 3 stacks using a single array
 *	Author: Ankit Srivastava
 *
 *	Date: 12/26/2015
 */

using System;

namespace CrackingTheCodingInterview
{
    internal class Item
    {
        public object data;
        public int prev;
    }

    /// <summary>
    /// Class implementing 3 stacks using single array
    /// </summary>
    public class Stacks
    {
        /// <summary>
        /// Pushing an element 'data' onto a stack 'i'
        /// </summary>
        public void Push(int i, object d)
        {
            i--;
            if (available != null)
            {
                int ava = (int)available.DeleteHead();
                elems[ava].data = d;
                elems[ava].prev = top[i];
                top[i] = ava;
            }
            else
            {
                Console.WriteLine("Array full. No more space to enter!");
                return;
            }
        }

        /// <summary>
        /// Popping an element from stack 'i'
        /// </summary>
        public object Pop(int i)
        {
            i--;
            if (top[i] != -1)
            {
                object popVal = elems[top[i]].data;
                int prevTop = elems[top[i]].prev;
                elems[top[i]].data = null;
                elems[top[i]].prev = -1;
                available.Insert(top[i]);
                top[i] = prevTop;

                return popVal;
            }
            else
            {
                Console.WriteLine("Stack: {0} empty!", i);
                return null;
            }
        }

        /// <summary>
        /// Peeking top element of a stack
        /// </summary>
        public object Peek(int i)
        {
            i--;
            if (top[i] != -1)
            {
                return elems[top[i]].data;
            }
            else
            {
                Console.WriteLine("Stack: {0} empty!", i);
                return null;
            }
        }

        /// <summary>
        /// Constructor initializing array of Nodes of size 'n' and the ability to store 'k' stacks
        /// </summary>
        public Stacks(int n, int k)
        {
            elems = new Item[n];
            top = new int[k];

            for (int i = 0; i < k; i++)
            {
                top[i] = -1;
            }

            for (int i = 0; i < n; i++)
            {
                elems[i] = new Item();
                elems[i].data = null;
                elems[i].prev = -1;
            }

            available = new SinglyLinkedList();

            for (int i = n - 1; i >= 0; i--)
            {
                available.Insert(i);
            }
        }

        private Item[] elems;
        private int[] top;
        private SinglyLinkedList available;
    }

    internal class StacksArrayTest
    {
        static void Main()
        {
            Stacks s = new Stacks(10, 3);
            s.Push(1, 'a');
            s.Push(1, 'b');
            s.Push(1, 'c');

            Console.WriteLine("After pushing in stack 1");
            Console.WriteLine("Top 1: {0}", s.Peek(1));

            s.Push(2, 'd');
            s.Push(2, 'e');
            s.Push(2, 'f');
            s.Push(2, 'g');

            Console.WriteLine("After pushing in stack 2");
            Console.WriteLine("Top 1: {0}", s.Peek(1));
            Console.WriteLine("Top 2: {0}", s.Peek(2));

            s.Pop(1);
            s.Pop(2);

            Console.WriteLine("After popping from stack 1 and 2");
            Console.WriteLine("Top 1: {0}", s.Peek(1));
            Console.WriteLine("Top 2: {0}", s.Peek(2));

            s.Push(3, 'h');
            s.Push(3, 'i');
            s.Push(3, 'j');
            s.Push(3, 'k');
            s.Push(3, 'l');

            Console.WriteLine("After pushing in stack 3");
            Console.WriteLine("Top 3: {0}", s.Peek(3));

            Console.ReadLine();
        }
    }
}

