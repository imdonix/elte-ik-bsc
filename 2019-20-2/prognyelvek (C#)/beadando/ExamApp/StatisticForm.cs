using ExamApp.Models;
using ExamApp.Web;
using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ExamApp
{
    public partial class StatisticForm : Form
    {
        private Exam exam;
        private Question[] examquestions;
        private User me;
        private Resoult[] newresults;
        private Resoult myresoult;
        private Localizator localizator;

        public StatisticForm(Localizator localizator, Exam exam, User me)
        {
            InitializeComponent();
            this.exam = exam;
            this.me = me;
            this.examquestions = exam.GetQuestions();
            this.localizator = localizator;
        }

        private void StatisticForm_Load(object sender, EventArgs e)
        {
            localizator.AddControls(this);
            localizator.Update();

            WebRequest.GetCollection("resoults", (res) =>
            {
                if (res.IsSucces())
                {
                    newresults = JsonConvert.DeserializeObject<Resoult[]>(res.ToString());
                    LoadUp();
                }
                else
                {
                    MessageBox.Show("Cant load result!", "Result Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    Close();
                }
            });

        }

        private void StatisticForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            localizator.RemoveControls(this);
        }

        private void LoadUp()
        {
            newresults = Array.FindAll<Resoult>(newresults, u => u.Exam == exam.Id);
            myresoult = Array.Find<Resoult>(newresults, u => u.User == me.Id);

            try
            {
                WriteText();
                WriteChart();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                throw;
            }


        }

        private void WriteText()
        {

            int max = GetMax();
            int curr = GetRes(myresoult);
            float prec = ((float)curr) / max * 100;

            ResultLabel.Text = $"{max}/{curr} | {prec:F2}%";
        }

        private void WriteChart()
        {
            int max = GetMax();
            int[] points = newresults.Select(u => GetRes(u)).ToArray();
            Array.Sort(points);

            int selection = max / (10 + (int)Math.Log10(max));
            if (selection < 1)
                selection++;

            int i = 1;
            int c = 0;
            foreach (int point in points)
                if (point <= i * selection)
                    c++;
                else
                {
                    Chart.Series["Points"].Points.AddXY(i * selection, c);
                    c = 0;
                    while (point > i * selection)
                        Chart.Series["Points"].Points.AddXY(i++ * selection, c);
                    c++;
                }
            Chart.Series["Points"].Points.AddXY(i * selection, c);

        }


        private int GetMax()
        {
            int max = 0;
            for (int i = 0; i < examquestions.Length; i++)
                max += examquestions[i].Point;
            return max;
        }

        private int GetRes(Resoult res)
        {
            int curr = 0;
            for (int i = 0; i < examquestions.Length; i++)
                if (res.Answers[i] == 0)
                    curr += examquestions[i].Point;
            return curr;
        }

    }
}
