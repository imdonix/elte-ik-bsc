using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StaticInstance
{
    class Hibajegy
    {
        //public DateTime Mikor
        //{
        //    get; set;
        //}

        public static int Counter
        {
            get; set;
        }

        DateTime mikor;

        public string HibaLeiras
        {
            get; set;
        }

        static Hibajegy()
        {
            // tegnapról van 10 hibánk
            Counter = 10;
        }

        public Hibajegy()
        {
            //// tegnapról van 10 hibánk
            //Counter = 10;
            Counter++;
        }

        public Hibajegy(string leiras)
        {
            //// tegnapról van 10 hibánk
            //Counter = 10;
            HibaLeiras = leiras;
            mikor = DateTime.Now;
            Counter++;
        }
    }
}
