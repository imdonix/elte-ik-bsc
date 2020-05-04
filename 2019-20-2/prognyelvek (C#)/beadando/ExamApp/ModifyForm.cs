using CSVReader;
using ExamApp.Models;
using ExamApp.Web;
using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ExamApp
{
    public partial class ModifyForm : Form
    {

        Exam[] exams;
        Question[] questions;
        List<Button> buttons;
        int selected = -1;

        public ModifyForm()
        {
            InitializeComponent();
            buttons = new List<Button>();
            buttons.Add(ExportButton); buttons.Add(ImportButton); buttons.Add(DeleteButton);
        }

        #region FORM_CONTROL

        private void ModifyForm_Load(object sender, EventArgs e)
        {
            Reload();
        }

        private void ExamsList_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (ExamsList.SelectedItems.Count == 1)
                selected = ExamsList.SelectedItems[0].Index;
        }

        private void ExportButton_Click(object sender, EventArgs e)
        {
            Exam exam = getSelectedItem();
            if (exam == null)
                return;
            Writer.WriteFile("exported.csv", exam.GetData());
            MessageBox.Show("Az exportálás sikeres volt! (exported.csv)", "Export", MessageBoxButtons.OK, MessageBoxIcon.Information);
            Process.Start("exported.csv");
        }

        private void DeleteButton_Click(object sender, EventArgs e)
        {
            Exam exam = getSelectedItem();
            if (exam == null)
                return;

            if (MessageBox.Show("Biztosan ki szeretnéd törötlni a vizsgát? " + exam.Title, "Törlés", MessageBoxButtons.YesNo, MessageBoxIcon.Warning) != DialogResult.Yes)
                return;

            DeleteButton.Enabled = false;
            WebRequest.DeleteExam(exam.Id, (res) =>
            {
                MessageBox.Show(res.ToString(), "Delte", MessageBoxButtons.OK, MessageBoxIcon.Information);
                Reload();
            });
        }

        private void ImportButton_Click(object sender, EventArgs e)
        {
            if (inputFileDialog.ShowDialog() == DialogResult.OK)
            {
                ImportButton.Enabled = false;
                List<string> lines = Reader.ReadFile(inputFileDialog.FileName);
                List<Question> questions = new List<Question>();

                UploadExam exam = new UploadExam(lines[0]); lines.RemoveAt(0);
                foreach (string line in lines)
                    questions.Add(new Question(line));
                exam.Questions = questions.ToArray();
                WebRequest.UploadExam(exam, (res) =>
                {
                    if (res.IsSucces())
                        Reload();
                    else
                        MessageBox.Show("Hiba történt vizsga feltöltés közben!", "Error", MessageBoxButtons.OK,MessageBoxIcon.Error);
                    ImportButton.Enabled = true;
                });           
            }
        }

        #endregion

        #region PRIVATE_METHODS

        void Reload()
        {
            UseWaitCursor = true;
            buttons.ForEach(u => u.Enabled = false);
            LoadResource<Exam>("exams", arr =>
            {
                exams = arr;
                UpdateList();
                LoadResource<Question>("questions", arr2 =>
                {
                    questions = arr2;
                    foreach (Exam item in exams)
                        item.FillQuestions(questions);
                    UseWaitCursor = false;
                    buttons.ForEach(u => u.Enabled = true);
                });
            });

        }

        private void UpdateList()
        {
            ExamsList.Items.Clear();
            foreach (Exam item in exams)
                ExamsList.Items.Add(new ListViewItem(item.ToArray()));
        }

        private Exam getSelectedItem()
        {
            if (selected >= 0)
                return exams[selected];
            return null;
        }

        private void LoadResource<T>(string collection, Action<T[]> callback)
        {
            WebRequest.GetCollection(collection, (res) =>
            {
                try
                {
                    if (!res.IsSucces()) throw new Exception("The requested collection is not aviable!");
                    callback(JsonConvert.DeserializeObject<T[]>(res.ToString()));
                }
                catch (Exception ex)
                { MessageBox.Show(ex.Message, typeof(T) + " collection error", MessageBoxButtons.OK, MessageBoxIcon.Error); }
            });
        }

        #endregion


    }
}
