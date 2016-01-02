/*	Program: To implement a queue for cat and dog shelter
 *	Author: Ankit Srivastava
 *	
 *	Date: 1/1/2016
 */

using System;

namespace CrackingTheCodingInterview
{
    /// <summary>
    /// Class for a cat and dog shelter queue
    /// </summary>
    public class CatDogShelterQueue
    {
        /// <summary>
        /// Class for storing type and number of cat/dog
        /// </summary>
        public class CatDog
		{
			internal CatDogType type;

            internal int num;

            /// <summary>
            /// Constructor for initializing CatDog with its type and number
            /// </summary>
            public CatDog(int n, CatDogType t)
            {
                num = n;
                type = t;
            }
        }

        private SinglyLinkedList queue;

        /// <summary>
        /// Constructor initializing a singly linked list acting as a FIFO queue
        /// </summary>
        public CatDogShelterQueue()
        {
            queue = new SinglyLinkedList();
        }

        /// <summary>
        /// <param name="d"> Cat/Dog Number </param>
        /// <param name="c"> Type - Cat or Dog </param>
        /// </summary>
        public void enqueue(object d, CatDogType c)
        {
            CatDog cd = new CatDog((int)d, c);

            queue.Insert(cd);
        }

        /// <summary>
        /// Dequeueing last animal - cat or dog
        /// </summary>
        /// <returns>Cat or Dog oldest arrival</returns>
        public CatDog dequeueAny()
        {
            return (CatDog)queue.DeleteEnd();
        }

        /// <summary>
        /// Dequeueing the oldest cat
        /// </summary>
        /// <returns>Oldest entered cat</returns>
        public CatDog dequeueCat()
        {
            Node lastCat = null;

            Node temp = queue.head;

            while(temp != null)
            {
                if (((CatDog)temp.Data).type == CatDogType.Cat)
                {
                    lastCat = temp;
                }

                temp = temp.Next;
            }

            if(lastCat.Next == null)
            {
                return (CatDog)queue.DeleteEnd();
            }
            else
            {
                CatDog del = (CatDog)lastCat.Data;
                lastCat.Data = lastCat.Next.Data;
                lastCat.Next = lastCat.Next.Next;

                return del;
            }
        }

        /// <summary>
        /// Dequeueing the oldest dog
        /// </summary>
        /// <returns>Oldest entered dog</returns>
        public CatDog dequeueDog()
        {
            Node lastCat = null;

            Node temp = queue.head;

            while (temp != null)
            {
                if (((CatDog)temp.Data).type == CatDogType.Dog)
                {
                    lastCat = temp;
                }

                temp = temp.Next;
            }

            if (lastCat.Next == null)
            {
                return (CatDog)queue.DeleteEnd();
            }
            else
            {
                CatDog del = (CatDog)lastCat.Data;
                lastCat.Data = lastCat.Next.Data;
                lastCat.Next = lastCat.Next.Next;

                return del;
            }
        }
    }

    internal class CatDogShelterQueueTest
    {
        static void Main()
        {
            CatDogShelterQueue q = new CatDogShelterQueue();

            q.enqueue(1, CatDogType.Cat);
            q.enqueue(2, CatDogType.Dog);
            q.enqueue(3, CatDogType.Cat);
            q.enqueue(4, CatDogType.Dog);
            q.enqueue(5, CatDogType.Cat);

            Console.WriteLine("Dequeueing last animal: {0}", q.dequeueAny().num);
            Console.WriteLine("Dequeueing last cat: {0}", q.dequeueCat().num);
            Console.WriteLine("Dequeueing last dog: {0}", q.dequeueDog().num);

            Console.ReadLine();
        }
    }

    /// <summary>
    /// Cat or Dog
    /// </summary>
    public enum CatDogType
    {
        /// <summary>
        /// Cat
        /// </summary>
        Cat,

        /// <summary>
        /// Dog
        /// </summary>
        Dog
    };
}