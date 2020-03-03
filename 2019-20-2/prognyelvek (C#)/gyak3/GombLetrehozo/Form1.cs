using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GombLetrehozo
{
    public partial class Form1 : Form
    {
        int gameovercounter = 0;
        int pontszam = 0;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_MouseClick(object sender, MouseEventArgs e)
        {

        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            Random rnd = new Random();
            Button button = new Button();

            button.Location = new Point(rnd.Next(750), rnd.Next(550));
            button.Size = new System.Drawing.Size(50, 50);
            button.Click += Button_Click;
            button.TabStop = false;

            this.Controls.Add(button);
            gameovercounter++;
            lblpont.Text = pontszam.ToString();

            if (gameovercounter > 10)
            {
                timer1.Enabled = false;
                MessageBox.Show("game over");
            }
        }

        private void Button_Click(object sender, EventArgs e)
        {
            pontszam++;
            gameovercounter--;
            this.Controls.Remove((Button)sender);
        }
    }
}
