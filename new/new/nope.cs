using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace new
{
    public partial class nope : Form
{
    public nope()
    {
        InitializeComponent();
    }

    private void 撤销ToolStripMenuItem1_Click(object sender, EventArgs e)
    {
        textBox1.Undo;
    }

    private void 复制ToolStripMenuItem1_Click(object sender, EventArgs e)
    {

    }

    private void 剪切ToolStripMenuItem1_Click(object sender, EventArgs e)
    {

    }

    private void 粘贴ToolStripMenuItem1_Click(object sender, EventArgs e)
    {

    }

    private void 删除ToolStripMenuItem1_Click(object sender, EventArgs e)
    {

    }

    private void textBox1_TextChanged(object sender, EventArgs e)
    {
        string str = textBox1.Text;
        int m = textBox1.SelectionStart;
        int Ln = 0;
        int Col = 0;
        for (int i = m - 1; i >= 0; i--)
        {
            if (str[i] == '\n')
            {
                Ln++;
            }
            if (Ln < 1)
            {
                Col++;
            }
        }
        Ln = Ln + 1;
        Col = Col + 1;
        toolStripStatusLabel1.Text = "行:" + Ln.ToString() + "," + "列:" + Col.ToString();
    }
}
}
