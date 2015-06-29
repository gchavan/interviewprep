using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DesignQuestsions_CS
{
    class Program
    {
        public static readonly string Alphabet = "abcdefghijklmnopqrstuvwxyz0123456789";
        public static readonly int Base = Alphabet.Length;

        public static string Encode(int i)
        {
            if (i == 0) return Alphabet[0].ToString();

            var s = string.Empty;
            while (i > 0)
            {
                s = Alphabet[i % Base] + s;
                i = i / Base;
            }

            return s;
        }

        public static int Decode(string s)
        {
            var i = 0;

            foreach (var c in s)
            {
                i = (i * Base) + Alphabet.IndexOf(c);
            }

            return i;
        }

        public static void Main(string[] args)
        {
            int i = 1234;
            string encodedString = Encode(i);
            System.Console.WriteLine("Encode({0}) is {1}", i, encodedString);

            System.Console.WriteLine("Decode({0}) is {1}", encodedString, Decode(encodedString));

            string[] words = { "Tushar", "likes", "to", "write", "code", "at", "free", "time" };
            textJustify(words, 12);

            Console.ReadLine();
        }

        private static void textJustify(string[] words, int width)
        {
            int[,] cost = new int[words.Length, words.Length];
            for (int i = 0; i < words.Length; i++)
            {
                cost[i, i] = width - words[i].Length;
                for (int j = i+1; j < words.Length; j++)
                {
                    cost[i, j] = cost[i, j - 1] - words[j].Length - 1;
                }
            }

            for (int i = 0; i < words.Length; i++)
            {
                for (int j = i; j < words.Length; j++)
                {
                    if (cost[i, j] < 0)
                        cost[i, j] = int.MaxValue;
                    else
                        cost[i, j] = cost[i, j] * cost[i, j];
                }
            }

            int[] minCost = new int[words.Length];
            int[] result = new int[words.Length];

            for (int i = words.Length - 1; i >= 0; i--)
            {
                minCost[i] = cost[i, words.Length - 1];
                result[i] = words.Length;
                for (int j = words.Length - 1; j > i; j--)
                {
                    if (cost[i, j - 1] == int.MaxValue)
                        continue;
                    if (minCost[i] > minCost[j] + cost[i, j-1])
                    {
                        minCost[i] = minCost[j] + cost[i, j - 1];
                        result[i] = j;
                    }
                }
            }

            int index = 0;
            int jIndex = 0;
            do
            {
                jIndex = result[index];
                for (int k = index; k < jIndex; k++)
                {
                    Console.Write(words[k] + " ");
                }
                Console.WriteLine();
                index = jIndex;
            } while (jIndex < words.Length);
        } 
    }
}
