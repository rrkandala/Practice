/*	Program: Given two numbers represented in a linked list in reverse order, sum them and store the result in a third linked list
 *	Author: Ankit Srivastava
 *
 *	Date: 12/25/2015
 */

using System;

namespace CrackingTheCodingInterview
{
    /// <summary>
    /// Singly Linked List with a method to add two numbers stored in two linked lists in reverse order
    /// </summary>
    public partial class SinglyLinkedList
    {
        /// <summary>
        /// Adding two numbers stored in a linked list in reverse order
        /// </summary>
        /// <param name="num1">Linked List 1 storing number 1</param>
        /// <param name="num2">Linked List 2 storing number 2</param>
        /// <param name="result">Linked List 3 storing sum of number 1 and number 2</param>
        public static void SumNumbersReverse(SinglyLinkedList num1, SinglyLinkedList num2, SinglyLinkedList result)
        {
            int carryForward = 0;
            int sum = 0;

            Node num1Digit = num1.head;
            Node num2Digit = num2.head;

            int sum1 = 0;
            int sum2 = 0;

            while (num1Digit != null || num2Digit != null)
            {
                if (num1Digit == null)
                {
                    sum1 = 0;
                }
                else
                {
                    sum1 = (int)num1Digit.Data;
                }

                if (num2Digit == null)
                {
                    sum2 = 0;
                }
                else
                {
                    sum2 = (int)num2Digit.Data;
                }

                sum = sum1 + sum2 + carryForward;

                if (sum > 9)
                {
                    carryForward = 1;
                }
                else
                {
                    carryForward = 0;
                }

                result.Insert(sum % 10);

                if (num1Digit != null)
                {
                    num1Digit = num1Digit.Next;
                }

                if (num2Digit != null)
                {
                    num2Digit = num2Digit.Next;
                }
            }

            result.ReverseList();
        }

        /// <summary>
        /// Adding two numbers stored in a linked list in reverse order
        /// </summary>
        /// <param name="num1">Linked List 1 storing number 1</param>
        /// <param name="num2">Linked List 2 storing number 2</param>
        /// <param name="result">Linked List 3 storing sum of number 1 and number 2</param>
        public static void SumNumbersForward(SinglyLinkedList num1, SinglyLinkedList num2, SinglyLinkedList result)
        {
            num1.ReverseList();
            num2.ReverseList();

            SumNumbersReverse(num1, num2, result);

            result.ReverseList();
        }

        /// <summary>
        /// Reverse a singly linked list
        /// </summary>
        public void ReverseList()
        {
            Node prev = null;
            Node curr = head;
            Node currNext;

            while(curr != null)
            {
                currNext = curr.Next;
                curr.Next = prev;
                prev = curr;
                curr = currNext;
            }

            head = prev;
        }
    }


    internal class SumNumbersLinkedListTest
    {
        static void Main()
        {
            SinglyLinkedList num1 = new SinglyLinkedList();
            SinglyLinkedList num2 = new SinglyLinkedList();

            num1.Insert(6);
            num1.Insert(1);
            num1.Insert(7);

            num2.Insert(2);
            num2.Insert(9);
            num2.Insert(5);

            num1.Print();
            num2.Print();

            SinglyLinkedList resultReverseSum = new SinglyLinkedList();
            SinglyLinkedList resultForwardSum = new SinglyLinkedList();

            SinglyLinkedList.SumNumbersReverse(num1, num2, resultReverseSum);
            Console.WriteLine("After summing reverse: ");
            resultReverseSum.Print();

            SinglyLinkedList num3 = new SinglyLinkedList();
            SinglyLinkedList num4 = new SinglyLinkedList();

            num3.Insert(7);
            num3.Insert(1);
            num3.Insert(6);

            num4.Insert(5);
            num4.Insert(9);
            num4.Insert(2);

            SinglyLinkedList.SumNumbersForward(num3, num4, resultForwardSum);
            Console.WriteLine("After summing forward: ");
            resultForwardSum.Print();

            Console.ReadLine();
        }
    }
}