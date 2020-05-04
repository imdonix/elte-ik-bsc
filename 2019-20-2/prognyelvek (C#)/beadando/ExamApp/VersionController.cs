using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ExamApp.Models;
using System.Windows.Forms;
using Version = ExamApp.Models.Version;

namespace ExamApp
{
    public class VersionController
    {
        const string CLIENT_VERSION = "1.0";
        const string API_VERSION = "1.0";

        private Version LocalVersion = new Version(API_VERSION, CLIENT_VERSION);
        private Version OnlineVersion;

        public Version GetLocalVersion() { return LocalVersion; }
        public void SetOnlineVersion(Version v) { OnlineVersion = v; }

        public DialogResult CheckVersion() 
        {
            if (!LocalVersion.Equals(OnlineVersion))
                return MessageBox.Show("Új verzió elérhető le szeretnéd tölteni?", "Frissítés", MessageBoxButtons.YesNo, MessageBoxIcon.Information);
            return DialogResult.No;
        }


    }
}
