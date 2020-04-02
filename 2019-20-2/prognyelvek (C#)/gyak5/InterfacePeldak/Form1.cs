using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace InterfacePeldak
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Ember[] emberek = new Ember[3];
            emberek[0] = new Ember("Béla", 1911);
            emberek[1] = new Ember("Anikó", 1991);
            emberek[2] = new Ember("Cecília", 1977);

            Emberek sokember = new Emberek(emberek);


            Array.Sort(sokember.EmberekTomb);

            foreach (Ember eeee in sokember)
            {
                listBox1.Items.Add(eeee);
            }
        }
        
    }
}
