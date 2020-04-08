using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApp36
{
    class SinRajzolo
    {
        Graphics graf;
        public SinRajzolo(Graphics g)
        {
            graf = g;
        }

        public void Kirajzol()
        {
            Pen p = new Pen(Color.Green);

            for (float i = 0; i < 12; i += (float)0.005)
            {
                float x = i * 100;
                float y = 100 + (float)(Math.Sin(i) * 100);                
                graf.DrawRectangle(p, x, y, 1, 1);
            }

        }
    }
}
