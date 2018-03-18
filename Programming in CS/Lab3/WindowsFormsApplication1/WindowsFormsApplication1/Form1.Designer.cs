namespace WindowsFormsApplication1
{
    partial class Form1
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
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.okienkoToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.zwiększToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.zmniejszToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.zamknijToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.okienkoToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(284, 24);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // okienkoToolStripMenuItem
            // 
            this.okienkoToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.zwiększToolStripMenuItem,
            this.zmniejszToolStripMenuItem,
            this.zamknijToolStripMenuItem});
            this.okienkoToolStripMenuItem.Name = "okienkoToolStripMenuItem";
            this.okienkoToolStripMenuItem.Size = new System.Drawing.Size(63, 20);
            this.okienkoToolStripMenuItem.Text = "Okienko";
            // 
            // zwiększToolStripMenuItem
            // 
            this.zwiększToolStripMenuItem.Name = "zwiększToolStripMenuItem";
            this.zwiększToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.I)));
            this.zwiększToolStripMenuItem.Size = new System.Drawing.Size(164, 22);
            this.zwiększToolStripMenuItem.Text = "Zwiększ";
            this.zwiększToolStripMenuItem.Click += new System.EventHandler(this.zwiększToolStripMenuItem_Click);
            // 
            // zmniejszToolStripMenuItem
            // 
            this.zmniejszToolStripMenuItem.Name = "zmniejszToolStripMenuItem";
            this.zmniejszToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.O)));
            this.zmniejszToolStripMenuItem.Size = new System.Drawing.Size(164, 22);
            this.zmniejszToolStripMenuItem.Text = "Zmniejsz";
            this.zmniejszToolStripMenuItem.Click += new System.EventHandler(this.zmniejszToolStripMenuItem_Click);
            // 
            // zamknijToolStripMenuItem
            // 
            this.zamknijToolStripMenuItem.Name = "zamknijToolStripMenuItem";
            this.zamknijToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.Z)));
            this.zamknijToolStripMenuItem.Size = new System.Drawing.Size(164, 22);
            this.zamknijToolStripMenuItem.Text = "Zamknij";
            this.zamknijToolStripMenuItem.Click += new System.EventHandler(this.zamknijToolStripMenuItem_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 261);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.Text = "Form1";
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem okienkoToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem zwiększToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem zmniejszToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem zamknijToolStripMenuItem;
    }
}

