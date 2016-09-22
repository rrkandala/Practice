/*	Program: Implement a graph and how to traverse it using BFS and DFS
 *	Author: Ankit Srivastava
 *	Date: 9/21/2016
 */
 
using System;
using System.Collections.Generic;

public class Node
{
	int data;
	bool visited;
	List<Node> edges;
	
	public Node()
	{
		data = 0;
		visited = false;
		edges = new List<Node>();
	}
	
	public Node(int d)
	{
		data = d;
		visited = false;
		edges = new List<Node>();
	}
}

public class Graph
{
	private List<Node> nodeList;
	
	public Graph()
	{
		nodeList = new List<Node>();
	}
	
	private Node CreateNode(int d)
	{
		Node newNode = new Node(d);
		return newNode;
	}
	
	public void AddNode(int d)
	{
		Node newNode = CreateNode(d);
		nodeList.Add(newNode);
	}
	
	public void AddEdge(int t1, int t2)
	{
		if(nodeList.Count < t1 && nodeList.Count < t2)
		{
			nodeList[t1].edges.Add(nodeList[t2]);
			nodeList[t2].edges.Add(nodeList[t1]);
		}
		else
		{
			Console.WriteLine("The indexes are not valid as the graph only has {0} nodes", nodeList.Count);
			return;
		}
	}
	
	private void _Dfs(Node search)
	{
		if(search == null)
		{
			return;
		}
		else
		{
			Console.Write("{0}->", search.data);
			search.visited = true;
			
			foreach(Node n in search.edges)
			{
				if(n.visited == false)
				{
					_Dfs(n);
				}
			}
		}
	}
	
	public void Dfs()
	{
		foreach(Node n in nodeList)
		{
			n.visited = false;
		}
		
		if(nodeList == null || nodeList.Count == 0)
		{
			Console.WriteLine("Graph is empty!");
			return;
		}
		else
		{
			_Dfs(nodeList[0]);
		}
	}
	
	private void _Bfs(Node temp)
	{
		Queue<Node> q = new Queue<Node>();
		
		if(temp == null)
		{
			return;
		}
		
		if(temp.visited == false)
		{
			Console.Write("{0}", temp.data);
		}
		
		q.Enqueue(temp);
		
		while(!q.IsEmpty())
		{
			foreach(Node n in temp.edges)
			{
				q.Dequeue();
				
				if(n.visited == false)
				{
					Console.Write("{0}", n.data);
					n.visited = true;
					queue.Enqueue(n));
				}
			}
		}
	}
}