using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace sum
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Adj egy számot");
            string input1 = Console.ReadLine();
            int a = int.Parse(input1);

            Console.WriteLine("Adj még egy számot");
            string input2 = Console.ReadLine();
            int b = int.Parse(input2);

            Console.WriteLine(Osszead(a,b));

            int x;
            Osszeadd(a, b, out x);
            Console.WriteLine(x);

            Console.ReadLine();
        
        }

        /// <summary>
        /// Ez osszead
        /// </summary>
        /// <param name="a">egyik</param>
        /// <param name="b">masik</param>
        /// <returns>ketto osszege</returns>
        static int Osszead(int a, int b)
        {
            return a + b;
        }

        /// <summary>
        /// gfghfghfhgfhgfghgffhfgfhfghfghfghfghfgfghfhghgfhhf
        /// </summary>
        /// <param name="a"></param>
        /// <param name="b"></param>
        /// <param name="c"></param>
        static void Osszead(int a, int b, out int c)
        {
            c = a + b;
        }


    }
}
