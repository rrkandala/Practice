/*	Program: Given a sorted array with unique elements, write an algo to create a BST with minimal height
 *	Author: Ankit Srivastava
 *
 *	Date: 1/19/2016
 */
 
using System;
using System.Collections.Generic;

namespace CrackingTheCodingInterview
{
	/// <summary>
	/// Class representing a node of the Binary Search Tree
	/// </summary>
	public class BstNode
	{
		private object data;
		private BstNode left;
		private BstNode right;
		
		/// <summary>
		/// Data contained in Binary Search Tree Node
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
		/// Node left to the current node
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
		/// Node right to the current node
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
		/// Constructor initializing a new node
		/// </summary>
		public BstNode(object d)
		{
			data = d;
			right = null;
			left = null;
		}
	}
	
	/// <summary>
	/// Class implementation of a Binary Search Tree
	/// </summary>
	public class BinarySearchTree
	{
		private BstNode root;
		
		/// <summary>
		/// Constructor initializing an empty binary search tree
		/// </summary>
		public BinarySearchTree()
		{
			root = null;
		}
	}
	
	/// <summary>
	/// Class which inputs a sorted array with unique elements and converts it into a minimum height Binary Search Tree
	/// </summary>
	public class MinimalHeightBst
	{
		private List<int> arrayElements;
	}
	
	internal class MinimalHeightBstTest
	{
		static void Main()
		{
			MinimalHeightBst obj = new MinimalHeightBst(6);
			
			obj.Insert(1);
			obj.Insert(3);
			obj.Insert(4);
			obj.Insert(6);
			obj.Insert(7);
			obj.Insert(9);
			
			obj.GetMinimumHeightBst();
		}
	}
}