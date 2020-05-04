using ExamApp.Models;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ExamApp.QuestionForms
{
    public partial class QuestionForm : Form
    {
        public Button[] buttons;
        public QuestionPrams question;

        QuestionContainer QuestionContainer;
        int random;
        int index;
        int answer;

        public QuestionForm(QuestionContainer questionContainer, QuestionPrams questionPrams, int i, Random random)
        {
            InitializeComponent();
            buttons = new Button[4];
            buttons[0] = button1; buttons[1] = button2; buttons[2] = button3; buttons[3] = button4;
            QuestionContainer = questionContainer;
            question = questionPrams;
            index = i;
            this.random = random.Next(0, buttons.Length);
        }

        public void Answer(int ans)
        {
            answer = ans;
            QuestionContainer.Next(++index);
        }

        public int GetAnswer()
        {
            return answer;
        }

        private void QuestionForm_Load(object sender, EventArgs e)
        {
            Question quest = question.question;
            DescriptionLabel.Text = quest.Description;
            if (quest.Type == "select") 
            {
                Title.Text = "Válaszd ki a helyes választ!";
                for (int i = 0; i < quest.Answers.Length; i++)
                {
                    var location = (i + random) % quest.Answers.Length;
                    buttons[i].Text = quest.Answers[location];
                    buttons[i].Click += (o, _) => Answer(location);
                    buttons[i].Show();
                }
            }
            else 
            {
                Title.Text = "Döntsd el az alábbi álításról hogy igaz-e!";
                bool goodans = quest.Answers[0].Equals("true");
                for (int i = 0; i < 2; i++)
                {
                    int j = i;
                    bool val = i % 2 == 0;
                    buttons[i].Text = val ? "Igaz" : "Hamis";
                    buttons[i].Click += (o, _) => Answer( goodans == val ? 0 : 1);
                    buttons[i].Show();
                }
            }


        }
    }
}
