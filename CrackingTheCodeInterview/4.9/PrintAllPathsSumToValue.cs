/*	Program: Print all paths of a binary tree that sum to a value
 *	Author: Ankit Srivastava
 *	Date: 9/20/2016
 */
 
using System;
using System.Collections.Generic;

public class Node
{
	public int data {get; set;}
	public Node left {get; set;}
	public Node right {get;set;}
	public Node parent {get;set;}
	
	public Node()
	{
		data = (int)0;
		left = null;
		right = null;
		parent = null;
	}
	
	public Node(int d)
	{
		data = d;
		left = null;
		right = null;
		parent = null;
	}
}

public class BinaryTree
{
	private Node root;
	
	public BinaryTree()
	{
		root = null;
	}
	
	private Node CreateNode(int d)
	{
		Node newNode = new Node(d);
		return newNode;
	}
	
	public void Insert(int d)
	{
		Node newNode = CreateNode(d);
		
		Node temp = root;
		
		if(root == null)
		{
			root = newNode;
		}
		else
		{
			while(true)
			{
				if(temp.data >= d)
				{
					if(temp.left == null)
					{
						temp.left = newNode;
						temp.left.parent = temp;
						break;
					}
					else
					{
						temp = temp.left;
					}
				}
				else
				{
					if(temp.right == null)
					{
						temp.right = newNode;
						temp.right.parent = temp;
						break;
					}
					else
					{
						temp = temp.right;
					}
				}
			}
		}
	}
	
	private void _PreOrder(Node temp)
	{
		if(temp == null)
		{
			return;
		}
		else
		{
			_PreOrder(temp.left);
			_PreOrder(temp.right);
			Console.WriteLine(temp.data);
		}
	}
	
	private void _InOrder(Node temp)
	{
		if(temp == null)
		{
			return;
		}
		else
		{
			_InOrder(temp.left);
			Console.WriteLine(temp.data);
			_InOrder(temp.right);
		}
	}
	
	private void _PostOrder(Node temp)
	{
		if(temp == null)
		{
			return;
		}
		else
		{
			_PostOrder(temp.left);			
			_PostOrder(temp.right);
			Console.WriteLine(temp.data);
		}
	}
	
	public void PreOrder()
	{
		_PreOrder(root);
	}
	
	public void InOrder()
	{
		_InOrder(root);
	}
	
	public void PostOrder()
	{
		_PostOrder(root);
	}
	
	private void _FindSum(Node temp, int sum, int[]path, int level)
	{
		if(temp == null)
		{
			return;
		}
		
		path[level] = temp.data;
		
		int t = 0;
		for(int i = level; i >= 0; i--)
		{
			t += path[i];
			if(t == sum)
			{
				PrintPath(path, i, level);
			}
		}
		
		_FindSum(temp.left, sum, path, level + 1);
		_FindSum(temp.right, sum, path, level + 1);
		
		path[level] = Int32.MinValue;
	}
	
	public void FindSum(int sum)
	{
		int d = depth(root);
		int[] path = new int[d];
		_FindSum(root, sum, path, 0);
	}
	
	private int depth(Node temp)
	{
		if(temp == null)
		{
			return 0;
		}
		else
		{
			return 1 + Math.Max(depth(temp.left), depth(temp.right));	
		}
	}
	
	public void PrintPath(int[] path, int start, int end)
	{
		for(int i = start; i <= end; i++)
		{
			Console.Write("{0} ", path[i]);
		}
	}
	
	static void Main()
	{
		Console.WriteLine("Binary Tree Implementation");
		BinaryTree bt = new BinaryTree();
		bt.Insert(3);
		bt.Insert(2);
		bt.Insert(4);
		bt.Insert(1);
		bt.Insert(5);
		
		bt.FindSum(5);
	}
}