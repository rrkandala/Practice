/*	Program: Implement a queue using two stacks
 *	Author: Ankit Srivastava
 *
 *	Date: 12/30/2015
 */

using System; 

namespace CrackingTheCodingInterview
{
	public class MyQueue
	{
		private LinkedListStack s1;
		
		private LinkedListStack s2;
		
		/// <summary>
		/// Constructor initializing the two stacks
		/// </summmary>
		public MyQueue()
		{
			s1 = new LinkedListStack();
			s2 = new LinkedListStack();
		}
		
		/// <summary>
		/// <param name="d"> Object to place on the queue</param>
		/// Place the element in the queue
		/// </summary>
		public void Enqueue(object d)
		{
			while(!s2.IsEmpty())
			{
				object elem = s2.Pop();
				s1.Push(elem);
			}
			
			s1.Push(d);
		}
		
		/// <summary>
		/// Removes an element from the queue
		/// <returns>Element to be removed from queue as per FIFO</returns>
		/// </summary>
		public object Dequeue()
		{
			while(!s1.IsEmpty())
			{
				object d = s1.Pop();
				s2.Push(d);
			}
			
			return s2.Pop();
		}
	}
	
	internal class MyQueueTest
	{
		static void Main()
		{
			MyQueue q = new MyQueue();
			
			q.Enqueue(1);
			q.Enqueue(2);
			q.Enqueue(3);
			q.Enqueue(4);
			q.Enqueue(5);
			
			Console.WriteLine(q.Dequeue());
			Console.WriteLine(q.Dequeue());
			Console.WriteLine(q.Dequeue());
			
			q.Enqueue(6);
			q.Enqueue(7);
			q.Enqueue(8);
			
			Console.ReadLine();
		}
	}
}