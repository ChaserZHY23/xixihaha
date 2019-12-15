using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace StudentMISC
{
    public partial class Welcome : Form
    {
        public static Login loginForm;
        public static Update updateForm;
        public static Browser browserForm;
        public Welcome()
        {
            InitializeComponent();
            loginForm = new Login();
            updateForm = new Update();
        }
        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            linkLabel1.LinkVisited = true;
            loginForm.Show();
            this.Hide();
        }

        private void Welcome_Load(object sender, EventArgs e)
        {

        }
    } 
}
