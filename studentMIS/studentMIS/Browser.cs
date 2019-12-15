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
    public partial class Browser : Form
    {
        public Browser()
        {
            InitializeComponent();
            pictureBox1.Image = Image.FromFile(StudentMIS.Update.path);            rtbxStudentInfo.Text = StudentMIS.Update.info;
        }

        private void Browser_Load(object sender, EventArgs e)
        {

        }
    }
}
