/*	Program: Sort a stack in ascending order with biggest items on top using another temp stack but no other data structure
 *	Author: Ankit Srivastava
 *
 *	Date: 12/31/2015
 */

using System;

namespace CrackingTheCodingInterview
{
    /// <summary>
    /// Sorting a stack using only one additional stack
    /// </summary>
    public class SortStack
    {
        private LinkedListStack s1;

        private LinkedListStack s2;

        /// <summary>
        /// Constructor initializing the main and temp stack
        /// </summary>
        public SortStack()
        {
            s1 = new LinkedListStack();
            s2 = new LinkedListStack();
        }

        /// <summary>
        /// Pushes an element onto stack
        /// </summary>
        /// <param name="d">Element to be inserted on stack</param>
        public void Push(object d)
        {
            s1.Push(d);
        }

        /// <summary>
        /// Sorts a stack and stores sorted one in another temp stack
        /// </summary>
        public void Sort()
        {
            while (!s1.IsEmpty())
            {
                int d = (int)s1.Pop();

                if (s2.IsEmpty())
                {
                    s2.Push(d);
                }
                else
                {
                    while (!s2.IsEmpty() && (int)s2.Peek() > d)
                    {
                        s1.Push(s2.Pop());
                    } 

                    s2.Push(d);
                }
            }

            Console.WriteLine("Sorted Stack: ");

            while (!s2.IsEmpty())
            {
                Console.WriteLine(s2.Pop());
            }
        }
    }

    /// <summary>
    /// Testing sort implementation using at most one additional stack
    /// </summary>
    internal class SortStackTest
    {
        static void Main()
        {
            SortStack s = new SortStack();

            s.Push(1);
            s.Push(2);
            s.Push(2);
            s.Push(4);
            s.Push(5);

            s.Sort();

            Console.ReadLine();
        }
    }
}