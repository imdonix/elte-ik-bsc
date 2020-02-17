using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Szamolo
{
    class Program
    {
        static void Main(string[] args)
        {
            for (int i = 0; i < 10; i++)
            {
                Console.WriteLine(i);
            }

            int j = 0;
            while (j < 10)
            {
                Console.WriteLine(j);
                j++;
            }

            int k = 0;
            do
            {
                Console.WriteLine(k);
                k++;
            } while (k< 10);
            Console.ReadLine();


        }
    }
}
