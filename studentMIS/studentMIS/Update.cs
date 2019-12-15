using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace studentMIS
{
    public partial class Update : Form
    {
        public Update()
        {
            InitializeComponent();
            path = @"D:\My Documents\证件照.gif";            pictureBox1.Image = Image.FromFile(path);
        }

        private void Update_Load(object sender, EventArgs e)
        {

        }
    }
}
