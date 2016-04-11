using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CrackingTheCodingInterview
{
    /// <summary>
    /// Class which has a method for in-place replacement of spaces in a string with '%20'
    /// </summary>
    public class ReplaceSpaces
    {
        /// <summary>
        /// Method which takes a string as input and performs in place replacement of spaces in it with '%20'
        /// </summary>
        /// <param name="s"></param>
        /// <returns></returns>
        public static string GetReplaceSpaces(string s)
        {
            char[] sArray = s.ToCharArray();

            long countSpaces = 0;

            for(int i = 0; i < sArray.Length; i++)
            {
                if (sArray[i] == ' ')
                {
                    countSpaces++;
                }
            }

            if (countSpaces % 3 != 0)
            {
                Console.WriteLine("The input string does not have enough buffer spaces on right to replace spaces with %20 in place!");
                return null;
            }

            long len = sArray.Length - 1;
            long buffer = len - ((2 * countSpaces) / 3);
            long start = len - ((2 * countSpaces) / 3);

            while (start >= 0)
            {
                if (len > buffer && sArray[len] != ' ')
                {
                    Console.WriteLine("Space expected at index: {0} but encountered: {1}", len, sArray[len]);
                }

                if (sArray[start] == ' ')
                {
                    sArray[len--] = '0';
                    sArray[len--] = '2';
                    sArray[len--] = '%';
                }
                else
                {
                    sArray[len--] = sArray[start];
                }

                start--;
            }

            return new string(sArray);
        }
    }

    internal class ReplaceSpaceTest
    {
        static void Main()
        {
            Console.WriteLine(ReplaceSpaces.GetReplaceSpaces("Hello World  "));

            Console.ReadLine();
        }
    }
}