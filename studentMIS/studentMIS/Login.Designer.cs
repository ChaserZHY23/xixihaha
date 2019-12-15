namespace studentMIS
{
    partial class Login
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.tbxUsr = new System.Windows.Forms.TextBox();
            this.tbxPwd = new System.Windows.Forms.TextBox();
            this.myDefaultBtn = new System.Windows.Forms.Button();
            this.myCanceIBtn = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(11, 27);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(67, 15);
            this.label1.TabIndex = 0;
            this.label1.Text = "用户名：";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(26, 58);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(52, 15);
            this.label2.TabIndex = 1;
            this.label2.Text = "密码：";
            // 
            // tbxUsr
            // 
            this.tbxUsr.Location = new System.Drawing.Point(87, 24);
            this.tbxUsr.Name = "tbxUsr";
            this.tbxUsr.Size = new System.Drawing.Size(100, 25);
            this.tbxUsr.TabIndex = 2;
            // 
            // tbxPwd
            // 
            this.tbxPwd.Location = new System.Drawing.Point(87, 55);
            this.tbxPwd.Name = "tbxPwd";
            this.tbxPwd.Size = new System.Drawing.Size(100, 25);
            this.tbxPwd.TabIndex = 3;
            // 
            // myDefaultBtn
            // 
            this.myDefaultBtn.Location = new System.Drawing.Point(48, 158);
            this.myDefaultBtn.Name = "myDefaultBtn";
            this.myDefaultBtn.Size = new System.Drawing.Size(75, 23);
            this.myDefaultBtn.TabIndex = 4;
            this.myDefaultBtn.Text = "登陆";
            this.myDefaultBtn.UseVisualStyleBackColor = true;
            this.myDefaultBtn.Click += new System.EventHandler(this.myDefaultBtn_Click);
            // 
            // myCanceIBtn
            // 
            this.myCanceIBtn.Location = new System.Drawing.Point(166, 158);
            this.myCanceIBtn.Name = "myCanceIBtn";
            this.myCanceIBtn.Size = new System.Drawing.Size(75, 23);
            this.myCanceIBtn.TabIndex = 5;
            this.myCanceIBtn.Text = "重写";
            this.myCanceIBtn.UseVisualStyleBackColor = true;
            this.myCanceIBtn.Click += new System.EventHandler(this.myCanceIBtn_Click);
            // 
            // Login
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(282, 253);
            this.Controls.Add(this.myCanceIBtn);
            this.Controls.Add(this.myDefaultBtn);
            this.Controls.Add(this.tbxPwd);
            this.Controls.Add(this.tbxUsr);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "Login";
            this.Text = "Login";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox tbxUsr;
        private System.Windows.Forms.TextBox tbxPwd;
        private System.Windows.Forms.Button myDefaultBtn;
        private System.Windows.Forms.Button myCanceIBtn;
    }
}