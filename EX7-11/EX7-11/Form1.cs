using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace EX7_11
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {

            Bitmap myBitmap = new Bitmap("E:\\QQ截图20190928212430.png");
            Graphics g = pictureBox1.CreateGraphics();
            g.DrawImage(myBitmap, 0, 0);
        }
    }
}
