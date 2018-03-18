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

namespace WindowsFormsApplication3
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
            {
                if(richTextBox2.Text.Length>0)
                    File.WriteAllLines(saveFileDialog1.FileName, richTextBox2.Lines);
                else File.WriteAllLines(saveFileDialog1.FileName, richTextBox1.Lines);
            }
            else richTextBox1.Text = "File type error!";
        }

        private void button3_Click(object sender, EventArgs e)
        {
            List<int> tab = new List<int>(richTextBox1.Lines.Length);
            for (int i = 0; i < richTextBox1.Lines.Length; i++) tab.Add(int.Parse(richTextBox1.Lines[i]));
            tab.Sort();
            richTextBox2.Text = "";
            for (int i = 0; i < richTextBox1.Lines.Length; i++) richTextBox2.Text += tab[i].ToString() + Environment.NewLine;
        }
        /*
* private void button1_Click(object sender, EventArgs e)
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
*/
    }
}
