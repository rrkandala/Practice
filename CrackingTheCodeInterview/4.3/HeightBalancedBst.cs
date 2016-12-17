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
		/// Left node of the BST tree
		/// </summary>
		public BstNode Left
		{ 
		    get 
		    { 
		        return left; 
		        
		    } 
		    set
		    { 
		        left = value;
		    }
		}

		/// <summary>
		/// Right node of the BST tree
		/// </summary>
		public BstNode Right
		{ 
		    get 
		    { 
		        return right; 
		        
		    } 
		    set
		    { 
		        right = value;
		    }
		}

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
		private int[] sortedArray;		

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
		public HeightBalancedBst(int s)
		{
			root = null;
			size = s;
			sortedArray = new int[size];
		}
		
		/// <summary>
		/// Inserting node to BST
		/// <param name="s"> Array to be inserted </param>
		/// </summary>
		public void Insert(int[] s)
		{
			sortedArray = s;
		}
		
		/// <summary>
		/// Inserting node in BST
		/// <param name="d"> Data element in node </param>
		/// </summary>
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
			
			int mid = start + (end - start) / 2;
			Console.WriteLine("Start: {0}", start);
			Console.WriteLine("End: {0}", end);
			Console.WriteLine("Mid: {0}", mid);
			
			InsertNode(sortedArray[mid]);
			
			CopySortedArrayToHBst(start, mid-1);
			CopySortedArrayToHBst(mid+1, end);
		}

        /// <summary>
        /// Printing inorder traversal
        /// <param name="n">Node to be the root
        /// </summary>
		internal void InorderPrint(BstNode n)
		{
			if(n != null)
			{
				InorderPrint(n.Left);	
				Console.WriteLine("{0}->", n.Data);			
				InorderPrint(n.Right);				
			}
		}
		
		/// <summary>
		/// Printing inorder traversal
		/// </summary>
		public void Print()
		{
		    InorderPrint(root);
		}
	}

	/// <summary>
	/// Testing implementation of height balanced binary search tree
	/// </summary>
	internal class HeightBalancedBstTest
	{
		static void Main()
		{
			int size = 5;
			HeightBalancedBst h = new HeightBalancedBst(size);
			int [] arr = new int[size];
			for(int i = 0; i < size; i++)
			{
				arr[i] = i;
			}	

			h.Insert(arr);
			h.CopySortedArrayToHBst(0, 4);
			h.Print();
			
			Console.ReadLine();
		}
	}
}
 