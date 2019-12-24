using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace EX9_3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            SqlConnection sqlcon = new SqlConnection(strcon);
            try
            {
                string stuID = txtStuID.Text.Trim();
                string stuName = txtName.Text.Trim();
                string stuXB;
                if (RbtnMale.Checked)
                {
                    stuXB = "男";
                }
                else
                {
                    stuXB = "女";
                }
                string stuBirthday = dateTimePicker1.Value.ToShortDateString().Split(' ')[0];
                string stuMajor = txtMajor.Text.Trim();
                string stuCredit = txtCredit.Text.Trim();
                SqlCommand command = new SqlCommand();
                command.CommandText = "INSERT INTO XSB(XH,XM,XB,CSRQ,ZY,ZXF)

        VALUES('" + stuID + "', '" + stuName + "', '" + stuXB + "', '" + stuBirthday + "', '" + stuMajor + 

                                                        "','" + stuCredit + "')";
                command.CommandType = CommandType.Text;
                command.Connection = sqlcon;
                sqlcon.Open();
                myda = new SqlDataAdapter(command);
                myda.Fill(myst, "XSB");
                MessageBox.Show("插入成功！", "消息", MessageBoxButtons.OK);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            finally
            {
                sqlcon.Close();
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            using (SqlConnection sqlcon = new SqlConnection(strcon))
            {
                sqlcon.Open();
                string sql = "SELECT * FROM XSB";
                SqlCommand command = new SqlCommand(sql, sqlcon);
                myda = new SqlDataAdapter(command);
                myst.Tables.Clear();
                myda.Fill(myst, "XSB");
                dgvAllStu.DataSource = myst.Tables["XSB"];
            }
        }
    }
}
