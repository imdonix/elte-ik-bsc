using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Tickets
{
    public partial class AddNewTicketFrom : Form
    {
        private TickModel model;
        private BekuldottTicketek current;

        public AddNewTicketFrom(TickModel model)
        {
            InitializeComponent();
            this.model = model;
        }

        private void AddNewTicketFrom_Load(object sender, EventArgs e)
        {
            foreach (var item in model.Bejelento)
                PeopleComboBox.Items.Add(item);
        }

        private void AddNewBtn_Click(object sender, EventArgs e)
        {
            Bejelento bejelento = (Bejelento) PeopleComboBox.SelectedItem;
            current = new BekuldottTicketek(bejelento.Id, DateTime.Now, (int)BekuldottTicketek.Status.New, InputTextBox.Text);
        }

        public BekuldottTicketek GetTicket() { return current; }


    }
}
