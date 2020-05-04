namespace ExamApp
{
    partial class QuestionContainer
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
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(QuestionContainer));
            this.MainPanel = new System.Windows.Forms.TableLayoutPanel();
            this.TimeLeftLabel = new System.Windows.Forms.Label();
            this.ActualInfoPanel = new System.Windows.Forms.TableLayoutPanel();
            this.PointWorth = new System.Windows.Forms.Label();
            this.InfPointWorth = new System.Windows.Forms.Label();
            this.QuestNumLabel = new System.Windows.Forms.Label();
            this.InfQuestNumLabel = new System.Windows.Forms.Label();
            this.Timer = new System.Windows.Forms.Timer(this.components);
            this.MainPanel.SuspendLayout();
            this.ActualInfoPanel.SuspendLayout();
            this.SuspendLayout();
            // 
            // MainPanel
            // 
            this.MainPanel.ColumnCount = 1;
            this.MainPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.MainPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Absolute, 20F));
            this.MainPanel.Controls.Add(this.TimeLeftLabel, 0, 1);
            this.MainPanel.Controls.Add(this.ActualInfoPanel, 0, 0);
            this.MainPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.MainPanel.Location = new System.Drawing.Point(0, 0);
            this.MainPanel.Name = "MainPanel";
            this.MainPanel.RowCount = 2;
            this.MainPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.MainPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.MainPanel.Size = new System.Drawing.Size(650, 60);
            this.MainPanel.TabIndex = 0;
            // 
            // TimeLeftLabel
            // 
            this.TimeLeftLabel.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.TimeLeftLabel.AutoSize = true;
            this.TimeLeftLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.TimeLeftLabel.Location = new System.Drawing.Point(300, 35);
            this.TimeLeftLabel.Name = "TimeLeftLabel";
            this.TimeLeftLabel.Size = new System.Drawing.Size(49, 20);
            this.TimeLeftLabel.TabIndex = 0;
            this.TimeLeftLabel.Text = "00:00";
            // 
            // ActualInfoPanel
            // 
            this.ActualInfoPanel.ColumnCount = 4;
            this.ActualInfoPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.ActualInfoPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 25.15528F));
            this.ActualInfoPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 24.68944F));
            this.ActualInfoPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.ActualInfoPanel.Controls.Add(this.PointWorth, 3, 0);
            this.ActualInfoPanel.Controls.Add(this.InfPointWorth, 2, 0);
            this.ActualInfoPanel.Controls.Add(this.QuestNumLabel, 1, 0);
            this.ActualInfoPanel.Controls.Add(this.InfQuestNumLabel, 0, 0);
            this.ActualInfoPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.ActualInfoPanel.Location = new System.Drawing.Point(3, 3);
            this.ActualInfoPanel.Name = "ActualInfoPanel";
            this.ActualInfoPanel.RowCount = 1;
            this.ActualInfoPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.ActualInfoPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 24F));
            this.ActualInfoPanel.Size = new System.Drawing.Size(644, 24);
            this.ActualInfoPanel.TabIndex = 1;
            // 
            // PointWorth
            // 
            this.PointWorth.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.PointWorth.AutoSize = true;
            this.PointWorth.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.PointWorth.Location = new System.Drawing.Point(485, 4);
            this.PointWorth.Name = "PointWorth";
            this.PointWorth.Size = new System.Drawing.Size(15, 15);
            this.PointWorth.TabIndex = 3;
            this.PointWorth.Text = "5";
            // 
            // InfPointWorth
            // 
            this.InfPointWorth.Anchor = System.Windows.Forms.AnchorStyles.Right;
            this.InfPointWorth.AutoSize = true;
            this.InfPointWorth.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.InfPointWorth.Location = new System.Drawing.Point(398, 4);
            this.InfPointWorth.Name = "InfPointWorth";
            this.InfPointWorth.Size = new System.Drawing.Size(81, 15);
            this.InfPointWorth.TabIndex = 2;
            this.InfPointWorth.Text = "<pointworth>:";
            // 
            // QuestNumLabel
            // 
            this.QuestNumLabel.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this.QuestNumLabel.AutoSize = true;
            this.QuestNumLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.QuestNumLabel.Location = new System.Drawing.Point(164, 4);
            this.QuestNumLabel.Name = "QuestNumLabel";
            this.QuestNumLabel.Size = new System.Drawing.Size(156, 15);
            this.QuestNumLabel.TabIndex = 1;
            this.QuestNumLabel.Text = "10/1";
            // 
            // InfQuestNumLabel
            // 
            this.InfQuestNumLabel.Anchor = System.Windows.Forms.AnchorStyles.Right;
            this.InfQuestNumLabel.AutoSize = true;
            this.InfQuestNumLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.InfQuestNumLabel.Location = new System.Drawing.Point(62, 4);
            this.InfQuestNumLabel.Name = "InfQuestNumLabel";
            this.InfQuestNumLabel.Size = new System.Drawing.Size(96, 15);
            this.InfQuestNumLabel.TabIndex = 0;
            this.InfQuestNumLabel.Text = "<questionnum>:";
            // 
            // Timer
            // 
            this.Timer.Interval = 1000;
            this.Timer.Tick += new System.EventHandler(this.Timer_Tick);
            // 
            // QuestionContainer
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(650, 60);
            this.ControlBox = false;
            this.Controls.Add(this.MainPanel);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "QuestionContainer";
            this.ShowIcon = false;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "QuestionContainer";
            this.TopMost = true;
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.QuestionContainer_FormClosing);
            this.Load += new System.EventHandler(this.QuestionContainer_Load);
            this.MainPanel.ResumeLayout(false);
            this.MainPanel.PerformLayout();
            this.ActualInfoPanel.ResumeLayout(false);
            this.ActualInfoPanel.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TableLayoutPanel MainPanel;
        private System.Windows.Forms.Label TimeLeftLabel;
        private System.Windows.Forms.TableLayoutPanel ActualInfoPanel;
        private System.Windows.Forms.Label PointWorth;
        private System.Windows.Forms.Label InfPointWorth;
        private System.Windows.Forms.Label QuestNumLabel;
        private System.Windows.Forms.Label InfQuestNumLabel;
        private System.Windows.Forms.Timer Timer;
    }
}