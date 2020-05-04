using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using ExamApp.Models;
using ExamApp.Web;
using Newtonsoft.Json;

namespace ExamApp
{
    public partial class LoginFrom : Form
    {
        private LoginResponse loginResponse;
        private Localizator localizator;

        public LoginFrom(Localizator localizator)
        {
            InitializeComponent();
            DialogResult = DialogResult.Cancel;
            this.localizator = localizator;
        }

        #region FORM_CONTROLL

        private void LoginFrom_Load(object sender, EventArgs e)
        {
            NeptunTextBox.Focus();
            localizator.AddControls(this);
            localizator.Update();
        }

        private void LoginFrom_FormClosing(object sender, FormClosingEventArgs e)
        {
            localizator.RemoveControls(this);
        }

        private void PasswordTextBox_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
                LoginButton.PerformClick();
        }

        private void LoginButton_Click(object sender, EventArgs e)
        {
            if (String.IsNullOrEmpty(NeptunTextBox.Text) || String.IsNullOrEmpty(PasswordTextBox.Text))
            {
                WriteError("Ne hagyj üresen mezőt!");
            }
            else
                StartLogin(NeptunTextBox.Text, PasswordTextBox.Text);

        }

        #endregion

        #region PRIVATE_METHODS

        private void WriteError(string msg)
        {
            InfoLabel.Text = msg;
            InfoLabel.ForeColor = Color.Red;
        }

        private void StartLogin(string name, string pass)
        {
            InfoLabel.Text = "Bejelentkezés...";
            InfoLabel.ForeColor = Color.Black;
            LoginButton.Enabled = false;

            WebRequest.Login(name, pass, HandleResponse);
        }

        private void HandleResponse(WebResponse webResponse)
        {
            if (webResponse.IsSucces())
            {
                loginResponse = JsonConvert.DeserializeObject<LoginResponse>(webResponse.ToString());
                DialogResult = DialogResult.OK;
                Close();
            }
            else
            {
                LoginButton.Enabled = true;
                WriteError(webResponse.ToString());
            }
        }

        #endregion

        #region PUBLIC_METHODS

        public LoginResponse GetResponse()
        {
            return loginResponse;
        }

        #endregion

    }
}
