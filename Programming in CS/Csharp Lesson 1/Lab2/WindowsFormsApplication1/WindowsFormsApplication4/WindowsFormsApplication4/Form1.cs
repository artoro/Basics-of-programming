using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace WindowsFormsApplication4
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            openFileDialog1.ShowDialog();
            if (openFileDialog1.FileName.Contains(".txt"))
                richTextBox1.Text = File.ReadAllText(openFileDialog1.FileName);
            else richTextBox1.Text = "File type error!";
        }

        private void button2_Click(object sender, EventArgs e)
        {
            saveFileDialog1.ShowDialog();
            if (saveFileDialog1.FileName.Contains(".txt"))
                File.WriteAllText(saveFileDialog1.FileName, richTextBox1.Text);
            else richTextBox1.Text = "File type error!";
        }
    }
}
