using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PermutationCombination
{
    class PermuteCombine
    {
        static void Main(string[] args)
        {
            string inString;

            Console.Write("Enter a string to permute/combine: ");
            inString = Console.ReadLine();

            DoCombine(inString);

            Console.ReadLine();
        }

        public static void DoPermute(string inStr)
        {
            int len = inStr.Length;
            char[] outStr = new char[len + 1];
            int[] used = new int[len];

            for(int i = 0; i < len; i++)
            {
                used[i] = 0;
            }

            DoPermuteAll(inStr, outStr, len, used, 0);
        }

        public static void DoPermuteAll(string inStr, char[] outStr, int len, int[] used, int level)
        {
            if(level == len)
            {
                outStr[len] = '\0';
                Console.WriteLine(outStr);
            }
            else
            {
                for(int i = 0; i < len; i++)
                {
                    if(used[i] == 1)
                    {
                        continue;
                    }

                    outStr[level] = inStr[i];
                    used[i] = 1;
                    DoPermuteAll(inStr, outStr, len, used, level + 1);
                    used[i] = 0;
                }
            }
        }

        public static void DoCombine(string inStr)
        {
            int len = inStr.Length;
            char[] outStr = new char[len + 1];
            DoCombineAll(inStr, outStr, len, 0, 0);
        }

        public static void DoCombineAll(string inStr, char[] outStr, int len, int level, int start)
        {
            for(int i = start; i < len; i++)
            {
                outStr[level] = inStr[i];
                outStr[level + 1] = '\0';
                Console.WriteLine(outStr);
                if(i < len - 1)
                {
                    DoCombineAll(inStr, outStr, len, level + 1, i + 1);
                }
            }
        }
    }
}
