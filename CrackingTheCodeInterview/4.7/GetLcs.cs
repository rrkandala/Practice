using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LowestCommonAncestor
{
    /// <summary>
    /// Node of a binary tree
    /// </summary>
    public class Node
    {
        public int data { get; set; }
        public Node left { get; set; }
        public Node right { get; set; }
    }

    /// <summary>
    /// BinaryTree methods
    /// </summary>
    public class BinaryTree
    {
        /// <summary>
        /// Starting point of binary tree
        /// </summary>
        private Node root;

        /// <summary>
        /// Creating a new Binary Tree Node
        /// </summary>
        /// <param name="d"></param>
        /// <returns></returns>
        private Node CreateNode(int d)
        {
            Node newNode = new Node();
            newNode.data = d;
            newNode.left = null;
            newNode.right = null;

            return newNode;
        }

        /// <summary>
        /// Constructor of Binary Tree
        /// </summary>
        public BinaryTree()
        {
            root = null;
        }

        /// <summary>
        /// Insert a new node in binary tree
        /// </summary>
        /// <param name="d">Value to be inserted</param>
        public void Insert(int d)
        {
            if(root == null)
            {
                Node newNode = CreateNode(d);
                root = newNode;
            }
            else
            {
                Node temp = root;

                while(true)
                {
                    if (temp.data > d && temp.left == null)
                    {
                        Node newNode = CreateNode(d);
                        temp.left = newNode;
                        break;
                    }
                    else if (temp.data > d && temp.left != null)
                    {
                        temp = temp.left;
                    }
                    else if(temp.data <= d && temp.right == null)
                    {
                        Node newNode = CreateNode(d);
                        temp.right = newNode;
                        break;
                    }
                    else
                    {
                        temp = temp.right;
                    }
                }
            }
        }

        private void Print(Node n)
        {
            if(n == null)
            {
                return;
            }
            else
            {
                Print(n.left);
                Console.WriteLine(string.Format("{0}->", n.data));
                Print(n.right);
            }
        }

        public void Print()
        {
            Print(root);
            Console.WriteLine();
        }

        private void Dfs(Node n, int s, ref Node found)
        {
            if(n == null || found != null)
            {
                return;
            }
            else
            {
                if(n.data == s)
                {
                    found = n;
                }

                Dfs(n, s, ref found);
                Dfs(n, s, ref found);
            }
        }

        public Node Dfs(int s)
        {
            Node found = null;
            Dfs(root, s, ref found);
            
            if(found == null)
            {
                return null;
            }
            else
            {
                return found;
            }
        }

        private void GetLowestCommonAncestor(Node n, Node n1, Node n2, ref Node found)
        {
            if(n1 == null || n2 == null || root == null || n == null || found != null)
            {
                return;
            }
            else
            {
                Node f = null;
                Node n1leftfound = null;
                Dfs(n.left, n1.data, ref n1leftfound);
                Node n2leftfound = null;
                Dfs(n.left, n2.data, ref n2leftfound);
                
                if (n1leftfound != null && n2leftfound != null)
                {
                    GetLowestCommonAncestor(n.left, n1, n2, ref f);
                }
                else if (n1leftfound != null)
                {
                    Node n2rightfound = null;
                    Dfs(n.right, n2.data, ref n2rightfound);

                    if (n2rightfound != null)
                    {
                        f = n;
                    }
                }
                else if(n2leftfound != null)
                {
                    Node n1rightfound = null;
                    Dfs(n.right, n1.data, ref n1rightfound);

                    if (n1rightfound != null)
                    {
                        f = n;
                    }
                }
                else
                {
                    GetLowestCommonAncestor(n.right, n1, n2, ref f);
                }
            }
        }

        public int GetLowestCommonAncestor(int s1, int s2)
        {
            Node n1 = Dfs(s1);
            Node n2 = Dfs(s2);

            Node lcs = null;
            GetLowestCommonAncestor(root, n1, n2, ref lcs);

            if (lcs == null)
            {
                return Int32.MinValue;
            }
            else
            {
                return lcs.data;
            }
        }
    }

    internal class LowestCommonAncestorTest
    {
        static void Main(string[] args)
        {
            BinaryTree bt = new BinaryTree();
            bt.Insert(5);
            bt.Insert(2);
            bt.Insert(3);
            bt.Insert(1);
            bt.Insert(6);
            bt.Insert(7);

            Console.WriteLine("The lowest common ancestor of {0} and {1} is: {2}", 3, 7, bt.GetLowestCommonAncestor(3, 7));

            Console.ReadLine();
        }
    }
}
