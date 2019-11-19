namespace dmo
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
            this.tbxUsr = new System.Windows.Forms.TextBox();
            this.tbxPwd = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.myDdfanltBtn = new System.Windows.Forms.Button();
            this.myCanceBtn = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // tbxUsr
            // 
            this.tbxUsr.Location = new System.Drawing.Point(128, 38);
            this.tbxUsr.Name = "tbxUsr";
            this.tbxUsr.Size = new System.Drawing.Size(100, 25);
            this.tbxUsr.TabIndex = 0;
            // 
            // tbxPwd
            // 
            this.tbxPwd.Location = new System.Drawing.Point(128, 90);
            this.tbxPwd.Name = "tbxPwd";
            this.tbxPwd.PasswordChar = '.';
            this.tbxPwd.Size = new System.Drawing.Size(100, 25);
            this.tbxPwd.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(70, 48);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(52, 15);
            this.label1.TabIndex = 2;
            this.label1.Text = "账号：";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(70, 93);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(52, 15);
            this.label2.TabIndex = 3;
            this.label2.Text = "密码：";
            // 
            // myDdfanltBtn
            // 
            this.myDdfanltBtn.Location = new System.Drawing.Point(152, 206);
            this.myDdfanltBtn.Name = "myDdfanltBtn";
            this.myDdfanltBtn.Size = new System.Drawing.Size(75, 23);
            this.myDdfanltBtn.TabIndex = 4;
            this.myDdfanltBtn.Text = "登陆";
            this.myDdfanltBtn.UseVisualStyleBackColor = true;
            this.myDdfanltBtn.Click += new System.EventHandler(this.myDdfanltBtn_Click);
            // 
            // myCanceBtn
            // 
            this.myCanceBtn.Location = new System.Drawing.Point(264, 206);
            this.myCanceBtn.Name = "myCanceBtn";
            this.myCanceBtn.Size = new System.Drawing.Size(75, 23);
            this.myCanceBtn.TabIndex = 5;
            this.myCanceBtn.Text = "重写";
            this.myCanceBtn.UseVisualStyleBackColor = true;
            // 
            // Login
            // 
            this.AcceptButton = this.myCanceBtn;
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.CancelButton = this.myDdfanltBtn;
            this.ClientSize = new System.Drawing.Size(368, 324);
            this.Controls.Add(this.myCanceBtn);
            this.Controls.Add(this.myDdfanltBtn);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.tbxPwd);
            this.Controls.Add(this.tbxUsr);
            this.Name = "Login";
            this.Text = "登陆";
            this.Load += new System.EventHandler(this.Login_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox tbxUsr;
        private System.Windows.Forms.TextBox tbxPwd;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button myDdfanltBtn;
        private System.Windows.Forms.Button myCanceBtn;
    }
}