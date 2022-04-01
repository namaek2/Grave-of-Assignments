using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1.Array_Multiply
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int a, b;

            a = Convert.ToInt32(Console.ReadLine());
            int[] array1 = new int[a];

            for(int i=0; i<array1.Length; i++)
            {
                array1[i] = Convert.ToInt32(Console.ReadLine());
            }

            b = Convert.ToInt32(Console.ReadLine());
            int[] array2 = new int[b];

            for (int i = 0; i < array2.Length; i++)
            {
                array2[i] = Convert.ToInt32(Console.ReadLine());
            }

            Console.Write("Result : [");
            for (int i=0; i< array1.Length; i++)
            {
                for(int j=0; j< array2.Length; j++)
                {
                    Console.Write(array1[i] * array2[j]);

                    if((i+1!= array1.Length) ||(j+1!= array2.Length))
                        Console.Write(" ");
                }
            }
            Console.Write("]");
        }
    }
}
