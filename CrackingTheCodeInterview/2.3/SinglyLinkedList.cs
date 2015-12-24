/*	Program: Singly Linked List implementation in C#
 *	Author: Ankit Srivastava
 *	
 *	Date: 12/24/2015
 */

using System;

/// <summary>
/// Practising problems from Cracking the Coding Interview book
/// </summary>
namespace CrackingTheCodingInterview
{
    /// <summary>
    /// Implementation of a singly linked list
    /// </summary>
    public class SinglyLinkedList
    {
        /// <summary>
        /// A node of the singly linked list
        ///	It contains data in generic object type and points to next node in the list
        /// </summary>
        public class Node
        {
            private object data;
            private Node next;

            /// <summary>
            /// Data contained in the node
            /// </summary>
            public object Data
            {
                get
                {
                    return data;
                }

                set
                {
                    data = value;
                }
            }

            /// <summary>
            /// Reference to the next node of the singly linked list
            /// </summary>
            public Node Next
            {
                get
                {
                    return next;
                }

                set
                {
                    next = value;
                }
            }
        }

        private Node head;

        /// <summary>
        ///	Creates a new node for inserting in singly linked list
        /// <param name="d">Data to be inserted in node</param>
        /// <returns>Returns the created node to be added in singly linked list</returns>
        private Node CreateNewNode(object d)
        {
            Node newNode = new Node();
            newNode.Data = d;
            newNode.Next = null;

            return newNode;
        }

        /// <summary>
        /// Default constructor of singly linked list
        /// </summary>
        public SinglyLinkedList()
        {
            head = null;
        }

        /// <summary>
        /// Insert a node to the start of singly linked list
        /// </summary>
        /// <param name="d">Data to be inserted in the singly linked list</param>
        public void Insert(object d)
        {
            Node newNode = CreateNewNode(d);

            if (head == null)
            {
                head = newNode;
            }
            else
            {
                newNode.Next = head;
                head = newNode;
            }
        }

        /// <summary>
        /// Traverse and print all the nodes of singly linked list
        /// </summary>
        public void Print()
        {
            Node temp = head;

            while (temp != null)
            {
                Console.Write("{0}->", temp.Data);
                temp = temp.Next;
            }

            Console.WriteLine();
        }

        /// <summary>
        /// Singly Linked List Implementation Test
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

            Console.ReadLine();
        }
    }
}