using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace EX7_6
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Graphics g = this.CreateGraphics();
            Pen myPen = new Pen(Color.Black, 4);
            Rectangle rect = new Rectangle(30, 30, 100, 80);
            g.DrawEllipse(myPen, rect);

        }

        private void button2_Click(object sender, EventArgs e)
        {
            Graphics g = this.CreateGraphics();
            Pen myPen = new Pen(Color.Red, 4);
            g.DrawEllipse(myPen, 160, 30, 100, 80);

        }
    }
}
