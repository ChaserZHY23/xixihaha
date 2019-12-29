namespace _4_3
{
    partial class Form1
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.选择出版社 = new System.Windows.Forms.Label();
            this.comboBox_Publishing = new System.Windows.Forms.ComboBox();
            this.textBox_Bookname = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.button_Remove = new System.Windows.Forms.Button();
            this.button_Add = new System.Windows.Forms.Button();
            this.listBox_Book = new System.Windows.Forms.ListBox();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.选择出版社);
            this.groupBox1.Controls.Add(this.comboBox_Publishing);
            this.groupBox1.Controls.Add(this.textBox_Bookname);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Location = new System.Drawing.Point(44, 55);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(170, 135);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            // 
            // 选择出版社
            // 
            this.选择出版社.AutoSize = true;
            this.选择出版社.Location = new System.Drawing.Point(26, 80);
            this.选择出版社.Name = "选择出版社";
            this.选择出版社.Size = new System.Drawing.Size(97, 15);
            this.选择出版社.TabIndex = 3;
            this.选择出版社.Text = "输入出版社：";
            // 
            // comboBox_Publishing
            // 
            this.comboBox_Publishing.FormattingEnabled = true;
            this.comboBox_Publishing.Location = new System.Drawing.Point(19, 105);
            this.comboBox_Publishing.Name = "comboBox_Publishing";
            this.comboBox_Publishing.Size = new System.Drawing.Size(107, 23);
            this.comboBox_Publishing.TabIndex = 2;
            // 
            // textBox_Bookname
            // 
            this.textBox_Bookname.Location = new System.Drawing.Point(19, 52);
            this.textBox_Bookname.Name = "textBox_Bookname";
            this.textBox_Bookname.Size = new System.Drawing.Size(100, 25);
            this.textBox_Bookname.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(16, 34);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(82, 15);
            this.label1.TabIndex = 0;
            this.label1.Text = "输入书名：";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.button_Remove);
            this.groupBox2.Controls.Add(this.button_Add);
            this.groupBox2.Location = new System.Drawing.Point(279, 68);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(170, 122);
            this.groupBox2.TabIndex = 1;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "groupBox2";
            // 
            // button_Remove
            // 
            this.button_Remove.Location = new System.Drawing.Point(36, 80);
            this.button_Remove.Name = "button_Remove";
            this.button_Remove.Size = new System.Drawing.Size(75, 23);
            this.button_Remove.TabIndex = 1;
            this.button_Remove.Text = "移除>>";
            this.button_Remove.UseVisualStyleBackColor = true;
            this.button_Remove.Click += new System.EventHandler(this.button_Remove_Click);
            // 
            // button_Add
            // 
            this.button_Add.Location = new System.Drawing.Point(36, 39);
            this.button_Add.Name = "button_Add";
            this.button_Add.Size = new System.Drawing.Size(75, 23);
            this.button_Add.TabIndex = 0;
            this.button_Add.Text = "添加>>";
            this.button_Add.UseVisualStyleBackColor = true;
            this.button_Add.Click += new System.EventHandler(this.button_Add_Click);
            // 
            // listBox_Book
            // 
            this.listBox_Book.FormattingEnabled = true;
            this.listBox_Book.ItemHeight = 15;
            this.listBox_Book.Location = new System.Drawing.Point(489, 81);
            this.listBox_Book.Name = "listBox_Book";
            this.listBox_Book.Size = new System.Drawing.Size(257, 214);
            this.listBox_Book.TabIndex = 2;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(758, 403);
            this.Controls.Add(this.listBox_Book);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label 选择出版社;
        private System.Windows.Forms.ComboBox comboBox_Publishing;
        private System.Windows.Forms.TextBox textBox_Bookname;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Button button_Remove;
        private System.Windows.Forms.Button button_Add;
        private System.Windows.Forms.ListBox listBox_Book;
    }
}

