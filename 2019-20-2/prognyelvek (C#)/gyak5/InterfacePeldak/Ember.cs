using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InterfacePeldak
{
   public class Ember : IComparable
    {
        public string Neve { get; set; }

        public int SzEv { get; set; }

        public Ember(string nev, int szev)
        {
            Neve = nev;
            SzEv = szev;
        }

        public override string ToString()
        {
            return $"{Neve} {SzEv}";
        }

        public int CompareTo(object obj)
        {
            if (SzEv >= ((Ember)obj).SzEv)
            {
                return 1;
            }
            return -1;
        }
    }
}
