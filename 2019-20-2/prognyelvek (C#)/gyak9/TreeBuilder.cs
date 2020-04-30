using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Kepnezegeto2
{
    static class TreeBuilder
    {

        public static Dictionary<int, Fajl> fajlok = new Dictionary<int, Fajl>();
        static int fileCounter = 0;

        public static TreeNode FillTreeNodes(string rootfolder)
        {
            DirectoryInfo di = new DirectoryInfo(rootfolder);

            TreeNode node = new TreeNode();
            node.Text = di.Name;
            Mappa m = new Mappa();
            m.di = di;
            node.Tag = m;

            GetFolderData(rootfolder, node);

            return node;
        }

        private static void GetFolderData(string folderName, TreeNode parentNode)
        {
            DirectoryInfo di = new DirectoryInfo(folderName);
            TreeNode newParent = new TreeNode();
            newParent.Text = di.Name;
            Mappa m = new Mappa();
            m.di = di;
            newParent.Tag = m;

            foreach (FileInfo fi in di.GetFiles())
            {
                if (fi.Extension == ".jpg")
                {
                    TreeNode fileNode = new TreeNode();
                    fileNode.Text = fi.Name;
                    Fajl f = new Fajl();
                    f.fi = fi;
                    f.Sorszam = fileCounter;
                    fileNode.Tag = f;
                    newParent.Nodes.Add(fileNode);
                    fajlok.Add(fileCounter, f);
                    fileCounter++;
                }                
            }


            foreach (DirectoryInfo dir in di.GetDirectories())
            {
                GetFolderData(dir.FullName, newParent);
            }
            parentNode.Nodes.Add(newParent);
        }

    }
}
