namespace ExamApp
{
    partial class MainForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
            this.MainPanel = new System.Windows.Forms.TableLayoutPanel();
            this.TitleLabel = new System.Windows.Forms.Label();
            this.ContentPanel = new System.Windows.Forms.TableLayoutPanel();
            this.InformationPanel = new System.Windows.Forms.TableLayoutPanel();
            this.SelfPanel = new System.Windows.Forms.TableLayoutPanel();
            this.NameLabel = new System.Windows.Forms.Label();
            this.InformationButtonPanel = new System.Windows.Forms.TableLayoutPanel();
            this.LoginButton = new System.Windows.Forms.Button();
            this.AddNewUsersButton = new System.Windows.Forms.Button();
            this.LangPanel = new System.Windows.Forms.TableLayoutPanel();
            this.EngPB = new System.Windows.Forms.PictureBox();
            this.HunPB = new System.Windows.Forms.PictureBox();
            this.InfLabel = new System.Windows.Forms.Label();
            this.ExamDescriptionPanel = new System.Windows.Forms.TableLayoutPanel();
            this.InfResoultLabel = new System.Windows.Forms.Label();
            this.InfTitleLabel = new System.Windows.Forms.Label();
            this.InfDescriptionLabel = new System.Windows.Forms.Label();
            this.InfIsRandomLabel = new System.Windows.Forms.Label();
            this.InfTimeLabel = new System.Windows.Forms.Label();
            this.InfQuestionNumLabel = new System.Windows.Forms.Label();
            this.DetTitleLabel = new System.Windows.Forms.Label();
            this.DetDescriptionLabel = new System.Windows.Forms.Label();
            this.DetIsRandomLabel = new System.Windows.Forms.Label();
            this.DetTimeLabel = new System.Windows.Forms.Label();
            this.DetQuestNumLabel = new System.Windows.Forms.Label();
            this.DetResoultLabel = new System.Windows.Forms.Label();
            this.ExamsPanel = new System.Windows.Forms.TableLayoutPanel();
            this.QuestionButtonPanel = new System.Windows.Forms.TableLayoutPanel();
            this.ExamStartButton = new System.Windows.Forms.Button();
            this.ExamStatisticButton = new System.Windows.Forms.Button();
            this.ExamNewButton = new System.Windows.Forms.Button();
            this.ExamListView = new System.Windows.Forms.ListBox();
            this.FooterPanel = new System.Windows.Forms.TableLayoutPanel();
            this.VersionLabel = new System.Windows.Forms.Label();
            this.ServerLabel = new System.Windows.Forms.Label();
            this.AuthorLabel = new System.Windows.Forms.Label();
            this.newUserFileDialog = new System.Windows.Forms.OpenFileDialog();
            this.MainPanel.SuspendLayout();
            this.ContentPanel.SuspendLayout();
            this.InformationPanel.SuspendLayout();
            this.SelfPanel.SuspendLayout();
            this.InformationButtonPanel.SuspendLayout();
            this.LangPanel.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.EngPB)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.HunPB)).BeginInit();
            this.ExamDescriptionPanel.SuspendLayout();
            this.ExamsPanel.SuspendLayout();
            this.QuestionButtonPanel.SuspendLayout();
            this.FooterPanel.SuspendLayout();
            this.SuspendLayout();
            // 
            // MainPanel
            // 
            this.MainPanel.ColumnCount = 1;
            this.MainPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.MainPanel.Controls.Add(this.TitleLabel, 0, 0);
            this.MainPanel.Controls.Add(this.ContentPanel, 0, 1);
            this.MainPanel.Controls.Add(this.FooterPanel, 0, 2);
            this.MainPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.MainPanel.Location = new System.Drawing.Point(0, 0);
            this.MainPanel.Name = "MainPanel";
            this.MainPanel.RowCount = 3;
            this.MainPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 8.465609F));
            this.MainPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 86.77248F));
            this.MainPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 4.761905F));
            this.MainPanel.Size = new System.Drawing.Size(915, 426);
            this.MainPanel.TabIndex = 0;
            // 
            // TitleLabel
            // 
            this.TitleLabel.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.TitleLabel.AutoSize = true;
            this.TitleLabel.Font = new System.Drawing.Font("Lucida Sans", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.TitleLabel.Location = new System.Drawing.Point(393, 4);
            this.TitleLabel.Name = "TitleLabel";
            this.TitleLabel.Size = new System.Drawing.Size(129, 27);
            this.TitleLabel.TabIndex = 0;
            this.TitleLabel.Text = "ExamApp";
            // 
            // ContentPanel
            // 
            this.ContentPanel.CellBorderStyle = System.Windows.Forms.TableLayoutPanelCellBorderStyle.Single;
            this.ContentPanel.ColumnCount = 2;
            this.ContentPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 60F));
            this.ContentPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 40F));
            this.ContentPanel.Controls.Add(this.InformationPanel, 0, 0);
            this.ContentPanel.Controls.Add(this.ExamsPanel, 1, 0);
            this.ContentPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.ContentPanel.Location = new System.Drawing.Point(3, 39);
            this.ContentPanel.Name = "ContentPanel";
            this.ContentPanel.RowCount = 1;
            this.ContentPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.ContentPanel.Size = new System.Drawing.Size(909, 363);
            this.ContentPanel.TabIndex = 2;
            // 
            // InformationPanel
            // 
            this.InformationPanel.ColumnCount = 1;
            this.InformationPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.InformationPanel.Controls.Add(this.SelfPanel, 0, 0);
            this.InformationPanel.Controls.Add(this.InformationButtonPanel, 0, 3);
            this.InformationPanel.Controls.Add(this.InfLabel, 0, 1);
            this.InformationPanel.Controls.Add(this.ExamDescriptionPanel, 0, 2);
            this.InformationPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.InformationPanel.Location = new System.Drawing.Point(4, 4);
            this.InformationPanel.Name = "InformationPanel";
            this.InformationPanel.RowCount = 4;
            this.InformationPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 10.23702F));
            this.InformationPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 9.991325F));
            this.InformationPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 70.68863F));
            this.InformationPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 9.083023F));
            this.InformationPanel.Size = new System.Drawing.Size(537, 355);
            this.InformationPanel.TabIndex = 0;
            // 
            // SelfPanel
            // 
            this.SelfPanel.CellBorderStyle = System.Windows.Forms.TableLayoutPanelCellBorderStyle.Inset;
            this.SelfPanel.ColumnCount = 1;
            this.SelfPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.SelfPanel.Controls.Add(this.NameLabel, 0, 0);
            this.SelfPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.SelfPanel.Location = new System.Drawing.Point(3, 3);
            this.SelfPanel.Name = "SelfPanel";
            this.SelfPanel.RowCount = 1;
            this.SelfPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.SelfPanel.Size = new System.Drawing.Size(531, 30);
            this.SelfPanel.TabIndex = 1;
            // 
            // NameLabel
            // 
            this.NameLabel.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.NameLabel.AutoSize = true;
            this.NameLabel.Font = new System.Drawing.Font("Lucida Sans Typewriter", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.NameLabel.Location = new System.Drawing.Point(250, 7);
            this.NameLabel.Name = "NameLabel";
            this.NameLabel.Size = new System.Drawing.Size(31, 15);
            this.NameLabel.TabIndex = 0;
            this.NameLabel.Text = "...";
            // 
            // InformationButtonPanel
            // 
            this.InformationButtonPanel.ColumnCount = 4;
            this.InformationButtonPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.InformationButtonPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.InformationButtonPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.InformationButtonPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.InformationButtonPanel.Controls.Add(this.LoginButton, 0, 0);
            this.InformationButtonPanel.Controls.Add(this.AddNewUsersButton, 2, 0);
            this.InformationButtonPanel.Controls.Add(this.LangPanel, 3, 0);
            this.InformationButtonPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.InformationButtonPanel.Location = new System.Drawing.Point(3, 324);
            this.InformationButtonPanel.Name = "InformationButtonPanel";
            this.InformationButtonPanel.RowCount = 1;
            this.InformationButtonPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.InformationButtonPanel.Size = new System.Drawing.Size(531, 28);
            this.InformationButtonPanel.TabIndex = 2;
            // 
            // LoginButton
            // 
            this.LoginButton.Dock = System.Windows.Forms.DockStyle.Fill;
            this.LoginButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.LoginButton.Location = new System.Drawing.Point(3, 3);
            this.LoginButton.Name = "LoginButton";
            this.LoginButton.Size = new System.Drawing.Size(126, 22);
            this.LoginButton.TabIndex = 1;
            this.LoginButton.Text = "<login>";
            this.LoginButton.UseVisualStyleBackColor = true;
            this.LoginButton.Click += new System.EventHandler(this.LoginButton_Click);
            // 
            // AddNewUsersButton
            // 
            this.AddNewUsersButton.Dock = System.Windows.Forms.DockStyle.Fill;
            this.AddNewUsersButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.AddNewUsersButton.Location = new System.Drawing.Point(267, 3);
            this.AddNewUsersButton.Name = "AddNewUsersButton";
            this.AddNewUsersButton.Size = new System.Drawing.Size(126, 22);
            this.AddNewUsersButton.TabIndex = 2;
            this.AddNewUsersButton.Text = "<newuser>";
            this.AddNewUsersButton.UseVisualStyleBackColor = true;
            this.AddNewUsersButton.Visible = false;
            this.AddNewUsersButton.Click += new System.EventHandler(this.AddNewUsersButton_Click);
            // 
            // LangPanel
            // 
            this.LangPanel.ColumnCount = 2;
            this.LangPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.LangPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.LangPanel.Controls.Add(this.EngPB, 1, 0);
            this.LangPanel.Controls.Add(this.HunPB, 0, 0);
            this.LangPanel.Location = new System.Drawing.Point(399, 3);
            this.LangPanel.Name = "LangPanel";
            this.LangPanel.RowCount = 1;
            this.LangPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.LangPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 22F));
            this.LangPanel.Size = new System.Drawing.Size(129, 22);
            this.LangPanel.TabIndex = 3;
            // 
            // EngPB
            // 
            this.EngPB.Anchor = System.Windows.Forms.AnchorStyles.Bottom;
            this.EngPB.Image = global::ExamApp.Properties.Resources.engFlag;
            this.EngPB.Location = new System.Drawing.Point(67, 3);
            this.EngPB.Name = "EngPB";
            this.EngPB.Size = new System.Drawing.Size(59, 16);
            this.EngPB.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.EngPB.TabIndex = 1;
            this.EngPB.TabStop = false;
            this.EngPB.Click += new System.EventHandler(this.EngPB_Click);
            // 
            // HunPB
            // 
            this.HunPB.Anchor = System.Windows.Forms.AnchorStyles.Bottom;
            this.HunPB.Image = global::ExamApp.Properties.Resources.hunFlag;
            this.HunPB.Location = new System.Drawing.Point(3, 3);
            this.HunPB.Name = "HunPB";
            this.HunPB.Size = new System.Drawing.Size(58, 16);
            this.HunPB.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.HunPB.TabIndex = 0;
            this.HunPB.TabStop = false;
            this.HunPB.Click += new System.EventHandler(this.HunPB_Click);
            // 
            // InfLabel
            // 
            this.InfLabel.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.InfLabel.AutoSize = true;
            this.InfLabel.Font = new System.Drawing.Font("Lucida Sans", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.InfLabel.Location = new System.Drawing.Point(3, 42);
            this.InfLabel.Name = "InfLabel";
            this.InfLabel.Size = new System.Drawing.Size(157, 22);
            this.InfLabel.TabIndex = 3;
            this.InfLabel.Text = "<information> :";
            // 
            // ExamDescriptionPanel
            // 
            this.ExamDescriptionPanel.ColumnCount = 2;
            this.ExamDescriptionPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 30F));
            this.ExamDescriptionPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 70F));
            this.ExamDescriptionPanel.Controls.Add(this.InfResoultLabel, 0, 5);
            this.ExamDescriptionPanel.Controls.Add(this.InfTitleLabel, 0, 0);
            this.ExamDescriptionPanel.Controls.Add(this.InfDescriptionLabel, 0, 1);
            this.ExamDescriptionPanel.Controls.Add(this.InfIsRandomLabel, 0, 2);
            this.ExamDescriptionPanel.Controls.Add(this.InfTimeLabel, 0, 3);
            this.ExamDescriptionPanel.Controls.Add(this.InfQuestionNumLabel, 0, 4);
            this.ExamDescriptionPanel.Controls.Add(this.DetTitleLabel, 1, 0);
            this.ExamDescriptionPanel.Controls.Add(this.DetDescriptionLabel, 1, 1);
            this.ExamDescriptionPanel.Controls.Add(this.DetIsRandomLabel, 1, 2);
            this.ExamDescriptionPanel.Controls.Add(this.DetTimeLabel, 1, 3);
            this.ExamDescriptionPanel.Controls.Add(this.DetQuestNumLabel, 1, 4);
            this.ExamDescriptionPanel.Controls.Add(this.DetResoultLabel, 1, 5);
            this.ExamDescriptionPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.ExamDescriptionPanel.Location = new System.Drawing.Point(3, 74);
            this.ExamDescriptionPanel.Name = "ExamDescriptionPanel";
            this.ExamDescriptionPanel.RowCount = 6;
            this.ExamDescriptionPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 16.71924F));
            this.ExamDescriptionPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 16.71924F));
            this.ExamDescriptionPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 16.71924F));
            this.ExamDescriptionPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 16.71924F));
            this.ExamDescriptionPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 16.71924F));
            this.ExamDescriptionPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 16.40379F));
            this.ExamDescriptionPanel.Size = new System.Drawing.Size(531, 244);
            this.ExamDescriptionPanel.TabIndex = 4;
            // 
            // InfResoultLabel
            // 
            this.InfResoultLabel.Anchor = System.Windows.Forms.AnchorStyles.Right;
            this.InfResoultLabel.AutoSize = true;
            this.InfResoultLabel.Location = new System.Drawing.Point(74, 216);
            this.InfResoultLabel.Name = "InfResoultLabel";
            this.InfResoultLabel.Size = new System.Drawing.Size(82, 12);
            this.InfResoultLabel.TabIndex = 5;
            this.InfResoultLabel.Text = "<resoult> :";
            // 
            // InfTitleLabel
            // 
            this.InfTitleLabel.Anchor = System.Windows.Forms.AnchorStyles.Right;
            this.InfTitleLabel.AutoSize = true;
            this.InfTitleLabel.Location = new System.Drawing.Point(81, 14);
            this.InfTitleLabel.Name = "InfTitleLabel";
            this.InfTitleLabel.Size = new System.Drawing.Size(75, 12);
            this.InfTitleLabel.TabIndex = 0;
            this.InfTitleLabel.Text = "<titile> :";
            // 
            // InfDescriptionLabel
            // 
            this.InfDescriptionLabel.Anchor = System.Windows.Forms.AnchorStyles.Right;
            this.InfDescriptionLabel.AutoSize = true;
            this.InfDescriptionLabel.Location = new System.Drawing.Point(46, 54);
            this.InfDescriptionLabel.Name = "InfDescriptionLabel";
            this.InfDescriptionLabel.Size = new System.Drawing.Size(110, 12);
            this.InfDescriptionLabel.TabIndex = 1;
            this.InfDescriptionLabel.Text = "<description> :";
            // 
            // InfIsRandomLabel
            // 
            this.InfIsRandomLabel.Anchor = System.Windows.Forms.AnchorStyles.Right;
            this.InfIsRandomLabel.AutoSize = true;
            this.InfIsRandomLabel.Location = new System.Drawing.Point(67, 94);
            this.InfIsRandomLabel.Name = "InfIsRandomLabel";
            this.InfIsRandomLabel.Size = new System.Drawing.Size(89, 12);
            this.InfIsRandomLabel.TabIndex = 2;
            this.InfIsRandomLabel.Text = "<israndom> :";
            // 
            // InfTimeLabel
            // 
            this.InfTimeLabel.Anchor = System.Windows.Forms.AnchorStyles.Right;
            this.InfTimeLabel.AutoSize = true;
            this.InfTimeLabel.Location = new System.Drawing.Point(95, 134);
            this.InfTimeLabel.Name = "InfTimeLabel";
            this.InfTimeLabel.Size = new System.Drawing.Size(61, 12);
            this.InfTimeLabel.TabIndex = 3;
            this.InfTimeLabel.Text = "<time> :";
            // 
            // InfQuestionNumLabel
            // 
            this.InfQuestionNumLabel.Anchor = System.Windows.Forms.AnchorStyles.Right;
            this.InfQuestionNumLabel.AutoSize = true;
            this.InfQuestionNumLabel.Location = new System.Drawing.Point(46, 174);
            this.InfQuestionNumLabel.Name = "InfQuestionNumLabel";
            this.InfQuestionNumLabel.Size = new System.Drawing.Size(110, 12);
            this.InfQuestionNumLabel.TabIndex = 4;
            this.InfQuestionNumLabel.Text = "<questionnum> :";
            // 
            // DetTitleLabel
            // 
            this.DetTitleLabel.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.DetTitleLabel.AutoSize = true;
            this.DetTitleLabel.Location = new System.Drawing.Point(162, 14);
            this.DetTitleLabel.Name = "DetTitleLabel";
            this.DetTitleLabel.Size = new System.Drawing.Size(0, 12);
            this.DetTitleLabel.TabIndex = 6;
            // 
            // DetDescriptionLabel
            // 
            this.DetDescriptionLabel.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.DetDescriptionLabel.AutoSize = true;
            this.DetDescriptionLabel.Location = new System.Drawing.Point(162, 54);
            this.DetDescriptionLabel.Name = "DetDescriptionLabel";
            this.DetDescriptionLabel.Size = new System.Drawing.Size(0, 12);
            this.DetDescriptionLabel.TabIndex = 7;
            // 
            // DetIsRandomLabel
            // 
            this.DetIsRandomLabel.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.DetIsRandomLabel.AutoSize = true;
            this.DetIsRandomLabel.Location = new System.Drawing.Point(162, 94);
            this.DetIsRandomLabel.Name = "DetIsRandomLabel";
            this.DetIsRandomLabel.Size = new System.Drawing.Size(0, 12);
            this.DetIsRandomLabel.TabIndex = 8;
            // 
            // DetTimeLabel
            // 
            this.DetTimeLabel.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.DetTimeLabel.AutoSize = true;
            this.DetTimeLabel.Location = new System.Drawing.Point(162, 134);
            this.DetTimeLabel.Name = "DetTimeLabel";
            this.DetTimeLabel.Size = new System.Drawing.Size(0, 12);
            this.DetTimeLabel.TabIndex = 9;
            // 
            // DetQuestNumLabel
            // 
            this.DetQuestNumLabel.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.DetQuestNumLabel.AutoSize = true;
            this.DetQuestNumLabel.Location = new System.Drawing.Point(162, 174);
            this.DetQuestNumLabel.Name = "DetQuestNumLabel";
            this.DetQuestNumLabel.Size = new System.Drawing.Size(0, 12);
            this.DetQuestNumLabel.TabIndex = 10;
            // 
            // DetResoultLabel
            // 
            this.DetResoultLabel.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.DetResoultLabel.AutoSize = true;
            this.DetResoultLabel.Location = new System.Drawing.Point(162, 216);
            this.DetResoultLabel.Name = "DetResoultLabel";
            this.DetResoultLabel.Size = new System.Drawing.Size(0, 12);
            this.DetResoultLabel.TabIndex = 11;
            // 
            // ExamsPanel
            // 
            this.ExamsPanel.AutoScroll = true;
            this.ExamsPanel.ColumnCount = 1;
            this.ExamsPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.ExamsPanel.Controls.Add(this.QuestionButtonPanel, 0, 1);
            this.ExamsPanel.Controls.Add(this.ExamListView, 0, 0);
            this.ExamsPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.ExamsPanel.Location = new System.Drawing.Point(548, 4);
            this.ExamsPanel.Name = "ExamsPanel";
            this.ExamsPanel.RowCount = 2;
            this.ExamsPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 90F));
            this.ExamsPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 10F));
            this.ExamsPanel.Size = new System.Drawing.Size(357, 355);
            this.ExamsPanel.TabIndex = 1;
            // 
            // QuestionButtonPanel
            // 
            this.QuestionButtonPanel.ColumnCount = 3;
            this.QuestionButtonPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 33.33333F));
            this.QuestionButtonPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 33.33333F));
            this.QuestionButtonPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 33.33333F));
            this.QuestionButtonPanel.Controls.Add(this.ExamStartButton, 0, 0);
            this.QuestionButtonPanel.Controls.Add(this.ExamStatisticButton, 1, 0);
            this.QuestionButtonPanel.Controls.Add(this.ExamNewButton, 2, 0);
            this.QuestionButtonPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.QuestionButtonPanel.Location = new System.Drawing.Point(3, 322);
            this.QuestionButtonPanel.Name = "QuestionButtonPanel";
            this.QuestionButtonPanel.RowCount = 1;
            this.QuestionButtonPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.QuestionButtonPanel.Size = new System.Drawing.Size(351, 30);
            this.QuestionButtonPanel.TabIndex = 0;
            // 
            // ExamStartButton
            // 
            this.ExamStartButton.Dock = System.Windows.Forms.DockStyle.Fill;
            this.ExamStartButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.ExamStartButton.Location = new System.Drawing.Point(3, 3);
            this.ExamStartButton.Name = "ExamStartButton";
            this.ExamStartButton.Size = new System.Drawing.Size(111, 24);
            this.ExamStartButton.TabIndex = 3;
            this.ExamStartButton.Text = "<start>";
            this.ExamStartButton.UseVisualStyleBackColor = true;
            this.ExamStartButton.Visible = false;
            this.ExamStartButton.Click += new System.EventHandler(this.ExamStartButton_Click);
            // 
            // ExamStatisticButton
            // 
            this.ExamStatisticButton.Dock = System.Windows.Forms.DockStyle.Fill;
            this.ExamStatisticButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.ExamStatisticButton.Location = new System.Drawing.Point(120, 3);
            this.ExamStatisticButton.Name = "ExamStatisticButton";
            this.ExamStatisticButton.Size = new System.Drawing.Size(111, 24);
            this.ExamStatisticButton.TabIndex = 4;
            this.ExamStatisticButton.Text = "<statistic>";
            this.ExamStatisticButton.UseVisualStyleBackColor = true;
            this.ExamStatisticButton.Visible = false;
            this.ExamStatisticButton.Click += new System.EventHandler(this.ExamStatisticButton_Click);
            // 
            // ExamNewButton
            // 
            this.ExamNewButton.Dock = System.Windows.Forms.DockStyle.Fill;
            this.ExamNewButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.ExamNewButton.Location = new System.Drawing.Point(237, 3);
            this.ExamNewButton.Name = "ExamNewButton";
            this.ExamNewButton.Size = new System.Drawing.Size(111, 24);
            this.ExamNewButton.TabIndex = 5;
            this.ExamNewButton.Text = "<edit>";
            this.ExamNewButton.UseVisualStyleBackColor = true;
            this.ExamNewButton.Visible = false;
            this.ExamNewButton.Click += new System.EventHandler(this.ExamNewButton_Click);
            // 
            // ExamListView
            // 
            this.ExamListView.BackColor = System.Drawing.SystemColors.Control;
            this.ExamListView.Dock = System.Windows.Forms.DockStyle.Fill;
            this.ExamListView.Font = new System.Drawing.Font("Lucida Sans Typewriter", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ExamListView.FormattingEnabled = true;
            this.ExamListView.ItemHeight = 18;
            this.ExamListView.Location = new System.Drawing.Point(3, 3);
            this.ExamListView.Name = "ExamListView";
            this.ExamListView.Size = new System.Drawing.Size(351, 313);
            this.ExamListView.TabIndex = 1;
            this.ExamListView.SelectedIndexChanged += new System.EventHandler(this.ExamListView_SelectedIndexChanged);
            // 
            // FooterPanel
            // 
            this.FooterPanel.ColumnCount = 3;
            this.FooterPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 33.33333F));
            this.FooterPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 33.33333F));
            this.FooterPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 33.33333F));
            this.FooterPanel.Controls.Add(this.VersionLabel, 2, 0);
            this.FooterPanel.Controls.Add(this.ServerLabel, 1, 0);
            this.FooterPanel.Controls.Add(this.AuthorLabel, 0, 0);
            this.FooterPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.FooterPanel.Location = new System.Drawing.Point(3, 408);
            this.FooterPanel.Name = "FooterPanel";
            this.FooterPanel.RowCount = 1;
            this.FooterPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.FooterPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 15F));
            this.FooterPanel.Size = new System.Drawing.Size(909, 15);
            this.FooterPanel.TabIndex = 3;
            // 
            // VersionLabel
            // 
            this.VersionLabel.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.VersionLabel.AutoSize = true;
            this.VersionLabel.Font = new System.Drawing.Font("Lucida Sans Typewriter", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.VersionLabel.ForeColor = System.Drawing.Color.Black;
            this.VersionLabel.Location = new System.Drawing.Point(757, 1);
            this.VersionLabel.Name = "VersionLabel";
            this.VersionLabel.Size = new System.Drawing.Size(0, 12);
            this.VersionLabel.TabIndex = 2;
            // 
            // ServerLabel
            // 
            this.ServerLabel.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.ServerLabel.AutoSize = true;
            this.ServerLabel.Font = new System.Drawing.Font("Lucida Sans Typewriter", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ServerLabel.Location = new System.Drawing.Point(441, 1);
            this.ServerLabel.Name = "ServerLabel";
            this.ServerLabel.Size = new System.Drawing.Size(26, 12);
            this.ServerLabel.TabIndex = 1;
            this.ServerLabel.Text = "...";
            // 
            // AuthorLabel
            // 
            this.AuthorLabel.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.AuthorLabel.AutoSize = true;
            this.AuthorLabel.Font = new System.Drawing.Font("Lucida Sans Typewriter", 6F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.AuthorLabel.Location = new System.Drawing.Point(3, 6);
            this.AuthorLabel.Name = "AuthorLabel";
            this.AuthorLabel.Size = new System.Drawing.Size(110, 9);
            this.AuthorLabel.TabIndex = 0;
            this.AuthorLabel.Text = "Magyar Tamás | RNYR2F";
            // 
            // newUserFileDialog
            // 
            this.newUserFileDialog.Filter = "CSV Files|*.csv";
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(915, 426);
            this.Controls.Add(this.MainPanel);
            this.Font = new System.Drawing.Font("Lucida Sans Typewriter", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MinimumSize = new System.Drawing.Size(464, 234);
            this.Name = "MainForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "ExamApp";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.MainPanel.ResumeLayout(false);
            this.MainPanel.PerformLayout();
            this.ContentPanel.ResumeLayout(false);
            this.InformationPanel.ResumeLayout(false);
            this.InformationPanel.PerformLayout();
            this.SelfPanel.ResumeLayout(false);
            this.SelfPanel.PerformLayout();
            this.InformationButtonPanel.ResumeLayout(false);
            this.LangPanel.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.EngPB)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.HunPB)).EndInit();
            this.ExamDescriptionPanel.ResumeLayout(false);
            this.ExamDescriptionPanel.PerformLayout();
            this.ExamsPanel.ResumeLayout(false);
            this.QuestionButtonPanel.ResumeLayout(false);
            this.FooterPanel.ResumeLayout(false);
            this.FooterPanel.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TableLayoutPanel MainPanel;
        private System.Windows.Forms.Label TitleLabel;
        private System.Windows.Forms.TableLayoutPanel ContentPanel;
        private System.Windows.Forms.TableLayoutPanel InformationPanel;
        private System.Windows.Forms.TableLayoutPanel ExamsPanel;
        private System.Windows.Forms.TableLayoutPanel SelfPanel;
        private System.Windows.Forms.Label NameLabel;
        private System.Windows.Forms.TableLayoutPanel InformationButtonPanel;
        private System.Windows.Forms.Button ExamNewButton;
        private System.Windows.Forms.Button AddNewUsersButton;
        private System.Windows.Forms.Button LoginButton;
        private System.Windows.Forms.Label InfLabel;
        private System.Windows.Forms.TableLayoutPanel ExamDescriptionPanel;
        private System.Windows.Forms.Label InfTitleLabel;
        private System.Windows.Forms.Label InfDescriptionLabel;
        private System.Windows.Forms.Label InfIsRandomLabel;
        private System.Windows.Forms.Label InfTimeLabel;
        private System.Windows.Forms.Label InfQuestionNumLabel;
        private System.Windows.Forms.TableLayoutPanel QuestionButtonPanel;
        private System.Windows.Forms.Button ExamStatisticButton;
        private System.Windows.Forms.Button ExamStartButton;
        private System.Windows.Forms.ListBox ExamListView;
        private System.Windows.Forms.Label InfResoultLabel;
        private System.Windows.Forms.Label DetTitleLabel;
        private System.Windows.Forms.Label DetDescriptionLabel;
        private System.Windows.Forms.Label DetIsRandomLabel;
        private System.Windows.Forms.Label DetTimeLabel;
        private System.Windows.Forms.Label DetQuestNumLabel;
        private System.Windows.Forms.Label DetResoultLabel;
        private System.Windows.Forms.TableLayoutPanel FooterPanel;
        private System.Windows.Forms.Label VersionLabel;
        private System.Windows.Forms.Label ServerLabel;
        private System.Windows.Forms.Label AuthorLabel;
        private System.Windows.Forms.TableLayoutPanel LangPanel;
        private System.Windows.Forms.PictureBox EngPB;
        private System.Windows.Forms.PictureBox HunPB;
        private System.Windows.Forms.OpenFileDialog newUserFileDialog;
    }
}

