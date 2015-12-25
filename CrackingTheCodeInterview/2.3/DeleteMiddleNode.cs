/*	Program: Delete the middle of a singly linked list given only a pointer to it
 *	Author: Ankit Srivastava
 *	
 *	Date: 12/24/2015
 */

using System;

namespace CrackingTheCodingInterview
{
    public partial class SinglyLinkedList
    {
        /// <summary>
        /// <param name="mid">Pointer to the middle node in the singly linked list</param>
        /// Deletes the middle node of the singly linked list given only a pointer to it
        /// </summary>
        public void DeleteMidNode(Node mid)
        {
            if (mid != null && mid.Next != null)
            {
                mid.Data = mid.Next.Data;
                mid.Next = mid.Next.Next;
            }
        }
    }

    /// <summary>
    /// Testing implementation of singly linked list
    /// </summary>
    internal class DeleteMiddleNodeTest
    {
        /// <summary>
        /// Testing deletion of middle given only a pointer to it
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

            Node mid = list.Search(3);

            list.DeleteMidNode(mid);

            Console.WriteLine("After deleteting middle node: ");

            list.Print();

            Console.ReadLine();
        }
    }
}