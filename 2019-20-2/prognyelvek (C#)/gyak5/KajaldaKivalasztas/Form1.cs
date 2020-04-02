using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace KajaldaKivalasztas
{
    public partial class Form1 : Form
    {
        KajaModel km;
        public Form1()
        {
            InitializeComponent();
            km = new KajaModel();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();
            listBox1.DisplayMember = nameof(Kajaldak.HelyNeve);
            // listBox1.ValueMember = nameof(Kajaldak.Id);

            foreach (Kajaldak k in km.Kajaldak)
            {
                listBox1.Items.Add(k);
            }
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            bool found = false;
            foreach (Kajaldak k in km.Kajaldak)
            {
                if (k.HelyNeve.StartsWith(textBox1.Text))
                {
                    label2.Text = k.HelyNeve;
                    found = true;
                }
            }
            if (!found)
            {
                label2.Text = string.Empty;
            }
        }

        private void textBox1_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                if (label2.Text != string.Empty)
                {
                    textBox1.Text = label2.Text;
                }
                else
                {
                    if (MessageBox.Show
                        ("Hozzá adjuk?", "Új hely", MessageBoxButtons.YesNo) == 
                        DialogResult.Yes)
                    {
                        int counter = 0;
                        foreach (Kajaldak kk in km.Kajaldak)
                        {
                            counter++;
                        }

                        Kajaldak k = new Kajaldak();
                        k.HelyNeve = textBox1.Text;
                        k.Id = ++counter;

                        km.Kajaldak.Add(k);
                        km.SaveChanges();
                    }
                }
            }
        }
    }
}
