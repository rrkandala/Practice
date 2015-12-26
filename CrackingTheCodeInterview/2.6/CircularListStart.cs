/*	Program: Find the beginning node of a circular linked list
 *	Author: Ankit Srivastava
 *
 *	Date: 12/25/2015
 */

using System;

namespace CrackingTheCodingInterview
{
    /// <summary>
    /// This contains a method which detects the beginning node where the linked list starts becoming circular
    /// Given A->B->C(start)->D->E->C, return C (third node) as that is where the list starts being circular
    /// </summary>
    public partial class SinglyLinkedList
    {
        /// <summary>
        /// Method which detects the beginning node where the linked list starts becoming circular
        /// </summary>
        /// <param name="circularHead">Head of singly linked list which starts becoming circular at some point</param>
        /// <returns></returns>
        public static Node GetCircularLinkedListStart(Node circularHead)
        {
            Node slow = circularHead;
            Node fast = circularHead;

            while (slow != null)
            {
                slow = slow.Next;

                if(fast.Next == null)
                {
                    return null;
                }
                else
                {
                    fast = fast.Next.Next;
                }

                if (slow == fast)
                {
                    slow = circularHead;

                    while (slow != fast)
                    {
                        slow = slow.Next;
                        fast = fast.Next;
                    }

                    return slow;
                }
            }

            return null;
        }
    }

    internal class CircularLinkedListTest
    {
        /// <summary>
        /// Internal test method which creates a corrupt (circular) singly linked list
        /// </summary>
        /// <returns></returns>
        internal static Node GetCircularLinkedList()
        {
            SinglyLinkedList circularList = new SinglyLinkedList();

            Node n1 = new Node();
            Node n2 = new Node();
            Node n3 = new Node();
            Node n4 = new Node();
            Node n5 = new Node();

            n1.Data = 1;
            n1.Next = n2;

            n2.Data = 2;
            n2.Next = n3;

            n3.Data = 3;
            n3.Next = n4;

            n4.Data = 4;
            n4.Next = n5;

            n5.Data = 5;
            n5.Next = n3;

            return n1;
        }

        /// <summary>
        /// Test to find if method is able to find beginning of a singly linked list which goes on to become circular
        /// </summary>
        static void Main()
        {
            Node circularHead = GetCircularLinkedList();
            Node circularStart = SinglyLinkedList.GetCircularLinkedListStart(circularHead);

            Console.WriteLine("Beginning of circular list: {0}", circularStart.Data);

            Console.ReadLine();
        }
    }
}