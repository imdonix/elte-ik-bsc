using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApp36
{
    class ABRajzolo
    {
        Graphics graf;
        Model2 m;

        public ABRajzolo(Graphics g)
        {
            graf = g;
            m = new Model2();
        }
        public void Kirajzol()
        {
            int darab = m.AdasVetelek.Count();
            // 700*700
            int counter = 0;
            Brush b = Brushes.Red;
            foreach (adasvetel av in m.AdasVetelek)
            {
                graf.FillRectangle(b, (700 / darab) * counter, 300, 30, av.darabszam);
                Font f = new Font(FontFamily.GenericSansSerif, 22);
                graf.DrawString(av.darabszam.ToString(), f, Brushes.Blue, (700 / darab) * counter, 250);
                counter++;
            }

        }
    }
}
