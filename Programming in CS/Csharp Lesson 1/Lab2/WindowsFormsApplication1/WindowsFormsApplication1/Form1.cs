using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Double a, b;
            try {
                a = Double.Parse(textBox1.Text);
                b = Double.Parse(textBox2.Text);
            }
            catch (Exception) {
                label1.Text = "Error!";
                return;
            }
            if (radioButton1.Checked) label1.Text = (a + b).ToString();
            else if (radioButton2.Checked) label1.Text = (a - b).ToString();
            else if (radioButton3.Checked) label1.Text = (a * b).ToString();
            else if (radioButton4.Checked && b!=0) label1.Text = (a / b).ToString();
            else label1.Text = "Error!";
        }
    }
}
