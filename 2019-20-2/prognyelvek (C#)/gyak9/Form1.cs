using System;
using System.IO;
using System.Net;
using System.Windows.Forms;
using System.Xml.Serialization;

namespace Kepnezegeto2
{
    public partial class Form1 : Form
    {
        int Aktualis;
        LikeLista likes;

        public Form1()
        {
            InitializeComponent();
            Aktualis = -1;
            LikeListaKezeles();
        }

        private void LikeListaKezeles()
        {
            if (File.Exists("LikeOk.xml"))
            {
                XmlSerializer xs = new XmlSerializer(typeof(LikeLista));
                StreamReader sr = new StreamReader("LikeOk.xml");
                likes = (LikeLista)xs.Deserialize(sr);
            }
            else
            {
                likes = new LikeLista();
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            FolderBrowserDialog fbd = new FolderBrowserDialog();
            fbd.SelectedPath = @"C:\temp\kepek\";
            if (fbd.ShowDialog() == DialogResult.OK)
            {
                treeView1.Nodes.Add(TreeBuilder.FillTreeNodes(fbd.SelectedPath));
            }
        }

        private void treeView1_AfterSelect(object sender, TreeViewEventArgs e)
        {
            Allomany a = (Allomany)e.Node.Tag;
            if (a.GetType() == typeof(Mappa))
            {
                // mit csináljak a mappákkal?
            }
            else
            {
                // itt egy file van kiválasztva
                Aktualis = ((Fajl)a).Sorszam;
                KepekKirajzol(((Fajl)a).Sorszam);
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            string kep = textBox1.Text;
            int index = kep.Length - 1;

            while (kep[index] != '/')
            {
                index--;
            }
            string kepnev = kep.Substring(index + 1);

            WebClient webC = new WebClient();
            webC.DownloadFile(new Uri(kep), @"C:\temp\kepek\Internetrol\" + kepnev);

        }

        private void pbElozo_MouseEnter(object sender, EventArgs e)
        {
            if (Aktualis != -1 && Aktualis > 0)
            {
                Aktualis--;
                KepekKirajzol(Aktualis);
            }
        }

        private void KepekKirajzol(int aktIndex)
        {
            pbAktualis.Load(TreeBuilder.fajlok[aktIndex].fi.FullName);
            pbAktualis.SizeMode = PictureBoxSizeMode.Zoom;

            pbNagy.Load(TreeBuilder.fajlok[aktIndex].fi.FullName);
            pbNagy.SizeMode = PictureBoxSizeMode.Zoom;


            if (TreeBuilder.fajlok.ContainsKey(aktIndex - 1))
            {
                pbElozo.Load(TreeBuilder.fajlok[aktIndex - 1].fi.FullName);
                pbElozo.SizeMode = PictureBoxSizeMode.Zoom;
            }

            if (TreeBuilder.fajlok.ContainsKey(aktIndex + 1))
            {
                pbKovetkezo.Load(TreeBuilder.fajlok[aktIndex + 1].fi.FullName);
                pbKovetkezo.SizeMode = PictureBoxSizeMode.Zoom;
            }

            bool found = false;
            foreach (EgyLike like in likes.Likeok)
            {
                if (like.KepNev == TreeBuilder.fajlok[Aktualis].fi.FullName)
                {
                    found = true;
                    label1.Text = like.Counter.ToString();
                    break;
                }
            }
            if (!found)
            {
                label1.Text = "0";
            }
        }

        private void pbKovetkezo_MouseEnter(object sender, EventArgs e)
        {
            if (Aktualis != -1 && Aktualis < TreeBuilder.fajlok.Count - 1)
            {
                Aktualis++;
                KepekKirajzol(Aktualis);
            }
        }

        private void pbNagy_Click(object sender, EventArgs e)
        {
            bool found = false;
            foreach (EgyLike like in likes.Likeok)
            {
                if (like.KepNev == TreeBuilder.fajlok[Aktualis].fi.FullName)
                {
                    like.Counter++;
                    found = true;
                    label1.Text = like.Counter.ToString();
                    break;
                }
            }
            if (!found)
            {
                EgyLike el = new EgyLike();
                el.KepNev = TreeBuilder.fajlok[Aktualis].fi.FullName;
                el.Counter = 1;
                label1.Text = el.Counter.ToString();
                likes.Likeok.Add(el);
            }
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            XmlSerializer xs = new XmlSerializer(typeof(LikeLista));
            StreamWriter sw = new StreamWriter("LikeOk.xml");
            xs.Serialize(sw, likes);
        }
    }
}
