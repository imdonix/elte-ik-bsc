using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Irszamos
{
    public partial class Form1 : Form
    {
        TelepulesKezelo tpkez;
        public Form1()
        {
            InitializeComponent();
            tpkez = new TelepulesKezelo();
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenFileDialog dlg = new OpenFileDialog();
            if (dlg.ShowDialog() == DialogResult.OK)
            {
                tpkez.AdatBetoltes(dlg.FileName);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (rbIrszam.Checked)
            {
                int irsz;
                if (int.TryParse(comboBox1.Text, out irsz) == false)
                {
                    MessageBox.Show("Nem számot kaptam!");
                    return;
                }

                List<Telepules> eredmeny = new List<Telepules>();
                eredmeny = tpkez.SzuresIrszszerint(irsz);
                listBox1.DataSource = eredmeny;
                listBox1.DisplayMember = nameof(Telepules.TelepulesNev);
            }
            else if (rbTelepules.Checked)
            {
                listBox1.DataSource = tpkez.SzuresNevSzerint(comboBox1.Text);
                listBox1.DisplayMember = nameof(Telepules.Irszam);
            }
            else
            {// megye
                listBox1.DataSource = tpkez.SzuresMegyeSzerint(comboBox1.Text);
            }
        }

        private void rbIrszam_CheckedChanged(object sender, EventArgs e)
        {
            comboBox1.DataSource = null;
            if (rbIrszam.Checked)
            {
                comboBox1.DataSource = tpkez.Telepulesek;
                comboBox1.DisplayMember = nameof(Telepules.Irszam);
            }
        }

        private void rbMegye_CheckedChanged(object sender, EventArgs e)
        {
            comboBox1.DataSource = null;
            if (rbMegye.Checked)
            {
                comboBox1.DataSource = tpkez.Telepulesek;
                comboBox1.DisplayMember = nameof(Telepules.Megye);
            }
        }

        private void rbTelepules_CheckedChanged(object sender, EventArgs e)
        {
            comboBox1.DataSource = null;
            if (rbTelepules.Checked)
            {
                comboBox1.DataSource = tpkez.Telepulesek;
                comboBox1.DisplayMember = nameof(Telepules.TelepulesNev);
            }
        }
    }
}
