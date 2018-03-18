using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Random rand = new Random();
            int[] tab = new int[100];
            richTextBox1.Text = "";
            for (int i = 0; i < tab.Length; i++)
            {
                tab[i] = rand.Next(0, 100000);
                richTextBox1.Text += tab[i].ToString() + "\n";
            }
            int min = tab[0], max = tab[0];
            for (int i=1; i<tab.Length;i++)
            {
                if (tab[i] > max) max = tab[i];
                else if (tab[i] < min) min = tab[i];
            }
            textBox1.Text = min.ToString();
            textBox2.Text = max.ToString();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Random rand = new Random();
            int[][] tab = new int[10][];
            for (int i = 0; i < tab.Length; i++) tab[i] = new int[10];
            richTextBox2.Text = "";
            for (int i = 0; i < tab.Length; i++, richTextBox2.Text += "\n") for (int j = 0; j < tab[i].Length; j++)
            {
                tab[i][j] = rand.Next(0, 100);
                richTextBox2.Text += tab[i][j].ToString() + " ";
            }
            int min = tab[0][0], max = tab[0][0];
            for (int i = 1; i < tab.Length; i++) for (int j = 0; j < tab[i].Length; j++)
                {
                if (tab[i][j] > max) max = tab[i][j];
                else if (tab[i][j] < min) min = tab[i][j];
            }
            textBox3.Text = min.ToString();
            textBox4.Text = max.ToString();
        }
    }
}
