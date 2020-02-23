using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp41
{
    class MasodfokPeldany
    {
        public int A { get; set; }

        public int B { get; set; }

        public int C { get; set; }

        double d;

        public MasodfokPeldany()
        {

        }
        public MasodfokPeldany(int a, int b, int c)
        {
            A = a;
            B = b;
            C = c;
        }

        public bool GetResult(out double x1, out double x2)
        {
            x1 = 0;
            x2 = 0;
            d = B * B - 4 * A * C;
            if (d < 0)
            {
                return false;
            }
            x1 = (-B + Math.Sqrt(d)) / (2 * A);
            x2 = (-B - Math.Sqrt(d)) / (2 * A);
            return true;
        }
    }
}
