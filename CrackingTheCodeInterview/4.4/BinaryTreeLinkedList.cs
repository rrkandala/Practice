/*	Program: Given a binary tree of depth 'd', create 'd' linked lists to store elements at each depth
 *	Author: Ankit Srivastava
 *	
 *	Date: 1/9/2016
 */

using System;

namespace CrackingTheCodingInterview
{
	/// <summary>
	/// Partial class of BTree adding a method to port elements of tree at each depth to a separate linked list
	/// </summary>
	public partial class BTree
	{
		private List<SinglyLinkedList> linkedLists;		
		
		private MyQueue<TreeNode> bfsQueue; 
		
		/// <summary>
		/// Take elements of each depth and store them in the queue
		/// </summary>
		public void Bfs()
		{
			TreeNode temp = root;
			bfsQueue.Enqueue(root);	

			while(bfsQueue != null)
			{
				
			}
		}
	}
}
