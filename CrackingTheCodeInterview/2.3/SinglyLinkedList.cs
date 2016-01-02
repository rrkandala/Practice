/*	Program: Singly Linked List implementation in C#
 *	Author: Ankit Srivastava
 *	
 *	Date: 12/24/2015
 */

using System;

namespace CrackingTheCodingInterview
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

    /// <summary>
    /// Implementation of a singly linked list
    /// </summary>
    public partial class SinglyLinkedList
    {
        private Node head;

        /// <summary>
        ///	Creates a new node for inserting in singly linked list
        /// <param name="d">Data to be inserted in node</param>
        /// <returns>Returns the created node to be added in singly linked list</returns>
        /// </summary>
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
        /// <param name="d">Data to be searched in all the nodes of a singly linked list</param>
        /// Traverses through each node of a singly linked list and searches for an element
        /// <returns>Node if the searched element exists else null </returns>
        /// </summary>
        public Node Search(object d)
        {
            Node temp = head;

            while (temp != null)
            {
                if (temp.Data.Equals(d))
                {
                    return temp;
                }

                temp = temp.Next;
            }

            return null;
        }

        /// <summary>
        /// Returns head of the linked list if it exists else null
        /// <returns>Data in head of linked list if it exists else null</returns>
        /// </summary>
        public object DeleteHead()
        {
            if (head != null)
            {
                Node temp = head;
                head = head.Next;

                return temp.Data;
            }
            else
            {
                return null;
            }
        }

        /// <summary>
        /// Peeks head of the linked list if it exists else null
        /// <returns>Data in head of linked list if it exists else null</returns>
        /// </summary>
        public object PeekHead()
        {
            if (head != null)
            {
                return head.Data;
            }
            else
            {
                return null;
            }
        }

        /// <summary>
        /// Checks if the singly linked list is empty
        /// <returns>true if linked list is empty else false</returns>
        /// </summary>
        public bool IsEmpty()
        {
            return (head == null);
        }
		
		/// <summary>
		/// Inserts the element at the end of the linked list
		/// <param name="d">Element to be inserted at the end</param>
		/// </summary>
		public void InsertEnd(object d)
		{
			Node newNode = CreateNewNode(d);
			
			Node temp = head;
			
			if(head == null)
			{
				head = newNode;
			}
			else
			{
				while(temp.Next != null)
				{
					temp = temp.Next;
				}
				
				temp.Next = newNode;
			}
		}
		
		public object DeleteEnd()
		{
			if(head == null || head.Next == null)
			{
				return DeleteHead();
			}
			else
			{
				Node temp = head;
				
				while(temp.Next != null)
				{
					temp = temp.Next;
				}
				
				temp.Next = null;
			}
		}
		
		/// <summary>
		/// Deletes second last element of linked list
		/// <returns>Second last element of linked list</returns>
		/// </summary>
		public object DeleteSecondLast()
		{
			if(head == null || head.Next == null)
			{
				return null;
			}
			else
			{
				if(head.Next.Next == null)
				{
					head = head.Next;
				}
				else
				{
					Node temp = head;
					
					while(temp.Next.Next.Next != null)
					{
						temp = temp.Next;
					}
					
					object del = temp.Next;
					temp = temp.Next.Next;
					
					return del;
				}
			}
		}
    }
}