/*	Program: To implement a queue for cat and dog shelter
 *	Author: Ankit Srivastava
 *	
 *	Date: 1/1/2016
 */

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
			private CatDogType type;

            private int num;

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
    }

    internal class CatDogShelterQueueTest
    {
        static void Main()
        {

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