using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IsPathBetweenNodes
{
    public class Node
    {
        internal bool Visited { get; set; }

        internal List<Node> Edges { get; set; }

        public Node()
        {
            Edges = new List<Node>();
        }
    }

    public class Graph
    {
        internal List<Node> nodes;

        public Graph()
        {
            nodes = new List<Node>();
        }

        public void Initialize()
        {
            foreach (Node n in nodes)
            {
                n.Visited = false;
            }
        }

        public void InsertNode(Node n)
        {
            nodes.Add(n);
        }

        public void InsertEdge(Node n1, Node n2)
        {
            n1.Edges.Add(n2);
            n2.Edges.Add(n1);
        }

        public bool IsPathBetweenNodes(Node n1, Node n2)
        {
            bool found = false;

            Initialize();

            Dfs(n1, n2, ref found);

            return found;
        }

        public void Dfs(Node root, Node search, ref bool found)
        {
            root.Visited = true;

            if (root == search)
            {
                found = true;
            }
            else
            {
                foreach (Node n in root.Edges)
                {
                    if(n.Visited == false)
                    {
                        Dfs(n, search, ref found);
                    }
                }
            }
        }

        public void Bfs(Node root, Node search, ref bool found)
        {
            root.Visited = true;
            if (root == search)
            {
                found = true;
            }
            else
            {
                Queue<Node> q = new Queue<Node>();
                q.Enqueue(root);

                while (q.Count > 0)
                {
                    Node r = q.Dequeue();

                    foreach (Node n in r.Edges)
                    {
                        if (n.Visited == false)
                        {
                            if (n == search)
                            {
                                found = true;
                                break;
                            }

                            n.Visited = true;
                            q.Enqueue(n);
                        }
                    }

                    if(found)
                    {
                        break;
                    }
                }
            }
        }
    }

    class GraphTraversal
    {
        static void Main(string[] args)
        {
            Graph g = new Graph();
            Node[] n = new Node[6];

            for(int i = 0; i < 6; i++)
            {
                n[i] = new Node();
            }

            g.InsertNode(n[0]);
            g.InsertNode(n[1]);
            g.InsertNode(n[2]);
            g.InsertNode(n[3]);
            g.InsertNode(n[4]);

            g.InsertEdge(n[0], n[1]);
            g.InsertEdge(n[1], n[3]);
            g.InsertEdge(n[4], n[5]);

            string res = g.IsPathBetweenNodes(n[0], n[3]) ? "is" : "is not";
            Console.WriteLine("There {0} a path between the two nodes", res);

            Console.ReadLine();
        }
    }
}
