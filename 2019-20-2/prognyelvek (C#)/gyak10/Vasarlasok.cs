using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MintaZH
{
    public class Vasarlasok
    {
        public List<EgyVasarlas> SokVasarlas { get; set; }

        public Vasarlasok()
        {
            SokVasarlas = new List<EgyVasarlas>();
        }
    }
}
