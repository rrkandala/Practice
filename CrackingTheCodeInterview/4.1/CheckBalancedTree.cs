/*	Program: To implement a binary tree in C#
 *	Author: Ankit Srivastava
 *
 *	Date: 1/2/2016
 */

using System;

namespace CrackingTheCodingInterview
{
    /// <summary>
    /// Implementing node of a binary tree
    /// </summary>
    public class TreeNode
    {
        private object data;
		private int depth;
        private TreeNode left;
        private TreeNode right;

        /// <summary>
        /// Value in node
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
        /// Node left of current node
        /// </summary>
        public TreeNode Left
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
        /// Node right of current node
        /// </summary>
        public TreeNode Right
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
		/// Depth of tree
		/// </summary>
		public int Depth
		{
			get
			{
				return depth;
			}
			set
			{
				depth = value;
			}
		}

        /// <summary>
        /// Constructor initializing the current node
        /// </summary>
        /// <param name="d">Data element</param>
        public TreeNode(object d)
        {
            Data = d;
			Depth = 1;
            Left = null;
            Right = null;
        }
    }

    /// <summary>
    /// Binary Tree Implementation
    /// </summary>
    public partial class BTree
    {
        private TreeNode root;

        /// <summary>
        /// Binary Tree Constructor initializing root
        /// </summary>
        public BTree()
        {
            root = null;
			linkedLists = new List<SinglyLinkedList>();
        }

        /// <summary>
        /// Inserting value in tree
        /// </summary>
        /// <param name="d">Data Element</param>
        public void Insert(object d)
        {
            if (root == null)
            {
                root = new TreeNode(d);
            }
            else
            {
                Insert(d, root);
            }
        }

        /// <summary>
        /// Recursively insert value in tree
        /// </summary>
        /// <param name="d">Data element</param>
        /// <param name="leaf">Current root node</param>
        public void Insert(object d, TreeNode leaf)
        {
            if ((int)d < (int)leaf.Data)
            {
                if (leaf.Left != null)
                {
                    Insert(d, leaf.Left);
                }
                else
                {
                    leaf.Left = new TreeNode(d);
                }
            }
            else if ((int)d >= (int)leaf.Data)
            {
                if (leaf.Right != null)
                {
                    Insert(d, leaf.Right);
                }
                else
                {
                    leaf.Right = new TreeNode(d);
                }
            }
        }

        /// <summary>
        /// Search a value in tree
        /// </summary>
        /// <param name="d">Data element</param>
        /// <returns>true if value found else false</returns>
        public bool Search(object d)
        {
            if (root == null)
            {
                return false;
            }
            else
            {
                return Search(d, root);
            }
        }

        /// <summary>
        /// Search a value in tree recursively
        /// </summary>
        /// <param name="d">Value to be found</param>
        /// <param name="leaf">Current node</param>
        /// <returns>true if value found else false</returns>
        public bool Search(object d, TreeNode leaf)
        {
            if (leaf == null)
            {
                return false;
            }
            else if ((int)d == (int)leaf.Data)
            {
                return true;
            }
            else if ((int)d < (int)leaf.Data)
            {
                return Search(d, leaf.Left);
            }
            else if ((int)d > (int)leaf.Data)
            {
                return Search(d, leaf.Right);
            }
            else
            {
                return false;
            }
        }

        /// <summary>
        /// In order print of tree
        /// </summary>
        public void Print()
        {
            InOrder(root);
        }

        /// <summary>
        /// Inorder traversal of tree
        /// </summary>
        /// <param name="leaf"></param>
        public void InOrder(TreeNode leaf)
        {
            if(leaf == null)
            {
                return;
            }
            else
            {
                InOrder(leaf.Left);
                Console.WriteLine(leaf.Data);
                InOrder(leaf.Right);
            }
        }

        /// <summary>
        /// Check if a tree is balanced
        /// </summary>
        /// <returns>true if tree balanced else false</returns>
        public bool IsTreeBalanced()
        {
            if(ComputeAndCheckHeight(root) == -1)
            {
                return false;
            }
            else
            {
                return true;
            }
        }

        /// <summary>
        /// Computes height of left and right subtree recursively and checks validity of balanced tree at each step
        /// </summary>
        /// <param name="leaf">Starts at root</param>
        /// <returns>true if tree with current leaf as root is balanced or not</returns>
        public int ComputeAndCheckHeight(TreeNode leaf)
        {
            if(leaf == null)
            {
                return 0;
            }
            else
            {
                int leftHeight = ComputeAndCheckHeight(leaf.Left);
                if(leftHeight == -1)
                {
                    return -1;
                }

                int rightHeight = ComputeAndCheckHeight(leaf.Right);
                if(rightHeight == -1)
                {
                    return -1;
                }

                int heightDiff = Math.Abs(leftHeight - rightHeight);
                if (heightDiff > 1)
                {
                    return -1;
                }
                else
                {
                    return (Math.Max(leftHeight, rightHeight) + 1);
                }
            }
        }
    }

    internal class BTreeTest
    {
        static void Main()
        {
            BTree t = new BTree();

            t.Insert(1);
            t.Insert(2);
            t.Insert(3);
            t.Insert(4);
            t.Insert(5);

            Console.WriteLine("Value {0} {1}", 3, t.Search(3));

            t.Print();

            Console.WriteLine("Is Tree Balanced: {0}", t.IsTreeBalanced());

            Console.ReadLine();
        }
    }
}
