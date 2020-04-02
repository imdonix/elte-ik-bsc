using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Irszamos
{
    class TelepulesKezelo
    {
        public List<Telepules> Telepulesek { get; set; }

        public TelepulesKezelo()
        {
            Telepulesek = new List<Telepules>();
        }

        public void AdatBetoltes(string filenev)
        {
            using (StreamReader sr = new StreamReader(filenev))
            {
                while (!sr.EndOfStream)
                {
                    // 5241;Abádszalók;Jász-Nagykun-Szolnok
                    string line = sr.ReadLine();
                    string[] elemek = line.Split(';');
                    Telepules t = new Telepules
                        (
                        int.Parse(elemek[0]),
                        elemek[1],
                        elemek[2]
                        );

                    Telepulesek.Add(t);
                }
            }
        }

        public List<Telepules> SzuresMegyeSzerint(string megye)
        {
            List<Telepules> szurt = new List<Telepules>();
            foreach (Telepules t in Telepulesek)
            {
                if (t.Megye == megye)
                {
                    szurt.Add(t);
                }
            }
            return szurt;
        }

        public List<Telepules> SzuresNevSzerint(string nev)
        {
            List<Telepules> szurt = new List<Telepules>();
            foreach (Telepules t in Telepulesek)
            {
                if (t.TelepulesNev == nev)
                {
                    szurt.Add(t);
                }
            }
            return szurt;
        }

        public List<Telepules> SzuresIrszszerint(int irsz)
        {
            List<Telepules> szurt = new List<Telepules>();
            foreach (Telepules t in Telepulesek)
            {
                if (t.Irszam == irsz)
                {
                    szurt.Add(t);
                }
            }
            return szurt;
        }

    }
}
