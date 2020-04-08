using System;
using System.Collections.Generic;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Windows.Forms;
using System.Windows.Forms.DataVisualization.Charting;

namespace WindowsFormsApp36
{
    public partial class Form1 : Form
    {
        Model2 adatok;
        public Form1()
        {
            InitializeComponent();
            adatok = new Model2();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //var bevetelek = from x in adatok.adasvetel
            //                select x.ar * x.darabszam;

            //var bevetelek2 = from x in adatok.adasvetel
            //                 orderby x.idopont
            //                 select new { x.vetel, x.ar, x.darabszam };

            //var bevetelek3 = from x in adatok.adasvetel
            //                 orderby x.idopont
            //                 select new { x.vetel, Ertek = x.darabszam * x.ar };

            var bevetelek4 = from x in adatok.AdasVetelek
                             orderby x.idopont
                             let Ertek = x.darabszam * x.ar
                             select new { x.vetel, Ertek };

            //listBox1.Items.Add(bevetelek.GetType());
            //foreach (var item in bevetelek)
            //{
            //    listBox1.Items.Add(item);
            //}

            //listBox1.Items.Add(bevetelek2.GetType());
            //foreach (var item in bevetelek2)
            //{
            //    listBox1.Items.Add(item);
            //}

            //listBox1.Items.Add(bevetelek3.GetType());
            //foreach (var item in bevetelek3)
            //{
            //    listBox1.Items.Add(item.vetel ? item.Ertek : -1 * item.Ertek);
            //}

            // listBox1.Items.Add(bevetelek4.GetType());
            foreach (var item in bevetelek4)
            {
                listBox1.Items.Add(item.vetel ? item.Ertek : -1 * item.Ertek);
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            var bevetelek4 = from x in adatok.AdasVetelek
                             orderby x.idopont
                             let Ertek = x.darabszam * x.ar
                             select new { x.vetel, Ertek };

            // chart1.Series[0].Points.Clear();
            foreach (var item in bevetelek4)
            {
                chart1.Series[0].Points.AddY(item.vetel ? item.Ertek : -1 * item.Ertek);
            }

        }

        private void button3_Click(object sender, EventArgs e)
        {
            chart2.Series.Clear();
            chart2.ChartAreas.Clear(); // -> ha nem töröljük, második jön létre!
            ChartArea ca = new ChartArea("Adataim");            
            chart2.ChartAreas.Add(ca);
            Series s1 = new Series();
            s1.ChartType = SeriesChartType.Line;
            s1.IsValueShownAsLabel = true;
            s1.LegendText = "Adásvételek";
            chart2.Series.Add(s1);
            foreach (adasvetel av in adatok.AdasVetelek)
            {
                s1.Points.AddY(av.vetel ? av.ar*av.darabszam : -1 *av.ar*av.darabszam);
               // s1.Points.AddXY(av.vetel ? av.ar*av.darabszam : -1 *av.ar*av.darabszam, av.idopont);                
            }
            s1.ChartArea = "Adataim";

        }

        private void button4_Click(object sender, EventArgs e)
        {
            Graphics g = pictureBox1.CreateGraphics();
            Pen p = new Pen(Color.Red);
            g.DrawLine(p, 10, 10, 20, 20);
        }

        private void button5_Click(object sender, EventArgs e)
        {
            // e helyett Paint-re kell feliratkozni!
            //Graphics g = pictureBox1.CreateGraphics();
            //SinRajzolo sr = new SinRajzolo(g);
            //sr.Kirajzol();
        }

        private void pictureBox1_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            SinRajzolo sr = new SinRajzolo(g);
            sr.Kirajzol();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            Graphics g = pictureBox1.CreateGraphics();
            ABRajzolo ab = new ABRajzolo(g);
            ab.Kirajzol();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            foreach (SeriesChartType item in Enum.GetValues(typeof(SeriesChartType)))
            {
                comboBox1.Items.Add(item);
            }
            
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            chart2.Series[0].ChartType = (SeriesChartType)comboBox1.SelectedItem;
        }
    }
}

