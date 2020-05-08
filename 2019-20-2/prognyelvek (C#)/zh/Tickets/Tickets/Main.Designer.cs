namespace Tickets
{
    partial class Main
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
            this.menuStrip = new System.Windows.Forms.MenuStrip();
            this.fIleToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.newToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.OpenedTickesList = new System.Windows.Forms.ListBox();
            this.CloseButton = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.ActiveTicketLabel = new System.Windows.Forms.Label();
            this.ArchiveButton = new System.Windows.Forms.Button();
            this.xmlDialog = new System.Windows.Forms.SaveFileDialog();
            this.NameLabel = new System.Windows.Forms.Label();
            this.TimesLabel = new System.Windows.Forms.Label();
            this.StatisticButton = new System.Windows.Forms.Button();
            this.AllDataList = new System.Windows.Forms.ListBox();
            this.menuStrip.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip
            // 
            this.menuStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fIleToolStripMenuItem});
            this.menuStrip.Location = new System.Drawing.Point(0, 0);
            this.menuStrip.Name = "menuStrip";
            this.menuStrip.Size = new System.Drawing.Size(800, 24);
            this.menuStrip.TabIndex = 0;
            this.menuStrip.Text = "menuStrip";
            // 
            // fIleToolStripMenuItem
            // 
            this.fIleToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.newToolStripMenuItem});
            this.fIleToolStripMenuItem.Name = "fIleToolStripMenuItem";
            this.fIleToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
            this.fIleToolStripMenuItem.Text = "File";
            // 
            // newToolStripMenuItem
            // 
            this.newToolStripMenuItem.Name = "newToolStripMenuItem";
            this.newToolStripMenuItem.Size = new System.Drawing.Size(98, 22);
            this.newToolStripMenuItem.Text = "New";
            this.newToolStripMenuItem.Click += new System.EventHandler(this.newToolStripMenuItem_Click);
            // 
            // OpenedTickesList
            // 
            this.OpenedTickesList.FormattingEnabled = true;
            this.OpenedTickesList.Location = new System.Drawing.Point(12, 27);
            this.OpenedTickesList.Name = "OpenedTickesList";
            this.OpenedTickesList.Size = new System.Drawing.Size(512, 212);
            this.OpenedTickesList.TabIndex = 1;
            // 
            // CloseButton
            // 
            this.CloseButton.Location = new System.Drawing.Point(12, 245);
            this.CloseButton.Name = "CloseButton";
            this.CloseButton.Size = new System.Drawing.Size(75, 23);
            this.CloseButton.TabIndex = 2;
            this.CloseButton.Text = "Lezár";
            this.CloseButton.UseVisualStyleBackColor = true;
            this.CloseButton.Click += new System.EventHandler(this.CloseButton_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(93, 250);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(108, 13);
            this.label1.TabIndex = 3;
            this.label1.Text = "Aktiv ticketek száma:";
            // 
            // ActiveTicketLabel
            // 
            this.ActiveTicketLabel.AutoSize = true;
            this.ActiveTicketLabel.Location = new System.Drawing.Point(200, 250);
            this.ActiveTicketLabel.Name = "ActiveTicketLabel";
            this.ActiveTicketLabel.Size = new System.Drawing.Size(13, 13);
            this.ActiveTicketLabel.TabIndex = 4;
            this.ActiveTicketLabel.Text = "0";
            // 
            // ArchiveButton
            // 
            this.ArchiveButton.Location = new System.Drawing.Point(12, 274);
            this.ArchiveButton.Name = "ArchiveButton";
            this.ArchiveButton.Size = new System.Drawing.Size(75, 23);
            this.ArchiveButton.TabIndex = 5;
            this.ArchiveButton.Text = "Archiválás";
            this.ArchiveButton.UseVisualStyleBackColor = true;
            this.ArchiveButton.Click += new System.EventHandler(this.ArchiveButton_Click);
            // 
            // NameLabel
            // 
            this.NameLabel.AutoSize = true;
            this.NameLabel.Location = new System.Drawing.Point(550, 35);
            this.NameLabel.Name = "NameLabel";
            this.NameLabel.Size = new System.Drawing.Size(27, 13);
            this.NameLabel.TabIndex = 6;
            this.NameLabel.Text = "Név";
            // 
            // TimesLabel
            // 
            this.TimesLabel.AutoSize = true;
            this.TimesLabel.Location = new System.Drawing.Point(684, 35);
            this.TimesLabel.Name = "TimesLabel";
            this.TimesLabel.Size = new System.Drawing.Size(44, 13);
            this.TimesLabel.TabIndex = 7;
            this.TimesLabel.Text = "Alkalom";
            // 
            // StatisticButton
            // 
            this.StatisticButton.Location = new System.Drawing.Point(449, 250);
            this.StatisticButton.Name = "StatisticButton";
            this.StatisticButton.Size = new System.Drawing.Size(75, 23);
            this.StatisticButton.TabIndex = 8;
            this.StatisticButton.Text = "Statisztika";
            this.StatisticButton.UseVisualStyleBackColor = true;
            this.StatisticButton.Click += new System.EventHandler(this.StatisticButton_Click);
            // 
            // AllDataList
            // 
            this.AllDataList.FormattingEnabled = true;
            this.AllDataList.Location = new System.Drawing.Point(12, 313);
            this.AllDataList.Name = "AllDataList";
            this.AllDataList.Size = new System.Drawing.Size(512, 212);
            this.AllDataList.TabIndex = 9;
            this.AllDataList.MouseEnter += new System.EventHandler(this.AllDataList_MouseEnter);
            // 
            // Main
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 537);
            this.Controls.Add(this.AllDataList);
            this.Controls.Add(this.StatisticButton);
            this.Controls.Add(this.TimesLabel);
            this.Controls.Add(this.NameLabel);
            this.Controls.Add(this.ArchiveButton);
            this.Controls.Add(this.ActiveTicketLabel);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.CloseButton);
            this.Controls.Add(this.OpenedTickesList);
            this.Controls.Add(this.menuStrip);
            this.MainMenuStrip = this.menuStrip;
            this.Name = "Main";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Main_Load);
            this.menuStrip.ResumeLayout(false);
            this.menuStrip.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip;
        private System.Windows.Forms.ToolStripMenuItem fIleToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem newToolStripMenuItem;
        private System.Windows.Forms.ListBox OpenedTickesList;
        private System.Windows.Forms.Button CloseButton;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label ActiveTicketLabel;
        private System.Windows.Forms.Button ArchiveButton;
        private System.Windows.Forms.SaveFileDialog xmlDialog;
        private System.Windows.Forms.Label NameLabel;
        private System.Windows.Forms.Label TimesLabel;
        private System.Windows.Forms.Button StatisticButton;
        private System.Windows.Forms.ListBox AllDataList;
    }
}

