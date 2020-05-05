using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Forms.DataVisualization.Charting;

namespace MintaZH
{
    public partial class Form2 : Form
    {

        public Form2(Dictionary<string, int> stat)
        {
            InitializeComponent();

            chart1.Series.Clear();
            Series series = new Series("Vasarlas");
            chart1.Series.Add(series);

            foreach (KeyValuePair<string, int> elem in stat)
            {
                chart1.Series["Vasarlas"].Points.AddXY(elem.Key, elem.Value);
            }
        }

        private void Form2_Load(object sender, EventArgs e)
        {

        }
    }
}
