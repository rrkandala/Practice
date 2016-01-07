/*	Program: Given a sorted array of unique integers, write an algorithm to create a BST with minimal height
 *	Author: Ankit Srivastava
 *
 *	Date: 1/6/2016
 */

using System;

namespace CrackingTheCodingInterview
{
	/// <summary>
	/// Node of a binary search tree
	/// </summary>
	public class BstNode
	{
		/// <summary>
		/// Key value in the tree
		/// </summary>			
		private object data;
		
		/// <summary>
		/// Left child of the node
		/// </summary>
		private BstNode left;
		
		/// <summary>
		/// Right child of the node
		/// </summary>
		private BstNode right;

		/// <summary>
		/// Data stored in the node
		/// </summary>
		public object Data { get; set; }
		
		/// <summary>
		/// Left node of the BST tree
		/// </summary>
		public BstNode Left { get; set; }

		/// <summary>
		/// Right node of the BST tree
		/// </summary>
		public BstNode Right { get; set; }

		/// <summary>
		/// Constructor of BST Node
		/// </summary>
		public BstNode(object d)
		{
			data = d;
			left = null;
			right = null;
		}
	}	
	
	/// <summary>
	/// Given an array of elements, write an algorithm to create a BST with minimal height
	/// </summary>
	public class HeightBalancedBst
	{	
		/// <summary>
		/// Sorted Array of integers
		/// </summary>
		private int[] sortedArray		

		/// <summary>
		/// Size of the BST array
		/// </summary>
		private int size;	

		/// <summary>
		/// Root of the Binary Search Tree
		/// </summary>
		private BstNode root;
		
		/// <summary>
		/// Constructor initializing root to null
		/// </summary>
		public HeightBalancedBst(int size)
		{
			root = null;
			sortedArray = new int[size];
		}
		
		/// <summary>
		/// Inserting node to BST
		/// </summary>
		public void Insert()
		{
			Console.WriteLine("Enter {0} elements: ", size);

			for(int i = 0; i < size; i++)
			{
				sortedArray[i] = Convert.ToInt32(Console.ReadLine());
			}
		}
		
		public void InsertNode(int d)
		{
			BstNode newBstNode = new BstNode(d);			

			if(root == null)
			{
				root = newBstNode;
			}
			else
			{
				BstNode temp = root;

				while(temp != null)
				{
					if(d < (int)temp.Data)
					{
						if(temp.Left == null)
						{
							temp.Left = newBstNode;
							break;
						}
						else
						{
							temp = temp.Left;
						}
					}
					else
					{
						if(temp.Right == null)
						{
							temp.Right = newBstNode;
							break;
						}
						else
						{
							temp = temp.Right;
						}
					}
				}
			}
		}

		/// <summary>
		/// Move all sorted elements of array to BST of minimal height
		/// </summary>
		public void CopySortedArrayToHBst(int start, int end)
		{
			if(start > end)
			{
				return;
			}
			
			int mid = start/2 + end/2;
			InsertNode(sortedArray(mid));
			
			CopySortedArrayToHBst(start, mid-1);
			CopySortedArrayToHBst(mid+1, end);
		}

		print void InorderPrint(BstNode n)
		{
			if(n != null)
			{
				Inorder(n.Left);	
				Console.WriteLine("{0}->", n->Data);			
				Inorder(n.Right);				
			}
		}
	}

	/// <summary>
	/// Testing implementation of height balanced binary search tree
	/// </summary>
	internal class HeightBalancedBstTest
	{
		static void Main()
		{
			HeightBalancedBst h = new HeightBalancedBst(5);
			h.Insert();
			h.CopySortedArrayToHBst(0, 4);
			h.Print();
			
			Console.ReadLine();
		}
	}
}
