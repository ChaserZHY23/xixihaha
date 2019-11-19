namespace _20191119
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
            this.TextBox1 = new System.Windows.Forms.TextBox();
            this.TexBox2 = new System.Windows.Forms.TextBox();
            this.hag = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // TextBox1
            // 
            this.TextBox1.Location = new System.Drawing.Point(13, 25);
            this.TextBox1.Name = "TextBox1";
            this.TextBox1.Size = new System.Drawing.Size(38, 25);
            this.TextBox1.TabIndex = 0;
            // 
            // TexBox2
            // 
            this.TexBox2.Location = new System.Drawing.Point(13, 68);
            this.TexBox2.Name = "TexBox2";
            this.TexBox2.Size = new System.Drawing.Size(38, 25);
            this.TexBox2.TabIndex = 1;
            // 
            // hag
            // 
            this.hag.AutoSize = true;
            this.hag.Location = new System.Drawing.Point(97, 35);
            this.hag.Name = "hag";
            this.hag.Size = new System.Drawing.Size(55, 15);
            this.hag.TabIndex = 2;
            this.hag.Text = "label1";
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(162, 126);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 3;
            this.button1.Text = "学号：";
            this.button1.UseVisualStyleBackColor = true;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(391, 502);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.hag);
            this.Controls.Add(this.TexBox2);
            this.Controls.Add(this.TextBox1);
            this.Name = "Form1";
            this.Text = "修改学生信息";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox TextBox1;
        private System.Windows.Forms.TextBox TexBox2;
        private System.Windows.Forms.Label hag;
        private System.Windows.Forms.Button button1;
    }
}

