using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Irszamos
{
    class Telepules
    {
        public int Irszam { get; set; }

        public string TelepulesNev { get; set; }

        public string Megye { get; set; }

        public Telepules(int irsz, string nev, string megy)
        {
            Irszam = irsz;
            TelepulesNev = nev;
            Megye = megy;
        }

        public override string ToString()
        {
            return $"{TelepulesNev} - {Irszam}";
        }
    }
}
