using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StaticInstance
{
    class Program
    {
        static void Main(string[] args)
        {
            List<Hibajegy> hibak = new List<Hibajegy>();

            Hibajegy j1 = new Hibajegy();
            j1.HibaLeiras = "Gond van!";
            // j1.Mikor = DateTime.Now;
            hibak.Add(j1);

            Hibajegy j2 = new Hibajegy("Nagy gond van!");
            hibak.Add(j2);

            Hibajegy j3 = new Hibajegy("Nagyon nagy gond van!");
            hibak.Add(j3);

            foreach (Hibajegy j in hibak)
            {
                Console.WriteLine("A hiba leírása: {0} ", j.HibaLeiras);
                HibaSuly.HibaSulyKiir(j);
            }


            Console.WriteLine("Eddigi hibák száma {0} ", Hibajegy.Counter);
            Console.WriteLine("A bajok összege: {0}", HibaSuly.Bajmeret);


            Console.ReadLine();

        }
    }
}
