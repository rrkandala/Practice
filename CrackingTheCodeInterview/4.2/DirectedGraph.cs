/*	Program: To check if there is a route between node A and node B in a directed graph
 *	Author: Ankit Srivastava
 *
 *	Date: 1/4/2016
 */

using System;
using System.Collections.Generic;

namespace CrackingTheCodingInterview
{
    /// <summary>
    /// Node of a directed graph
    /// </summary>
    public class GraphNode
    {
        private object data;
        private List<GraphNode> edgeTo;

        /// <summary>
        /// Data inside the graph node
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
        /// Neighbors of a node in the directed graph
        /// </summary>
        public List<GraphNode> EdgeTo
        {
            get
            {
                return edgeTo;
            }
            set
            {
                edgeTo = value;
            }
        }

        /// <summary>
        /// Constructor of graph node
        /// </summary>
        /// <param name="d">Data to be initialized in node</param>
        public GraphNode(object d)
        {
            Data = d;
            EdgeTo = new List<GraphNode>();
        }
    }

    /// <summary>
    /// Directed Graph Class
    /// </summary>
    public class DirectedGraph
    {
        private List<GraphNode> vertices;

        /// <summary>
        /// Constructor initializing the list of nodes
        /// </summary>
        public DirectedGraph()
        {
            vertices = new List<GraphNode>();
        }

        /// <summary>
        /// Inserting node in graph
        /// </summary>
        /// <param name="d">Data to be inserted in node</param>
        public void InsertNode(object d)
        {
            GraphNode newGraphNode = new GraphNode(d);
            vertices.Add(newGraphNode);
        }

        /// <summary>
        /// Inserting edge in graph
        /// </summary>
        /// <param name="a">Source Node A</param>
        /// <param name="b">Destination Node B</param>
        public void InsertEdge(int a, int b)
        {
            vertices[a - 1].EdgeTo.Add(vertices[b - 1]);
        }

        /// <summary>
        /// Check if route exists between two nodes in a directed graph
        /// </summary>
        /// <param name="a">Node A</param>
        /// <param name="b">Node B</param>
        /// <returns>true if route exists else false</returns>
        public bool IsRouteBetweenNodes(int a, int b)
        {
            bool[] visited = new bool[vertices.Count];

            for(int i = 0; i < vertices.Count; i++)
            {
                visited[i] = false;
            }

            return Dfs(a, b, visited);
        }

        /// <summary>
        /// Depth First Search to find a route between route A and route B
        /// </summary>
        /// <param name="a">Node A</param>
        /// <param name="b">Node B</param>
        /// <param name="visited">Node visited - true/false</param>
        /// <returns>true if route exists else false</returns>
        public bool Dfs(int a, int b, bool[] visited)
        {
            visited[a - 1] = true;

            foreach (GraphNode neighbor in vertices[a-1].EdgeTo)
            {
                if (!visited[(int)neighbor.Data - 1])
                {
                    if (vertices[b - 1] == vertices[(int)neighbor.Data - 1])
                    {
                        return true;
                    }

                    visited[(int)neighbor.Data - 1] = true;

                    foreach (GraphNode vertex in neighbor.EdgeTo)
                    {
                        if (!visited[(int)vertex.Data - 1])
                        {
                            if (vertices[b- 1] == vertices[(int)vertex.Data - 1])
                            {
                                return true;
                            }

                            visited[(int)vertex.Data - 1] = true;
                        }
                    }
                }
            }

            return false;
        } 
    }

    /// <summary>
    /// Testing implementation of directed graph
    /// </summary>
    internal class DirectedGraphTest
    {
        static void Main()
        {
            DirectedGraph dg = new DirectedGraph();

            dg.InsertNode(1);
            dg.InsertNode(2);
            dg.InsertNode(3);
            dg.InsertNode(4);
            dg.InsertNode(5);
            dg.InsertNode(6);

            dg.InsertEdge(1, 2);
            dg.InsertEdge(1, 3);
            dg.InsertEdge(1, 4);
            dg.InsertEdge(2, 5);
            dg.InsertEdge(2, 6);
            dg.InsertEdge(3, 4);
            dg.InsertEdge(4, 5);
            dg.InsertEdge(5, 3);

            Console.WriteLine("Route exists between {0} and {1}: {2}", 6, 1, dg.IsRouteBetweenNodes(6, 1));

            Console.ReadLine();
        }
	}
}