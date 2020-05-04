using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using CSVReader;
using ExamApp.Models;
using ExamApp.Web;
using Newtonsoft.Json;
using Version = ExamApp.Models.Version;

namespace ExamApp
{
    public partial class MainForm : Form
    {

        public enum FormState
        {
            Check,
            Login,
            ExamLoading,
            QuestionLoading,
            ResoultsLoding,
            LoggedIn
        }


        public User User { get; private set; }
        public string LoginKey { get; private set; }
        public FormState State { get; private set; }
        public VersionController VersionController { get; private set; }
        public Localizator Localizator { get; private set; }

        public Exam[] Exams { get; private set; }
        public Question[] Questions { get; private set; }
        public Resoult[] Resoults { get; private set; }

        private List<Button> examButtons;
        private List<Button> moderatorButtons;

        public MainForm()
        {
            InitializeComponent();
            VersionController = new VersionController();
            InitLocalizator();

            examButtons = new List<Button>(); moderatorButtons = new List<Button>();
            examButtons.Add(ExamStartButton); examButtons.Add(ExamStatisticButton);
            moderatorButtons.Add(ExamNewButton); moderatorButtons.Add(AddNewUsersButton);
        }

        #region FORM_EVENTS

        private void Form1_Load(object sender, EventArgs e)
        {
            setState(FormState.Check);
            Localizator.ChangeLanguage("hun");
        }

        private void LoginButton_Click(object sender, EventArgs e)
        {
            LoginFrom result = new LoginFrom(Localizator);
            if (DialogResult.OK == result.ShowDialog())
                setUser(result.GetResponse());
        }

        private void ExamListView_SelectedIndexChanged(object sender, EventArgs e)
        {
            int index = ExamListView.SelectedIndex;
            if (index >= 0) 
            {
                Exam ex = Exams[ExamListView.SelectedIndex];
                bool isTaken = FindResult(ex) != null;
                ExamStartButton.Enabled = !isTaken;
                ExamStatisticButton.Enabled = isTaken;
                ShowDetails(Exams[ExamListView.SelectedIndex]);
            }
        }

        private void AddNewUsersButton_Click(object sender, EventArgs e)
        {
            if (newUserFileDialog.ShowDialog() != DialogResult.OK)
                return;

            UploadNewUsers();
            newUserFileDialog.Reset();
        }

        private void HunPB_Click(object sender, EventArgs e)
        {
            Localizator.ChangeLanguage("hun");
        }

        private void EngPB_Click(object sender, EventArgs e)
        {
            Localizator.ChangeLanguage("eng");
        }
         
        private void ExamStartButton_Click(object sender, EventArgs e)
        {
            QuestionContainer qc = new QuestionContainer(Localizator ,Exams[ExamListView.SelectedIndex], ExamFinished);
            Hide();
            qc.Show();
        }

        private void ExamStatisticButton_Click(object sender, EventArgs e)
        {
            OpenExamResult(Exams[ExamListView.SelectedIndex]);
        }

        #endregion

        #region PRIVATE_METHODS

        private void InitLocalizator()
        {
            try { Localizator = new Localizator(this, "hun"); }
            catch (FileNotFoundException e)
            {
                MessageBox.Show("A " + e.Message + " fájl nem található a könyvtárban!",
                    "Localization", MessageBoxButtons.OK, MessageBoxIcon.Error);
                Close();
            }
            catch (Exception)
            {
                MessageBox.Show("Hiba a localziációs fájl betöltésekor", "Localization",
                    MessageBoxButtons.OK, MessageBoxIcon.Error);
                Close();
            }

        }

        private void setState(FormState state)
        {
            switch (state)
            {
                case FormState.Check:
                    CheckServer();
                    break;
                case FormState.Login:
                    LoginButton.Enabled = true;
                    break;
                case FormState.ExamLoading:
                    LoadResource<Exam>("exams", FormState.QuestionLoading, arr =>
                    {
                        Exams = arr;
                        ExamListView.Items.Clear();
                        ShowExams();
                    });
                    LoginButton.Hide();
                    break;
                case FormState.QuestionLoading:
                    LoadResource<Question>("questions", FormState.ResoultsLoding, arr =>
                    {
                        Questions = arr;
                        FillExamsWithQuestions();
                        Exam[] e = Exams;
                        ExamStartButton.Enabled = true;
                    });
                    ExamStartButton.Show();
                    ExamStartButton.Enabled = false;
                    break;
                case FormState.ResoultsLoding:
                    LoadResource<Resoult>("resoults", FormState.LoggedIn, arr => 
                    {
                        Resoults = arr;
                        if (ExamListView.Items.Count > 0)
                            ExamListView.SelectedIndex = 0;
                        else
                            ExamStartButton.Enabled = ExamStatisticButton.Enabled = false;
                    });
                    break;
                case FormState.LoggedIn:
                    examButtons.ForEach(u => u.Show());
                    break;
            }

        }

        private void CheckServer()
        {
            LoginButton.Enabled = false;
            AddNewUsersButton.Visible = false;
            examButtons.ForEach(u => u.Hide());
            WebRequest.Check((res) =>
            {
                ServerLabel.Text = WebRequest.GetDomain();
                ServerLabel.ForeColor = res.IsSucces() ? Color.Black : Color.Red;
                if (res.IsSucces()) 
                {
                    VersionLabel.Text = "v" + VersionController.GetLocalVersion().Client;
                    VersionController.SetOnlineVersion(JsonConvert.DeserializeObject<Version>(res.ToString()));
                    if (VersionController.CheckVersion() == DialogResult.Yes)
                        Process.Start(WebRequest.GetDownloadString()); 
                    setState(FormState.Login);
                }
                else
                {
                    MessageBox.Show("The exam server is currently unaviable! Check your internet status, and try again!", "Server is offline", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    Close();
                }
            });
        }

        private void LoadResource<T>(string collection, FormState nextState, Action<T[]> callback)
        {
            WebRequest.GetCollection(collection, (res) =>
            {
                try
                {
                    if (!res.IsSucces()) throw new Exception("The requested collection is not aviable!");
                    //MessageBox.Show("Test"); //SHOW
                    callback(JsonConvert.DeserializeObject<T[]>(res.ToString()));
                    setState(nextState);
                }
                catch (Exception ex)
                { MessageBox.Show(ex.Message, typeof(T) + " collection error", MessageBoxButtons.OK, MessageBoxIcon.Error); }
            });
        }

        private void setUser(LoginResponse lr)
        {
            User = lr.User;
            LoginKey = lr.Key;
            NameLabel.Text = User.Name + " [ " + User.Neptun.ToUpper() + " ]";
            moderatorButtons.ForEach(b => b.Visible = User.isModerator());
            setState(FormState.ExamLoading);
        }

        private void ShowExams()
        {
            foreach (Exam exam in Exams)
                ExamListView.Items.Add(exam.Title);
        }

        private void ShowDetails(Exam exam)
        {
            DetTitleLabel.Text = exam.Title;
            DetDescriptionLabel.Text = exam.Description;
            DetIsRandomLabel.Text = exam.IsRandomized ? "Igen" : "Nem";
            DetTimeLabel.Text = exam.Time.ToString() + " perc";
            DetQuestNumLabel.Text = exam.QuestionsIDs.Length.ToString();
            DetResoultLabel.Text = CreateResoultDeatail(exam);
        }

        private string CreateResoultDeatail(Exam exam)
        {
            return (FindResult(exam) != null ? "Van" : "Nincs");
        }

        private void UploadNewUsers()
        {
            AddNewUsersButton.Enabled = false;
            List<string> fileData = Reader.ReadFile(newUserFileDialog.FileName);
            User[] newUsers = new User[fileData.Count];
            int i = 0;
            foreach (string line in fileData)
                newUsers[i++] = new User(line);

            WebRequest.UploadNewUsers(newUsers, u =>
            {
                AddNewUsersButton.Enabled = true;
                MessageBox.Show(u.ToString(), "User upload", MessageBoxButtons.OK, MessageBoxIcon.Information);
            });
        }

        private void FillExamsWithQuestions()
        {
            foreach (Exam exam in Exams)
                exam.FillQuestions(Questions);
        }

        private void OpenExamResult(Exam exam)
        {
            StatisticForm statisticForm = new StatisticForm(Localizator,exam,User);
            statisticForm.ShowDialog();
        }

        private void ExamFinished(Resoult resoult)
        {
            Show();
            resoult.User = User.Id;
            WebRequest.UploadResoult(resoult, (response) => 
            {
                if (response.IsSucces())
                {
                    AddResLocaly(resoult);
                    Exam element = null;
                    foreach (Exam exam in Exams)
                        if (exam.Id == resoult.Exam)
                            element = exam;
                    OpenExamResult(element);
                    ExamListView_SelectedIndexChanged(this, new EventArgs());
                }
                else
                    MessageBox.Show("Error while uploading the result! Try again!", "Exam error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            });
        }

        private void AddResLocaly(Resoult res)
        {
            Resoult[] temp = new Resoult[Resoults.Length + 1];
            Array.Copy(Resoults, temp, Resoults.Length);
            temp[Resoults.Length] = res;
            Resoults = temp;
        }

        private Resoult FindResult(Exam exam)
        {
            Resoult r = null;
            foreach (var res in Resoults)
                if (res.Exam == exam.Id && res.User == User.Id)
                    r = res;
            return r;
        }

        #endregion

        private void ExamNewButton_Click(object sender, EventArgs e)
        {
            ModifyForm modifyForm = new ModifyForm();
            modifyForm.ShowDialog();
            setState(FormState.ExamLoading);
        }
    }
}
