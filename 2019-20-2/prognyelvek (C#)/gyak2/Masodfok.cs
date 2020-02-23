using System;

namespace ConsoleApp41
{
    class Program
    {
        static void Main(string[] args)
        {
            MasodfokPeldany m = new MasodfokPeldany();
            m.A = 1;
            m.B = -3;
            m.C = 2;

            double x1, x2;
            if (m.GetResult( out x1, out x2))
            {
                Console.WriteLine("A megoldás: {0:F3} / {1:F3}", x1, x2);
            }
            else
            {
                Console.WriteLine("Nincs megoldás");
            }

            MasodfokPeldany m2 = new MasodfokPeldany(4, -6, 2);
            if (m2.GetResult(out x1, out x2))
            {
                Console.WriteLine("A megoldás: {0:F3} / {1:F3}", x1, x2);
            }
            else
            {
                Console.WriteLine("Nincs megoldás");
            }
            Console.ReadLine();
        }
    }
}



