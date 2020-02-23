using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StaticInstance
{
    static class HibaSuly
    {

        public static int Bajmeret
        {
            get; set;
        }


        public static void HibaSulyKiir(Hibajegy j)
        {
            Console.WriteLine("A hiba súlyossága: {0}", j.HibaLeiras.Length);
            Bajmeret += j.HibaLeiras.Length;
        }
    }
}
