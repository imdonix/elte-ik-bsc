using System;

namespace ConsoleApp39
{
    class Program
    {
        static void Main(string[] args)
        {
            Pelda p= new Pelda();
            p.Ertek = 77;
            string s = "alma";
            int[] ar = new int[2] { 77, 88 };
            int x = 123;

            SimaGetBack(s, p, ar, x);


            Pelda pp1 = new Pelda();
            pp1.Ertek = 44;
            Pelda pp2 = new Pelda();
            pp2.Ertek = 55;
            int a = 11;
            int b = 22;
            int c = 33;

            GetBack(out a, ref b, c, pp1, ref pp2); // out helyett in: az átadott paraméter nem módosítható

            Console.ReadLine();
        }

        static void SimaGetBack(string s, Pelda p, int[] ar, int x)
        {
            s = "Korte";
            p.Ertek++;
            ar[0]++;
            x++;
        }

        static void GetBack(out int x, ref int y, int z, Pelda p1, ref Pelda p2)
        {
            x = 111;
            y = 222;
            z = 333;
            p1.Ertek = 444;
            p2 = new Pelda();
            p2.Ertek = 555;
        }
    }

    class Pelda
    {
        public int Ertek { get; set; }
    }
}
