/*	Program: To implement a queue for cat and dog shelter
 *	Author: Ankit Srivastava
 *	
 *	Date: 1/1/2016
 */
 
namespace CrackingTheCodingInterview
{	
	public class CatDogShelterQueue
	{
		internal CatDog
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
			CatDog cd = new CatDog(d, c);
			
			queue.Insert(cd);
		}
		
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
	
	enum CatDogType
	{
		Cat, Dog
	};
}