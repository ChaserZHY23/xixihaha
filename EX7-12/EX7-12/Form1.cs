using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace EX7_12
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

        private void groupBox2_Enter(object sender, EventArgs e)
        {

        }

        private void button10_Click(object sender, EventArgs e)
        {

        }

        private void button12_Click(object sender, EventArgs e)
        {

        }

        private void button13_Click(object sender, EventArgs e)
        {

        }

        private void button11_Click(object sender, EventArgs e)
        {

        }

        private void button14_Click(object sender, EventArgs e)
        {

        }

        private void btnControl_Click(object sender, EventArgs e)
        {

        }

        private void groupBox3_Enter(object sender, EventArgs e)
        {

        }

        private void btnRed_Click(object sender, EventArgs e)
        {

        }

        private void btnYellow_Click(object sender, EventArgs e)
        {

        }

        private void btnGreen_Click(object sender, EventArgs e)
        {

        }

        private void button19_Click(object sender, EventArgs e)
        {

        }
        private void button21_Click(object sender, EventArgs e)
        {

        }

        private void button17_Click(object sender, EventArgs e)
        {

        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            
        }

        private void pictureBox1_MouseDown(object sender, MouseEventArgs e)
        {

        }

        private void pictureBox1_MouseUp(object sender, MouseEventArgs e)
        {
        if(e.Button ==MouseButtons.Left)
            {
                pEnd.X = e.X;
                pEnd.Y = e.Y;
                switch (ChoiceGraph)
                {

                }

            }
        }

        private void pictureBox1_MouseMove(object sender, MouseEventArgs e)
        {

            toolStripStatusLabel1.Text = "X:" + e.X.ToString() + ",Y:" + e.Y.ToString();

            if (e.Button == MouseButtons.Left)
            {
                switch (ChoiceGraph)
                {
                    case (int)mySelected.Pencil:            // 选择的是铅笔
                        Pen pen1 = new Pen(btnControl.BackColor, penWidth);
                        pEnd.X = e.X;
                        pEnd.Y = e.Y;
                        g.DrawLine(pen1, pStart, pEnd);
                        pStart = pEnd;          // 将已经绘制的终点作为下一次绘制的起点
                        break;
                    case (int)mySelected.Eraser:
                        Pen pen2 = new Pen(Color.White, penWidth);   // 定义白色画笔作为擦除效果
                        pEnd.X = e.X;
                        pEnd.Y = e.Y;
                        g.DrawLine(pen2, pStart, pEnd);
                        pStart = pEnd;          // 将已经绘制的终点作为下一次绘制的起点
                        break;
                    default:
                        break;
                }
            }
        }
    }
}
