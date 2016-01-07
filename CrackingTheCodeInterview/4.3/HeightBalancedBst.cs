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
		
	}

	/// <summary>
	/// Testing implementation of height balanced binary search tree
	/// </summary>
	internal class HeightBalancedBstTest
	{
		static void Main()
		{
			
		}
	}
}
