using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml.Serialization;

namespace MintaZH
{
    public partial class Form1 : Form
    {
        AlatModel am;
        Vasarlasok vk;
        
        public Form1()
        {
            InitializeComponent();
            am = new AlatModel();

            foreach (Aru aru in am.Aru)
            {
                comboBox1.Items.Add(aru);
                comboBox1.DisplayMember = nameof(Aru.Megnevezes);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();

            foreach (Aru a in am.Aru)
            {
                if (a.Egysegar < int.Parse(textBox1.Text))
                {
                    listBox1.Items.Add(a.Megnevezes);
                }
            }
        }

        private void comboBox1_SelectedValueChanged(object sender, EventArgs e)
        {
            listBox2.Items.Clear();
            vk = new Vasarlasok();

            Aru mitkeresek = (Aru)comboBox1.SelectedItem;

            int osszeg = 0;

            foreach (Vasarlas vasarlas in am.Vasarlas)
            {
                if (vasarlas.TermekId == mitkeresek.Id)
                {
                    EgyVasarlas v = new EgyVasarlas();
                    v.Datum = vasarlas.Datum;
                    v.Mennyiseg = vasarlas.Mennyiseg;
                    v.TermekID = vasarlas.TermekId;
                    v.UgyfelID = vasarlas.UgyfelId;

                    string vevoNeve = string.Empty;
                    foreach (Vevo vevo in am.Vevo)
                    {
                        if (vevo.Id == v.UgyfelID)
                        {
                            vevoNeve = vevo.Nev;
                        }
                    }

                    osszeg += v.Mennyiseg * mitkeresek.Egysegar;
                    vk.SokVasarlas.Add(v);
                    listBox2.Items.Add($"{vevoNeve} - {v.Datum }  - {v.Mennyiseg}");
                }
            }

            label2.Text = osszeg.ToString();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (vk != null)
            {
                string filenev = "mentes.xml";
                XmlSerializer xs = new XmlSerializer(typeof(Vasarlasok));
                StreamWriter sw = new StreamWriter(filenev);
                xs.Serialize(sw, vk);
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Dictionary<string, int> statisztika = new Dictionary<string, int>();

            foreach (Vasarlas v in am.Vasarlas)
            {
                foreach (Aru a in am.Aru)
                {
                    if (v.TermekId == a.Id)
                    {
                        if (statisztika.ContainsKey(a.Megnevezes))
                        {
                            statisztika[a.Megnevezes] += v.Mennyiseg;
                        }
                        else
                        {
                            statisztika.Add(a.Megnevezes, v.Mennyiseg);
                        }
                    }
                }
            }

            Form2 frm = new Form2(statisztika);
            frm.ShowDialog();
        }
    }
}
