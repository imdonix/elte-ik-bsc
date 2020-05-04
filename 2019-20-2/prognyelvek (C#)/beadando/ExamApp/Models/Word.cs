using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExamApp.Models
{
    class Word
    {
        const char DELIMITER = ';';

        public readonly string identify;
        public readonly string[] langs;

        public Word(string inp)
        {
            string[] splitted = inp.Split(DELIMITER);
            langs = new string[splitted.Length-1];
            identify = splitted[0];
            for (int i=1;i<splitted.Length;i++)
                langs[i - 1] = splitted[i];
        }
    }
}
