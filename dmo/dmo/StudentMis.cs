using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace dmo
{
    public partial class StudentMis : Form
    {
        public static Login loginFrom;
        public static Updata updataFrom;
        public static Browser browerFrom;
        public StudentMis()
        {
            InitializeComponent();
        }

        private void StudentMis_Load(object sender, EventArgs e)
        {

        }

        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            linkLabel1.LinkVisited = true;
            loginFrom.Show();
            this.Hide();
        }
    }
}
