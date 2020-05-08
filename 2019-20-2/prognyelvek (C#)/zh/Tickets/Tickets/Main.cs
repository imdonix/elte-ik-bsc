using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml;

namespace Tickets
{
    public partial class Main : Form
    {
        TickModel model;


        public Main()
        {
            InitializeComponent();
            model = new TickModel();
        }

        private void Main_Load(object sender, EventArgs e)
        {
            ListModifier.UpdateList(OpenedTickesList,ActiveTicketLabel, model.BekuldottTicketek.ToArray());
        }

        private void newToolStripMenuItem_Click(object sender, EventArgs e)
        {
            AddNewTicketFrom addNewTicketFrom = new AddNewTicketFrom(model);
            if (addNewTicketFrom.ShowDialog() == DialogResult.OK)
            {     
                model.BekuldottTicketek.Add(addNewTicketFrom.GetTicket());
                model.SaveChanges();
            }

        }

        private void CloseButton_Click(object sender, EventArgs e)
        {
            BekuldottTicketek found = model.BekuldottTicketek.Find(((BekuldottTicketek)OpenedTickesList.SelectedItem).Id);
            if (found != null)
            {
                found.Statusz = (int) BekuldottTicketek.Status.Ended;
                model.SaveChanges();
                ListModifier.UpdateList(OpenedTickesList, ActiveTicketLabel, model.BekuldottTicketek.ToArray());
            }

        }

        private void ArchiveButton_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show("Biztosan szeretnéd kitörölni?", "Warning", MessageBoxButtons.YesNo) != DialogResult.Yes)
                return;

            if (xmlDialog.ShowDialog() == DialogResult.OK)
            {
                using (XmlWriter writer = XmlWriter.Create(xmlDialog.FileName))
                {
                    writer.WriteStartDocument();
                    writer.WriteStartElement("Tickets");

                    foreach (var item in model.BekuldottTicketek)
                        if (item.Statusz == (int)BekuldottTicketek.Status.Ended)
                        {

                            writer.WriteStartElement("Ticket");
                            writer.WriteElementString("Uzenet", item.Uzenet);
                            writer.WriteElementString("BejelentoId", item.BejelentoId.ToString());
                            writer.WriteElementString("Datum", item.Datum.ToString());
                            writer.WriteEndElement();
                            item.Statusz = (int)BekuldottTicketek.Status.Archive;
                        }

                    writer.WriteEndElement();
                    writer.WriteEndDocument();
                }
                model.SaveChanges();
            }
        }

        private void StatisticButton_Click(object sender, EventArgs e)
        {
            int i = 1;
            foreach (var item in model.Bejelento)
            {
                Label nameLabel = new Label();
                Label timesLabel = new Label();
                Controls.Add(nameLabel); Controls.Add(timesLabel);
                
                nameLabel.AutoSize = true;
                nameLabel.Location = new System.Drawing.Point(NameLabel.Location.X, NameLabel.Location.Y + (i*30));
                nameLabel.Name = "NameLabel" + i;
                nameLabel.Size = new System.Drawing.Size(27, 13);
                nameLabel.TabIndex = 10+i;
                nameLabel.Text = item.Nev;

                timesLabel.AutoSize = true;
                timesLabel.Location = new System.Drawing.Point(TimesLabel.Location.X, TimesLabel.Location.Y + (i*30));
                timesLabel.Name = "TimesLabel" + i;
                timesLabel.Size = new System.Drawing.Size(44, 13);
                timesLabel.TabIndex = 10+i;
                timesLabel.Text = model.BekuldottTicketek.Count(u => u.BejelentoId == item.Id).ToString();

                i++;
            }
        }

        private void AllDataList_MouseEnter(object sender, EventArgs e)
        {
            AllDataList.Items.Clear();
            var data = from x in model.BekuldottTicketek orderby x.Datum select x;
            foreach (var item in data)
                AllDataList.Items.Add(item);
        }
    }
}
