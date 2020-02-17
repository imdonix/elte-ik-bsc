using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace szamkitalalo
{
    class Program
    {
        static void Main(string[] args)
        {
            Random r = new Random();
            int goal = r.Next(100);
            int tipp;
            int i = 0;

            do
            {
                i++;
                tipp = int.Parse(Console.ReadLine());
                if (goal < tipp)
                    Console.WriteLine("kissebb");
                else
                    Console.WriteLine("nagyobb");
            } while (tipp != goal);
            Console.WriteLine("nyertél : {0}", i);
            Console.ReadLine();
        }
    }
}
