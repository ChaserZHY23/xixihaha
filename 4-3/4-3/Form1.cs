using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _4_3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button_Add_Click(object sender, EventArgs e)
        {
            listBox_Book.Items.Add("书名：" + textBox_Bookname.Text + "，出版社：" + comboBox_Publishing.Text);
            textBox_Bookname.Text = "";
        }

        private void button_Remove_Click(object sender, EventArgs e)
        {
            if (listBox_Book.SelectedIndex != -1)
            {
                listBox_Book.Items.Remove(this.listBox_Book.SelectedItem);
            }
        }
    }
}
