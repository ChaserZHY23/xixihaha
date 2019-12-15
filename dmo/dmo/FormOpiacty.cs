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
    public partial class FormOpiacty : Form
    {
        public FormOpiacty()
        {
            InitializeComponent();
        }

        private void BtnAdd_Click(object sender, EventArgs e)
        {
            this.Opacity += 0.1;
        }

        private void SubAtn_Click(object sender, EventArgs e)
        {
            if(this.Opacity>0.2)
            {
                this.Opacity -= 0.1;
            }
            else
            {
                this.Opacity = 1;
            }
        }

        private void FormOpiacty_Load(object sender, EventArgs e)
        {

        }
    }
}
