using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Jelszo1
{
    class Program
    {
        static void Main(string[] args)
        {
            string valami = "XXXabrakadabra183055xxx";
            string valamiMas = "B";
            char[] betuk = new char[valami.Length];
            List<char> masBetuk = new List<char>();
            int x = 0;

            foreach (char c in valami)
            {
                if (c % 2 == 0)
                {
                    betuk[x] = char.ToUpper(c);
                }
                else
                {
                    betuk[x] = (char)((byte)c + 1);
                }
                masBetuk.Add(c);
                x++;
            }
            masBetuk.Sort();
            Array.Sort(betuk);

            for (int i = 0; i < betuk.Length; i++)
            {
                if (betuk[i] == masBetuk[i]+1)
                {
                    valamiMas += betuk[i];
                }
            }
            Console.WriteLine(valamiMas);
            Console.ReadLine();
        }
    }
}
