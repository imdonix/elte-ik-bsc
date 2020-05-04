using ExamApp.Models;
using ExamApp.QuestionForms;
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

    public struct QuestionPrams
    {
        public Question question;
        public int shuffled;
        public int position;

        public QuestionPrams(Question question, int shuffled, int position)
        {
            this.question = question;
            this.shuffled = shuffled;
            this.position = position;
        }

        public override string ToString()
        {
            return question.Description + " | " + shuffled + " | " + position;
        }
    }

    public partial class QuestionContainer : Form
    {
        private Random random;
        private Exam exam;
        private int timeLeft;
        private QuestionPrams[] questions;
        private Localizator localizator;
        private QuestionForm questionForm;
        private Action<Resoult> callback;

        private int[] answers;


        public QuestionContainer(Localizator localizator, Exam exam, Action<Resoult> callback)
        {
            random = new Random();
            InitializeComponent();

            this.exam = exam;
            this.callback = callback;
            this.localizator = localizator;

            answers = new int[exam.QuestionsIDs.Length];
            answers = answers.Select(u => -1).ToArray();

            InitExam();
            Randomize();
            Timer.Start();
            Next(0);
        }

        private void QuestionContainer_Load(object sender, EventArgs e)
        {
            Top = 0;
            localizator.AddControls(this);
            localizator.Update();
        }

        private void QuestionContainer_FormClosing(object sender, FormClosingEventArgs e)
        {
            localizator.RemoveControls(this);
        }

        private void InitExam()
        {
            Question[] arr = exam.GetQuestions();
            questions = new QuestionPrams[arr.Length]; int i = 0;
            foreach (Question q in arr)
                questions[i] = new QuestionPrams(q, random.Next(0, q.Answers.Length), i++);
            timeLeft = exam.Time * 60;
        }

        private void Randomize()
        {
            if (exam.IsRandomized)
                questions = questions.OrderBy(x => random.Next()).ToArray();
        }

        public void Next(int i)
        {
            if (questionForm != null)
            {
                answers[questionForm.question.position] = questionForm.GetAnswer();
                questionForm.Close();
            }

            if (i < questions.Length)
            {
                QuestNumLabel.Text = $"{questions.Length}/{i + 1}";
                PointWorth.Text = $"{questions[i].question.Point}";
                questionForm = new QuestionForm(this, questions[i], i, random);
                questionForm.Show();
            }
            else
                Finish();
        }

        private void Finish() 
        {
            Timer.Stop();
            callback(new Resoult(exam.Id, answers));
            if(questionForm != null)
                questionForm.Close();
            Close();
        }

        private void Debug()
        {
            foreach (var item in questions)
                MessageBox.Show(item.ToString());
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            timeLeft -= 1;
            if (timeLeft < 60)
            {
                if (timeLeft < 0)
                    Finish();
                TimeLeftLabel.ForeColor = Color.Red;
            }


            TimeLeftLabel.Text = $"{timeLeft/60}:{timeLeft%60}";
        }
    }
}
