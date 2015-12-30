/*	Program: To implement solution for Towers of Hanoi problem using Stacks
 *	Author: Ankit Srivastava
 *	
 *	Date: 12/29/2015
 */

using System;

namespace CrackingTheCodingInterview
{
    /// <summary>
    /// Implementation of Towers of Hanoi problem with N disks and 3 stacks
    /// </summary>
    public class TowersOfHanoi
    {
        private LinkedListStack[] stacks;

        private int[] disks;

        private int[] stackLength;

        /// <summary>
        /// <param name="N">Number of disks</param>
        /// Constructor which initializes the stack and the disk array
        /// </summary>
        public TowersOfHanoi(int N)
        {
            stacks = new LinkedListStack[3];

            disks = new int[N];

            for(int i = 0; i < 3; i++)
            {
                stacks[i] = new LinkedListStack();
            }

            // Initializing disk array and first stack
            for (int i = 0; i < N; i++)
            {
                disks[i] = i;
                stacks[0].Push(N - i);
            }

            // Initializing length of stacks
            stackLength = new int[3];
            stackLength[0] = N;
            stackLength[1] = 0;
            stackLength[2] = 0;
        }

        /// <summary>
        /// Solving Tower of Hanoi problem for even and odd number of disks
        /// </summary>
        public void Solve()
        {
            int odd = disks.Length % 2;

            int counter = 0;

            while (stackLength[2] != disks.Length)
            {
                if (odd == 1)
                {
                    if(!MoveTop(0, 2))
                    {
                        MoveTop(2, 0);
                    }

                    if(stackLength[2] == disks.Length)
                    {
                        break;
                    }

                    if(!MoveTop(0, 1))
                    {
                        MoveTop(1, 0);
                    }

                    if (stackLength[2] == disks.Length)
                    {
                        break;
                    }

                    if (!MoveTop(2, 1))
                    {
                        MoveTop(1, 2);
                    }
                }
                else
                {
                    Console.WriteLine("Move Number: {0}", ++counter);

                    if(!MoveTop(0, 1))
                    {
                        MoveTop(1, 0);
                    }

                    if (stackLength[2] == disks.Length)
                    {
                        break;
                    }

                    if (!MoveTop(0, 2))
                    {
                        MoveTop(2, 0);
                    }

                    if (stackLength[2] == disks.Length)
                    {
                        break;
                    }

                    if (!MoveTop(1, 2))
                    {
                        MoveTop(2, 1);
                    }
                }
            }

            Console.WriteLine("Moved {0} disks from stack 0 to stack 2!", disks.Length);
        }

        internal bool MoveTop(int i, int j)
        {
            if (!stacks[i].IsEmpty() && (stacks[j].Peek() == null || (int)stacks[i].Peek() < (int)stacks[j].Peek()))
            {
                int topElem = (int)stacks[i].Pop();
                stacks[j].Push(topElem);
                stackLength[i]--;
                stackLength[j]++;

                Console.WriteLine("Moved {0} from stack {1} to {2}", topElem, i + 1, j + 1);
                Console.WriteLine("Stack 1 top: {0} \nStack 2 top: {1} \nStack 3 top: {2} \n", stacks[0].Peek(), stacks[1].Peek(), stacks[2].Peek());
                return true;
            }
            else
            {
                return false;
            }
        }
    }

    internal class TowersOfHanoiTest
    {
        static void Main()
        {
            TowersOfHanoi twEven = new TowersOfHanoi(6);
            twEven.Solve();

            TowersOfHanoi twOdd = new TowersOfHanoi(5);
            twOdd.Solve();

            Console.ReadLine();
        }
    }
}