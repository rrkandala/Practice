/*	Program: Partition a linked list around node 'x' such that all elements less than 'x' occur before nodes g.t.e 'x'
 *	Author: Ankit Srivastava
 *
 *	Date: 12/25/2015
 */

using System;

namespace CrackingTheCodingInterview
{
    public partial class SinglyLinkedList
    {
        /// <summary>
        /// Partition a singly linked list such that nodes less than 'x' occur before nodes g.t.e 'x'
        /// </summary>
        /// <param name="x"></param>
        public void PartitionList(int x)
        {
            if (head != null && head.Next != null)
            {
                Node prev = head;
                Node curr = head.Next;

                while (curr != null)
                {
                    if (x.CompareTo(curr.Data) > 0)
                    {
                        object insertBeforeX = curr.Data;
                        prev.Next = curr.Next;
                        curr = prev.Next;
                        Insert(insertBeforeX);
                    }
                    else
                    {
                        prev = curr;
                        curr = curr.Next;
                    }
                }
            }
            else
            {
                return;
            }
        }
    }

    /// <summary>
    /// Class which tests the method which partitions the singly linked list around 'x'
    /// </summary>
    internal class PartitionLinkedListTest
    {
        /// <summary>
        /// Testing implementation of linked list partition
        /// </summary>
        static void Main()
        {
            SinglyLinkedList list = new SinglyLinkedList();
            list.Insert(1);
            list.Insert(2);
            list.Insert(3);
            list.Insert(4);
            list.Insert(5);

            list.Print();

            list.PartitionList(3);

            Console.WriteLine("After partitioning: ");

            list.Print();

            Console.ReadLine();
        }
    }
}