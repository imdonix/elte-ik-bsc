using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Tickets
{
    public static class ListModifier
    {
        public static void UpdateList(ListBox box, Label lab, BekuldottTicketek[] coll)
        {
            int c = 0;
            box.Items.Clear();
            foreach (var item in coll)
                if (item.Statusz == (int)BekuldottTicketek.Status.InProgress || item.Statusz == (int)BekuldottTicketek.Status.New)
                {
                    c++;
                    box.Items.Add(item);
                }
            lab.Text = c.ToString();
        }
    }
}
