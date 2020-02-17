using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace KorKerTer
{
    class Program
    {
        static void Main(string[] args)
        {
            double r;
            Console.WriteLine("kérem a sugarat");
            string sugaram = Console.ReadLine();

            if (double.TryParse(sugaram, out r))
            {
                double kerulet = 2 * r * Math.PI;
                double terulet = r * r * Math.PI;
                Console.WriteLine("A kerület: {0:F3} a terület: {1:F3}", kerulet, terulet);
            }
            else
            {
                Console.WriteLine("nem szam");
            }

            Console.ReadLine();
        }
    }
}
