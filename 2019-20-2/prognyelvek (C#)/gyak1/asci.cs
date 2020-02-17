using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace asci
{
    class Program
    {
        static void Main(string[] args)
        {
            for (int i = 32; i < 255; i++)
            {
                Console.Write("{0,3}:{1}", i, (char) i);
            }
            Console.ReadLine();
        }
    }
}
