using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SzinesHV
{
    class Program
    {
        static void Main(string[] args)
        {
            for (int i = 0; i < 16; i++)
            {
                Console.ForegroundColor = (ConsoleColor)i;
                Console.BackgroundColor = (ConsoleColor)(15 - i);
                Console.WriteLine("Hello world");
            }

            
            Console.ReadLine();

        }
    }
}
