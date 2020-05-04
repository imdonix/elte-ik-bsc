using CSVReader;
using ExamApp.Models;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Security.Cryptography.Xml;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ExamApp
{
    public struct IdentifiedControl
    {
        public IdentifiedControl(Control control)
        {
            this.control = control;
            identify = control.Text;
        }

        public Control control;
        public string identify;
    }

    public class Localizator
    {
        private List<Word> database;
        private Word langsList;
        private string current;
        private List<IdentifiedControl> controls;

        public Localizator(Form form, string lang) 
        {
            controls = new List<IdentifiedControl>();
            database = GetDatabase("localization.csv");
            langsList = database.First();
            database.RemoveAt(0);
            current = lang;
            AddControls(form);
        }

        public void AddControls(Control parent)
        {
            controls.Add(new IdentifiedControl(parent));
            foreach (Control child in parent.Controls)
            {
                AddControls(child);
                controls.Add(new IdentifiedControl(child));
            }
        }

        public void RemoveControls(Control parent)
        {
            controls.Remove(controls.Find(u => u.control == parent));
            foreach (Control child in parent.Controls)
            {
                AddControls(child);
                controls.Remove(controls.Find(u => u.control == child));
            }
        }

        public void ChangeLanguage(string lan)
        {
            current = lan;
            Update();
        }

        public void Update()
        {
            foreach (IdentifiedControl ic in controls)
            {
                int c = database.Count;
                Word w = database.Find(u => ic.identify.Contains(u.identify));
                if (w != null)
                    ic.control.Text = ic.identify.Replace(w.identify, GetLanguageWord(w));
            }
        }

        private string GetLanguageWord(Word w)
        {
            return w.langs[FindIndexOfLang()];
        }

        private int FindIndexOfLang()
        {
            for (int i = 0; i < langsList.langs.Length; i++)
                if (langsList.langs[i].Equals(current))
                    return i;
            return -1;
        }

        private static List<Word> GetDatabase(string src)
        {
            var a = Reader.ReadFile(src);
            return Reader.ReadFile(src).Select(s => new Word(s)).ToList();
        }

    }
}
