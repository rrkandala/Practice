/*	Program: Check if a linked list is a palindrome or not
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
        /// Check if a linked list is a palindrome or not
        /// </summary>
        /// <returns>true if linked list is a palindrome else false</returns>
        public bool IsLinkedListPalindrome()
        {
            SinglyLinkedList rev = new SinglyLinkedList();

            Node curr = head;

            while(curr != null)
            {
                rev.Insert(curr.Data);
                curr = curr.Next;
            }

            Node origNode = head;
            Node revNode = rev.head;

            while (origNode != null)
            {
                if (!origNode.Data.Equals(revNode.Data))
                {
                    return false;
                }

                origNode = origNode.Next;
                revNode = revNode.Next;
            }

            return true;
        }
    }

    internal class CheckLinkedListPalindromeTest
    {
        static void Main()
        {
            SinglyLinkedList list = new SinglyLinkedList();

            list.Insert(1);
            list.Insert(2);
            list.Insert(3);
            list.Insert(2);
            list.Insert(1);

            if (list.IsLinkedListPalindrome())
            {
                Console.WriteLine("Linked List is Palindrome");
            }
            else
            {
                Console.WriteLine("Linked List is not Palindrome");
            }

            Console.ReadLine();
        }
    }
}