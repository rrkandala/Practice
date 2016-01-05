/*	Program: To check if there is a route between node A and node B in a directed graph
 *	Author: Ankit Srivastava
 *
 *	Date: 1/4/2016
 */

using System;
using System.Collections.Generic;

namespace CrackingTheCodingInterview
{
    public class GraphNode
    {
        private object data;
        private List<GraphNode> edgeTo;

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

        public GraphNode(object d)
        {
            Data = d;
            EdgeTo = new List<GraphNode>();
        }
    }

    public class DirectedGraph
    {
        private List<GraphNode> vertices;

        public DirectedGraph()
        {
            vertices = new List<GraphNode>();
        }

        public void InsertNode(object d)
        {
            GraphNode newGraphNode = new GraphNode(d);
            vertices.Add(newGraphNode);
        }

        public void InsertEdge(int a, int b)
        {
            vertices[a-1].EdgeTo.Add(vertices[b-1]);
        }
    }

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

            Console.ReadLine();
        }
	}
}